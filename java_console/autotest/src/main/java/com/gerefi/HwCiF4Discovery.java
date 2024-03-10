package com.gerefi;

import com.gerefi.common.MiscTest;
import com.gerefi.f4discovery.CommonFunctionalTest;
import com.gerefi.f4discovery.HighRevTest;
import com.gerefi.f4discovery.PwmHardwareTest;
import com.gerefi.f4discovery.VssHardwareLoopTest;
import com.gerefi.io.CommandQueue;

/**
 * dead?
 * 
 * The following jumper wires are used to test some subsystems as realistically as possible:
 * PD1 <=> PC6
 * PD2 <=> PA5
 * <p>
 * <p>
 * <p>
 * this test connects to real hardware via serial port
 * Andrey Belomutskiy, (c) 2013-2020
 * 2/22/2015
 */
public class HwCiF4Discovery {

    public static void main(String[] args) {
        /**
         * trying a random hack https://github.com/gerefi/gerefi/issues/4772
         */
        CommandQueue.DEFAULT_TIMEOUT = 4950;
        boolean isOk = runHardwareTest();
        if (!isOk)
            System.exit(-1);
    }

    static boolean runHardwareTest() {
        return CmdJUnitRunner.runHardwareTest(
                new Class[]{MiscTest.class,
                        CommonFunctionalTest.class,
                        PwmHardwareTest.class,
                        VssHardwareLoopTest.class,
                        HighRevTest.class});
    }
}
