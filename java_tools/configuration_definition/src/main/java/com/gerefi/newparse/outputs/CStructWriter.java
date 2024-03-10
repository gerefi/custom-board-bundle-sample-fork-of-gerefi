package com.gerefi.newparse.outputs;

import com.gerefi.newparse.ParseState;
import com.gerefi.newparse.layout.StructLayout;
import com.gerefi.newparse.parsing.Struct;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;

public class CStructWriter {
    public void writeCStructs(ParseState parser, String outputFile) throws FileNotFoundException {
        writeCStructs(parser, new PrintStreamAlwaysUnix(new FileOutputStream(outputFile)));
    }

    public void writeCStructs(ParseState parser, PrintStream ps) {
        ps.println(
                "// begin\n" +
                "#pragma once\n" +
                "#include \"gerefi_types.h\""
        );

        for (Struct s : parser.getStructs()) {
            StructLayout sl = new StructLayout(0, "root", s);
            sl.writeCLayoutRoot(ps);
        }

        ps.println("// end");

        ps.close();
    }
}
