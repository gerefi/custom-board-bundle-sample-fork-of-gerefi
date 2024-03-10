package com.gerefi.config.generated;

// this file was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/algo/wall_fuel_state.txt Fri May 05 21:06:50 UTC 2023

// by class com.gerefi.output.FileJavaFieldsConsumer
import com.gerefi.config.*;

public class WallFuelState {
	public static final Field WALLFUELCORRECTION = Field.create("WALLFUELCORRECTION", 0, FieldType.FLOAT).setBaseOffset(1240);
	public static final Field WALLFUEL = Field.create("WALLFUEL", 4, FieldType.FLOAT).setBaseOffset(1240);
	public static final Field[] VALUES = {
	WALLFUELCORRECTION,
	WALLFUEL,
	};
}
