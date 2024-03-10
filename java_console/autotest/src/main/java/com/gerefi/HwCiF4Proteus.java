package com.gerefi;

import com.gerefi.common.MiscTest;
import com.gerefi.proteus.ProteusAnalogTest;

public class HwCiF4Proteus {
    public static void main(String[] args) {
        boolean isOk = CmdJUnitRunner.runHardwareTest(new Class[]{
                MiscTest.class,
                ProteusAnalogTest.class,
        });
        if (!isOk)
            System.exit(-1);
    }
}
