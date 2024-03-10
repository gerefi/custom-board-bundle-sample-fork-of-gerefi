package com.gerefi.output;

import com.gerefi.ReaderStateImpl;
import com.gerefi.ToolUtil;
import com.gerefi.util.LazyFile;

import java.io.File;
import java.io.IOException;

import static com.gerefi.ToolUtil.EOL;

/**
 * This class generates java representation of gerefi data structures used by gerefi console
 */
public class FileJavaFieldsConsumer extends JavaFieldsConsumer {
    private static final String JAVA_PACKAGE = "com.gerefi.config.generated";

    private final LazyFile javaFields;
    private final String className;

    public FileJavaFieldsConsumer(ReaderStateImpl state, String javaDestination, int baseOffset) {
        super(state, baseOffset);
        javaFields = new LazyFile(javaDestination);
        String className = new File(javaDestination).getName();
        this.className = className.substring(0, className.indexOf('.'));
    }

    @Override
    public void startFile() {
        javaFields.write("package " + JAVA_PACKAGE + ";" + ToolUtil.EOL + ToolUtil.EOL);
        javaFields.write("// this file " + state.getHeader() + ToolUtil.EOL + EOL);
        javaFields.write("// by " + getClass() + EOL);
        javaFields.write("import com.gerefi.config.*;" + EOL + EOL);
        javaFields.write("public class " + className + " {" + ToolUtil.EOL);
    }

    @Override
    public void endFile() throws IOException {
        javaFields.write(state.getVariableRegistry().getJavaConstants());
        javaFields.write(getContent());

        allFields.append("\t};" + EOL);
        javaFields.write(allFields.toString());

        javaFields.write("}" + ToolUtil.EOL);
        javaFields.close();
    }
}
