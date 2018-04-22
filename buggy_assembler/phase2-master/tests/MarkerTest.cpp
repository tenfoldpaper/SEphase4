
#include "newtestclass3.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass3);

newtestclass3::newtestclass3() {
}

newtestclass3::~newtestclass3() {
}

void newtestclass3::setUp() {
}

void newtestclass3::tearDown() {
}

Marker::Marker();

void newtestclass3::testMarker() {
    Marker marker();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

Marker::Marker(const Marker& orig);

void newtestclass3::testMarker2() {
    const Marker& orig;
    Marker marker(orig);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Marker::set_bits(int bit);

void newtestclass3::testSet_bits() {
    int bit;
    Marker marker;
    marker.set_bits(bit);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int Marker::get_bits();

void newtestclass3::testGet_bits() {
    Marker marker;
    int result = marker.get_bits();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Marker::set_marker(tmark mark, tcolor col);

void newtestclass3::testSet_marker() {
    tmark mark;
    tcolor col;
    Marker marker;
    marker.set_marker(mark, col);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Marker::clear_marker(tmark mark, tcolor col);

void newtestclass3::testClear_marker() {
    tmark mark;
    tcolor col;
    Marker marker;
    marker.clear_marker(mark, col);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

bool Marker::check_marker(tmark mark, tcolor col);

void newtestclass3::testCheck_marker() {
    tmark mark;
    tcolor col;
    Marker marker;
    bool result = marker.check_marker(mark, col);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

bool Marker::check_other_marker(tcolor col);

void newtestclass3::testCheck_other_marker() {
    tcolor col;
    Marker marker;
    bool result = marker.check_other_marker(col);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

