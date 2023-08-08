#ifndef SUBSURFACE_TESTS_DIVE_PROXY_H
#define SUBSURFACE_TESTS_DIVE_PROXY_H

#include "../core/dive.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @brief exposes the internal implementation function of the same name in dive.c
pressure_t merge_pressures_proxy(pressure_t a, pressure_t sample_a, pressure_t b, pressure_t sample_b, bool take_min);

#ifdef __cplusplus
}
#endif

#endif
