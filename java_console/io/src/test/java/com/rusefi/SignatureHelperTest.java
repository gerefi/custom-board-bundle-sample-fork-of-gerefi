package com.gerefi;

import com.gerefi.core.gerefiSignature;
import com.gerefi.core.SignatureHelper;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class SignatureHelperTest {
    @Test
    public void parseSignature() {
        gerefiSignature s = SignatureHelper.parse("gerefi master.2021.09.22.all.3378169541");

        assertEquals("master", s.getBranch());
        assertEquals("all", s.getBundleTarget());
    }
}
