// SPDX-License-Identifier: GPL-2.0
#ifndef TESTDIVEC_H
#define TESTDIVEC_H

#include <QtTest>
#include "core/dive.h"

class TestDiveC : public QObject {
	Q_OBJECT
private slots:
	/// @brief called before first test case
	void initTestCase();
	/// @brief called after last test case
	void cleanupTestCase();

	/// @brief called before a test case
	void init();
	/// @brief called after a test case
	void cleanup();

	void testMergePressure0();
	void testMergePressureABManual();
	void testMergePressureASampleBManual();
	void testMergePressureABSample();

private:
	pressure_t a{0};
	pressure_t a_samp{0};
	pressure_t b{0};
	pressure_t b_samp{0};
};

#endif
