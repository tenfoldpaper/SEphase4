
#ifndef NEWTESTCLASS_H
#define NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testWorld);
    CPPUNIT_TEST(testSet_width);
    CPPUNIT_TEST(testSet_length);
    CPPUNIT_TEST(testGet_width);
    CPPUNIT_TEST(testGet_length);
    CPPUNIT_TEST(testLoad);
    CPPUNIT_TEST(testGet_cell);
    CPPUNIT_TEST(testAdjacent);
    CPPUNIT_TEST(testOther_color);
    CPPUNIT_TEST(testRed_food);
    CPPUNIT_TEST(testBlack_food);
    CPPUNIT_TEST(testBlack_count);
    CPPUNIT_TEST(testRed_count);
    CPPUNIT_TEST(testWinner);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testWorld();
    void testSet_width();
    void testSet_length();
    void testGet_width();
    void testGet_length();
    void testLoad();
    void testGet_cell();
    void testAdjacent();
    void testOther_color();
    void testRed_food();
    void testBlack_food();
    void testBlack_count();
    void testRed_count();
    void testWinner();

};

#endif /* NEWTESTCLASS_H */

