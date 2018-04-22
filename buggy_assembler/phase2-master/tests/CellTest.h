

#ifndef NEWTESTCLASS1_H
#define NEWTESTCLASS1_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass1);

    CPPUNIT_TEST(testCell);
    CPPUNIT_TEST(testCell2);
    CPPUNIT_TEST(testGet_occupant);
    CPPUNIT_TEST(testSet_occupant);
    CPPUNIT_TEST(testGet_food);
    CPPUNIT_TEST(testSet_food);
    CPPUNIT_TEST(testGet_obstructed);
    CPPUNIT_TEST(testIs_black_home_area);
    CPPUNIT_TEST(testIs_red_home_area);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass1();
    virtual ~newtestclass1();
    void setUp();
    void tearDown();

private:
    void testCell();
    void testCell2();
    void testGet_occupant();
    void testSet_occupant();
    void testGet_food();
    void testSet_food();
    void testGet_obstructed();
    void testIs_black_home_area();
    void testIs_red_home_area();

};

#endif /* NEWTESTCLASS1_H */

