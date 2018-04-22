

#ifndef NEWTESTCLASS2_H
#define NEWTESTCLASS2_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass2 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass2);

    CPPUNIT_TEST(testBug);
    CPPUNIT_TEST(testBug2);
    CPPUNIT_TEST(testStart_resting);
    CPPUNIT_TEST(testRested);
    CPPUNIT_TEST(testGet_progid);
    CPPUNIT_TEST(testGet_color);
    CPPUNIT_TEST(testGet_state);
    CPPUNIT_TEST(testSet_state);
    CPPUNIT_TEST(testGet_direction);
    CPPUNIT_TEST(testSet_direction);
    CPPUNIT_TEST(testGet_position);
    CPPUNIT_TEST(testSet_position);
    CPPUNIT_TEST(testGet_food);
    CPPUNIT_TEST(testSet_food);
    CPPUNIT_TEST(testIs_dead);
    CPPUNIT_TEST(testKill);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass2();
    virtual ~newtestclass2();
    void setUp();
    void tearDown();

private:
    void testBug();
    void testBug2();
    void testStart_resting();
    void testRested();
    void testGet_progid();
    void testGet_color();
    void testGet_state();
    void testSet_state();
    void testGet_direction();
    void testSet_direction();
    void testGet_position();
    void testSet_position();
    void testGet_food();
    void testSet_food();
    void testIs_dead();
    void testKill();

};

#endif /* NEWTESTCLASS2_H */

