// this section was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/sensors//sent_state.txt Mon Feb 20 16:39:15 UTC 2023
// by class com.gerefi.output.CHeaderConsumer
// begin
#pragma once
#include "gerefi_types.h"
// start of sent_state_s
struct sent_state_s {
	/**
	 * "ETB: SENT value0"
	value
	 * offset 0
	 */
	uint16_t value0 = (uint16_t)0;
	/**
	 * "ETB: SENT value1"
	value
	 * offset 2
	 */
	uint16_t value1 = (uint16_t)0;
	/**
	 * "ETB: SENT error rate"
	ratio
	 * offset 4
	 */
	float errorRate = (float)0;
};
static_assert(sizeof(sent_state_s) == 8);

// end
// this section was generated automatically by gerefi tool ConfigDefinition.jar based on (unknown script) controllers/sensors//sent_state.txt Mon Feb 20 16:39:15 UTC 2023
