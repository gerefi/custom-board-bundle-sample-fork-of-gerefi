package com.gerefi.output;

import com.devexperts.logging.Logging;
import com.gerefi.ReaderState;

import java.io.FileWriter;
import java.io.IOException;

import static com.devexperts.logging.Logging.getLogging;

/**
 * TODO: We have to move either forward or backwards with newparse #4441
 * [OutputChannels]
 */
public class OutputsSectionConsumer implements ConfigurationConsumer {
    private static final Logging log = getLogging(OutputsSectionConsumer.class);

    private final String tsOutputsSectionFileName;
    private final TsOutput tsOutput;
    private int sensorTsPosition;

    public OutputsSectionConsumer(String tsOutputsSectionFileName) {
        this.tsOutputsSectionFileName = tsOutputsSectionFileName;
        tsOutput = new TsOutput(false);
    }

    public String getContent() {
        return tsOutput.getContent();
    }

    public int getBaseOffset() {
        return sensorTsPosition;
    }

    @Override
    public void handleEndStruct(ReaderState readerState, ConfigStructure structure) throws IOException {
        log.info("handleEndStruct");

        sensorTsPosition = tsOutput.run(readerState, structure, sensorTsPosition);

        if (readerState.isStackEmpty()) {
            if (tsOutputsSectionFileName != null) {
                FileWriter fos = new FileWriter(tsOutputsSectionFileName);
                fos.write(tsOutput.getContent());
                fos.close();
            }
        }
    }
}
