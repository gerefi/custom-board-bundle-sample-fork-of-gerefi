package com.gerefi.config.generated;

// this file was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/math/throttle_model.txt Fri May 05 21:06:50 UTC 2023

// by class com.gerefi.output.FileJavaFieldsConsumer
import com.gerefi.config.*;

public class ThrottleModel {
	public static final Field THROTTLEUSEWOTMODEL = Field.create("THROTTLEUSEWOTMODEL", 0, FieldType.BIT, 0).setBaseOffset(908);
	public static final Field THROTTLEMODELCROSSOVERANGLE = Field.create("THROTTLEMODELCROSSOVERANGLE", 4, FieldType.INT16).setScale(0.01).setBaseOffset(908);
	public static final Field ALIGNMENTFILL_AT_6 = Field.create("ALIGNMENTFILL_AT_6", 6, FieldType.INT8).setScale(1.0).setBaseOffset(908);
	public static final Field THROTTLEESTIMATEDFLOW = Field.create("THROTTLEESTIMATEDFLOW", 8, FieldType.FLOAT).setBaseOffset(908);
	public static final Field[] VALUES = {
	THROTTLEUSEWOTMODEL,
	THROTTLEMODELCROSSOVERANGLE,
	ALIGNMENTFILL_AT_6,
	THROTTLEESTIMATEDFLOW,
	};
}
