package com.gerefi.etb;

import com.gerefi.config.generated.Fields;
import com.gerefi.io.CommandQueue;
import com.gerefi.ui.UIContext;

public class EtbTarget extends TestSequenceStep {
    private final UIContext uiContext;
    /**
     * 0-100 percent open
     */
    private final double position;
    private final Runnable onEachStep;

    public EtbTarget(UIContext uiContext, long duration, double position, Runnable onEachStep, Condition condition) {
        super(duration, condition);
        this.uiContext = uiContext;
        this.position = position;
        this.onEachStep = onEachStep;
    }

    protected void doJob() {
        uiContext.getCommandQueue().write("set " + Fields.MOCK_PPS_POSITION_COMMAND + " " + position);
        if (onEachStep != null)
            onEachStep.run();
    }

    @Override
    public String toString() {
        return "EtbTarget{" +
                "nextStepDelay=" + nextStepDelay +
                ", position=" + position +
                '}';
    }
}
