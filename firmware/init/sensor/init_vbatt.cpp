#include "pch.h"

#include "init.h"
#include "adc_subscription.h"
#include "functional_sensor.h"
#include "linear_func.h"

static LinearFunc vbattFunc;
static FunctionalSensor vbattSensor(SensorType::BatteryVoltage, /* timeout = */ MS2NT(100));

void initVbatt() {
	vbattFunc.configure(0, 0, 1, engineConfiguration->vbattDividerCoeff, 0, 50);
	vbattSensor.setFunction(vbattFunc);

	if (!isAdcChannelValid(engineConfiguration->vbattAdcChannel)) {
		return;
	}

	// adcVoltsPerVolt is set to 1.0 because vbatt doesn't go thru the analog input divider
	AdcSubscription::SubscribeSensor(vbattSensor, engineConfiguration->vbattAdcChannel, /* filter HZ = */ 20, /* adcVoltsPerVolt = */ 1.0f);

	vbattSensor.Register();
}

void deinitVbatt() {
	AdcSubscription::UnsubscribeSensor(vbattSensor, engineConfiguration->vbattAdcChannel);
}
