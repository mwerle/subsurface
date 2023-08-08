#include "../core/dive.c"
#include "dive_proxy.h"

pressure_t merge_pressures_proxy(pressure_t a, pressure_t sample_a, pressure_t b, pressure_t sample_b, bool take_min) {
	return merge_pressures(a, sample_a, b, sample_b, take_min);
}
