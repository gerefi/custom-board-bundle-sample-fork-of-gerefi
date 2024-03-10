package com.gerefi.ui.etb;

import com.gerefi.config.generated.Fields;
import com.gerefi.core.Sensor;
import com.gerefi.ui.UIContext;
import com.gerefi.ui.config.BitConfigField;
import com.gerefi.ui.config.ConfigUiField;
import com.gerefi.ui.config.EnumConfigField;
import com.gerefi.core.preferences.storage.Node;
import com.gerefi.ui.util.UiUtils;
import com.gerefi.ui.widgets.AnyCommand;
import com.gerefi.ui.widgets.DetachedSensor;
import org.jetbrains.annotations.NotNull;
import org.putgemin.VerticalFlowLayout;

import javax.swing.*;

import static com.gerefi.config.generated.Fields.CMD_ETB_DUTY;

/**
 * Panel for ETB bench testing & research.
 */
public class EtbCommandsPanel {
    private final JPanel content = new JPanel(new VerticalFlowLayout());
    private final UIContext uiContext;

    public EtbCommandsPanel(UIContext uiContext) {
        this.uiContext = uiContext;
        content.add(new DirectDrivePanel(uiContext).getContent());

        JPanel testParameters = new JPanel(new VerticalFlowLayout());
        testParameters.setBorder(BorderFactory.createTitledBorder("Try PID settings"));
        EtbTestSequence etbTestSequence = new EtbTestSequence(uiContext);
        testParameters.add(etbTestSequence.getButton());
        testParameters.add(UiUtils.wrap(etbTestSequence.getCancelButton()));
        testParameters.add(etbTestSequence.getResult());
        testParameters.add(new JLabel("To change setting use following commands:"));
        testParameters.add(new JLabel("set etb_p X"));
        testParameters.add(new JLabel("set etb_i X"));
        testParameters.add(new JLabel("set etb_d X"));
        testParameters.add(new JLabel("set etb_o X"));
        testParameters.add(new JLabel("For example:"));
        testParameters.add(new JLabel("set etb_p 1.1"));

        testParameters.add(new BitConfigField(uiContext, Fields.PAUSEETBCONTROL, "Pause").getContent());
        testParameters.add(new ConfigUiField(uiContext, Fields.ETB_PFACTOR, "pFactor").getContent());
        testParameters.add(new ConfigUiField(uiContext, Fields.ETB_IFACTOR, "iFactor").getContent());
        testParameters.add(new ConfigUiField(uiContext, Fields.ETB_DFACTOR, "dFactor").getContent());

        content.setBorder(BorderFactory.createTitledBorder("Commands"));

        content.add(testParameters);

        content.add(AnyCommand.createArea(uiContext, new Node(), CMD_ETB_DUTY + " " + "10", false, false).getContent());

        JPanel mockPpsPanel = new JPanel(new VerticalFlowLayout());
        mockPpsPanel.setBorder(BorderFactory.createTitledBorder("Mock PPS"));
        mockPpsPanel.add(DetachedSensor.createMockVoltageSlider(uiContext.getCommandQueue(), Sensor.PPS));


        content.add(mockPpsPanel);

        // todo: restore this functionality
        // content.add(LiveDocPanel.createPanel("ETB", ElectronicThrottleMeta.CONTENT));

        content.add(new EnumConfigField(uiContext, Fields.DEBUGMODE, "Debug Mode").getContent());

        content.add(createMagicSpotsPanel());
        content.add(UiUtils.wrap(new EtbMonteCarloSequence(uiContext).getButton()));
        content.add(UiUtils.wrap(new EtbReturnToNeutral(uiContext).getContent()));
    }

    @NotNull
    private JPanel createMagicSpotsPanel() {
        JPanel spotsPane = new JPanel(new VerticalFlowLayout());
        spotsPane.setBorder(BorderFactory.createTitledBorder("Magic Spots"));
        MagicSpotsFinder magicSpotsFinder = new MagicSpotsFinder(uiContext);
        spotsPane.add(UiUtils.wrap(magicSpotsFinder.getButton()));
        spotsPane.add(magicSpotsFinder.getPoints());
        return spotsPane;
    }

    public JComponent getContent() {
        return new JScrollPane(content, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
    }
}
