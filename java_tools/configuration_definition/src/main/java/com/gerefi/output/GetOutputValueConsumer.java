package com.gerefi.output;

import com.gerefi.ConfigField;
import com.gerefi.ReaderState;
import com.gerefi.TypesHelper;
import com.gerefi.core.Pair;
import com.gerefi.output.variables.VariableRecord;
import org.jetbrains.annotations.NotNull;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

import static com.gerefi.output.ConfigStructureImpl.ALIGNMENT_FILL_AT;
import static com.gerefi.output.DataLogConsumer.UNUSED;
import static com.gerefi.output.GetConfigValueConsumer.FILE_HEADER;
import static com.gerefi.output.GetConfigValueConsumer.getCompareName;

/**
 * here we generate C++ code needed for https://github.com/gerefi/gerefi/wiki/Lua-Scripting#getoutputname implementation
 *
 * @see GetConfigValueConsumer
 */
@SuppressWarnings("StringConcatenationInsideStringBufferAppend")
public class GetOutputValueConsumer implements ConfigurationConsumer {
    private final List<VariableRecord> getterPairs = new ArrayList<>();
    private final String fileName;

    public String currentSectionPrefix = "engine->outputChannels";
    public String conditional;

    public GetOutputValueConsumer(String fileName) {
        this.fileName = fileName;
    }

    @Override
    public void handleEndStruct(ReaderState state, ConfigStructure structure) throws IOException {
        if (state.isStackEmpty()) {
            PerFieldWithStructuresIterator iterator = new PerFieldWithStructuresIterator(state, structure.getTsFields(), "",
                    (readerState, cf, prefix) -> processOutput(cf, prefix), ".");
            iterator.loop();
        }
    }

    private String processOutput(ConfigField cf, String prefix) {
        if (cf.getName().contains(UNUSED) || cf.getName().contains(ALIGNMENT_FILL_AT))
            return "";

        if (cf.isArray() || cf.isFromIterate() || cf.isDirective())
            return "";
        if (!TypesHelper.isPrimitive(cf.getType()) && !TypesHelper.isBoolean(cf.getType())) {
            return "";
        }

        String userName = prefix + cf.getName();
        String javaName = currentSectionPrefix + "." + prefix;

        getterPairs.add(new VariableRecord(userName, javaName + cf.getName(),  null, conditional));


        return "";
    }

    @Override
    public void endFile() throws IOException {
        GetConfigValueConsumer.writeStringToFile(fileName, getContent());
    }

    public String getContent() {
        StringBuilder switchBody = new StringBuilder();

        StringBuilder getterBody = getGetters(switchBody, getterPairs);

        String fullSwitch = wrapSwitchStatement(switchBody);

        return FILE_HEADER +
                "float getOutputValueByName(const char *name) {\n" +
                fullSwitch +
                getterBody + GetConfigValueConsumer.GET_METHOD_FOOTER;
    }

    @NotNull
    static String wrapSwitchStatement(StringBuilder switchBody) {
        String fullSwitch = switchBody.length() == 0 ? "" :
                ("\tint hash = djb2lowerCase(name);\n" +

                        "\tswitch(hash) {\n" + switchBody + "\t}\n");
        return fullSwitch;
    }

    @NotNull
    static StringBuilder getGetters(StringBuilder switchBody, List<VariableRecord> getterPairs) {
        HashMap<Integer, AtomicInteger> hashConflicts = getHashConflicts(getterPairs);

        StringBuilder getterBody = new StringBuilder();
        for (VariableRecord pair : getterPairs) {
            String returnLine = "\t\treturn " + pair.getFullName() + ";\n";
            String conditional = pair.getConditional();

            String before = conditional == null ? "" : "#if " + conditional + "\n";
            String after = conditional == null ? "" : "#endif\n";

            int hash = HashUtil.hash(pair.getUserName());
            if (hashConflicts.get(hash).get() == 1) {
                switchBody.append("// " + pair.getUserName() + "\n");
                switchBody.append(before);
                switchBody.append("\t\tcase " + hash + ":\n");
                switchBody.append("\t" + returnLine);
                switchBody.append(after);
            } else {
                getterBody.append(getCompareName(pair.getUserName()));
                getterBody.append(returnLine);
            }
        }
        return getterBody;
    }

    @NotNull
    static HashMap<Integer, AtomicInteger> getHashConflicts(List<VariableRecord> getterPairs) {
        HashMap<Integer, AtomicInteger> hashConflicts = new HashMap<>();
        for (VariableRecord pair : getterPairs) {
            hashConflicts.computeIfAbsent(HashUtil.hash(pair.getUserName()), integer -> new AtomicInteger(0)).incrementAndGet();
        }
        return hashConflicts;
    }

}
