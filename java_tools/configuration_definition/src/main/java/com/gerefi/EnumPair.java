package com.gerefi;

public class EnumPair {
    private final String shorterForm;
    private final String simpleForm;

    public EnumPair(String shorterForm, String simpleForm) {
        this.shorterForm = shorterForm;
        this.simpleForm = simpleForm;
    }

    public String getShorterForm() {
        return shorterForm;
    }

    public String getSimpleForm() {
        return simpleForm;
    }
}
