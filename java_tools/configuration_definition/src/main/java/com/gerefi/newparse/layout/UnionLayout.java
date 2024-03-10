package com.gerefi.newparse.layout;

import com.gerefi.newparse.outputs.TsMetadata;
import com.gerefi.newparse.parsing.ArrayField;
import com.gerefi.newparse.parsing.Field;
import com.gerefi.newparse.parsing.ScalarField;
import com.gerefi.newparse.parsing.Union;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class UnionLayout extends Layout {
    private final List<Layout> children = new ArrayList<>();

    public UnionLayout(Union u) {
        for (Field f : u.fields) {
            // For every child, check if it is the largest, and grow if so
            if (f instanceof ArrayField) {
                ArrayField af = (ArrayField)f;

                // we probably don't need union of iterate?
                assert(!af.iterate);

                ScalarField prototype = (ScalarField)af.prototype;
                this.children.add(new ArrayLayout(prototype, af.length));
            } else if (f instanceof ScalarField) {
                this.children.add(new ScalarLayout((ScalarField)f));
            } else {
                throw new RuntimeException("Tried to create union with member type " + f.getClass().getSimpleName());
            }
        }
    }

    @Override
    public void setOffset(int offset) {
        super.setOffset(offset);
        this.children.forEach(c -> c.setOffset(offset));
    }

    @Override
    public void setOffsetWithinStruct(int offset) {
        super.setOffsetWithinStruct(offset);
        this.children.forEach(c -> c.setOffsetWithinStruct(offset));
    }

    @Override
    public int getSize() {
        return this.children.stream().map(Layout::getSize).max(Integer::compare).get();
    }

    @Override
    public int getAlignment() {
        // The alignment of the union is the largest alignment required by one of the members
        return this.children.stream().map(Layout::getAlignment).max(Integer::compare).get();
    }

    @Override
    protected void writeTunerstudioLayout(PrintStream ps, TsMetadata meta, StructNamePrefixer prefixer, int offsetAdd) {
        // Simply write out all children - no container necessary as fields can overlap in TS
        this.children.forEach(c -> c.writeTunerstudioLayout(ps, meta, prefixer, offsetAdd));
    }

    @Override
    public void writeCLayout(PrintStream ps) {
        this.writeCOffsetHeader(ps, "union size " + this.getSize() + ", " + this.children.size() + " members", null);

        // emit an anonymous union that contains all our members
        ps.println("\tunion {");
        this.children.forEach(c -> c.writeCLayout(ps));
        ps.println("\t};");
    }
}
