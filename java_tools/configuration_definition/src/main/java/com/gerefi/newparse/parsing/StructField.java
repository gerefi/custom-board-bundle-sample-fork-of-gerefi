package com.gerefi.newparse.parsing;

public class StructField extends PrototypeField {
    public final Struct struct;

    public StructField(Struct struct, String name) {
        super(name);

        this.struct = struct;
    }
}
