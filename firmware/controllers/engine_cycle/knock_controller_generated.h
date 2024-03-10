// this section was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/engine_cycle/knock_controller.txt Tue Apr 11 14:44:26 UTC 2023
// by class com.gerefi.output.CHeaderConsumer
// begin
#pragma once
#include "gerefi_types.h"
// start of knock_controller_s
struct knock_controller_s {
	/**
	 * Knock Degrees retarded
	 * larger number = more retard
	 * offset 0
	 */
	angle_t m_knockRetard = (angle_t)0;
	/**
	 * Knock Retard Threshold
	 * offset 4
	 */
	float m_knockThreshold = (float)0;
	/**
	 * Knock Count
	 * offset 8
	 */
	uint32_t m_knockCount = (uint32_t)0;
	/**
	 * offset 12
	 */
	float m_maximumRetard = (float)0;
};
static_assert(sizeof(knock_controller_s) == 16);

// end
// this section was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/engine_cycle/knock_controller.txt Tue Apr 11 14:44:26 UTC 2023
