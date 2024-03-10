package com.gerefi;

import com.gerefi.core.SignatureHelper;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class SignatureHelperTest {
    @Test
    public void test() {
        String url = SignatureHelper.getUrl("gerefi master.2020.07.06.frankenso_na6.2468827536").first;
        assertEquals("https://gerefi.com/online/ini/gerefi/master/2020/07/06/frankenso_na6/2468827536.ini", url);
    }
}
