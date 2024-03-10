package com.gerefi.native_;

import com.opensr5.ConfigurationImage;
import com.gerefi.config.Field;
import com.gerefi.config.generated.Fields;
import com.gerefi.core.Sensor;
import com.gerefi.enums.SensorType;
import org.junit.Before;
import org.junit.Test;

import java.nio.ByteBuffer;

import static com.gerefi.config.generated.Fields.TS_FILE_VERSION;
import static com.gerefi.config.generated.Fields.engine_type_e_FRANKENSO_MAZDA_MIATA_2003;
import static com.gerefi.core.FileUtil.littleEndianWrap;
import static junit.framework.Assert.*;

public class JniUnitTest {
    private static final double EPS = 0.001;

    @Before
    public void reset() {
        JniSandbox.loadLibrary();
        EngineLogic.resetTest();
    }

    @Test
    public void run() {
        String version = EngineLogic.getVersion();
        assertTrue("Got " + version, version.contains("Hello"));

        EngineLogic engineLogic = new EngineLogic();
        engineLogic.invokePeriodicCallback();

        assertEquals(TS_FILE_VERSION, (int) getValue(engineLogic.getOutputs(), Sensor.FIRMWARE_VERSION));

        assertEquals(14.0, getValue(engineLogic.getOutputs(), Sensor.afrTarget));

        double veValue = getValue(engineLogic.getOutputs(), Sensor.veValue);
        assertTrue("veValue", veValue > 40 && veValue < 90);

//        assertEquals(18.11, getValue(engineLogic.getOutputs(), Sensor.runningFuel));

        engineLogic.setSensor(SensorType.Rpm.name(), 4000);
        engineLogic.invokePeriodicCallback();
        assertEquals(4000.0, getValue(engineLogic.getOutputs(), Sensor.RPMValue));

  //      assertEquals(18.11, getValue(engineLogic.getOutputs(), Sensor.runningFuel));

        assertEquals(0.25096, getValue(engineLogic.getOutputs(), Sensor.sdAirMassInOneCylinder), 0.0001);

        engineLogic.setEngineType(engine_type_e_FRANKENSO_MAZDA_MIATA_2003);
        assertEquals(3.76, getField(engineLogic, Fields.GEARRATIO1), EPS);
    }

    @Test
    public void testEtbStuff() {
        EngineLogic engineLogic = new EngineLogic();

        engineLogic.setSensor(SensorType.Tps1Primary.name(), 30);
        engineLogic.setSensor(SensorType.Tps1Secondary.name(), 30);

        engineLogic.burnRequest(); // hack: this is here to initialize engine helper prior to mocking sensors

        engineLogic.setSensor(SensorType.AcceleratorPedalPrimary.name(), 40);
        engineLogic.setSensor(SensorType.AcceleratorPedalSecondary.name(), 40);

        engineLogic.setConfiguration(new byte[]{3}, Fields.TPS1_1ADCCHANNEL.getTotalOffset(), 1);
        engineLogic.setConfiguration(new byte[]{3}, Fields.TPS1_2ADCCHANNEL.getTotalOffset(), 1);
        engineLogic.setConfiguration(new byte[]{3}, Fields.THROTTLEPEDALPOSITIONADCCHANNEL.getTotalOffset(), 1);
        engineLogic.setConfiguration(new byte[]{3}, Fields.THROTTLEPEDALPOSITIONSECONDADCCHANNEL.getTotalOffset(), 1);

        engineLogic.initTps();
        engineLogic.burnRequest();
        System.out.println("engineLogic.invokeEtbCycle");
        engineLogic.invokeEtbCycle();

        assertEquals(120.38, getValue(engineLogic.getOutputs(), Sensor.etb1DutyCycle));
    }

    private double getField(EngineLogic engineLogic, Field field) {
        byte[] configuration = engineLogic.getConfiguration();
        assertNotNull("configuration", configuration);
        return field.getValue(new ConfigurationImage(configuration), field.getScale());
    }

    private double getValue(byte[] outputs, Sensor sensor) {
        ByteBuffer bb = littleEndianWrap(outputs, sensor.getOffset(), 4);
        return sensor.getValueForChannel(bb) * sensor.getScale();
    }
}
