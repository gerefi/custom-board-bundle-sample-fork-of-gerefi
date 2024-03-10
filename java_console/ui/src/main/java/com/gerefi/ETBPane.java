package com.gerefi;

import com.gerefi.core.Sensor;
import com.gerefi.ui.GaugesGridElement;
import com.gerefi.ui.UIContext;
import com.gerefi.ui.etb.EtbCommandsPanel;

import javax.swing.*;
import java.awt.*;

/**
 * Controls related to Electronic Throttle Body
 *
 * Andrey Belomutskiy, (c) 2013-2020
 */
public class ETBPane {
    private final JPanel content = new JPanel(new BorderLayout());

    public ETBPane(UIContext uiContext) {
        JPanel centerPanel = new JPanel(new GridLayout(3, 1));
        centerPanel.add(GaugesGridElement.create(uiContext, Sensor.PPS));
        centerPanel.add(GaugesGridElement.create(uiContext, Sensor.ETB_CONTROL_QUALITY));
        centerPanel.add(GaugesGridElement.create(uiContext, Sensor.TPS));

        content.add(new EtbCommandsPanel(uiContext).getContent(), BorderLayout.WEST);
        content.add(centerPanel, BorderLayout.CENTER);
    }

    public JPanel getContent() {
        return content;
    }

}
