

#ifndef NEWTESTCLASS3_H
#define NEWTESTCLASS3_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass3 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass3);

    CPPUNIT_TEST(testMarker);
    CPPUNIT_TEST(testMarker2);
    CPPUNIT_TEST(testSet_bits);
    CPPUNIT_TEST(testGet_bits);
    CPPUNIT_TEST(testSet_marker);
    CPPUNIT_TEST(testClear_marker);
    CPPUNIT_TEST(testCheck_marker);
    CPPUNIT_TEST(testCheck_other_marker);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass3();
    virtual ~newtestclass3();
    void setUp();
    void tearDown();

private:
    void testMarker();
    void testMarker2();
    void testSet_bits();
    void testGet_bits();
    void testSet_marker();
    void testClear_marker();
    void testCheck_marker();
    void testCheck_other_marker();

};

#endif /* NEWTESTCLASS3_H */

