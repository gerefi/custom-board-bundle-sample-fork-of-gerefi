package com.gerefi.util;

import java.io.IOException;

public interface Output {
    void write(String line);

    void close() throws IOException;
}
