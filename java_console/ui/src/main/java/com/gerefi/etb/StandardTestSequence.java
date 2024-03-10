package com.gerefi.etb;

import com.gerefi.core.Sensor;
import com.gerefi.core.SensorCentral;
import com.gerefi.ui.UIContext;
import org.jetbrains.annotations.NotNull;

import static com.gerefi.Timeouts.SECOND;
import static com.gerefi.ui.etb.EtbTestSequence.PAST_DEPTH;

public class StandardTestSequence {
    public final static ClosedLoopControlQualityMetric metric = createMetric();

    @NotNull
    protected static ClosedLoopControlQualityMetric createMetric() {
        return new ClosedLoopControlQualityMetric(
                SensorCentral.getInstance().getValueSource(Sensor.PPS),
                SensorCentral.getInstance().getValueSource(Sensor.TPS),
                Sensor.ETB_CONTROL_QUALITY,
                PAST_DEPTH
        );
    }

    public static TestSequenceStep addSequence(UIContext uiContext, TestSequenceStep first_step, Runnable onEachStep, TestSequenceStep.Condition condition) {
        TestSequenceStep secondStep = new TestSequenceStep(SECOND, EtbTarget.Condition.YES) {
            @Override
            protected void doJob() {
                metric.reset();
            }
        };
        return first_step.addNext(secondStep)
                .addNext(uiContext, 10 * SECOND, 4 /*position*/, onEachStep, condition)
                .addNext(uiContext, 5 * SECOND, 6, /*position*/onEachStep, condition)
                .addNext(uiContext, 5 * SECOND, 8, /*position*/onEachStep, condition)
                .addNext(uiContext, 5 * SECOND, 6, /*position*/onEachStep, condition)
                .addNext(uiContext, 5 * SECOND, 4, /*position*/onEachStep, condition)
                .addNext(uiContext, 5 * SECOND, 2, /*position*/onEachStep, condition)
                .addNext(uiContext, 5 * SECOND, 0, /*position*/onEachStep, condition)
                .addNext(uiContext, 5 * SECOND, 10, /*position*/onEachStep, condition)
                .addNext(uiContext, 3 * SECOND, 0, /*position*/onEachStep, condition)
                .addNext(uiContext, 1 * SECOND, 6, /*position*/onEachStep, condition)
                .addNext(uiContext, 1 * SECOND, 8, /*position*/onEachStep, condition)
                .addNext(uiContext, 1 * SECOND, 6, /*position*/onEachStep, condition)
                .addNext(uiContext, 1 * SECOND, 4, /*position*/onEachStep, condition)
                .addNext(uiContext, 1 * SECOND, 2, /*position*/onEachStep, condition)
                .addNext(uiContext, 1 * SECOND, 0, /*position*/onEachStep, condition)
                .addNext(uiContext, 1 * SECOND, 10, /*position*/onEachStep, condition)
                .addNext(uiContext, 3 * SECOND, 7, /*position*/onEachStep, condition)
                .addNext(uiContext, 3 * SECOND, 6, /*position*/onEachStep, condition)
                .addNext(uiContext, 3 * SECOND, 5, /*position*/onEachStep, condition)
                .addNext(uiContext, 3 * SECOND, 4, /*position*/onEachStep, condition)
                .addNext(uiContext, 3 * SECOND, 3, /*position*/onEachStep, condition)
                .addNext(uiContext, 3 * SECOND, 2, /*position*/onEachStep, condition)
                .addNext(uiContext, 3 * SECOND, 1, /*position*/onEachStep, condition)
                .addNext(uiContext, 3 * SECOND, 0, /*position*/onEachStep, condition)
                .addNext(uiContext, 10 * SECOND, 6, /*position*/onEachStep, condition)
                .addNext(uiContext, 10 * SECOND, 30, /*position*/onEachStep, condition)
                .addNext(uiContext, 10 * SECOND, 50, /*position*/onEachStep, condition)
                .addNext(uiContext, 10 * SECOND, 70, /*position*/onEachStep, condition)
                .addNext(uiContext, 10 * SECOND, 95, /*position*/onEachStep, condition)
                .addNext(uiContext, 10 * SECOND, 50, /*position*/onEachStep, condition)
                .addNext(uiContext, 10 * SECOND, 70, /*position*/onEachStep, condition)
                .addNext(uiContext, 10 * SECOND, 4, /*position*/onEachStep, condition)
                .addNext(uiContext, 10 * SECOND, 0, /*position*/onEachStep, condition)
                ;
    }
}
