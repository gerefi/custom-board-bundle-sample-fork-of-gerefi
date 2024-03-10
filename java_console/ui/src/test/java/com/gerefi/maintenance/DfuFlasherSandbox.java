package com.gerefi.maintenance;

import com.gerefi.ui.StatusConsumer;

import static com.gerefi.maintenance.DfuFlasher.detectPcan;
import static com.gerefi.maintenance.DfuFlasher.detectStLink;

public class DfuFlasherSandbox {
    public static void main(String[] args) {
        System.out.println("detectStLink " + detectStLink(StatusConsumer.VOID));
        System.out.println("detectPcan " + detectPcan(StatusConsumer.VOID));
    }
}
