// SPDX-License-Identifier: GPL-2.0
#include "utDiveC.h"
#include "dive_proxy.h"

QTEST_GUILESS_MAIN(TestDiveC)

void TestDiveC::initTestCase()
{
	// Nothing to do
}

void TestDiveC::cleanupTestCase()
{
	// Nothing to do
}

void TestDiveC::init()
{
	a.mbar = 0;
	a_samp.mbar = 0;
	b.mbar = 0;
	b_samp.mbar = 0;
}

void TestDiveC::cleanup()
{
	// Nothing to do
}

/// @brief Test merging pressure when all input values are 0
void TestDiveC::testMergePressure0()
{
	pressure_t p;

	// Test 1 - all data is empty
	p = merge_pressures_proxy(a, a_samp, b, b_samp, false);
	QCOMPARE(p.mbar, 0);
}

/// @brief Test merging pressure when A and B both have manual data
void TestDiveC::testMergePressureABManual()
{
	pressure_t p;

	a.mbar = 205;
	b.mbar = 84;

	// Test 1 - merge starting pressure.
	p = merge_pressures_proxy(a, a_samp, b, b_samp, false);
	QCOMPARE(p.mbar, 205);

	// Test 2 - merge ending pressure.
	p = merge_pressures_proxy(a, a_samp, b, b_samp, true);
	QCOMPARE(p.mbar, 84);

	// Make sure the tests work the other way around
	a.mbar = 84;
	b.mbar = 205;

	p = merge_pressures_proxy(a, a_samp, b, b_samp, false);
	QCOMPARE(p.mbar, 205);
	p = merge_pressures_proxy(a, a_samp, b, b_samp, true);
	QCOMPARE(p.mbar, 84);
}

/// @brief Test when one cylinder has manual data, and the other sample data.
void TestDiveC::testMergePressureASampleBManual()
{
	pressure_t p;

	a_samp.mbar = 205;
	b.mbar = 84;

	// Test 1 - merge starting pressure.
	p = merge_pressures_proxy(a, a_samp, b, b_samp, false);
	QCOMPARE(p.mbar, 205);

	// Test 2 - merge ending pressure.
	p = merge_pressures_proxy(a, a_samp, b, b_samp, true);
	QCOMPARE(p.mbar, 84);
}

/// @brief Test when both cylinders only have sample pressure data.
void TestDiveC::testMergePressureABSample()
{
	pressure_t p;

	// No manual data, but we have sample data
	// Since there is no manual data, we expect the merged
	// result to also be empty.
	a_samp.mbar = 205;
	b_samp.mbar = 84;
	p = merge_pressures_proxy(a, a_samp, b, b_samp, false);
	QCOMPARE(p.mbar, 0);

	p = merge_pressures_proxy(a, a_samp, b, b_samp, true);
	QCOMPARE(p.mbar, 0);
}
