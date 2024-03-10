// this section was generated automatically by gerefi tool ConfigDefinition.jar based on hellen_cypress_gen_config.bat integration/gerefi_config.txt Fri May 05 21:37:57 UTC 2023
// by class com.gerefi.output.CHeaderConsumer
// begin
#pragma once
#include "gerefi_types.h"
// start of stft_cell_cfg_s
struct stft_cell_cfg_s {
	/**
	%
	 * offset 0
	 */
	int8_t maxAdd;
	/**
	%
	 * offset 1
	 */
	int8_t maxRemove;
	/**
	 * Time constant for correction while in this cell: this sets responsiveness of the closed loop correction. A value of 5.0 means it will try to make most of the correction within 5 seconds, and a value of 1.0 will try to correct within 1 second.
	sec
	 * offset 2
	 */
	scaled_channel<uint16_t, 10, 1> timeConstant;
};
static_assert(sizeof(stft_cell_cfg_s) == 4);

// start of stft_s
struct stft_s {
	/**
	 * Below this RPM, the idle region is active
	RPM
	 * offset 0
	 */
	scaled_channel<uint8_t, 1, 50> maxIdleRegionRpm;
	/**
	 * Below this engine load, the overrun region is active
	load
	 * offset 1
	 */
	uint8_t maxOverrunLoad;
	/**
	 * Above this engine load, the power region is active
	load
	 * offset 2
	 */
	uint8_t minPowerLoad;
	/**
	 * When close to correct AFR, pause correction. This can improve stability by not changing the adjustment if the error is extremely small, but is not required.
	%
	 * offset 3
	 */
	scaled_channel<uint8_t, 10, 1> deadband;
	/**
	 * Below this temperature, correction is disabled.
	C
	 * offset 4
	 */
	int8_t minClt;
	/**
	 * Below this AFR, correction is paused
	afr
	 * offset 5
	 */
	scaled_channel<uint8_t, 10, 1> minAfr;
	/**
	 * Above this AFR, correction is paused
	afr
	 * offset 6
	 */
	scaled_channel<uint8_t, 10, 1> maxAfr;
	/**
	 * Delay after starting the engine before beginning closed loop correction.
	seconds
	 * offset 7
	 */
	uint8_t startupDelay;
	/**
	 * offset 8
	 */
	stft_cell_cfg_s cellCfgs[STFT_CELL_COUNT];
};
static_assert(sizeof(stft_s) == 24);

// start of pid_s
struct pid_s {
	/**
	 * offset 0
	 */
	float pFactor;
	/**
	 * offset 4
	 */
	float iFactor;
	/**
	 * offset 8
	 */
	float dFactor;
	/**
	 * Linear addition to PID logic
	 * offset 12
	 */
	int16_t offset;
	/**
	 * PID dTime
	ms
	 * offset 14
	 */
	int16_t periodMs;
	/**
	 * Output Min Duty Cycle
	 * offset 16
	 */
	int16_t minValue;
	/**
	 * Output Max Duty Cycle
	 * offset 18
	 */
	int16_t maxValue;
};
static_assert(sizeof(pid_s) == 20);

// start of cranking_parameters_s
struct cranking_parameters_s {
	/**
	 * Base mass of the per-cylinder fuel injected during cranking. This is then modified by the multipliers for CLT, IAT, TPS ect, to give the final cranking pulse width.
	 * A reasonable starting point is 60mg per liter per cylinder.
	 * ex: 2 liter 4 cyl = 500cc/cyl, so 30mg cranking fuel.
	mg
	 * offset 0
	 */
	float baseFuel;
	/**
	 * This sets the RPM limit below which the ECU will use cranking fuel and ignition logic, typically this is around 350-450rpm. 
	 * set cranking_rpm X
	RPM
	 * offset 4
	 */
	int16_t rpm;
	/**
	 * need 4 byte alignment
	units
	 * offset 6
	 */
	uint8_t alignmentFill_at_6[2];
};
static_assert(sizeof(cranking_parameters_s) == 8);

// start of gppwm_channel
struct gppwm_channel {
	/**
	 * Select a pin to use for PWM or on-off output.
	 * offset 0
	 */
	output_pin_e pin;
	/**
	 * If an error (with a sensor, etc) is detected, this value is used instead of reading from the table.
	 * This should be a safe value for whatever hardware is connected to prevent damage.
	%
	 * offset 2
	 */
	uint8_t dutyIfError;
	/**
	 * need 4 byte alignment
	units
	 * offset 3
	 */
	uint8_t alignmentFill_at_3[1];
	/**
	 * Select a frequency to run PWM at.
	 * Set this to 0hz to enable on-off mode.
	hz
	 * offset 4
	 */
	uint16_t pwmFrequency;
	/**
	 * Hysteresis: in on-off mode, turn the output on when the table value is above this duty.
	%
	 * offset 6
	 */
	uint8_t onAboveDuty;
	/**
	 * Hysteresis: in on-off mode, turn the output off when the table value is below this duty.
	%
	 * offset 7
	 */
	uint8_t offBelowDuty;
	/**
	 * Selects the Y axis to use for the table.
	 * offset 8
	 */
	gppwm_channel_e loadAxis;
	/**
	 * Selects the X axis to use for the table.
	 * offset 9
	 */
	gppwm_channel_e rpmAxis;
	/**
	load
	 * offset 10
	 */
	scaled_channel<int16_t, 10, 1> loadBins[GPPWM_LOAD_COUNT];
	/**
	RPM
	 * offset 26
	 */
	scaled_channel<int16_t, 1, 1> rpmBins[GPPWM_RPM_COUNT];
	/**
	duty
	 * offset 42
	 */
	scaled_channel<uint8_t, 2, 1> table[GPPWM_RPM_COUNT][GPPWM_LOAD_COUNT];
	/**
	 * need 4 byte alignment
	units
	 * offset 106
	 */
	uint8_t alignmentFill_at_106[2];
};
static_assert(sizeof(gppwm_channel) == 108);

// start of air_pressure_sensor_config_s
struct air_pressure_sensor_config_s {
	/**
	 * kPa value at low volts
	kpa
	 * offset 0
	 */
	float lowValue;
	/**
	 * kPa value at high volts
	kpa
	 * offset 4
	 */
	float highValue;
	/**
	 * offset 8
	 */
	air_pressure_sensor_type_e type;
	/**
	 * offset 9
	 */
	adc_channel_e hwChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 10
	 */
	uint8_t alignmentFill_at_10[2];
};
static_assert(sizeof(air_pressure_sensor_config_s) == 12);

/**
 * @brief MAP averaging configuration

*/
// start of MAP_sensor_config_s
struct MAP_sensor_config_s {
	/**
	 * offset 0
	 */
	float samplingAngleBins[MAP_ANGLE_SIZE];
	/**
	 * MAP averaging sampling start crank degree angle
	deg
	 * offset 32
	 */
	float samplingAngle[MAP_ANGLE_SIZE];
	/**
	 * offset 64
	 */
	float samplingWindowBins[MAP_WINDOW_SIZE];
	/**
	 * MAP averaging angle crank degree duration
	deg
	 * offset 96
	 */
	float samplingWindow[MAP_WINDOW_SIZE];
	/**
	 * offset 128
	 */
	air_pressure_sensor_config_s sensor;
};
static_assert(sizeof(MAP_sensor_config_s) == 140);

/**
 * @brief Thermistor known values

*/
// start of thermistor_conf_s
struct thermistor_conf_s {
	/**
	 * these values are in Celcius
	*C
	 * offset 0
	 */
	float tempC_1;
	/**
	*C
	 * offset 4
	 */
	float tempC_2;
	/**
	*C
	 * offset 8
	 */
	float tempC_3;
	/**
	Ohm
	 * offset 12
	 */
	float resistance_1;
	/**
	Ohm
	 * offset 16
	 */
	float resistance_2;
	/**
	Ohm
	 * offset 20
	 */
	float resistance_3;
	/**
	 * Pull-up resistor value on your board
	Ohm
	 * offset 24
	 */
	float bias_resistor;
};
static_assert(sizeof(thermistor_conf_s) == 28);

/**
 * @brief Linear sensor interpolation

*/
// start of linear_sensor_s
struct linear_sensor_s {
	/**
	 * offset 0
	 */
	adc_channel_e hwChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 1
	 */
	uint8_t alignmentFill_at_1[3];
	/**
	volts
	 * offset 4
	 */
	float v1;
	/**
	kPa
	 * offset 8
	 */
	float value1;
	/**
	volts
	 * offset 12
	 */
	float v2;
	/**
	kPa
	 * offset 16
	 */
	float value2;
};
static_assert(sizeof(linear_sensor_s) == 20);

/**
 * @brief Thermistor curve parameters

*/
// start of ThermistorConf
struct ThermistorConf {
	/**
	 * offset 0
	 */
	thermistor_conf_s config;
	/**
	 * offset 28
	 */
	adc_channel_e adcChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 29
	 */
	uint8_t alignmentFill_at_29[3];
};
static_assert(sizeof(ThermistorConf) == 32);

// start of injector_s
struct injector_s {
	/**
	 * This is your injector flow at the fuel pressure used in the vehicle. cc/min, cubic centimetre per minute
	 * By the way, g/s = 0.125997881 * (lb/hr)
	 * g/s = 0.125997881 * (cc/min)/10.5
	 * g/s = 0.0119997981 * cc/min
	cm3/min
	 * offset 0
	 */
	float flow;
	/**
	volts
	 * offset 4
	 */
	float battLagCorrBins[VBAT_INJECTOR_CURVE_SIZE];
	/**
	 * ms delay between injector open and close dead times
	ms
	 * offset 36
	 */
	float battLagCorr[VBAT_INJECTOR_CURVE_SIZE];
};
static_assert(sizeof(injector_s) == 68);

/**
 * @brief Trigger wheel(s) configuration

*/
// start of trigger_config_s
struct trigger_config_s {
	/**
	 * https://github.com/gerefi/gerefi/wiki/All-Supported-Triggers
	 * set trigger_type X
	 * offset 0
	 */
	trigger_type_e type;
	/**
	number
	 * offset 4
	 */
	int customTotalToothCount;
	/**
	number
	 * offset 8
	 */
	int customSkippedToothCount;
};
static_assert(sizeof(trigger_config_s) == 12);

// start of afr_sensor_s
struct afr_sensor_s {
	/**
	 * offset 0
	 */
	adc_channel_e hwChannel;
	/**
	 * offset 1
	 */
	adc_channel_e hwChannel2;
	/**
	 * need 4 byte alignment
	units
	 * offset 2
	 */
	uint8_t alignmentFill_at_2[2];
	/**
	volts
	 * offset 4
	 */
	float v1;
	/**
	AFR
	 * offset 8
	 */
	float value1;
	/**
	volts
	 * offset 12
	 */
	float v2;
	/**
	AFR
	 * offset 16
	 */
	float value2;
};
static_assert(sizeof(afr_sensor_s) == 20);

// start of idle_hardware_s
struct idle_hardware_s {
	/**
	Hz
	 * offset 0
	 */
	int solenoidFrequency;
	/**
	 * offset 4
	 */
	output_pin_e solenoidPin;
	/**
	 * offset 6
	 */
	Gpio stepperDirectionPin;
	/**
	 * offset 8
	 */
	Gpio stepperStepPin;
	/**
	 * offset 10
	 */
	pin_output_mode_e solenoidPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 11
	 */
	uint8_t alignmentFill_at_11[1];
};
static_assert(sizeof(idle_hardware_s) == 12);

// start of dc_io
struct dc_io {
	/**
	 * offset 0
	 */
	Gpio directionPin1;
	/**
	 * offset 2
	 */
	Gpio directionPin2;
	/**
	 * Acts as EN pin in two-wire mode
	 * offset 4
	 */
	Gpio controlPin;
	/**
	 * offset 6
	 */
	Gpio disablePin;
};
static_assert(sizeof(dc_io) == 8);

// start of vr_threshold_s
struct vr_threshold_s {
	/**
	rpm
	 * offset 0
	 */
	scaled_channel<uint8_t, 1, 50> rpmBins[6];
	/**
	volts
	 * offset 6
	 */
	scaled_channel<uint8_t, 100, 1> values[6];
	/**
	 * offset 12
	 */
	Gpio pin;
	/**
	 * need 4 byte alignment
	units
	 * offset 14
	 */
	uint8_t alignmentFill_at_14[2];
};
static_assert(sizeof(vr_threshold_s) == 16);

