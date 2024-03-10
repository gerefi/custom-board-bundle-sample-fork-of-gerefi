package com.gerefi.config.generated;

// this file was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/algo/fuel/injector_model.txt Fri May 05 21:06:50 UTC 2023

// by class com.gerefi.output.FileJavaFieldsConsumer
import com.gerefi.config.*;

public class InjectorModel {
	public static final Field M_DEADTIME = Field.create("M_DEADTIME", 0, FieldType.FLOAT).setBaseOffset(948);
	public static final Field PRESSUREDELTA = Field.create("PRESSUREDELTA", 4, FieldType.FLOAT).setBaseOffset(948);
	public static final Field PRESSURERATIO = Field.create("PRESSURERATIO", 8, FieldType.FLOAT).setBaseOffset(948);
	public static final Field[] VALUES = {
	M_DEADTIME,
	PRESSUREDELTA,
	PRESSURERATIO,
	};
}
