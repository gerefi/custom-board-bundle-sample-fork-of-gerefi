// this section was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/trigger/trigger_central.txt Wed Mar 29 00:38:14 UTC 2023
// by class com.gerefi.output.CHeaderConsumer
// begin
#pragma once
#include "gerefi_types.h"
#define HW_EVENT_TYPES 6
// start of trigger_central_s
struct trigger_central_s {
	/**
	 * Hardware events since boot
	 * offset 0
	 */
	uint32_t hwEventCounters[HW_EVENT_TYPES];
	/**
	 * Sync: total cams front counter
	 * offset 24
	 */
	uint32_t vvtCamCounter = (uint32_t)0;
	/**
	 * offset 28
	 */
	float mapVvt_MAP_AT_SPECIAL_POINT = (float)0;
	/**
	 * offset 32
	 */
	float mapVvt_MAP_AT_DIFF = (float)0;
	/**
	 * offset 36
	 */
	uint8_t mapVvt_MAP_AT_CYCLE_COUNT = (uint8_t)0;
	/**
	 * offset 37
	 */
	uint8_t mapVvt_map_peak = (uint8_t)0;
	/**
	 * need 4 byte alignment
	units
	 * offset 38
	 */
	uint8_t alignmentFill_at_38[2];
	/**
	 * Sync: Engine Phase
	deg
	 * offset 40
	 */
	float currentEngineDecodedPhase = (float)0;
	/**
	 * Sync: trigger angle error
	deg
	 * offset 44
	 */
	float triggerToothAngleError = (float)0;
	/**
	 * offset 48
	 */
	uint8_t triggerIgnoredToothCount = (uint8_t)0;
	/**
	 * need 4 byte alignment
	units
	 * offset 49
	 */
	uint8_t alignmentFill_at_49[3];
};
static_assert(sizeof(trigger_central_s) == 52);

// end
// this section was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/trigger/trigger_central.txt Wed Mar 29 00:38:14 UTC 2023
