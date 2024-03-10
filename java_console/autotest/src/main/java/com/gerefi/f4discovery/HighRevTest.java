package com.gerefi.f4discovery;

import com.gerefi.gerefiTestBase;
import com.gerefi.enums.engine_type_e;
import com.gerefi.functional_tests.EcuTestHelper;
import org.junit.Test;

import static com.gerefi.config.generated.Fields.CMD_ENGINESNIFFERRPMTHRESHOLD;
import static com.gerefi.functional_tests.EcuTestHelper.FAIL;

public class HighRevTest extends gerefiTestBase {
    @Test
    public void testVW() {
        ecu.setEngineType(engine_type_e.VW_ABA);
        // trying to disable engine sniffer to help https://github.com/gerefi/gerefi/issues/1849
        ecu.sendCommand("set " + CMD_ENGINESNIFFERRPMTHRESHOLD + " 100");
        ecu.changeRpm(900);
        // first let's get to expected RPM
        EcuTestHelper.assertRpmDoesNotJump(6000, 5, 40, FAIL, ecu.commandQueue);
    }

    @Test
    public void testV12() {
        ecu.setEngineType(engine_type_e.FRANKENSO_BMW_M73_F);
        ecu.changeRpm(700);
        // first let's get to expected RPM
        EcuTestHelper.assertRpmDoesNotJump(6000, 5, 40, FAIL, ecu.commandQueue);

        // tests bug 1873
        EcuTestHelper.assertRpmDoesNotJump(60, 5, 110, FAIL, ecu.commandQueue);
    }
}
