package com.gerefi.ui.etb;

import com.gerefi.core.MessagesCentral;
import com.gerefi.core.Sensor;
import com.gerefi.core.SensorCentral;
import com.gerefi.ui.UIContext;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import static com.gerefi.Timeouts.SECOND;
import static com.gerefi.config.generated.Fields.CMD_ETB_DUTY;

/**
 * Andrey Belomutskiy, (c) 2013-2020
 */
public class EtbReturnToNeutral {
    private static final int ZERO_POSITION = 0;
    private static final int NEUTRAL_POSITION = 7;
    private static final int ACCEPTABLE_ERROR = 1;
    private static final int CYCLES_COUNT = 10;
    private static final String ZERO_DUTY_CYCLE_COMMAND = CMD_ETB_DUTY + " " + 0;
    private final UIContext uiContext;

    private JButton button = new JButton("ETB Spring Test");

    private final static float SHUT_OPEN = 70;
    private final static float SHUT_CLOSED = -70;

    public EtbReturnToNeutral(UIContext uiContext) {
        this.uiContext = uiContext;
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Runnable runnable = new Runnable() {
                    @Override
                    public void run() {

                        try {
                            testSequence();
                        } catch (InterruptedException e1) {
                            throw new IllegalStateException(e1);
                        }


                    }
                };
                new Thread(runnable).start();
            }
        });
    }

    private void testSequence() throws InterruptedException {

        uiContext.getCommandQueue().write(ZERO_DUTY_CYCLE_COMMAND);
        // longer pause in the beginning just in case
        Thread.sleep(2 * SECOND);
        assertPosition("First neutral position expected.", NEUTRAL_POSITION);

        int errorCount = 0;

        for (int i = 1; i <= CYCLES_COUNT; i++) {
            uiContext.getCommandQueue().write(ZERO_DUTY_CYCLE_COMMAND);
            Thread.sleep(SECOND);

            boolean isError = assertPosition(i + ": Neutral position expected.", NEUTRAL_POSITION);
            if (isError)
                errorCount++;

            uiContext.getCommandQueue().write(CMD_ETB_DUTY + " " + SHUT_OPEN);
            Thread.sleep((long) (0.5 * SECOND));

            uiContext.getCommandQueue().write(CMD_ETB_DUTY + " " + SHUT_CLOSED);
            Thread.sleep(SECOND);
            isError = assertPosition(i + ": Should be shot closed", 0);
            if (isError)
                errorCount++;
        }

        uiContext.getCommandQueue().write(ZERO_DUTY_CYCLE_COMMAND);
//        CommandQueue.getInstance().write(DirectDrivePanel.CANCEL_DIRECT_DRIVE_COMMAND);
        MessagesCentral.getInstance().postMessage(getClass(), "Cycles = " + CYCLES_COUNT + ", errors = " + errorCount);
    }

    /**
     * @return true in case of error: TPS is too far from expected position
     */
    private boolean assertPosition(String msg, float expectedPosition) {
        double tps = SensorCentral.getInstance().getValue(Sensor.TPS);
        MessagesCentral.getInstance().postMessage(getClass(), msg + " TPS=" + tps);
        boolean isError = Math.abs(tps - expectedPosition) > ACCEPTABLE_ERROR;
        if (isError)
            MessagesCentral.getInstance().postMessage(getClass(), msg + " NOT GREAT " + tps + " while expected " + expectedPosition);
        return isError;
    }

    public JComponent getContent() {
        return button;
    }
}