// start of engine_configuration_s
struct engine_configuration_s {
	/**
	 * http://gerefi.com/wiki/index.php?title=Manual:Engine_Type
	 * set engine_type X
	 * offset 0
	 */
	engine_type_e engineType;
	/**
	 * Disable sensor sniffer above this rpm
	RPM
	 * offset 4
	 */
	uint16_t sensorSnifferRpmThreshold;
	/**
	 * A secondary Rev limit engaged by the driver to help launch the vehicle faster
	rpm
	 * offset 6
	 */
	uint16_t launchRpm;
	/**
	 * set rpm_hard_limit X
	rpm
	 * offset 8
	 */
	uint16_t rpmHardLimit;
	/**
	 * Engine sniffer would be disabled above this rpm
	 * set engineSnifferRpmThreshold X
	RPM
	 * offset 10
	 */
	uint16_t engineSnifferRpmThreshold;
	/**
	 * Disable multispark above this engine speed.
	rpm
	 * offset 12
	 */
	scaled_channel<uint8_t, 1, 50> multisparkMaxRpm;
	/**
	 * Above this RPM, disable AC. Set to 0 to disable check.
	rpm
	 * offset 13
	 */
	scaled_channel<uint8_t, 1, 50> maxAcRpm;
	/**
	 * Above this TPS, disable AC. Set to 0 to disable check.
	%
	 * offset 14
	 */
	uint8_t maxAcTps;
	/**
	 * Above this CLT, disable AC to prevent overheating the engine. Set to 0 to disable check.
	deg C
	 * offset 15
	 */
	uint8_t maxAcClt;
	/**
	RPM
	 * offset 16
	 */
	uint16_t knockNoiseRpmBins[ENGINE_NOISE_CURVE_SIZE];
	/**
	 * This parameter sets the latest that the last multispark can occur after the main ignition event. For example, if the ignition timing is 30 degrees BTDC, and this parameter is set to 45, no multispark will ever be fired after 15 degrees ATDC.
	deg
	 * offset 48
	 */
	uint8_t multisparkMaxSparkingAngle;
	/**
	 * Configures the maximum number of extra sparks to fire (does not include main spark)
	count
	 * offset 49
	 */
	uint8_t multisparkMaxExtraSparkCount;
	/**
	 * need 4 byte alignment
	units
	 * offset 50
	 */
	uint8_t alignmentFill_at_50[2];
	/**
	 * offset 52
	 */
	injector_s injector;
	/**
	 * Does the vehicle have a turbo or supercharger?
	offset 120 bit 0 */
	bool isForcedInduction : 1 {};
	/**
	 * On some Ford and Toyota vehicles one of the throttle sensors is not linear on the full range, i.e. in the specific range of the positions we effectively have only one sensor.
	offset 120 bit 1 */
	bool useFordRedundantTps : 1 {};
	/**
	offset 120 bit 2 */
	bool enableKline : 1 {};
	/**
	offset 120 bit 3 */
	bool overrideTriggerGaps : 1 {};
	/**
	 * Turn on this fan when AC is on.
	offset 120 bit 4 */
	bool enableFan1WithAc : 1 {};
	/**
	 * Turn on this fan when AC is on.
	offset 120 bit 5 */
	bool enableFan2WithAc : 1 {};
	/**
	 * Inhibit operation of this fan while the engine is not running.
	offset 120 bit 6 */
	bool disableFan1WhenStopped : 1 {};
	/**
	 * Inhibit operation of this fan while the engine is not running.
	offset 120 bit 7 */
	bool disableFan2WhenStopped : 1 {};
	/**
	 * Enable secondary spark outputs that fire after the primary (rotaries, twin plug engines).
	offset 120 bit 8 */
	bool enableTrailingSparks : 1 {};
	/**
	 * TLE7209 uses two-wire mode. TLE9201 and VNH2SP30 do NOT use two wire mode.
	offset 120 bit 9 */
	bool etb_use_two_wires : 1 {};
	/**
	 * Subaru/BMW style where default valve position is somewhere in the middle. First solenoid opens it more while second can close it more than default position.
	offset 120 bit 10 */
	bool isDoubleSolenoidIdle : 1 {};
	/**
	offset 120 bit 11 */
	bool useEeprom : 1 {};
	/**
	 * Switch between Industrial and Cic PID implementation
	offset 120 bit 12 */
	bool useCicPidForIdle : 1 {};
	/**
	offset 120 bit 13 */
	bool useTLE8888_cranking_hack : 1 {};
	/**
	offset 120 bit 14 */
	bool kickStartCranking : 1 {};
	/**
	 * This uses separate ignition timing and VE tables not only for idle conditions, also during the postcranking-to-idle taper transition (See also afterCrankingIACtaperDuration).
	offset 120 bit 15 */
	bool useSeparateIdleTablesForCrankingTaper : 1 {};
	/**
	offset 120 bit 16 */
	bool launchControlEnabled : 1 {};
	/**
	 * "Detect double trigger edges"
	offset 120 bit 17 */
	bool doNotFilterTriggerEdgeNoise : 1 {};
	/**
	offset 120 bit 18 */
	bool antiLagEnabled : 1 {};
	/**
	 * For cranking either use the specified fixed base fuel mass, or use the normal running math (VE table).
	offset 120 bit 19 */
	bool useRunningMathForCranking : 1 {};
	/**
	 * Shall we display real life signal or just the part consumed by trigger decoder.
	 * Applies to both trigger and cam/vvt input.
	 * 
	 * enable logic_level_trigger
	offset 120 bit 20 */
	bool displayLogicLevelsInEngineSniffer : 1 {};
	/**
	offset 120 bit 21 */
	bool useTLE8888_stepper : 1 {};
	/**
	offset 120 bit 22 */
	bool usescriptTableForCanSniffingFiltering : 1 {};
	/**
	 * Print incoming and outgoing first bus CAN messages in gerefi console
	offset 120 bit 23 */
	bool verboseCan : 1 {};
	/**
	 * Experimental setting that will cause a misfire
	 * DO NOT ENABLE.
	offset 120 bit 24 */
	bool artificialTestMisfire : 1 {};
	/**
	 * On some Ford and Toyota vehicles one of the pedal sensors is not linear on the full range, i.e. in the specific range of the positions we effectively have only one sensor.
	offset 120 bit 25 */
	bool useFordRedundantPps : 1 {};
	/**
	offset 120 bit 26 */
	bool unusedBit_40_26 : 1 {};
	/**
	offset 120 bit 27 */
	bool unusedBit_40_27 : 1 {};
	/**
	offset 120 bit 28 */
	bool unusedBit_40_28 : 1 {};
	/**
	offset 120 bit 29 */
	bool unusedBit_40_29 : 1 {};
	/**
	offset 120 bit 30 */
	bool unusedBit_40_30 : 1 {};
	/**
	offset 120 bit 31 */
	bool unusedBit_40_31 : 1 {};
	/**
	 * Closed throttle, 1 volt = 200 units.
	 * See also tps1_1AdcChannel
	 * set tps_min X
	ADC
	 * offset 124
	 */
	int16_t tpsMin;
	/**
	 * Full throttle.
	 * See also tps1_1AdcChannel
	 * set tps_max X
	ADC
	 * offset 126
	 */
	int16_t tpsMax;
	/**
	 * TPS error detection: what throttle % is unrealistically low?
	 * Also used for accelerator pedal error detection if so equiped.
	%
	 * offset 128
	 */
	int16_t tpsErrorDetectionTooLow;
	/**
	 * TPS error detection: what throttle % is unrealistically high?
	 * Also used for accelerator pedal error detection if so equiped.
	%
	 * offset 130
	 */
	int16_t tpsErrorDetectionTooHigh;
	/**
	 * offset 132
	 */
	cranking_parameters_s cranking;
	/**
	 * Dwell duration while cranking
	ms
	 * offset 140
	 */
	float ignitionDwellForCrankingMs;
	/**
	 * Once engine speed passes this value, start reducing ETB angle.
	rpm
	 * offset 144
	 */
	uint16_t etbRevLimitStart;
	/**
	 * This far above 'Soft limiter start', fully close the throttle. At the bottom of the range, throttle control is normal. At the top of the range, the throttle is fully closed.
	rpm
	 * offset 146
	 */
	uint16_t etbRevLimitRange;
	/**
	 * @see isMapAveragingEnabled
	 * offset 148
	 */
	MAP_sensor_config_s map;
	/**
	 * todo: merge with channel settings, use full-scale Thermistor here!
	 * offset 288
	 */
	ThermistorConf clt;
	/**
	 * offset 320
	 */
	ThermistorConf iat;
	/**
	deg
	 * offset 352
	 */
	int launchTimingRetard;
	/**
	 * value '6' for 8MHz hw osc
	 * read hip9011 datasheet for details
	 * todo split into two bit fields
	integer
	 * offset 356
	 */
	int hip9011PrescalerAndSDO;
	/**
	 * We calculate knock band based of cylinderBore
	 *  Use this to override - kHz knock band override
	kHz
	 * offset 360
	 */
	float knockBandCustom;
	/**
	 * Engine displacement in litres
	L
	 * offset 364
	 */
	scaled_channel<uint16_t, 1000, 1> displacement;
	/**
	RPM
	 * offset 366
	 */
	uint16_t triggerSimulatorRpm;
	/**
	 * Number of cylinder the engine has.
	 * offset 368
	 */
	uint32_t cylindersCount;
	/**
	 * offset 372
	 */
	firing_order_e firingOrder;
	/**
	 * need 4 byte alignment
	units
	 * offset 373
	 */
	uint8_t alignmentFill_at_373[3];
	/**
	 * Cylinder diameter in mm.
	mm
	 * offset 376
	 */
	float cylinderBore;
	/**
	 * This setting controls which fuel quantity control algorithm is used.
	 * Alpha-N means drive by TPS commonly only used for NA engines
	 * Speed Density requires MAP sensor and is the default choice for may installs
	 * MAF air charge is a cylinder filling based method that uses a mass air flow sensor.
	 * offset 380
	 */
	engine_load_mode_e fuelAlgorithm;
	/**
	%
	 * offset 381
	 */
	uint8_t ALSMaxTPS;
	/**
	 * offset 382
	 */
	Gpio criticalLedPin;
	/**
	 * This is the injection strategy during engine start. See Fuel/Injection settings for more detail. It is suggested to use "Simultaneous".
	 * offset 384
	 */
	injection_mode_e crankingInjectionMode;
	/**
	 * This is where the fuel injection type is defined: "Simultaneous" means all injectors will fire together at once. "Sequential" fires the injectors on a per cylinder basis, which requires individually wired injectors. "Batched" will fire the injectors in groups. If your injectors are individually wired you will also need to enable "Two wire batch emulation". 
	 * set injection_mode X
	 * See also twoWireBatchInjection
	 * offset 385
	 */
	injection_mode_e injectionMode;
	/**
	 * Minimum RPM to enable boost control. Use this to avoid solenoid noise at idle, and help spool in some cases.
	 * offset 386
	 */
	uint16_t boostControlMinRpm;
	/**
	 * Minimum TPS to enable boost control. Use this to avoid solenoid noise at idle, and help spool in some cases.
	 * offset 388
	 */
	uint8_t boostControlMinTps;
	/**
	 * Minimum MAP to enable boost control. Use this to avoid solenoid noise at idle, and help spool in some cases.
	 * offset 389
	 */
	uint8_t boostControlMinMap;
	/**
	 * need 4 byte alignment
	units
	 * offset 390
	 */
	uint8_t alignmentFill_at_390[2];
	/**
	 * Ignition advance angle used during engine cranking, 5-10 degrees will work as a base setting for most engines.
	 * There is tapering towards running timing advance
	 * set cranking_timing_angle X
	deg
	 * offset 392
	 */
	angle_t crankingTimingAngle;
	/**
	 * Single coil = distributor
	 * Individual coils = one coil per cylinder (COP, coil-near-plug), requires sequential mode
	 * Wasted spark = Fires pairs of cylinders together, either one coil per pair of cylinders or one coil per cylinder
	 * Two distributors = A pair of distributors, found on some BMW, Toyota and other engines
	 * set ignition_mode X
	 * offset 396
	 */
	ignition_mode_e ignitionMode;
	/**
	 * How many consecutive gap rations have to match expected ranges for sync to happen
	count
	 * offset 397
	 */
	int8_t gapTrackingLengthOverride;
	/**
	 * Above this speed, disable closed loop idle control. Set to 0 to disable (allow closed loop idle at any speed).
	kph
	 * offset 398
	 */
	uint8_t maxIdleVss;
	/**
	 * need 4 byte alignment
	units
	 * offset 399
	 */
	uint8_t alignmentFill_at_399[1];
	/**
	 * Expected oil pressure after starting the engine. If oil pressure does not reach this level within 5 seconds of engine start, fuel will be cut. Set to 0 to disable and always allow starting.
	kPa
	 * offset 400
	 */
	uint16_t minOilPressureAfterStart;
	/**
	 * Dynamic uses the timing map to decide the ignition timing, Static timing fixes the timing to the value set below (only use for checking static timing with a timing light).
	 * offset 402
	 */
	timing_mode_e timingMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 403
	 */
	uint8_t alignmentFill_at_403[1];
	/**
	 * This value is the ignition timing used when in 'fixed timing' mode, i.e. constant timing
	 * This mode is useful when adjusting distributor location.
	RPM
	 * offset 404
	 */
	angle_t fixedModeTiming;
	/**
	 * Angle between Top Dead Center (TDC) and the first trigger event.
	 * Positive value in case of synchnization point before TDC and negative in case of synchnization point after TDC
	 * .Knowing this angle allows us to control timing and other angles in reference to TDC.
	 * set global_trigger_offset_angle X
	deg btdc
	 * offset 408
	 */
	angle_t globalTriggerAngleOffset;
	/**
	 * Ratio/coefficient of input voltage dividers on your PCB. For example, use '2' if your board divides 5v into 2.5v. Use '1.66' if your board divides 5v into 3v.
	coef
	 * offset 412
	 */
	float analogInputDividerCoefficient;
	/**
	 * This is the ratio of the resistors for the battery voltage, measure the voltage at the battery and then adjust this number until the gauge matches the reading.
	coef
	 * offset 416
	 */
	float vbattDividerCoeff;
	/**
	 * Cooling fan turn-on temperature threshold, in Celsius
	deg C
	 * offset 420
	 */
	float fanOnTemperature;
	/**
	 * Cooling fan turn-off temperature threshold, in Celsius
	deg C
	 * offset 424
	 */
	float fanOffTemperature;
	/**
	 * Number of revolutions per kilometer for the wheels your vehicle speed sensor is connected to. Use an online calculator to determine this based on your tire size.
	revs/km
	 * offset 428
	 */
	float driveWheelRevPerKm;
	/**
	 * set can_mode X
	 * offset 432
	 */
	can_nbc_e canNbcType;
	/**
	 * need 4 byte alignment
	units
	 * offset 433
	 */
	uint8_t alignmentFill_at_433[3];
	/**
	 * CANbus thread period in ms
	ms
	 * offset 436
	 */
	int canSleepPeriodMs;
	/**
	 * offset 440
	 */
	uint8_t unused440;
	/**
	 * need 4 byte alignment
	units
	 * offset 441
	 */
	uint8_t alignmentFill_at_441[3];
	/**
	index
	 * offset 444
	 */
	int byFirmwareVersion;
	/**
	 * First throttle body, first sensor. See also pedalPositionAdcChannel
	 * offset 448
	 */
	adc_channel_e tps1_1AdcChannel;
	/**
	 * This is the processor input pin that the battery voltage circuit is connected to, if you are unsure of what pin to use, check the schematic that corresponds to your PCB.
	 * offset 449
	 */
	adc_channel_e vbattAdcChannel;
	/**
	 * This is the processor pin that your fuel level sensor in connected to. This is a non standard input so will need to be user defined.
	 * offset 450
	 */
	adc_channel_e fuelLevelSensor;
	/**
	 * Second throttle body position sensor, single channel so far
	 * set_analog_input_pin tps2 X
	 * offset 451
	 */
	adc_channel_e tps2_1AdcChannel;
	/**
	 * 0.1 is a good default value
	x
	 * offset 452
	 */
	float idle_derivativeFilterLoss;
	/**
	 * just a temporary solution
	angle
	 * offset 456
	 */
	int trailingSparkAngle;
	/**
	 * offset 460
	 */
	trigger_config_s trigger;
	/**
	 * Extra air taper amount
	%
	 * offset 472
	 */
	float airByRpmTaper;
	/**
	 * offset 476
	 */
	spi_device_e hip9011SpiDevice;
	/**
	 * Duty cycle to use in case of a sensor failure. This duty cycle should produce the minimum possible amount of boost. This duty is also used in case any of the minimum RPM/TPS/MAP conditions are not met.
	%
	 * offset 477
	 */
	uint8_t boostControlSafeDutyCycle;
	/**
	 * offset 478
	 */
	adc_channel_e mafAdcChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 479
	 */
	uint8_t alignmentFill_at_479[1];
	/**
	coef
	 * offset 480
	 */
	float globalFuelCorrection;
	/**
	volts
	 * offset 484
	 */
	float adcVcc;
	/**
	Deg
	 * offset 488
	 */
	float mapCamDetectionAnglePosition;
	/**
	 * Camshaft input could be used either just for engine phase detection if your trigger shape does not include cam sensor as 'primary' channel, or it could be used for Variable Valve timing on one of the camshafts.
	 * offset 492
	 */
	brain_input_pin_e camInputs[CAM_INPUTS_COUNT];
	/**
	 * offset 500
	 */
	afr_sensor_s afr;
	/**
	 * Electronic throttle pedal position first channel
	 * See throttlePedalPositionSecondAdcChannel for second channel
	 * See also tps1_1AdcChannel
	 * set_analog_input_pin pps X
	 * See throttlePedalUpVoltage and throttlePedalWOTVoltage
	 * offset 520
	 */
	adc_channel_e throttlePedalPositionAdcChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 521
	 */
	uint8_t alignmentFill_at_521[1];
	/**
	 * offset 522
	 */
	Gpio tle6240_cs;
	/**
	 * offset 524
	 */
	pin_output_mode_e tle6240_csPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 525
	 */
	uint8_t alignmentFill_at_525[1];
	/**
	 * Throttle Pedal not pressed switch - used on some older vehicles like early Mazda Miata
	 * offset 526
	 */
	switch_input_pin_e throttlePedalUpPin;
	/**
	 * @see hasBaroSensor
	 * offset 528
	 */
	air_pressure_sensor_config_s baroSensor;
	/**
	 * offset 540
	 */
	idle_hardware_s idle;
	/**
	 * Value between 0 and 100 used in Manual mode
	%
	 * offset 552
	 */
	float manIdlePosition;
	/**
	 * Ignition timing to remove when a knock event occurs.
	%
	 * offset 556
	 */
	scaled_channel<uint8_t, 10, 1> knockRetardAggression;
	/**
	 * After a knock event, reapply timing at this rate.
	deg/s
	 * offset 557
	 */
	scaled_channel<uint8_t, 10, 1> knockRetardReapplyRate;
	/**
	 * Select which cam is used for engine sync. Other cams will be used only for VVT measurement, but not engine sync.
	 * offset 558
	 */
	engineSyncCam_e engineSyncCam;
	/**
	 * Set this so your vehicle speed signal is responsive, but not noisy. Larger value give smoother but slower response.
	 * offset 559
	 */
	uint8_t vssFilterReciprocal;
	/**
	 * Number of turns of your vehicle speed sensor per turn of the wheels. For example if your sensor is on the transmission output, enter your axle/differential ratio. If you are using a hub-mounted sensor, enter a value of 1.0.
	ratio
	 * offset 560
	 */
	scaled_channel<uint16_t, 1000, 1> vssGearRatio;
	/**
	 * Number of pulses output per revolution of the shaft where your VSS is mounted. For example, GM applications of the T56 output 17 pulses per revolution of the transmission output shaft.
	count
	 * offset 562
	 */
	uint8_t vssToothCount;
	/**
	 * Override the Y axis (load) value used for only the Idle VE table.
	 * Advanced users only: If you aren't sure you need this, you probably don't need this.
	 * offset 563
	 */
	ve_override_e idleVeOverrideMode;
	/**
	 * offset 564
	 */
	Gpio l9779_cs;
	/**
	 * offset 566
	 */
	output_pin_e injectionPins[MAX_CYLINDER_COUNT];
	/**
	 * offset 590
	 */
	output_pin_e ignitionPins[MAX_CYLINDER_COUNT];
	/**
	 * offset 614
	 */
	pin_output_mode_e injectionPinMode;
	/**
	 * offset 615
	 */
	pin_output_mode_e ignitionPinMode;
	/**
	 * offset 616
	 */
	output_pin_e fuelPumpPin;
	/**
	 * offset 618
	 */
	pin_output_mode_e fuelPumpPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 619
	 */
	uint8_t alignmentFill_at_619[1];
	/**
	 * Check engine light, also malfunction indicator light. Always blinks once on boot.
	 * offset 620
	 */
	output_pin_e malfunctionIndicatorPin;
	/**
	 * offset 622
	 */
	pin_output_mode_e malfunctionIndicatorPinMode;
	/**
	 * offset 623
	 */
	pin_output_mode_e fanPinMode;
	/**
	 * offset 624
	 */
	output_pin_e fanPin;
	/**
	 * Some cars have a switch to indicate that clutch pedal is all the way down
	 * offset 626
	 */
	switch_input_pin_e clutchDownPin;
	/**
	 * offset 628
	 */
	output_pin_e alternatorControlPin;
	/**
	 * offset 630
	 */
	pin_output_mode_e alternatorControlPinMode;
	/**
	 * offset 631
	 */
	pin_input_mode_e clutchDownPinMode;
	/**
	 * offset 632
	 */
	Gpio digitalPotentiometerChipSelect[DIGIPOT_COUNT];
	/**
	 * offset 640
	 */
	pin_output_mode_e electronicThrottlePin1Mode;
	/**
	 * offset 641
	 */
	spi_device_e max31855spiDevice;
	/**
	 * offset 642
	 */
	Gpio debugTriggerSync;
	/**
	 * Digital Potentiometer is used by stock ECU stimulation code
	 * offset 644
	 */
	spi_device_e digitalPotentiometerSpiDevice;
	/**
	 * need 4 byte alignment
	units
	 * offset 645
	 */
	uint8_t alignmentFill_at_645[1];
	/**
	 * offset 646
	 */
	Gpio mc33972_cs;
	/**
	 * offset 648
	 */
	pin_output_mode_e mc33972_csPinMode;
	/**
	 * Useful in Research&Development phase
	 * offset 649
	 */
	adc_channel_e auxFastSensor1_adcChannel;
	/**
	 * First throttle body, second sensor.
	 * offset 650
	 */
	adc_channel_e tps1_2AdcChannel;
	/**
	 * Second throttle body, second sensor.
	 * offset 651
	 */
	adc_channel_e tps2_2AdcChannel;
	/**
	 * Electronic throttle pedal position input
	 * Second channel
	 * See also tps1_1AdcChannel
	 * See throttlePedalSecondaryUpVoltage and throttlePedalSecondaryWOTVoltage
	 * offset 652
	 */
	adc_channel_e throttlePedalPositionSecondAdcChannel;
	/**
	%
	 * offset 653
	 */
	uint8_t fuelLevelValues[FUEL_LEVEL_TABLE_COUNT];
	/**
	 * AFR, WBO, EGO - whatever you like to call it
	 * offset 661
	 */
	ego_sensor_e afr_type;
	/**
	 * need 4 byte alignment
	units
	 * offset 662
	 */
	uint8_t alignmentFill_at_662[2];
	/**
	 * 0.1 is a good default value
	x
	 * offset 664
	 */
	float idle_antiwindupFreq;
	/**
	 * offset 668
	 */
	brain_input_pin_e triggerInputPins[TRIGGER_INPUT_PIN_COUNT];
	/**
	 * Minimum allowed time for the boost phase. If the boost target current is reached before this time elapses, it is assumed that the injector has failed short circuit.
	us
	 * offset 672
	 */
	uint16_t mc33_t_min_boost;
	/**
	 * offset 674
	 */
	pin_output_mode_e hip9011CsPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 675
	 */
	uint8_t alignmentFill_at_675[1];
	/**
	 * offset 676
	 */
	output_pin_e tachOutputPin;
	/**
	 * offset 678
	 */
	pin_output_mode_e tachOutputPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 679
	 */
	uint8_t alignmentFill_at_679[1];
	/**
	 * offset 680
	 */
	output_pin_e mainRelayPin;
	/**
	 * offset 682
	 */
	Gpio sdCardCsPin;
	/**
	 * set_can_tx_pin X
	 * offset 684
	 */
	Gpio canTxPin;
	/**
	 * set_can_rx_pin X
	 * offset 686
	 */
	Gpio canRxPin;
	/**
	 * offset 688
	 */
	pin_input_mode_e throttlePedalUpPinMode;
	/**
	 * Additional idle % while A/C is active
	%
	 * offset 689
	 */
	uint8_t acIdleExtraOffset;
	/**
	 * Ratio between the wheels and your transmission output.
	ratio
	 * offset 690
	 */
	scaled_channel<uint16_t, 100, 1> finalGearRatio;
	/**
	 * offset 692
	 */
	brain_input_pin_e tcuInputSpeedSensorPin;
	/**
	 * offset 694
	 */
	uint8_t tcuInputSpeedSensorTeeth;
	/**
	 * need 4 byte alignment
	units
	 * offset 695
	 */
	uint8_t alignmentFill_at_695[1];
	/**
	 * Voltage when the wastegate is closed.
	 * You probably don't have one of these!
	mv
	 * offset 696
	 */
	uint16_t wastegatePositionMin;
	/**
	 * Voltage when the wastegate is fully open.
	 * You probably don't have one of these!
	 * 1 volt = 1000 units
	mv
	 * offset 698
	 */
	uint16_t wastegatePositionMax;
	/**
	 * Voltage when the idle valve is closed.
	 * You probably don't have one of these!
	mv
	 * offset 700
	 */
	uint16_t idlePositionMin;
	/**
	 * Voltage when the idle valve is open.
	 * You probably don't have one of these!
	 * 1 volt = 1000 units
	mv
	 * offset 702
	 */
	uint16_t idlePositionMax;
	/**
	 * Secondary TTL channel baud rate
	BPs
	 * offset 704
	 */
	uint32_t tunerStudioSerialSpeed;
	/**
	 * Just for reference really, not taken into account by any logic at this point
	CR
	 * offset 708
	 */
	float compressionRatio;
	/**
	 * Each gerefi piece can provide synthetic trigger signal for external ECU. Sometimes these wires are routed back into trigger inputs of the same gerefi board.
	 * See also directSelfStimulation which is different.
	 * offset 712
	 */
	Gpio triggerSimulatorPins[TRIGGER_SIMULATOR_PIN_COUNT];
	/**
	g/s
	 * offset 716
	 */
	scaled_channel<uint16_t, 1000, 1> fordInjectorSmallPulseSlope;
	/**
	 * offset 718
	 */
	pin_output_mode_e triggerSimulatorPinModes[TRIGGER_SIMULATOR_PIN_COUNT];
	/**
	 * offset 720
	 */
	adc_channel_e maf2AdcChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 721
	 */
	uint8_t alignmentFill_at_721[1];
	/**
	 * On-off O2 sensor heater control. 'ON' if engine is running, 'OFF' if stopped or cranking.
	 * offset 722
	 */
	output_pin_e o2heaterPin;
	/**
	 * offset 724
	 */
	pin_output_mode_e o2heaterPinModeTodO;
	/**
	 * need 4 byte alignment
	units
	 * offset 725
	 */
	uint8_t alignmentFill_at_725[3];
	/**
	offset 728 bit 0 */
	bool is_enabled_spi_1 : 1 {};
	/**
	offset 728 bit 1 */
	bool is_enabled_spi_2 : 1 {};
	/**
	offset 728 bit 2 */
	bool is_enabled_spi_3 : 1 {};
	/**
	 * enable sd/disable sd
	offset 728 bit 3 */
	bool isSdCardEnabled : 1 {};
	/**
	 * Use 11 bit (standard) or 29 bit (extended) IDs for gerefi verbose CAN format.
	offset 728 bit 4 */
	bool gerefiVerbose29b : 1 {};
	/**
	offset 728 bit 5 */
	bool unusedIsEngineControlEnabled : 1 {};
	/**
	offset 728 bit 6 */
	bool isHip9011Enabled : 1 {};
	/**
	offset 728 bit 7 */
	bool isVerboseAlternator : 1 {};
	/**
	offset 728 bit 8 */
	bool verboseQuad : 1 {};
	/**
	 * This setting should only be used if you have a stepper motor idle valve and a stepper motor driver installed.
	offset 728 bit 9 */
	bool useStepperIdle : 1 {};
	/**
	offset 728 bit 10 */
	bool enabledStep1Limiter : 1 {};
	/**
	offset 728 bit 11 */
	bool useTpicAdvancedMode : 1 {};
	/**
	offset 728 bit 12 */
	bool unused760b12 : 1 {};
	/**
	offset 728 bit 13 */
	bool verboseTLE8888 : 1 {};
	/**
	 * CAN broadcast using custom gerefi protocol
	 * enable can_broadcast/disable can_broadcast
	offset 728 bit 14 */
	bool enableVerboseCanTx : 1 {};
	/**
	offset 728 bit 15 */
	bool etb1configured : 1 {};
	/**
	offset 728 bit 16 */
	bool etb2configured : 1 {};
	/**
	 * Useful for individual intakes
	offset 728 bit 17 */
	bool measureMapOnlyInOneCylinder : 1 {};
	/**
	offset 728 bit 18 */
	bool stepperForceParkingEveryRestart : 1 {};
	/**
	 * If enabled, try to fire the engine before a full engine cycle has been completed using RPM estimated from the last 90 degrees of engine rotation. As soon as the trigger syncs plus 90 degrees rotation, fuel and ignition events will occur. If disabled, worst case may require up to 4 full crank rotations before any events are scheduled.
	offset 728 bit 19 */
	bool isFasterEngineSpinUpEnabled : 1 {};
	/**
	 * This setting disables fuel injection while the engine is in overrun, this is useful as a fuel saving measure and to prevent back firing.
	offset 728 bit 20 */
	bool coastingFuelCutEnabled : 1 {};
	/**
	 * Override the IAC position during overrun conditions to help reduce engine breaking, this can be helpful for large engines in light weight cars or engines that have trouble returning to idle.
	offset 728 bit 21 */
	bool useIacTableForCoasting : 1 {};
	/**
	offset 728 bit 22 */
	bool useNoiselessTriggerDecoder : 1 {};
	/**
	offset 728 bit 23 */
	bool useIdleTimingPidControl : 1 {};
	/**
	 * Allows disabling the ETB when the engine is stopped. You may not like the power draw or PWM noise from the motor, so this lets you turn it off until it's necessary.
	offset 728 bit 24 */
	bool disableEtbWhenEngineStopped : 1 {};
	/**
	offset 728 bit 25 */
	bool is_enabled_spi_4 : 1 {};
	/**
	 * Disable the electronic throttle motor and DC idle motor for testing.
	 * This mode is for testing ETB/DC idle position sensors, etc without actually driving the throttle.
	offset 728 bit 26 */
	bool pauseEtbControl : 1 {};
	/**
	offset 728 bit 27 */
	bool alignEngineSnifferAtTDC : 1 {};
	/**
	offset 728 bit 28 */
	bool verboseKLine : 1 {};
	/**
	offset 728 bit 29 */
	bool idleIncrementalPidCic : 1 {};
	/**
	 * AEM X-Series or gerefi Wideband
	offset 728 bit 30 */
	bool enableAemXSeries : 1 {};
	/**
	offset 728 bit 31 */
	bool unusedBit_223_31 : 1 {};
	/**
	 * offset 732
	 */
	brain_input_pin_e logicAnalyzerPins[LOGIC_ANALYZER_CHANNEL_COUNT];
	/**
	 * offset 740
	 */
	pin_output_mode_e mainRelayPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 741
	 */
	uint8_t alignmentFill_at_741[1];
	/**
	 * offset 742
	 */
	Gpio hip9011CsPin;
	/**
	 * offset 744
	 */
	Gpio hip9011IntHoldPin;
	/**
	 * offset 746
	 */
	pin_output_mode_e hip9011IntHoldPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 747
	 */
	uint8_t alignmentFill_at_747[1];
	/**
	 * offset 748
	 */
	uint32_t verboseCanBaseAddress;
	/**
	 * Boost Voltage
	v
	 * offset 752
	 */
	uint8_t mc33_hvolt;
	/**
	 * Minimum MAP before closed loop boost is enabled. Use to prevent misbehavior upon entering boost.
	kPa
	 * offset 753
	 */
	uint8_t minimumBoostClosedLoopMap;
	/**
	 * Optional Radiator Fan used with A/C
	 * offset 754
	 */
	output_pin_e acFanPin;
	/**
	 * offset 756
	 */
	pin_output_mode_e acFanPinMode;
	/**
	 * offset 757
	 */
	spi_device_e l9779spiDevice;
	/**
	volts
	 * offset 758
	 */
	scaled_channel<uint8_t, 10, 1> dwellVoltageCorrVoltBins[DWELL_CURVE_SIZE];
	/**
	 * offset 766
	 */
	imu_type_e imuType;
	/**
	multiplier
	 * offset 767
	 */
	scaled_channel<uint8_t, 50, 1> dwellVoltageCorrValues[DWELL_CURVE_SIZE];
	/**
	 * need 4 byte alignment
	units
	 * offset 775
	 */
	uint8_t alignmentFill_at_775[1];
	/**
	kg
	 * offset 776
	 */
	uint16_t vehicleWeight;
	/**
	 * How far above idle speed do we consider idling, i.e. coasting detection threshold.
	 * For example, if target = 800, this param = 200, then anything below 1000 RPM is considered idle.
	RPM
	 * offset 778
	 */
	int16_t idlePidRpmUpperLimit;
	/**
	 * Apply nonlinearity correction below a pulse of this duration. Pulses longer than this duration will receive no adjustment.
	ms
	 * offset 780
	 */
	scaled_channel<uint16_t, 1000, 1> applyNonlinearBelowPulse;
	/**
	 * offset 782
	 */
	Gpio lps25BaroSensorScl;
	/**
	 * offset 784
	 */
	Gpio lps25BaroSensorSda;
	/**
	 * offset 786
	 */
	brain_input_pin_e vehicleSpeedSensorInputPin;
	/**
	 * Some vehicles have a switch to indicate that clutch pedal is all the way up
	 * offset 788
	 */
	switch_input_pin_e clutchUpPin;
	/**
	 * offset 790
	 */
	InjectorNonlinearMode injectorNonlinearMode;
	/**
	 * offset 791
	 */
	pin_input_mode_e clutchUpPinMode;
	/**
	 * offset 792
	 */
	Gpio max31855_cs[EGT_CHANNEL_COUNT];
	/**
	 * Continental/GM flex fuel sensor, 50-150hz type
	 * offset 808
	 */
	brain_input_pin_e flexSensorPin;
	/**
	 * offset 810
	 */
	Gpio test557pin;
	/**
	 * offset 812
	 */
	pin_output_mode_e stepperDirectionPinMode;
	/**
	 * offset 813
	 */
	spi_device_e mc33972spiDevice;
	/**
	 * Stoichiometric ratio for your secondary fuel. This value is used when the Flex Fuel sensor indicates E100, typically 9.0
	:1
	 * offset 814
	 */
	scaled_channel<uint8_t, 10, 1> stoichRatioSecondary;
	/**
	 * Maximum allowed ETB position. Some throttles go past fully open, so this allows you to limit it to fully open.
	%
	 * offset 815
	 */
	uint8_t etbMaximumPosition;
	/**
	 * Rate the ECU will log to the SD card, in hz (log lines per second).
	hz
	 * offset 816
	 */
	uint16_t sdCardLogFrequency;
	/**
	 * offset 818
	 */
	adc_channel_e idlePositionSensor;
	/**
	 * need 4 byte alignment
	units
	 * offset 819
	 */
	uint8_t alignmentFill_at_819[1];
	/**
	 * offset 820
	 */
	Gpio debugMapAveraging;
	/**
	 * offset 822
	 */
	output_pin_e starterRelayDisablePin;
	/**
	 * On some vehicles we can disable starter once engine is already running
	 * offset 824
	 */
	pin_output_mode_e starterRelayDisablePinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 825
	 */
	uint8_t alignmentFill_at_825[1];
	/**
	 * Some Subaru and some Mazda use double-solenoid idle air valve
	 * offset 826
	 */
	output_pin_e secondSolenoidPin;
	/**
	 * See also starterControlPin
	 * offset 828
	 */
	switch_input_pin_e startStopButtonPin;
	/**
	 * need 4 byte alignment
	units
	 * offset 830
	 */
	uint8_t alignmentFill_at_830[2];
	/**
	 * This many MAP samples are used to estimate the current MAP. This many samples are considered, and the minimum taken. Recommended value is 1 for single-throttle engines, and your number of cylinders for individual throttle bodies.
	count
	 * offset 832
	 */
	int mapMinBufferLength;
	/**
	 * Below this throttle position, the engine is considered idling. If you have an electronic throttle, this checks accelerator pedal position instead of throttle position, and should be set to 1-2%.
	%
	 * offset 836
	 */
	int16_t idlePidDeactivationTpsThreshold;
	/**
	%
	 * offset 838
	 */
	int16_t stepperParkingExtraSteps;
	/**
	ADC
	 * offset 840
	 */
	uint16_t tps1SecondaryMin;
	/**
	ADC
	 * offset 842
	 */
	uint16_t tps1SecondaryMax;
	/**
	rpm
	 * offset 844
	 */
	int16_t antiLagRpmTreshold;
	/**
	 * Maximum time to crank starter when start/stop button is pressed
	Seconds
	 * offset 846
	 */
	uint16_t startCrankingDuration;
	/**
	 * This pin is used for debugging - snap a logic analyzer on it and see if it's ever high
	 * offset 848
	 */
	Gpio triggerErrorPin;
	/**
	 * offset 850
	 */
	pin_output_mode_e triggerErrorPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 851
	 */
	uint8_t alignmentFill_at_851[1];
	/**
	 * offset 852
	 */
	output_pin_e acRelayPin;
	/**
	 * offset 854
	 */
	pin_output_mode_e acRelayPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 855
	 */
	uint8_t alignmentFill_at_855[1];
	/**
	 * offset 856
	 */
	script_setting_t scriptSetting[SCRIPT_SETTING_COUNT];
	/**
	 * offset 888
	 */
	Gpio spi1mosiPin;
	/**
	 * offset 890
	 */
	Gpio spi1misoPin;
	/**
	 * offset 892
	 */
	Gpio spi1sckPin;
	/**
	 * offset 894
	 */
	Gpio spi2mosiPin;
	/**
	 * offset 896
	 */
	Gpio spi2misoPin;
	/**
	 * offset 898
	 */
	Gpio spi2sckPin;
	/**
	 * offset 900
	 */
	Gpio spi3mosiPin;
	/**
	 * offset 902
	 */
	Gpio spi3misoPin;
	/**
	 * offset 904
	 */
	Gpio spi3sckPin;
	/**
	 * Saab Combustion Detection Module knock signal input pin
	 * also known as Saab Ion Sensing Module
	 * offset 906
	 */
	Gpio cdmInputPin;
	/**
	 * offset 908
	 */
	uart_device_e consoleUartDevice;
	/**
	 * gerefi console Sensor Sniffer mode
	 * offset 909
	 */
	sensor_chart_e sensorChartMode;
	/**
	 * offset 910
	 */
	maf_sensor_type_e mafSensorType;
	/**
	 * need 4 byte alignment
	units
	 * offset 911
	 */
	uint8_t alignmentFill_at_911[1];
	/**
	offset 912 bit 0 */
	bool clutchUpPinInverted : 1 {};
	/**
	offset 912 bit 1 */
	bool clutchDownPinInverted : 1 {};
	/**
	 * If enabled we use two H-bridges to drive stepper idle air valve
	offset 912 bit 2 */
	bool useHbridgesToDriveIdleStepper : 1 {};
	/**
	offset 912 bit 3 */
	bool multisparkEnable : 1 {};
	/**
	offset 912 bit 4 */
	bool enableLaunchRetard : 1 {};
	/**
	offset 912 bit 5 */
	bool unfinishedenableLaunchBoost : 1 {};
	/**
	offset 912 bit 6 */
	bool unfinishedlaunchDisableBySpeed : 1 {};
	/**
	 * Read VSS from OEM CAN bus according to selected CAN vehicle configuration.
	offset 912 bit 7 */
	bool enableCanVss : 1 {};
	/**
	offset 912 bit 8 */
	bool enableInnovateLC2 : 1 {};
	/**
	offset 912 bit 9 */
	bool showHumanReadableWarning : 1 {};
	/**
	 * If enabled, adjust at a constant rate instead of a rate proportional to the current lambda error. This mode may be easier to tune, and more tolerant of sensor noise. Use of this mode is required if you have a narrowband O2 sensor.
	offset 912 bit 10 */
	bool stftIgnoreErrorMagnitude : 1 {};
	/**
	offset 912 bit 11 */
	bool vvtBooleanForVerySpecialCases : 1 {};
	/**
	offset 912 bit 12 */
	bool enableSoftwareKnock : 1 {};
	/**
	 * Verbose info in console below engineSnifferRpmThreshold
	 * enable vvt_details
	offset 912 bit 13 */
	bool verboseVVTDecoding : 1 {};
	/**
	 * get invertCamVVTSignal
	offset 912 bit 14 */
	bool invertCamVVTSignal : 1 {};
	/**
	 * This property is useful if using gerefi as TCM or BCM only
	 * enable consumeObdSensors
	offset 912 bit 15 */
	bool consumeObdSensors : 1 {};
	/**
	offset 912 bit 16 */
	bool knockBankCyl1 : 1 {};
	/**
	offset 912 bit 17 */
	bool knockBankCyl2 : 1 {};
	/**
	offset 912 bit 18 */
	bool knockBankCyl3 : 1 {};
	/**
	offset 912 bit 19 */
	bool knockBankCyl4 : 1 {};
	/**
	offset 912 bit 20 */
	bool knockBankCyl5 : 1 {};
	/**
	offset 912 bit 21 */
	bool knockBankCyl6 : 1 {};
	/**
	offset 912 bit 22 */
	bool knockBankCyl7 : 1 {};
	/**
	offset 912 bit 23 */
	bool knockBankCyl8 : 1 {};
	/**
	offset 912 bit 24 */
	bool knockBankCyl9 : 1 {};
	/**
	offset 912 bit 25 */
	bool knockBankCyl10 : 1 {};
	/**
	offset 912 bit 26 */
	bool knockBankCyl11 : 1 {};
	/**
	offset 912 bit 27 */
	bool knockBankCyl12 : 1 {};
	/**
	offset 912 bit 28 */
	bool tcuEnabled : 1 {};
	/**
	offset 912 bit 29 */
	bool canBroadcastUseChannelTwo : 1 {};
	/**
	 * If enabled we use four Push-Pull outputs to directly drive stepper idle air valve coilss
	offset 912 bit 30 */
	bool useRawOutputToDriveIdleStepper : 1 {};
	/**
	 * Print incoming and outgoing second bus CAN messages in gerefi console
	offset 912 bit 31 */
	bool verboseCan2 : 1 {};
	/**
	 * offset 916
	 */
	dc_io etbIo[ETB_COUNT];
	/**
	 * Wastegate control Solenoid
	 * offset 932
	 */
	output_pin_e boostControlPin;
	/**
	 * offset 934
	 */
	pin_output_mode_e boostControlPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 935
	 */
	uint8_t alignmentFill_at_935[1];
	/**
	 * offset 936
	 */
	switch_input_pin_e ALSActivatePin;
	/**
	 * offset 938
	 */
	switch_input_pin_e launchActivatePin;
	/**
	 * offset 940
	 */
	pid_s boostPid;
	/**
	 * offset 960
	 */
	boostType_e boostType;
	/**
	 * need 4 byte alignment
	units
	 * offset 961
	 */
	uint8_t alignmentFill_at_961[3];
	/**
	Hz
	 * offset 964
	 */
	int boostPwmFrequency;
	/**
	 * offset 968
	 */
	launchActivationMode_e launchActivationMode;
	/**
	 * offset 969
	 */
	antiLagActivationMode_e antiLagActivationMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 970
	 */
	uint8_t alignmentFill_at_970[2];
	/**
	 * Disabled above this speed
	Kph
	 * offset 972
	 */
	int launchSpeedThreshold;
	/**
	 * Range from Launch RPM for Timing Retard to activate
	RPM
	 * offset 976
	 */
	int launchTimingRpmRange;
	/**
	 * Extra Fuel Added
	%
	 * offset 980
	 */
	int launchFuelAdded;
	/**
	 * Duty Cycle for the Boost Solenoid
	%
	 * offset 984
	 */
	int launchBoostDuty;
	/**
	 * Range from Launch RPM to activate Hard Cut
	RPM
	 * offset 988
	 */
	int hardCutRpmRange;
	/**
	 * offset 992
	 */
	float turbochargerFilter;
	/**
	 * offset 996
	 */
	int launchTpsThreshold;
	/**
	 * offset 1000
	 */
	float launchActivateDelay;
	/**
	 * offset 1004
	 */
	stft_s stft;
	/**
	 * offset 1028
	 */
	dc_io stepperDcIo[DC_PER_STEPPER];
	/**
	 * For example, BMW, GM or Chevrolet
	 * REQUIRED for gerefi Online
	 * offset 1044
	 */
	vehicle_info_t engineMake;
	/**
	 * For example, LS1 or NB2
	 * REQUIRED for gerefi Online
	 * offset 1076
	 */
	vehicle_info_t engineCode;
	/**
	 * For example, Hunchback or Orange Miata
	 * Vehicle name has to be unique between your vehicles.
	 * REQUIRED for gerefi Online
	 * offset 1108
	 */
	vehicle_info_t vehicleName;
	/**
	 * offset 1140
	 */
	output_pin_e tcu_solenoid[TCU_SOLENOID_COUNT];
	/**
	 * offset 1152
	 */
	dc_function_e etbFunctions[ETB_COUNT];
	/**
	 * offset 1154
	 */
	spi_device_e drv8860spiDevice;
	/**
	 * need 4 byte alignment
	units
	 * offset 1155
	 */
	uint8_t alignmentFill_at_1155[1];
	/**
	 * offset 1156
	 */
	Gpio drv8860_cs;
	/**
	 * offset 1158
	 */
	pin_output_mode_e drv8860_csPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1159
	 */
	uint8_t alignmentFill_at_1159[1];
	/**
	 * offset 1160
	 */
	Gpio drv8860_miso;
	/**
	volt
	 * offset 1162
	 */
	scaled_channel<uint16_t, 1000, 1> fuelLevelBins[FUEL_LEVEL_TABLE_COUNT];
	/**
	 * offset 1178
	 */
	output_pin_e luaOutputPins[LUA_PWM_COUNT];
	/**
	 * need 4 byte alignment
	units
	 * offset 1194
	 */
	uint8_t alignmentFill_at_1194[2];
	/**
	 * Angle between cam sensor and VVT zero position
	 * set vvt_offset X
	value
	 * offset 1196
	 */
	float vvtOffsets[CAM_INPUTS_COUNT];
	/**
	 * offset 1212
	 */
	vr_threshold_s vrThreshold[VR_THRESHOLD_COUNT];
	/**
	 * offset 1244
	 */
	gppwm_note_t gpPwmNote[GPPWM_CHANNELS];
	/**
	ADC
	 * offset 1308
	 */
	uint16_t tps2SecondaryMin;
	/**
	ADC
	 * offset 1310
	 */
	uint16_t tps2SecondaryMax;
	/**
	 * Select which bus the wideband controller is attached to.
	offset 1312 bit 0 */
	bool widebandOnSecondBus : 1 {};
	/**
	 * Enables lambda sensor closed loop feedback for fuelling.
	offset 1312 bit 1 */
	bool fuelClosedLoopCorrectionEnabled : 1 {};
	/**
	 * Print details into gerefi console
	 * enable verbose_idle
	offset 1312 bit 2 */
	bool isVerboseIAC : 1 {};
	/**
	offset 1312 bit 3 */
	bool boardUseTachPullUp : 1 {};
	/**
	offset 1312 bit 4 */
	bool boardUseTempPullUp : 1 {};
	/**
	offset 1312 bit 5 */
	bool yesUnderstandLocking : 1 {};
	/**
	 * Sometimes we have a performance issue while printing error
	offset 1312 bit 6 */
	bool silentTriggerError : 1 {};
	/**
	offset 1312 bit 7 */
	bool useLinearCltSensor : 1 {};
	/**
	 * enable can_read/disable can_read
	offset 1312 bit 8 */
	bool canReadEnabled : 1 {};
	/**
	 * enable can_write/disable can_write
	offset 1312 bit 9 */
	bool canWriteEnabled : 1 {};
	/**
	offset 1312 bit 10 */
	bool useLinearIatSensor : 1 {};
	/**
	offset 1312 bit 11 */
	bool boardUse2stepPullDown : 1 {};
	/**
	 * Treat milliseconds value as duty cycle value, i.e. 0.5ms would become 50%
	offset 1312 bit 12 */
	bool tachPulseDurationAsDutyCycle : 1 {};
	/**
	 * This enables smart alternator control and activates the extra alternator settings.
	offset 1312 bit 13 */
	bool isAlternatorControlEnabled : 1 {};
	/**
	 * https://wiki.gerefi.com/Trigger-Configuration-Guide
	 * This setting flips the signal from the primary engine speed sensor.
	offset 1312 bit 14 */
	bool invertPrimaryTriggerSignal : 1 {};
	/**
	 * https://wiki.gerefi.com/Trigger-Configuration-Guide
	 * This setting flips the signal from the secondary engine speed sensor.
	offset 1312 bit 15 */
	bool invertSecondaryTriggerSignal : 1 {};
	/**
	offset 1312 bit 16 */
	bool cutFuelOnHardLimit : 1 {};
	/**
	 * Be careful enabling this: some engines are known to self-disassemble their valvetrain with a spark cut. Fuel cut is much safer.
	offset 1312 bit 17 */
	bool cutSparkOnHardLimit : 1 {};
	/**
	offset 1312 bit 18 */
	bool launchFuelCutEnable : 1 {};
	/**
	 * This is the Cut Mode normally used
	offset 1312 bit 19 */
	bool launchSparkCutEnable : 1 {};
	/**
	offset 1312 bit 20 */
	bool boardUseCrankPullUp : 1 {};
	/**
	offset 1312 bit 21 */
	bool boardUseCamPullDown : 1 {};
	/**
	offset 1312 bit 22 */
	bool boardUseCamVrPullUp : 1 {};
	/**
	offset 1312 bit 23 */
	bool boardUseD2PullDown : 1 {};
	/**
	offset 1312 bit 24 */
	bool boardUseD3PullDown : 1 {};
	/**
	offset 1312 bit 25 */
	bool boardUseD4PullDown : 1 {};
	/**
	offset 1312 bit 26 */
	bool boardUseD5PullDown : 1 {};
	/**
	offset 1312 bit 27 */
	bool verboseIsoTp : 1 {};
	/**
	offset 1312 bit 28 */
	bool engineSnifferFocusOnInputs : 1 {};
	/**
	offset 1312 bit 29 */
	bool launchActivateInverted : 1 {};
	/**
	offset 1312 bit 30 */
	bool twoStroke : 1 {};
	/**
	 * Where is your primary skipped wheel located?
	offset 1312 bit 31 */
	bool skippedWheelOnCam : 1 {};
	/**
	 * offset 1316
	 */
	adc_channel_e hipOutputChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 1317
	 */
	uint8_t alignmentFill_at_1317[1];
	/**
	 * A/C button input
	 * offset 1318
	 */
	switch_input_pin_e acSwitch;
	/**
	 * offset 1320
	 */
	adc_channel_e vRefAdcChannel;
	/**
	 * Expected neutral position
	%
	 * offset 1321
	 */
	uint8_t etbNeutralPosition;
	/**
	 * See also idleRpmPid
	 * offset 1322
	 */
	idle_mode_e idleMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1323
	 */
	uint8_t alignmentFill_at_1323[1];
	/**
	offset 1324 bit 0 */
	bool isInjectionEnabled : 1 {};
	/**
	offset 1324 bit 1 */
	bool isIgnitionEnabled : 1 {};
	/**
	 * When enabled if TPS is held above 95% no fuel is injected while cranking to clear excess fuel from the cylinders.
	offset 1324 bit 2 */
	bool isCylinderCleanupEnabled : 1 {};
	/**
	 * Should we use tables to vary tau/beta based on CLT/MAP, or just with fixed values?
	offset 1324 bit 3 */
	bool complexWallModel : 1 {};
	/**
	 * RPM is measured based on last 720 degrees while instant RPM is measured based on the last 90 degrees of crank revolution
	offset 1324 bit 4 */
	bool alwaysInstantRpm : 1 {};
	/**
	offset 1324 bit 5 */
	bool isMapAveragingEnabled : 1 {};
	/**
	 * If enabled, use separate temperature multiplier table for cranking idle position.
	 * If disabled, use normal running multiplier table applied to the cranking base position.
	offset 1324 bit 6 */
	bool overrideCrankingIacSetting : 1 {};
	/**
	 * This activates a separate ignition timing table for idle conditions, this can help idle stability by using ignition retard and advance either side of the desired idle speed. Extra retard at low idle speeds will prevent stalling and extra advance at high idle speeds can help reduce engine power and slow the idle speed.
	offset 1324 bit 7 */
	bool useSeparateAdvanceForIdle : 1 {};
	/**
	offset 1324 bit 8 */
	bool isWaveAnalyzerEnabled : 1 {};
	/**
	 * This activates a separate fuel table for Idle, this allows fine tuning of the idle fuelling.
	offset 1324 bit 9 */
	bool useSeparateVeForIdle : 1 {};
	/**
	 * Verbose info in console below engineSnifferRpmThreshold
	 * enable trigger_details
	offset 1324 bit 10 */
	bool verboseTriggerSynchDetails : 1 {};
	/**
	 * Usually if we have no trigger events that means engine is stopped
	 * Unless we are troubleshooting and spinning the engine by hand - this case a longer
	 * delay is needed
	offset 1324 bit 11 */
	bool isManualSpinningMode : 1 {};
	/**
	 * This is needed if your coils are individually wired and you wish to use batch injection.
	 * enable two_wire_batch_injection
	offset 1324 bit 12 */
	bool twoWireBatchInjection : 1 {};
	/**
	offset 1324 bit 13 */
	bool hondaK : 1 {};
	/**
	 * This is needed if your coils are individually wired (COP) and you wish to use batch ignition (Wasted Spark).
	offset 1324 bit 14 */
	bool twoWireBatchIgnition : 1 {};
	/**
	offset 1324 bit 15 */
	bool useFixedBaroCorrFromMap : 1 {};
	/**
	 * In Constant mode, timing is automatically tapered to running as RPM increases.
	 * In Table mode, the "Cranking ignition advance" table is used directly.
	offset 1324 bit 16 */
	bool useSeparateAdvanceForCranking : 1 {};
	/**
	 * This enables the various ignition corrections during cranking (IAT, CLT, FSIO and PID idle).
	 * You probably don't need this.
	offset 1324 bit 17 */
	bool useAdvanceCorrectionsForCranking : 1 {};
	/**
	 * Enable a second cranking table to use for E100 flex fuel, interpolating between the two based on flex fuel sensor.
	offset 1324 bit 18 */
	bool flexCranking : 1 {};
	/**
	 * This flag allows to use a special 'PID Multiplier' table (0.0-1.0) to compensate for nonlinear nature of IAC-RPM controller
	offset 1324 bit 19 */
	bool useIacPidMultTable : 1 {};
	/**
	offset 1324 bit 20 */
	bool isBoostControlEnabled : 1 {};
	/**
	 * Interpolates the Ignition Retard from 0 to 100% within the RPM Range
	offset 1324 bit 21 */
	bool launchSmoothRetard : 1 {};
	/**
	 * Some engines are OK running semi-random sequential while other engine require phase synchronization
	offset 1324 bit 22 */
	bool isPhaseSyncRequiredForIgnition : 1 {};
	/**
	 * If enabled, use a curve for RPM limit (based on coolant temperature) instead of a constant value.
	offset 1324 bit 23 */
	bool useCltBasedRpmLimit : 1 {};
	/**
	 * If enabled, don't wait for engine start to heat O2 sensors. WARNING: this will reduce the life of your sensor, as condensation in the exhaust from a cold start can crack the sensing element.
	offset 1324 bit 24 */
	bool forceO2Heating : 1 {};
	/**
	 * If increased VVT duty cycle increases the indicated VVT angle, set this to 'advance'. If it decreases, set this to 'retard'. Most intake cams use 'advance', and most exhaust cams use 'retard'.
	offset 1324 bit 25 */
	bool invertVvtControlIntake : 1 {};
	/**
	 * If increased VVT duty cycle increases the indicated VVT angle, set this to 'advance'. If it decreases, set this to 'retard'. Most intake cams use 'advance', and most exhaust cams use 'retard'.
	offset 1324 bit 26 */
	bool invertVvtControlExhaust : 1 {};
	/**
	offset 1324 bit 27 */
	bool useBiQuadOnAuxSpeedSensors : 1 {};
	/**
	 * 'Trigger' mode will write a high speed log of trigger events (warning: uses lots of space!). 'Normal' mode will write a standard MLG of sensors, engine function, etc. similar to the one captured in TunerStudio.
	offset 1324 bit 28 */
	bool sdTriggerLog : 1 {};
	/**
	offset 1324 bit 29 */
	bool ALSActivateInverted : 1 {};
	/**
	offset 1324 bit 30 */
	bool stepper_dc_use_two_wires : 1 {};
	/**
	offset 1324 bit 31 */
	bool tempBooleanForVerySpecialLogic : 1 {};
	/**
	count
	 * offset 1328
	 */
	uint32_t engineChartSize;
	/**
	mult
	 * offset 1332
	 */
	float turboSpeedSensorMultiplier;
	/**
	 * offset 1336
	 */
	Gpio camInputsDebug[CAM_INPUTS_COUNT];
	/**
	 * Extra idle target speed when A/C is enabled. Some cars need the extra speed to keep the AC efficient while idling.
	RPM
	 * offset 1344
	 */
	int16_t acIdleRpmBump;
	/**
	 * set warningPeriod X
	seconds
	 * offset 1346
	 */
	int16_t warningPeriod;
	/**
	angle
	 * offset 1348
	 */
	float knockDetectionWindowStart;
	/**
	angle
	 * offset 1352
	 */
	float knockDetectionWindowEnd;
	/**
	ms
	 * offset 1356
	 */
	float idleStepperReactionTime;
	/**
	count
	 * offset 1360
	 */
	int idleStepperTotalSteps;
	/**
	 * TODO: finish this #413
	sec
	 * offset 1364
	 */
	float noAccelAfterHardLimitPeriodSecs;
	/**
	 * At what trigger index should some MAP-related math be executed? This is a performance trick to reduce load on synchronization trigger callback.
	index
	 * offset 1368
	 */
	int mapAveragingSchedulingAtIndex;
	/**
	 * Duration in ms or duty cycle depending on selected mode
	 * offset 1372
	 */
	float tachPulseDuractionMs;
	/**
	 * Length of time the deposited wall fuel takes to dissipate after the start of acceleration.
	Seconds
	 * offset 1376
	 */
	float wwaeTau;
	/**
	 * offset 1380
	 */
	pid_s alternatorControl;
	/**
	 * offset 1400
	 */
	pid_s etb;
	/**
	 * offset 1420
	 */
	Gpio triggerInputDebugPins[TRIGGER_INPUT_PIN_COUNT];
	/**
	 * RPM range above upper limit for extra air taper,"RPM", 1, 0, 0, 1500, 0
	 * offset 1424
	 */
	int16_t airTaperRpmRange;
	/**
	 * offset 1426
	 */
	brain_input_pin_e turboSpeedSensorInputPin;
	/**
	 * Closed throttle#2. todo: extract these two fields into a structure
	 * See also tps2_1AdcChannel
	 * set tps2_min X
	ADC
	 * offset 1428
	 */
	int16_t tps2Min;
	/**
	 * Full throttle#2. tpsMax value as 10 bit ADC value. Not Voltage!
	 * See also tps1_1AdcChannel
	 * set tps2_max X
	ADC
	 * offset 1430
	 */
	int16_t tps2Max;
	/**
	 * See also startStopButtonPin
	 * offset 1432
	 */
	output_pin_e starterControlPin;
	/**
	 * offset 1434
	 */
	pin_input_mode_e startStopButtonMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1435
	 */
	uint8_t alignmentFill_at_1435[1];
	/**
	 * offset 1436
	 */
	Gpio mc33816_flag0;
	/**
	Pulse
	 * offset 1438
	 */
	uint8_t tachPulsePerRev;
	/**
	 * need 4 byte alignment
	units
	 * offset 1439
	 */
	uint8_t alignmentFill_at_1439[1];
	/**
	 * kPa value which is too low to be true
	kPa
	 * offset 1440
	 */
	float mapErrorDetectionTooLow;
	/**
	 * kPa value which is too high to be true
	kPa
	 * offset 1444
	 */
	float mapErrorDetectionTooHigh;
	/**
	 * How long to wait for the spark to fire before recharging the coil for another spark.
	ms
	 * offset 1448
	 */
	scaled_channel<uint16_t, 1000, 1> multisparkSparkDuration;
	/**
	 * This sets the dwell time for subsequent sparks. The main spark's dwell is set by the dwell table.
	ms
	 * offset 1450
	 */
	scaled_channel<uint16_t, 1000, 1> multisparkDwell;
	/**
	 * See cltIdleRpmBins
	 * offset 1452
	 */
	pid_s idleRpmPid;
	/**
	 * 0 = No fuel settling on port walls 1 = All the fuel settling on port walls setting this to 0 disables the wall wetting enrichment.
	Fraction
	 * offset 1472
	 */
	float wwaeBeta;
	/**
	 * blue LED on many gerefi boards.
	 * Blue Communication LED which is expected to blink at 50% duty cycle during normal board operation.
	 * If USB communication cable is connected Blue LED starts to blink faster.
	 * offset 1476
	 */
	Gpio communicationLedPin;
	/**
	 * Green LED on many gerefi boards.
	 * Off if engine is stopped, blinks if engine is cranking, solid if engine is running.
	 * offset 1478
	 */
	Gpio runningLedPin;
	/**
	 * See also EFI_CONSOLE_RX_BRAIN_PIN
	 * offset 1480
	 */
	Gpio binarySerialTxPin;
	/**
	 * offset 1482
	 */
	Gpio binarySerialRxPin;
	/**
	 * offset 1484
	 */
	Gpio auxValves[AUX_DIGITAL_VALVE_COUNT];
	/**
	 * offset 1488
	 */
	switch_input_pin_e tcuUpshiftButtonPin;
	/**
	 * offset 1490
	 */
	switch_input_pin_e tcuDownshiftButtonPin;
	/**
	voltage
	 * offset 1492
	 */
	float throttlePedalUpVoltage;
	/**
	 * Pedal in the floor
	voltage
	 * offset 1496
	 */
	float throttlePedalWOTVoltage;
	/**
	 * on IGN voltage detection turn fuel pump on to build fuel pressure
	seconds
	 * offset 1500
	 */
	int16_t startUpFuelPumpDuration;
	/**
	 * If the RPM closer to target than this value, disable closed loop idle correction to prevent oscillation
	RPM
	 * offset 1502
	 */
	int16_t idlePidRpmDeadZone;
	/**
	 * This is the target battery voltage the alternator PID control will attempt to maintain
	Volts
	 * offset 1504
	 */
	float targetVBatt;
	/**
	 * Turns off alternator output above specified TPS, enabling this reduced parasitic drag on the engine at full load.
	%
	 * offset 1508
	 */
	float alternatorOffAboveTps;
	/**
	 * This is the duration in cycles that the IAC will take to reach its normal idle position, it can be used to hold the idle higher for a few seconds after cranking to improve startup.
	cycles
	 * offset 1512
	 */
	int16_t afterCrankingIACtaperDuration;
	/**
	 * Extra IAC, in percent between 0 and 100, tapered between zero and idle deactivation TPS value
	percent
	 * offset 1514
	 */
	int16_t iacByTpsTaper;
	/**
	 * Auxiliary sensor serial, not to be confused with secondary calibration serial
	 * set_aux_tx_pin X
	 * offset 1516
	 */
	Gpio auxSerialTxPin;
	/**
	 * offset 1518
	 */
	Gpio warningLedPin;
	/**
	 * Auxiliary sensor serial, not to be confused with secondary calibration serial
	 * set_aux_rx_pin X
	 * offset 1520
	 */
	Gpio auxSerialRxPin;
	/**
	 * offset 1522
	 */
	Gpio LIS302DLCsPin;
	/**
	 * How long to look back for TPS-based acceleration enrichment. Increasing this time will trigger enrichment for longer when a throttle position change occurs.
	sec
	 * offset 1524
	 */
	scaled_channel<uint8_t, 20, 1> tpsAccelLookback;
	/**
	 * Below this speed, disable DFCO. Use this to prevent jerkiness from fuel enable/disable in low gears.
	kph
	 * offset 1525
	 */
	uint8_t coastingFuelCutVssLow;
	/**
	 * Above this speed, allow DFCO. Use this to prevent jerkiness from fuel enable/disable in low gears.
	kph
	 * offset 1526
	 */
	uint8_t coastingFuelCutVssHigh;
	/**
	 * Pause closed loop fueling after deceleration fuel cut occurs. Set this to a little longer than however long is required for normal fueling behavior to resume after fuel cut.
	sec
	 * offset 1527
	 */
	scaled_channel<uint8_t, 10, 1> noFuelTrimAfterDfcoTime;
	/**
	 * Maximum change delta of TPS percentage over the 'length'. Actual TPS change has to be above this value in order for TPS/TPS acceleration to kick in.
	roc
	 * offset 1528
	 */
	float tpsAccelEnrichmentThreshold;
	/**
	 * offset 1532
	 */
	brain_input_pin_e auxSpeedSensorInputPin[2];
	/**
	 * offset 1536
	 */
	uint8_t totalGearsCount;
	/**
	 * Sets what part of injection's is controlled by the injection phase table.
	 * offset 1537
	 */
	InjectionTimingMode injectionTimingMode;
	/**
	 * See http://gerefi.com/s/debugmode
	 * offset 1538
	 */
	debug_mode_e debugMode;
	/**
	 * Additional idle % when fan #1 is active
	%
	 * offset 1539
	 */
	uint8_t fan1ExtraIdle;
	/**
	 * Band rate for primary TTL
	BPs
	 * offset 1540
	 */
	uint32_t uartConsoleSerialSpeed;
	/**
	 * For decel we simply multiply delta of TPS and tFor decel we do not use table?!
	roc
	 * offset 1544
	 */
	float tpsDecelEnleanmentThreshold;
	/**
	 * Magic multiplier, we multiply delta of TPS and get fuel squirt duration
	coeff
	 * offset 1548
	 */
	float tpsDecelEnleanmentMultiplier;
	/**
	BPs
	 * offset 1552
	 */
	uint32_t auxSerialSpeed;
	/**
	voltage
	 * offset 1556
	 */
	float throttlePedalSecondaryUpVoltage;
	/**
	 * Pedal in the floor
	voltage
	 * offset 1560
	 */
	float throttlePedalSecondaryWOTVoltage;
	/**
	 * set can_baudrate
	 * offset 1564
	 */
	can_baudrate_e canBaudRate;
	/**
	 * Override the Y axis (load) value used for the VE table.
	 * Advanced users only: If you aren't sure you need this, you probably don't need this.
	 * offset 1565
	 */
	ve_override_e veOverrideMode;
	/**
	 * offset 1566
	 */
	can_baudrate_e can2BaudRate;
	/**
	 * Override the Y axis (load) value used for the AFR table.
	 * Advanced users only: If you aren't sure you need this, you probably don't need this.
	 * offset 1567
	 */
	load_override_e afrOverrideMode;
	/**
	A
	 * offset 1568
	 */
	scaled_channel<uint8_t, 10, 1> mc33_hpfp_i_peak;
	/**
	A
	 * offset 1569
	 */
	scaled_channel<uint8_t, 10, 1> mc33_hpfp_i_hold;
	/**
	 * How long to deactivate power when hold current is reached before applying power again
	us
	 * offset 1570
	 */
	uint8_t mc33_hpfp_i_hold_off;
	/**
	 * Maximum amount of time the solenoid can be active before assuming a programming error
	ms
	 * offset 1571
	 */
	uint8_t mc33_hpfp_max_hold;
	/**
	 * Enable if DC-motor driver (H-bridge) inverts the signals (eg. RZ7899 on Hellen boards)
	offset 1572 bit 0 */
	bool stepperDcInvertedPins : 1 {};
	/**
	 * Allow OpenBLT on Primary CAN
	offset 1572 bit 1 */
	bool canOpenBLT : 1 {};
	/**
	 * Allow OpenBLT on Secondary CAN
	offset 1572 bit 2 */
	bool can2OpenBLT : 1 {};
	/**
	 * Select whether to configure injector flow in volumetric flow (defualt, cc/min) or mass flow (g/s).
	offset 1572 bit 3 */
	bool injectorFlowAsMassFlow : 1 {};
	/**
	offset 1572 bit 4 */
	bool boardUseCanTerminator : 1 {};
	/**
	offset 1572 bit 5 */
	bool kLineDoHondaSend : 1 {};
	/**
	offset 1572 bit 6 */
	bool unused1129 : 1 {};
	/**
	offset 1572 bit 7 */
	bool unused1130 : 1 {};
	/**
	offset 1572 bit 8 */
	bool unusedBit_523_8 : 1 {};
	/**
	offset 1572 bit 9 */
	bool unusedBit_523_9 : 1 {};
	/**
	offset 1572 bit 10 */
	bool unusedBit_523_10 : 1 {};
	/**
	offset 1572 bit 11 */
	bool unusedBit_523_11 : 1 {};
	/**
	offset 1572 bit 12 */
	bool unusedBit_523_12 : 1 {};
	/**
	offset 1572 bit 13 */
	bool unusedBit_523_13 : 1 {};
	/**
	offset 1572 bit 14 */
	bool unusedBit_523_14 : 1 {};
	/**
	offset 1572 bit 15 */
	bool unusedBit_523_15 : 1 {};
	/**
	offset 1572 bit 16 */
	bool unusedBit_523_16 : 1 {};
	/**
	offset 1572 bit 17 */
	bool unusedBit_523_17 : 1 {};
	/**
	offset 1572 bit 18 */
	bool unusedBit_523_18 : 1 {};
	/**
	offset 1572 bit 19 */
	bool unusedBit_523_19 : 1 {};
	/**
	offset 1572 bit 20 */
	bool unusedBit_523_20 : 1 {};
	/**
	offset 1572 bit 21 */
	bool unusedBit_523_21 : 1 {};
	/**
	offset 1572 bit 22 */
	bool unusedBit_523_22 : 1 {};
	/**
	offset 1572 bit 23 */
	bool unusedBit_523_23 : 1 {};
	/**
	offset 1572 bit 24 */
	bool unusedBit_523_24 : 1 {};
	/**
	offset 1572 bit 25 */
	bool unusedBit_523_25 : 1 {};
	/**
	offset 1572 bit 26 */
	bool unusedBit_523_26 : 1 {};
	/**
	offset 1572 bit 27 */
	bool unusedBit_523_27 : 1 {};
	/**
	offset 1572 bit 28 */
	bool unusedBit_523_28 : 1 {};
	/**
	offset 1572 bit 29 */
	bool unusedBit_523_29 : 1 {};
	/**
	offset 1572 bit 30 */
	bool unusedBit_523_30 : 1 {};
	/**
	offset 1572 bit 31 */
	bool unusedBit_523_31 : 1 {};
	/**
	 * How many test bench pulses do you want
	count
	 * offset 1576
	 */
	uint8_t benchTestCount;
	/**
	 * need 4 byte alignment
	units
	 * offset 1577
	 */
	uint8_t alignmentFill_at_1577[1];
	/**
	 * Length of each of the test pulses
	ms
	 * offset 1578
	 */
	scaled_channel<uint16_t, 10, 1> benchTestOnTime;
	/**
	 * offset 1580
	 */
	pin_input_mode_e launchActivatePinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1581
	 */
	uint8_t alignmentFill_at_1581[1];
	/**
	 * set_can2_tx_pin X
	 * offset 1582
	 */
	Gpio can2TxPin;
	/**
	 * set_can2_rx_pin X
	 * offset 1584
	 */
	Gpio can2RxPin;
	/**
	 * offset 1586
	 */
	pin_output_mode_e starterControlPinMode;
	/**
	 * offset 1587
	 */
	adc_channel_e wastegatePositionSensor;
	/**
	 * Override the Y axis (load) value used for the ignition table.
	 * Advanced users only: If you aren't sure you need this, you probably don't need this.
	 * offset 1588
	 */
	load_override_e ignOverrideMode;
	/**
	 * Select which fuel pressure sensor measures the pressure of the fuel at your injectors.
	 * offset 1589
	 */
	injector_pressure_type_e injectorPressureType;
	/**
	 * offset 1590
	 */
	output_pin_e hpfpValvePin;
	/**
	 * offset 1592
	 */
	pin_output_mode_e hpfpValvePinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1593
	 */
	uint8_t alignmentFill_at_1593[3];
	/**
	 * MAP value above which fuel is cut in case of overboost.
	 * Set to 0 to disable overboost cut.
	kPa (absolute)
	 * offset 1596
	 */
	float boostCutPressure;
	/**
	kg/h
	 * offset 1600
	 */
	scaled_channel<uint8_t, 1, 5> tchargeBins[16];
	/**
	ratio
	 * offset 1616
	 */
	scaled_channel<uint8_t, 100, 1> tchargeValues[16];
	/**
	 * Fixed timing, useful for TDC testing
	deg
	 * offset 1632
	 */
	float fixedTiming;
	/**
	 * MAP voltage for low point
	v
	 * offset 1636
	 */
	float mapLowValueVoltage;
	/**
	 * MAP voltage for low point
	v
	 * offset 1640
	 */
	float mapHighValueVoltage;
	/**
	 * EGO value correction
	value
	 * offset 1644
	 */
	float egoValueShift;
	/**
	 * VVT output
	 * TODO: rename to vvtOutputs
	 * offset 1648
	 */
	output_pin_e vvtPins[CAM_INPUTS_COUNT];
	/**
	 * offset 1656
	 */
	pin_output_mode_e sdCardCsPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1657
	 */
	uint8_t alignmentFill_at_1657[3];
	/**
	 * This is the IAC position during cranking, some engines start better if given more air during cranking to improve cylinder filling.
	percent
	 * offset 1660
	 */
	int crankingIACposition;
	/**
	 * offset 1664
	 */
	float tChargeMinRpmMinTps;
	/**
	 * offset 1668
	 */
	float tChargeMinRpmMaxTps;
	/**
	 * offset 1672
	 */
	float tChargeMaxRpmMinTps;
	/**
	 * offset 1676
	 */
	float tChargeMaxRpmMaxTps;
	/**
	 * offset 1680
	 */
	pwm_freq_t vvtOutputFrequency[CAMS_PER_BANK];
	/**
	Hz
	 * offset 1684
	 */
	int alternatorPwmFrequency;
	/**
	 * set vvt_mode X
	 * offset 1688
	 */
	vvt_mode_e vvtMode[CAMS_PER_BANK];
	/**
	 * Additional idle % when fan #2 is active
	%
	 * offset 1690
	 */
	uint8_t fan2ExtraIdle;
	/**
	 * Delay to allow fuel pressure to build before firing the priming pulse.
	sec
	 * offset 1691
	 */
	scaled_channel<uint8_t, 100, 1> primingDelay;
	/**
	 * offset 1692
	 */
	adc_channel_e auxAnalogInputs[LUA_ANALOG_INPUT_COUNT];
	/**
	 * offset 1700
	 */
	output_pin_e trailingCoilPins[MAX_CYLINDER_COUNT];
	/**
	 * offset 1724
	 */
	tle8888_mode_e tle8888mode;
	/**
	 * offset 1725
	 */
	pin_output_mode_e LIS302DLCsPinMode;
	/**
	 * None = I have a MAP-referenced fuel pressure regulator
	 * Fixed rail pressure = I have an atmosphere-referenced fuel pressure regulator (returnless, typically)
	 * Sensed rail pressure = I have a fuel pressure sensor
	 * offset 1726
	 */
	injector_compensation_mode_e injectorCompensationMode;
	/**
	 * offset 1727
	 */
	pin_output_mode_e fan2PinMode;
	/**
	 * This is the pressure at which your injector flow is known.
	 * For example if your injectors flow 400cc/min at 3.5 bar, enter 350kpa here.
	kPa
	 * offset 1728
	 */
	float fuelReferencePressure;
	/**
	 * Fuel multiplier (enrichment) immediately after engine start
	mult
	 * offset 1732
	 */
	float postCrankingFactor;
	/**
	 * Time over which to taper out after start enrichment
	seconds
	 * offset 1736
	 */
	float postCrankingDurationSec;
	/**
	 * offset 1740
	 */
	ThermistorConf auxTempSensor1;
	/**
	 * offset 1772
	 */
	ThermistorConf auxTempSensor2;
	/**
	Deg
	 * offset 1804
	 */
	int16_t knockSamplingDuration;
	/**
	Hz
	 * offset 1806
	 */
	int16_t etbFreq;
	/**
	 * offset 1808
	 */
	pid_s etbWastegatePid;
	/**
	 * For micro-stepping, make sure that PWM frequency (etbFreq) is high enough
	 * offset 1828
	 */
	stepper_num_micro_steps_e stepperNumMicroSteps;
	/**
	 * Use to limit the current when the stepper motor is idle, not moving (100% = no limit)
	%
	 * offset 1829
	 */
	uint8_t stepperMinDutyCycle;
	/**
	 * Use to limit the max.current through the stepper motor (100% = no limit)
	%
	 * offset 1830
	 */
	uint8_t stepperMaxDutyCycle;
	/**
	 * offset 1831
	 */
	spi_device_e sdCardSpiDevice;
	/**
	 * per-cylinder timing correction
	deg
	 * offset 1832
	 */
	angle_t timing_offset_cylinder[MAX_CYLINDER_COUNT];
	/**
	seconds
	 * offset 1880
	 */
	float idlePidActivationTime;
	/**
	 * offset 1884
	 */
	pin_mode_e spi1SckMode;
	/**
	 * Modes count be used for 3v<>5v integration using pull-ups/pull-downs etc.
	 * offset 1885
	 */
	pin_mode_e spi1MosiMode;
	/**
	 * offset 1886
	 */
	pin_mode_e spi1MisoMode;
	/**
	 * offset 1887
	 */
	pin_mode_e spi2SckMode;
	/**
	 * offset 1888
	 */
	pin_mode_e spi2MosiMode;
	/**
	 * offset 1889
	 */
	pin_mode_e spi2MisoMode;
	/**
	 * offset 1890
	 */
	pin_mode_e spi3SckMode;
	/**
	 * offset 1891
	 */
	pin_mode_e spi3MosiMode;
	/**
	 * offset 1892
	 */
	pin_mode_e spi3MisoMode;
	/**
	 * offset 1893
	 */
	pin_output_mode_e stepperEnablePinMode;
	/**
	 * ResetB
	 * offset 1894
	 */
	Gpio mc33816_rstb;
	/**
	 * offset 1896
	 */
	Gpio mc33816_driven;
	/**
	 * Brake pedal switch
	 * offset 1898
	 */
	switch_input_pin_e brakePedalPin;
	/**
	 * offset 1900
	 */
	pin_input_mode_e brakePedalPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1901
	 */
	uint8_t alignmentFill_at_1901[3];
	/**
	 * VVT output PID
	 * TODO: rename to vvtPid
	 * offset 1904
	 */
	pid_s auxPid[CAMS_PER_BANK];
	/**
	 * offset 1944
	 */
	float injectorCorrectionPolynomial[8];
	/**
	C
	 * offset 1976
	 */
	int8_t primeBins[8];
	/**
	 * offset 1984
	 */
	linear_sensor_s oilPressure;
	/**
	 * offset 2004
	 */
	spi_device_e accelerometerSpiDevice;
	/**
	 * need 4 byte alignment
	units
	 * offset 2005
	 */
	uint8_t alignmentFill_at_2005[1];
	/**
	 * offset 2006
	 */
	output_pin_e fan2Pin;
	/**
	 * Cooling fan turn-on temperature threshold, in Celsius
	deg C
	 * offset 2008
	 */
	uint8_t fan2OnTemperature;
	/**
	 * Cooling fan turn-off temperature threshold, in Celsius
	deg C
	 * offset 2009
	 */
	uint8_t fan2OffTemperature;
	/**
	 * offset 2010
	 */
	Gpio stepperEnablePin;
	/**
	 * offset 2012
	 */
	Gpio tle8888_cs;
	/**
	 * offset 2014
	 */
	pin_output_mode_e tle8888_csPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 2015
	 */
	uint8_t alignmentFill_at_2015[1];
	/**
	 * offset 2016
	 */
	Gpio mc33816_cs;
	/**
	 * need 4 byte alignment
	units
	 * offset 2018
	 */
	uint8_t alignmentFill_at_2018[2];
	/**
	 * offset 2020
	 */
	float auxFrequencyFilter;
	/**
	RPM
	 * offset 2024
	 */
	int16_t vvtControlMinRpm;
	/**
	 * offset 2026
	 */
	sent_input_pin_e sentInputPins[SENT_INPUT_COUNT];
	/**
	 * offset 2028
	 */
	int8_t launchFuelAdderPercent;
	/**
	 * Time required to detect a stuck throttle.
	sec
	 * offset 2029
	 */
	scaled_channel<uint8_t, 50, 1> etbJamTimeout;
	/**
	 * By the way ETB PID runs at 500hz, length in 1/500 of second here.
	 * offset 2030
	 */
	uint16_t etbExpAverageLength;
	/**
	 * offset 2032
	 */
	float etbDutyThreshold;
	/**
	 * This sets the RPM above which fuel cut is active.
	rpm
	 * offset 2036
	 */
	int16_t coastingFuelCutRpmHigh;
	/**
	 * This sets the RPM below which fuel cut is deactivated, this prevents jerking or issues transitioning to idle
	rpm
	 * offset 2038
	 */
	int16_t coastingFuelCutRpmLow;
	/**
	 * Throttle position below which fuel cut is active. With an electronic throttle enabled, this checks against pedal position.
	%
	 * offset 2040
	 */
	int16_t coastingFuelCutTps;
	/**
	 * Fuel cutoff is disabled when the engine is cold.
	C
	 * offset 2042
	 */
	int16_t coastingFuelCutClt;
	/**
	 * Increases PID reaction for RPM<target by adding extra percent to PID-error
	%
	 * offset 2044
	 */
	int16_t pidExtraForLowRpm;
	/**
	 * MAP value above which fuel injection is re-enabled.
	kPa
	 * offset 2046
	 */
	int16_t coastingFuelCutMap;
	/**
	 * offset 2048
	 */
	linear_sensor_s highPressureFuel;
	/**
	 * offset 2068
	 */
	linear_sensor_s lowPressureFuel;
	/**
	C
	 * offset 2088
	 */
	int8_t cltRevLimitRpmBins[CLT_LIMITER_CURVE_SIZE];
	/**
	RPM
	 * offset 2092
	 */
	uint16_t cltRevLimitRpm[CLT_LIMITER_CURVE_SIZE];
	/**
	 * offset 2100
	 */
	gppwm_note_t scriptCurveName[SCRIPT_CURVE_COUNT];
	/**
	 * offset 2196
	 */
	gppwm_note_t scriptTableName[SCRIPT_TABLE_COUNT];
	/**
	 * offset 2260
	 */
	gppwm_note_t scriptSettingName[SCRIPT_SETTING_COUNT];
	/**
	 * Heat transfer coefficient at zero flow.
	 * 0 means the air charge is fully heated to the same temperature as CLT.
	 * 1 means the air charge gains no heat, and enters the cylinder at the temperature measured by IAT.
	 * offset 2388
	 */
	float tChargeAirCoefMin;
	/**
	 * Heat transfer coefficient at high flow, as defined by "max air flow".
	 * 0 means the air charge is fully heated to the same temperature as CLT.
	 * 1 means the air charge gains no heat, and enters the cylinder at the temperature measured by IAT.
	 * offset 2392
	 */
	float tChargeAirCoefMax;
	/**
	 * High flow point for heat transfer estimation.
	 * Set this to perhaps 50-75% of your maximum airflow at wide open throttle.
	kg/h
	 * offset 2396
	 */
	float tChargeAirFlowMax;
	/**
	 * Maximum allowed rate of increase allowed for the estimated charge temperature
	deg/sec
	 * offset 2400
	 */
	float tChargeAirIncrLimit;
	/**
	 * Maximum allowed rate of decrease allowed for the estimated charge temperature
	deg/sec
	 * offset 2404
	 */
	float tChargeAirDecrLimit;
	/**
	 * offset 2408
	 */
	tChargeMode_e tChargeMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 2409
	 */
	uint8_t alignmentFill_at_2409[3];
	/**
	 * offset 2412
	 */
	float hip9011Gain;
	/**
	 * iTerm min value
	 * offset 2416
	 */
	int16_t etb_iTermMin;
	/**
	 * iTerm max value
	 * offset 2418
	 */
	int16_t etb_iTermMax;
	/**
	 * See useIdleTimingPidControl
	 * offset 2420
	 */
	pid_s idleTimingPid;
	/**
	 * By the way ETB PID runs at 500hz, length in 1/500 of second here.
	 * offset 2440
	 */
	int16_t etbRocExpAverageLength;
	/**
	 * A delay in cycles between fuel-enrich. portions
	cycles
	 * offset 2442
	 */
	int16_t tpsAccelFractionPeriod;
	/**
	 * A fraction divisor: 1 or less = entire portion at once, or split into diminishing fractions
	coef
	 * offset 2444
	 */
	float tpsAccelFractionDivisor;
	/**
	 * offset 2448
	 */
	spi_device_e tle8888spiDevice;
	/**
	 * offset 2449
	 */
	spi_device_e mc33816spiDevice;
	/**
	 * iTerm min value
	 * offset 2450
	 */
	int16_t idlerpmpid_iTermMin;
	/**
	 * offset 2452
	 */
	spi_device_e tle6240spiDevice;
	/**
	 * Stoichiometric ratio for your primary fuel. When Flex Fuel is enabled, this value is used when the Flex Fuel sensor indicates E0.
	 * E0 = 14.7
	 * E10 = 14.1
	 * E85 = 9.9
	 * E100 = 9.0
	:1
	 * offset 2453
	 */
	scaled_channel<uint8_t, 10, 1> stoichRatioPrimary;
	/**
	 * iTerm max value
	 * offset 2454
	 */
	int16_t idlerpmpid_iTermMax;
	/**
	 * This sets the range of the idle control on the ETB. At 100% idle position, the value specified here sets the base ETB position.
	%
	 * offset 2456
	 */
	float etbIdleThrottleRange;
	/**
	 * Select which fuel correction bank this cylinder belongs to. Group cylinders that share the same O2 sensor
	 * offset 2460
	 */
	uint8_t cylinderBankSelect[MAX_CYLINDER_COUNT];
	/**
	mg
	 * offset 2472
	 */
	scaled_channel<uint8_t, 1, 5> primeValues[8];
	/**
	 * Trigger comparator center point voltage
	V
	 * offset 2480
	 */
	scaled_channel<uint8_t, 50, 1> triggerCompCenterVolt;
	/**
	 * Trigger comparator hysteresis voltage (Min)
	V
	 * offset 2481
	 */
	scaled_channel<uint8_t, 50, 1> triggerCompHystMin;
	/**
	 * Trigger comparator hysteresis voltage (Max)
	V
	 * offset 2482
	 */
	scaled_channel<uint8_t, 50, 1> triggerCompHystMax;
	/**
	 * VR-sensor saturation RPM
	RPM
	 * offset 2483
	 */
	scaled_channel<uint8_t, 1, 50> triggerCompSensorSatRpm;
	/**
	 * offset 2484
	 */
	pid_s idleRpmPid2;
	/**
	 * set can_vss X
	 * offset 2504
	 */
	can_vss_nbc_e canVssNbcType;
	/**
	 * need 4 byte alignment
	units
	 * offset 2505
	 */
	uint8_t alignmentFill_at_2505[3];
	/**
	 * offset 2508
	 */
	gppwm_channel gppwm[GPPWM_CHANNELS];
	/**
	 * Boost Current
	mA
	 * offset 2940
	 */
	uint16_t mc33_i_boost;
	/**
	 * Peak Current
	mA
	 * offset 2942
	 */
	uint16_t mc33_i_peak;
	/**
	 * Hold Current
	mA
	 * offset 2944
	 */
	uint16_t mc33_i_hold;
	/**
	 * Maximum allowed boost phase time. If the injector current doesn't reach the threshold before this time elapses, it is assumed that the injector is missing or has failed open circuit.
	us
	 * offset 2946
	 */
	uint16_t mc33_t_max_boost;
	/**
	us
	 * offset 2948
	 */
	uint16_t mc33_t_peak_off;
	/**
	 * Peak phase duration
	us
	 * offset 2950
	 */
	uint16_t mc33_t_peak_tot;
	/**
	us
	 * offset 2952
	 */
	uint16_t mc33_t_bypass;
	/**
	us
	 * offset 2954
	 */
	uint16_t mc33_t_hold_off;
	/**
	 * Hold phase duration
	us
	 * offset 2956
	 */
	uint16_t mc33_t_hold_tot;
	/**
	 * offset 2958
	 */
	pin_input_mode_e tcuUpshiftButtonPinMode;
	/**
	 * offset 2959
	 */
	pin_input_mode_e tcuDownshiftButtonPinMode;
	/**
	 * offset 2960
	 */
	pin_input_mode_e acSwitchMode;
	/**
	 * offset 2961
	 */
	pin_output_mode_e tcu_solenoid_mode[TCU_SOLENOID_COUNT];
	/**
	 * Knock sensor output knock detection threshold depending on current RPM.
	dB
	 * offset 2967
	 */
	scaled_channel<int8_t, 2, 1> knockBaseNoise[ENGINE_NOISE_CURVE_SIZE];
	/**
	 * need 4 byte alignment
	units
	 * offset 2983
	 */
	uint8_t alignmentFill_at_2983[1];
	/**
	ratio
	 * offset 2984
	 */
	float triggerGapOverrideFrom[GAP_TRACKING_LENGTH];
	/**
	ratio
	 * offset 3056
	 */
	float triggerGapOverrideTo[GAP_TRACKING_LENGTH];
	/**
	 * Below this RPM, use camshaft information to synchronize the crank's position for full sequential operation. Use this if your cam sensor does weird things at high RPM. Set to 0 to disable, and always use cam to help sync crank.
	rpm
	 * offset 3128
	 */
	scaled_channel<uint8_t, 1, 50> maxCamPhaseResolveRpm;
	/**
	 * Delay before cutting fuel. Set to 0 to cut immediately with no delay. May cause rumbles and pops out of your exhaust...
	sec
	 * offset 3129
	 */
	scaled_channel<uint8_t, 10, 1> dfcoDelay;
	/**
	 * Delay before engaging the AC compressor. Set to 0 to engage immediately with no delay. Use this to prevent bogging at idle when AC engages.
	sec
	 * offset 3130
	 */
	scaled_channel<uint8_t, 10, 1> acDelay;
	/**
	 * need 4 byte alignment
	units
	 * offset 3131
	 */
	uint8_t alignmentFill_at_3131[1];
	/**
	mg
	 * offset 3132
	 */
	scaled_channel<uint16_t, 1000, 1> fordInjectorSmallPulseBreakPoint;
	/**
	multiplier
	 * offset 3134
	 */
	scaled_channel<uint8_t, 50, 1> tpsTspCorrValues[TPS_TPS_ACCEL_CLT_CORR_TABLE];
	/**
	%
	 * offset 3138
	 */
	uint8_t etbJamIntegratorLimit;
	/**
	lobes/cam
	 * offset 3139
	 */
	uint8_t hpfpCamLobes;
	/**
	 * offset 3140
	 */
	hpfp_cam_e hpfpCam;
	/**
	 * offset 3141
	 */
	uint8_t auxiliarySetting1;
	/**
	 * If the requested activation time is below this angle, don't bother running the pump
	deg
	 * offset 3142
	 */
	uint8_t hpfpMinAngle;
	/**
	 * need 4 byte alignment
	units
	 * offset 3143
	 */
	uint8_t alignmentFill_at_3143[1];
	/**
	 * Size of the pump chamber in cc. Typical Bosch HDP5 has a 9.0mm diameter, typical BMW N* stroke is 4.4mm.
	cc
	 * offset 3144
	 */
	scaled_channel<uint16_t, 1000, 1> hpfpPumpVolume;
	/**
	 * How long to keep the valve activated (in order to allow the pump to build pressure and keep the valve open on its own)
	deg
	 * offset 3146
	 */
	uint8_t hpfpActivationAngle;
	/**
	 * offset 3147
	 */
	uint8_t issFilterReciprocal;
	/**
	%/kPa
	 * offset 3148
	 */
	scaled_channel<uint16_t, 1000, 1> hpfpPidP;
	/**
	%/kPa/lobe
	 * offset 3150
	 */
	scaled_channel<uint16_t, 100000, 1> hpfpPidI;
	/**
	 * The fastest rate the target pressure can be reduced by. This is because HPFP have no way to bleed off pressure other than injecting fuel.
	kPa/s
	 * offset 3152
	 */
	uint16_t hpfpTargetDecay;
	/**
	%
	 * offset 3154
	 */
	scaled_channel<uint8_t, 2, 1> hpfpLobeProfileQuantityBins[HPFP_LOBE_PROFILE_SIZE];
	/**
	deg
	 * offset 3170
	 */
	scaled_channel<uint8_t, 2, 1> hpfpLobeProfileAngle[HPFP_LOBE_PROFILE_SIZE];
	/**
	volts
	 * offset 3186
	 */
	uint8_t hpfpDeadtimeVoltsBins[HPFP_DEADTIME_SIZE];
	/**
	ms
	 * offset 3194
	 */
	scaled_channel<uint16_t, 1000, 1> hpfpDeadtimeMS[HPFP_DEADTIME_SIZE];
	/**
	kPa
	 * offset 3210
	 */
	uint16_t hpfpTarget[HPFP_TARGET_SIZE][HPFP_TARGET_SIZE];
	/**
	load
	 * offset 3410
	 */
	scaled_channel<uint16_t, 10, 1> hpfpTargetLoadBins[HPFP_TARGET_SIZE];
	/**
	RPM
	 * offset 3430
	 */
	scaled_channel<uint8_t, 1, 50> hpfpTargetRpmBins[HPFP_TARGET_SIZE];
	/**
	%
	 * offset 3440
	 */
	int8_t hpfpCompensation[HPFP_COMPENSATION_SIZE][HPFP_COMPENSATION_SIZE];
	/**
	cc/lobe
	 * offset 3540
	 */
	scaled_channel<uint16_t, 1000, 1> hpfpCompensationLoadBins[HPFP_COMPENSATION_SIZE];
	/**
	RPM
	 * offset 3560
	 */
	scaled_channel<uint8_t, 1, 50> hpfpCompensationRpmBins[HPFP_COMPENSATION_SIZE];
	/**
	 * offset 3570
	 */
	output_pin_e stepper_raw_output[4];
	/**
	ratio
	 * offset 3578
	 */
	scaled_channel<uint16_t, 100, 1> gearRatio[GEARS_COUNT];
	/**
	 * We need to give engine time to build oil pressure without diverting it to VVT
	ms
	 * offset 3594
	 */
	uint16_t vvtActivationDelayMs;
	/**
	deg C
	 * offset 3596
	 */
	int8_t wwCltBins[WWAE_TABLE_SIZE];
	/**
	 * offset 3604
	 */
	scaled_channel<uint8_t, 100, 1> wwTauCltValues[WWAE_TABLE_SIZE];
	/**
	 * offset 3612
	 */
	scaled_channel<uint8_t, 100, 1> wwBetaCltValues[WWAE_TABLE_SIZE];
	/**
	kPa
	 * offset 3620
	 */
	int8_t wwMapBins[WWAE_TABLE_SIZE];
	/**
	 * offset 3628
	 */
	scaled_channel<uint8_t, 100, 1> wwTauMapValues[WWAE_TABLE_SIZE];
	/**
	 * offset 3636
	 */
	scaled_channel<uint8_t, 100, 1> wwBetaMapValues[WWAE_TABLE_SIZE];
	/**
	Nm
	 * offset 3644
	 */
	scaled_channel<uint8_t, 1, 10> torqueTable[TORQUE_CURVE_SIZE][TORQUE_CURVE_SIZE];
	/**
	RPM
	 * offset 3680
	 */
	uint16_t torqueRpmBins[TORQUE_CURVE_SIZE];
	/**
	Load
	 * offset 3692
	 */
	uint16_t torqueLoadBins[TORQUE_CURVE_SIZE];
	/**
	 * offset 3704
	 */
	GearControllerMode gearControllerMode;
	/**
	 * offset 3705
	 */
	TransmissionControllerMode transmissionControllerMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 3706
	 */
	uint8_t alignmentFill_at_3706[2];
	/**
	 * offset 3708
	 */
	linear_sensor_s auxLinear1;
	/**
	 * offset 3728
	 */
	linear_sensor_s auxLinear2;
	/**
	 * offset 3748
	 */
	output_pin_e tcu_tcc_onoff_solenoid;
	/**
	 * offset 3750
	 */
	pin_output_mode_e tcu_tcc_onoff_solenoid_mode;
	/**
	 * need 4 byte alignment
	units
	 * offset 3751
	 */
	uint8_t alignmentFill_at_3751[1];
	/**
	 * offset 3752
	 */
	output_pin_e tcu_tcc_pwm_solenoid;
	/**
	 * offset 3754
	 */
	pin_output_mode_e tcu_tcc_pwm_solenoid_mode;
	/**
	 * need 4 byte alignment
	units
	 * offset 3755
	 */
	uint8_t alignmentFill_at_3755[1];
	/**
	 * offset 3756
	 */
	pwm_freq_t tcu_tcc_pwm_solenoid_freq;
	/**
	 * offset 3758
	 */
	output_pin_e tcu_pc_solenoid_pin;
	/**
	 * offset 3760
	 */
	pin_output_mode_e tcu_pc_solenoid_pin_mode;
	/**
	 * need 4 byte alignment
	units
	 * offset 3761
	 */
	uint8_t alignmentFill_at_3761[1];
	/**
	 * offset 3762
	 */
	pwm_freq_t tcu_pc_solenoid_freq;
	/**
	 * offset 3764
	 */
	output_pin_e tcu_32_solenoid_pin;
	/**
	 * offset 3766
	 */
	pin_output_mode_e tcu_32_solenoid_pin_mode;
	/**
	 * need 4 byte alignment
	units
	 * offset 3767
	 */
	uint8_t alignmentFill_at_3767[1];
	/**
	 * offset 3768
	 */
	pwm_freq_t tcu_32_solenoid_freq;
	/**
	 * need 4 byte alignment
	units
	 * offset 3770
	 */
	uint8_t alignmentFill_at_3770[2];
	/**
	%
	 * offset 3772
	 */
	float etbMinimumPosition;
	/**
	 * offset 3776
	 */
	uint16_t tuneHidingKey;
	/**
	 * offset 3778
	 */
	vin_number_t vinNumber;
	/**
	 * need 4 byte alignment
	units
	 * offset 3795
	 */
	uint8_t alignmentFill_at_3795[1];
	/**
	 * offset 3796
	 */
	uint16_t highSpeedOffsets[HIGH_SPEED_COUNT];
	/**
	 * offset 3860
	 */
	float etbDutyShutdownThreshold;
	/**
	 * offset 3864
	 */
	fuel_pressure_sensor_mode_e fuelPressureSensorMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 3865
	 */
	uint8_t alignmentFill_at_3865[1];
	/**
	 * offset 3866
	 */
	Gpio luaDigitalInputPins[LUA_DIGITAL_INPUT_COUNT];
	/**
	RPM
	 * offset 3882
	 */
	scaled_channel<uint8_t, 1, 50> tpsTspCorrValuesBins[TPS_TPS_ACCEL_CLT_CORR_TABLE];
	/**
	rpm
	 * offset 3886
	 */
	int16_t ALSMinRPM;
	/**
	rpm
	 * offset 3888
	 */
	int16_t ALSMaxRPM;
	/**
	sec
	 * offset 3890
	 */
	int16_t ALSMaxDuration;
	/**
	C
	 * offset 3892
	 */
	int8_t ALSMinCLT;
	/**
	C
	 * offset 3893
	 */
	int8_t ALSMaxCLT;
	/**
	 * offset 3894
	 */
	uint8_t alsMinTimeBetween;
	/**
	 * offset 3895
	 */
	uint8_t alsEtbPosition;
	/**
	 * offset 3896
	 */
	uint8_t acRelayAlternatorDutyAdder;
	/**
	 * offset 3897
	 */
	SentEtbType sentEtbType;
	/**
	 * offset 3898
	 */
	uint16_t customSentTpsMin;
	/**
	%
	 * offset 3900
	 */
	int ALSIdleAdd;
	/**
	%
	 * offset 3904
	 */
	int ALSEtbAdd;
	/**
	 * offset 3908
	 */
	float ALSSkipRatio;
	/**
	%
	 * offset 3912
	 */
	uint8_t ALSMaxDriverThrottleIntent;
	/**
	 * offset 3913
	 */
	pin_input_mode_e ALSActivatePinMode;
	/**
	 * For Ford TPS, use 53%. For Toyota ETCS-i, use ~65%
	%
	 * offset 3914
	 */
	scaled_channel<uint8_t, 2, 1> tpsSecondaryMaximum;
	/**
	 * For Toyota ETCS-i, use ~69%
	%
	 * offset 3915
	 */
	scaled_channel<uint8_t, 2, 1> ppsSecondaryMaximum;
	/**
	 * offset 3916
	 */
	pin_input_mode_e luaDigitalInputPinModes[LUA_DIGITAL_INPUT_COUNT];
	/**
	 * offset 3924
	 */
	uint16_t customSentTpsMax;
	/**
	 * offset 3926
	 */
	uint16_t kLineBaudRate;
	/**
	 * offset 3928
	 */
	CanGpioType canGpioType;
	/**
	 * offset 3929
	 */
	UiMode uiMode;
	/**
	 * Crank angle ATDC of first lobe peak
	deg
	 * offset 3930
	 */
	int16_t hpfpPeakPos;
	/**
	us
	 * offset 3932
	 */
	int16_t kLinePeriodUs;
	/**
	 * Window that the correction will be added throughout (example, if rpm limit is 7000, and rpmSoftLimitWindowSize is 200, the corrections activate at 6800RPM, creating a 200rpm window)
	RPM
	 * offset 3934
	 */
	scaled_channel<uint8_t, 1, 10> rpmSoftLimitWindowSize;
	/**
	 * Degrees of timing REMOVED from actual timing during soft RPM limit window
	deg
	 * offset 3935
	 */
	scaled_channel<uint8_t, 5, 1> rpmSoftLimitTimingRetard;
	/**
	 * % of fuel ADDED during window
	%
	 * offset 3936
	 */
	scaled_channel<uint8_t, 5, 1> rpmSoftLimitFuelAdded;
	/**
	 * Hysterisis: if the hard limit is 7200rpm and rpmHardLimitHyst is 200rpm, then when the ECU sees 7200rpm, fuel/ign will cut, and stay cut until 7000rpm (7200-200) is reached
	RPM
	 * offset 3937
	 */
	scaled_channel<uint8_t, 1, 10> rpmHardLimitHyst;
	/**
	 * Time between bench test pulses
	ms
	 * offset 3938
	 */
	scaled_channel<uint16_t, 10, 1> benchTestOffTime;
	/**
	 * Hysterisis: if hard cut is 240kpa, and boostCutPressureHyst is 20, when the ECU sees 240kpa, fuel/ign will cut, and stay cut until 240-20=220kpa is reached
	kPa (absolute)
	 * offset 3940
	 */
	scaled_channel<uint8_t, 2, 1> boostCutPressureHyst;
	/**
	units
	 * offset 3941
	 */
	uint8_t mainUnusedEnd[31];
};
static_assert(sizeof(engine_configuration_s) == 3972);

