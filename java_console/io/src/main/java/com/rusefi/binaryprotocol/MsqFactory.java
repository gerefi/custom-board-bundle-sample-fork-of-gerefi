package com.gerefi.binaryprotocol;

import com.opensr5.ConfigurationImage;
import com.gerefi.config.generated.Fields;
import com.gerefi.tune.xml.Msq;

public class MsqFactory {
    public static Msq valueOf(ConfigurationImage image) {
        return Msq.valueOf(image, Fields.TOTAL_CONFIG_SIZE, Fields.TS_SIGNATURE);
    }
}
