// this section was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/algo/ignition_state.txt Fri May 05 01:35:23 UTC 2023
// by class com.gerefi.output.CHeaderConsumer
// begin
#pragma once
#include "gerefi_types.h"
// start of ignition_state_s
struct ignition_state_s {
	/**
	 * "Ignition: base dwell"
	ms
	 * offset 0
	 */
	float baseDwell = (float)0;
	/**
	 * @@GAUGE_COIL_DWELL_TIME@@
	ms
	 * offset 4
	 */
	floatms_t sparkDwell = (floatms_t)0;
	/**
	 * Ignition: dwell duration
	 * as crankshaft angle
	 * NAN if engine is stopped
	 * See also sparkDwell
	deg
	 * offset 8
	 */
	angle_t dwellAngle = (angle_t)0;
	/**
	 * Ign: CLT correction
	deg
	 * offset 12
	 */
	scaled_channel<int16_t, 100, 1> cltTimingCorrection = (int16_t)0;
	/**
	 * Ign: IAT correction
	deg
	 * offset 14
	 */
	scaled_channel<int16_t, 100, 1> timingIatCorrection = (int16_t)0;
	/**
	 * Idle: Timing adjustment
	deg
	 * offset 16
	 */
	scaled_channel<int16_t, 100, 1> timingPidCorrection = (int16_t)0;
	/**
	 * @@GAUGE_NAME_TIMING_ADVANCE@@
	deg
	 * offset 18
	 */
	scaled_channel<int16_t, 50, 1> baseIgnitionAdvance = (int16_t)0;
	/**
	 * @@GAUGE_NAME_ADJUSTED_TIMING@@
	deg
	 * offset 20
	 */
	scaled_channel<int16_t, 50, 1> correctedIgnitionAdvance = (int16_t)0;
	/**
	 * need 4 byte alignment
	units
	 * offset 22
	 */
	uint8_t alignmentFill_at_22[2];
	/**
	 * Ign: Dwell voltage correction
	 * offset 24
	 */
	float dwellVoltageCorrection = (float)0;
	/**
	 * Ign: Lua timing add
	deg
	 * offset 28
	 */
	float luaTimingAdd = (float)0;
	/**
	 * Ign: Lua timing mult
	deg
	 * offset 32
	 */
	float luaTimingMult = (float)0;
	/**
	Timing Cyl
	 * offset 36
	 */
	uint8_t perCylinderTiming[MAX_CYLINDER_COUNT];
};
static_assert(sizeof(ignition_state_s) == 48);

// end
// this section was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/algo/ignition_state.txt Fri May 05 01:35:23 UTC 2023