// start of cyl_trim_s
struct cyl_trim_s {
	/**
	 * offset 0
	 */
	scaled_channel<int8_t, 5, 1> table[TRIM_SIZE][TRIM_SIZE];
};
static_assert(sizeof(cyl_trim_s) == 16);

// start of blend_table_s
struct blend_table_s {
	/**
	 * offset 0
	 */
	scaled_channel<int16_t, 10, 1> table[8][8];
	/**
	Load
	 * offset 128
	 */
	uint16_t loadBins[8];
	/**
	RPM
	 * offset 144
	 */
	uint16_t rpmBins[8];
	/**
	 * offset 160
	 */
	gppwm_channel_e blendParameter;
	/**
	 * need 4 byte alignment
	units
	 * offset 161
	 */
	uint8_t alignmentFill_at_161[1];
	/**
	 * offset 162
	 */
	scaled_channel<int16_t, 10, 1> blendBins[8];
	/**
	%
	 * offset 178
	 */
	scaled_channel<uint8_t, 2, 1> blendValues[8];
	/**
	 * need 4 byte alignment
	units
	 * offset 186
	 */
	uint8_t alignmentFill_at_186[2];
};
static_assert(sizeof(blend_table_s) == 188);

// start of persistent_config_s
struct persistent_config_s {
	/**
	 * offset 0
	 */
	engine_configuration_s engineConfiguration;
	/**
	 * target TPS value, 0 to 100%
	 * TODO: use int8 data date once we template interpolation method
	target TPS position
	 * offset 3972
	 */
	float etbBiasBins[ETB_BIAS_CURVE_LENGTH];
	/**
	 * PWM bias, 0 to 100%
	ETB duty cycle bias
	 * offset 4004
	 */
	float etbBiasValues[ETB_BIAS_CURVE_LENGTH];
	/**
	%
	 * offset 4036
	 */
	scaled_channel<uint8_t, 20, 1> iacPidMultTable[IAC_PID_MULT_SIZE][IAC_PID_MULT_SIZE];
	/**
	Load
	 * offset 4100
	 */
	uint8_t iacPidMultLoadBins[IAC_PID_MULT_SIZE];
	/**
	RPM
	 * offset 4108
	 */
	scaled_channel<uint8_t, 1, 10> iacPidMultRpmBins[IAC_PID_MULT_SIZE];
	/**
	 * On Single Coil or Wasted Spark setups you have to lower dwell at high RPM
	RPM
	 * offset 4116
	 */
	uint16_t sparkDwellRpmBins[DWELL_CURVE_SIZE];
	/**
	ms
	 * offset 4132
	 */
	scaled_channel<uint16_t, 100, 1> sparkDwellValues[DWELL_CURVE_SIZE];
	/**
	 * CLT-based target RPM for automatic idle controller
	C
	 * offset 4148
	 */
	scaled_channel<int8_t, 1, 2> cltIdleRpmBins[CLT_CURVE_SIZE];
	/**
	 * See idleRpmPid
	RPM
	 * offset 4164
	 */
	scaled_channel<uint8_t, 1, 20> cltIdleRpm[CLT_CURVE_SIZE];
	/**
	 * CLT-based timing correction
	C
	 * offset 4180
	 */
	float cltTimingBins[CLT_TIMING_CURVE_SIZE];
	/**
	degree
	 * offset 4212
	 */
	float cltTimingExtra[CLT_TIMING_CURVE_SIZE];
	/**
	x
	 * offset 4244
	 */
	float scriptCurve1Bins[SCRIPT_CURVE_16];
	/**
	y
	 * offset 4308
	 */
	float scriptCurve1[SCRIPT_CURVE_16];
	/**
	x
	 * offset 4372
	 */
	float scriptCurve2Bins[SCRIPT_CURVE_16];
	/**
	y
	 * offset 4436
	 */
	float scriptCurve2[SCRIPT_CURVE_16];
	/**
	x
	 * offset 4500
	 */
	float scriptCurve3Bins[SCRIPT_CURVE_8];
	/**
	y
	 * offset 4532
	 */
	float scriptCurve3[SCRIPT_CURVE_8];
	/**
	x
	 * offset 4564
	 */
	float scriptCurve4Bins[SCRIPT_CURVE_8];
	/**
	y
	 * offset 4596
	 */
	float scriptCurve4[SCRIPT_CURVE_8];
	/**
	x
	 * offset 4628
	 */
	float scriptCurve5Bins[SCRIPT_CURVE_8];
	/**
	y
	 * offset 4660
	 */
	float scriptCurve5[SCRIPT_CURVE_8];
	/**
	x
	 * offset 4692
	 */
	float scriptCurve6Bins[SCRIPT_CURVE_8];
	/**
	y
	 * offset 4724
	 */
	float scriptCurve6[SCRIPT_CURVE_8];
	/**
	kPa
	 * offset 4756
	 */
	float baroCorrPressureBins[BARO_CORR_SIZE];
	/**
	RPM
	 * offset 4772
	 */
	float baroCorrRpmBins[BARO_CORR_SIZE];
	/**
	ratio
	 * offset 4788
	 */
	float baroCorrTable[BARO_CORR_SIZE][BARO_CORR_SIZE];
	/**
	 * Cranking fuel correction coefficient based on TPS
	Ratio
	 * offset 4852
	 */
	float crankingTpsCoef[CRANKING_CURVE_SIZE];
	/**
	%
	 * offset 4884
	 */
	float crankingTpsBins[CRANKING_CURVE_SIZE];
	/**
	 * Narrow Band WBO Approximation
	V
	 * offset 4916
	 */
	float narrowToWideOxygenBins[NARROW_BAND_WIDE_BAND_CONVERSION_SIZE];
	/**
	ratio
	 * offset 4948
	 */
	float narrowToWideOxygen[NARROW_BAND_WIDE_BAND_CONVERSION_SIZE];
	/**
	 * Optional timing advance table for Cranking (see useSeparateAdvanceForCranking)
	RPM
	 * offset 4980
	 */
	uint16_t crankingAdvanceBins[CRANKING_ADVANCE_CURVE_SIZE];
	/**
	 * Optional timing advance table for Cranking (see useSeparateAdvanceForCranking)
	deg
	 * offset 4988
	 */
	scaled_channel<int16_t, 100, 1> crankingAdvance[CRANKING_ADVANCE_CURVE_SIZE];
	/**
	 * RPM-based idle position for coasting
	RPM
	 * offset 4996
	 */
	scaled_channel<uint8_t, 1, 100> iacCoastingRpmBins[CLT_CURVE_SIZE];
	/**
	 * RPM-based idle position for coasting
	%
	 * offset 5012
	 */
	scaled_channel<uint8_t, 2, 1> iacCoasting[CLT_CURVE_SIZE];
	/**
	 * offset 5028
	 */
	warning_message_t warning_message;
	/**
	C
	 * offset 5148
	 */
	float afterstartCoolantBins[AFTERSTART_HOLD_CURVE_SIZE];
	/**
	Seconds
	 * offset 5180
	 */
	float afterstartHoldTime[AFTERSTART_HOLD_CURVE_SIZE];
	/**
	%
	 * offset 5212
	 */
	float afterstartEnrich[AFTERSTART_ENRICH_CURVE_SIZE];
	/**
	Seconds
	 * offset 5244
	 */
	float afterstartDecayTime[AFTERSTART_DECAY_CURVE_SIZE];
	/**
	 * offset 5276
	 */
	scaled_channel<uint8_t, 2, 1> boostTableOpenLoop[BOOST_RPM_COUNT][BOOST_LOAD_COUNT];
	/**
	RPM
	 * offset 5340
	 */
	scaled_channel<uint8_t, 1, 100> boostRpmBins[BOOST_RPM_COUNT];
	/**
	 * offset 5348
	 */
	scaled_channel<uint8_t, 1, 2> boostTableClosedLoop[BOOST_RPM_COUNT][BOOST_LOAD_COUNT];
	/**
	%
	 * offset 5412
	 */
	uint8_t boostTpsBins[BOOST_LOAD_COUNT];
	/**
	%
	 * offset 5420
	 */
	uint8_t pedalToTpsTable[PEDAL_TO_TPS_SIZE][PEDAL_TO_TPS_SIZE];
	/**
	%
	 * offset 5484
	 */
	uint8_t pedalToTpsPedalBins[PEDAL_TO_TPS_SIZE];
	/**
	RPM
	 * offset 5492
	 */
	scaled_channel<uint8_t, 1, 100> pedalToTpsRpmBins[PEDAL_TO_TPS_SIZE];
	/**
	 * CLT-based cranking position multiplier for simple manual idle controller
	C
	 * offset 5500
	 */
	float cltCrankingCorrBins[CLT_CRANKING_CURVE_SIZE];
	/**
	 * CLT-based cranking position multiplier for simple manual idle controller
	%
	 * offset 5532
	 */
	float cltCrankingCorr[CLT_CRANKING_CURVE_SIZE];
	/**
	 * Optional timing advance table for Idle (see useSeparateAdvanceForIdle)
	RPM
	 * offset 5564
	 */
	scaled_channel<uint8_t, 1, 50> idleAdvanceBins[IDLE_ADVANCE_CURVE_SIZE];
	/**
	 * Optional timing advance table for Idle (see useSeparateAdvanceForIdle)
	deg
	 * offset 5572
	 */
	float idleAdvance[IDLE_ADVANCE_CURVE_SIZE];
	/**
	RPM
	 * offset 5604
	 */
	scaled_channel<uint8_t, 1, 10> idleVeRpmBins[IDLE_VE_SIZE];
	/**
	load
	 * offset 5608
	 */
	uint8_t idleVeLoadBins[IDLE_VE_SIZE];
	/**
	%
	 * offset 5612
	 */
	scaled_channel<uint16_t, 10, 1> idleVeTable[IDLE_VE_SIZE][IDLE_VE_SIZE];
	/**
	 * offset 5644
	 */
	lua_script_t luaScript;
	/**
	C
	 * offset 13644
	 */
	float cltFuelCorrBins[CLT_CURVE_SIZE];
	/**
	ratio
	 * offset 13708
	 */
	float cltFuelCorr[CLT_CURVE_SIZE];
	/**
	C
	 * offset 13772
	 */
	float iatFuelCorrBins[IAT_CURVE_SIZE];
	/**
	ratio
	 * offset 13836
	 */
	float iatFuelCorr[IAT_CURVE_SIZE];
	/**
	ratio
	 * offset 13900
	 */
	float crankingFuelCoef[CRANKING_CURVE_SIZE];
	/**
	C
	 * offset 13932
	 */
	float crankingFuelBins[CRANKING_CURVE_SIZE];
	/**
	ratio
	 * offset 13964
	 */
	float crankingCycleCoef[CRANKING_CURVE_SIZE];
	/**
	counter
	 * offset 13996
	 */
	float crankingCycleBins[CRANKING_CURVE_SIZE];
	/**
	 * CLT-based idle position multiplier for simple manual idle controller
	C
	 * offset 14028
	 */
	float cltIdleCorrBins[CLT_CURVE_SIZE];
	/**
	 * CLT-based idle position multiplier for simple manual idle controller
	ratio
	 * offset 14092
	 */
	float cltIdleCorr[CLT_CURVE_SIZE];
	/**
	 * Also known as MAF transfer function.
	 * kg/hour value.
	 * By the way 2.081989116 kg/h = 1 ft3/m
	kg/hour
	 * offset 14156
	 */
	float mafDecoding[MAF_DECODING_COUNT];
	/**
	V
	 * offset 15180
	 */
	float mafDecodingBins[MAF_DECODING_COUNT];
	/**
	deg
	 * offset 16204
	 */
	scaled_channel<int8_t, 10, 1> ignitionIatCorrTable[8][8];
	/**
	C
	 * offset 16268
	 */
	int8_t ignitionIatCorrTempBins[8];
	/**
	Load
	 * offset 16276
	 */
	scaled_channel<uint8_t, 1, 5> ignitionIatCorrLoadBins[8];
	/**
	deg
	 * offset 16284
	 */
	int16_t injectionPhase[IGN_RPM_COUNT][IGN_LOAD_COUNT];
	/**
	Load
	 * offset 16796
	 */
	uint16_t injPhaseLoadBins[FUEL_LOAD_COUNT];
	/**
	RPM
	 * offset 16828
	 */
	uint16_t injPhaseRpmBins[FUEL_RPM_COUNT];
	/**
	onoff
	 * offset 16860
	 */
	uint8_t tcuSolenoidTable[TCU_SOLENOID_COUNT][TCU_GEAR_COUNT];
	/**
	kPa
	 * offset 16920
	 */
	scaled_channel<uint16_t, 100, 1> mapEstimateTable[FUEL_RPM_COUNT][FUEL_LOAD_COUNT];
	/**
	% TPS
	 * offset 17432
	 */
	scaled_channel<uint16_t, 100, 1> mapEstimateTpsBins[FUEL_LOAD_COUNT];
	/**
	RPM
	 * offset 17464
	 */
	uint16_t mapEstimateRpmBins[FUEL_RPM_COUNT];
	/**
	value
	 * offset 17496
	 */
	int8_t vvtTable1[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 17560
	 */
	uint16_t vvtTable1LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 17576
	 */
	uint16_t vvtTable1RpmBins[SCRIPT_TABLE_8];
	/**
	value
	 * offset 17592
	 */
	int8_t vvtTable2[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 17656
	 */
	uint16_t vvtTable2LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 17672
	 */
	uint16_t vvtTable2RpmBins[SCRIPT_TABLE_8];
	/**
	deg
	 * offset 17688
	 */
	scaled_channel<int16_t, 10, 1> ignitionTable[IGN_RPM_COUNT][IGN_LOAD_COUNT];
	/**
	Load
	 * offset 18200
	 */
	uint16_t ignitionLoadBins[IGN_LOAD_COUNT];
	/**
	RPM
	 * offset 18232
	 */
	uint16_t ignitionRpmBins[IGN_RPM_COUNT];
	/**
	%
	 * offset 18264
	 */
	scaled_channel<uint16_t, 10, 1> veTable[FUEL_RPM_COUNT][FUEL_LOAD_COUNT];
	/**
	kPa
	 * offset 18776
	 */
	uint16_t veLoadBins[FUEL_LOAD_COUNT];
	/**
	RPM
	 * offset 18808
	 */
	uint16_t veRpmBins[FUEL_RPM_COUNT];
	/**
	lambda
	 * offset 18840
	 */
	scaled_channel<uint8_t, 147, 1> lambdaTable[FUEL_RPM_COUNT][FUEL_LOAD_COUNT];
	/**
	 * offset 19096
	 */
	uint16_t lambdaLoadBins[FUEL_LOAD_COUNT];
	/**
	RPM
	 * offset 19128
	 */
	uint16_t lambdaRpmBins[FUEL_RPM_COUNT];
	/**
	value
	 * offset 19160
	 */
	float tpsTpsAccelTable[TPS_TPS_ACCEL_TABLE][TPS_TPS_ACCEL_TABLE];
	/**
	from
	 * offset 19416
	 */
	float tpsTpsAccelFromRpmBins[TPS_TPS_ACCEL_TABLE];
	/**
	to
	 * offset 19448
	 */
	float tpsTpsAccelToRpmBins[TPS_TPS_ACCEL_TABLE];
	/**
	value
	 * offset 19480
	 */
	float scriptTable1[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 19736
	 */
	int16_t scriptTable1LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 19752
	 */
	int16_t scriptTable1RpmBins[SCRIPT_TABLE_8];
	/**
	value
	 * offset 19768
	 */
	uint8_t scriptTable2[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 19832
	 */
	int16_t scriptTable2LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 19848
	 */
	int16_t scriptTable2RpmBins[SCRIPT_TABLE_8];
	/**
	value
	 * offset 19864
	 */
	uint8_t scriptTable3[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 19928
	 */
	int16_t scriptTable3LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 19944
	 */
	int16_t scriptTable3RpmBins[SCRIPT_TABLE_8];
	/**
	value
	 * offset 19960
	 */
	uint8_t scriptTable4[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 20024
	 */
	int16_t scriptTable4LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 20040
	 */
	int16_t scriptTable4RpmBins[SCRIPT_TABLE_8];
	/**
	 * offset 20056
	 */
	uint16_t ignTrimLoadBins[TRIM_SIZE];
	/**
	rpm
	 * offset 20064
	 */
	uint16_t ignTrimRpmBins[TRIM_SIZE];
	/**
	 * offset 20072
	 */
	cyl_trim_s ignTrims[12];
	/**
	 * offset 20264
	 */
	uint16_t fuelTrimLoadBins[TRIM_SIZE];
	/**
	rpm
	 * offset 20272
	 */
	uint16_t fuelTrimRpmBins[TRIM_SIZE];
	/**
	 * offset 20280
	 */
	cyl_trim_s fuelTrims[12];
	/**
	ratio
	 * offset 20472
	 */
	scaled_channel<uint16_t, 100, 1> crankingFuelCoefE100[CRANKING_CURVE_SIZE];
	/**
	Airmass
	 * offset 20488
	 */
	scaled_channel<uint8_t, 50, 1> tcu_pcAirmassBins[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20496
	 */
	uint8_t tcu_pcValsR[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20504
	 */
	uint8_t tcu_pcValsN[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20512
	 */
	uint8_t tcu_pcVals1[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20520
	 */
	uint8_t tcu_pcVals2[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20528
	 */
	uint8_t tcu_pcVals3[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20536
	 */
	uint8_t tcu_pcVals4[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20544
	 */
	uint8_t tcu_pcVals12[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20552
	 */
	uint8_t tcu_pcVals23[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20560
	 */
	uint8_t tcu_pcVals34[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20568
	 */
	uint8_t tcu_pcVals21[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20576
	 */
	uint8_t tcu_pcVals32[TCU_MAGIC_SIZE];
	/**
	%
	 * offset 20584
	 */
	uint8_t tcu_pcVals43[TCU_MAGIC_SIZE];
	/**
	TPS
	 * offset 20592
	 */
	uint8_t tcu_tccTpsBins[8];
	/**
	MPH
	 * offset 20600
	 */
	uint8_t tcu_tccLockSpeed[8];
	/**
	MPH
	 * offset 20608
	 */
	uint8_t tcu_tccUnlockSpeed[8];
	/**
	KPH
	 * offset 20616
	 */
	uint8_t tcu_32SpeedBins[8];
	/**
	%
	 * offset 20624
	 */
	uint8_t tcu_32Vals[8];
	/**
	%
	 * offset 20632
	 */
	scaled_channel<int8_t, 10, 1> throttle2TrimTable[6][6];
	/**
	%
	 * offset 20668
	 */
	uint8_t throttle2TrimTpsBins[6];
	/**
	RPM
	 * offset 20674
	 */
	scaled_channel<uint8_t, 1, 100> throttle2TrimRpmBins[6];
	/**
	deg
	 * offset 20680
	 */
	scaled_channel<uint8_t, 4, 1> maxKnockRetardTable[6][6];
	/**
	%
	 * offset 20716
	 */
	uint8_t maxKnockRetardLoadBins[6];
	/**
	RPM
	 * offset 20722
	 */
	scaled_channel<uint8_t, 1, 100> maxKnockRetardRpmBins[6];
	/**
	deg
	 * offset 20728
	 */
	scaled_channel<int16_t, 10, 1> ALSTimingRetardTable[4][4];
	/**
	TPS
	 * offset 20760
	 */
	uint16_t alsIgnRetardLoadBins[4];
	/**
	RPM
	 * offset 20768
	 */
	uint16_t alsIgnRetardrpmBins[4];
	/**
	percent
	 * offset 20776
	 */
	scaled_channel<int16_t, 10, 1> ALSFuelAdjustment[4][4];
	/**
	TPS
	 * offset 20808
	 */
	uint16_t alsFuelAdjustmentLoadBins[4];
	/**
	RPM
	 * offset 20816
	 */
	uint16_t alsFuelAdjustmentrpmBins[4];
	/**
	ratio
	 * offset 20824
	 */
	scaled_channel<int16_t, 1, 10> ALSIgnSkipTable[4][4];
	/**
	TPS
	 * offset 20856
	 */
	uint16_t alsIgnSkipLoadBins[4];
	/**
	RPM
	 * offset 20864
	 */
	uint16_t alsIgnSkiprpmBins[4];
	/**
	 * offset 20872
	 */
	blend_table_s ignBlends[IGN_BLEND_COUNT];
	/**
	 * offset 21624
	 */
	blend_table_s veBlends[VE_BLEND_COUNT];
	/**
	%
	 * offset 22376
	 */
	scaled_channel<uint16_t, 10, 1> throttleEstimateEffectiveAreaBins[12];
	/**
	 * In units of g/s normalized to choked flow conditions
	g/s
	 * offset 22400
	 */
	scaled_channel<uint16_t, 10, 1> throttleEstimateEffectiveAreaValues[12];
	/**
	 * offset 22424
	 */
	blend_table_s boostOpenLoopBlends[BOOST_BLEND_COUNT];
	/**
	 * offset 22800
	 */
	blend_table_s boostClosedLoopBlends[BOOST_BLEND_COUNT];
};
static_assert(sizeof(persistent_config_s) == 23176);

// end
// this section was generated automatically by gerefi tool ConfigDefinition.jar based on hellen_cypress_gen_config.bat integration/gerefi_config.txt Fri May 05 21:37:57 UTC 2023
