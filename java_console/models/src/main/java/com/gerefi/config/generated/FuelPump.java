package com.gerefi.config.generated;

// this file was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/actuators/fuel_pump_control.txt Fri May 05 21:06:50 UTC 2023

// by class com.gerefi.output.FileJavaFieldsConsumer
import com.gerefi.config.*;

public class FuelPump {
	public static final Field ISPRIME = Field.create("ISPRIME", 0, FieldType.BIT, 0).setBaseOffset(1020);
	public static final Field ENGINETURNEDRECENTLY = Field.create("ENGINETURNEDRECENTLY", 0, FieldType.BIT, 1).setBaseOffset(1020);
	public static final Field ISFUELPUMPON = Field.create("ISFUELPUMPON", 0, FieldType.BIT, 2).setBaseOffset(1020);
	public static final Field IGNITIONON = Field.create("IGNITIONON", 0, FieldType.BIT, 3).setBaseOffset(1020);
	public static final Field[] VALUES = {
	ISPRIME,
	ENGINETURNEDRECENTLY,
	ISFUELPUMPON,
	IGNITIONON,
	};
}
