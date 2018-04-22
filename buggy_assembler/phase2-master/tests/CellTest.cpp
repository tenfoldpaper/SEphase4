

#include "newtestclass1.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass1);

newtestclass1::newtestclass1() {
}

newtestclass1::~newtestclass1() {
}

void newtestclass1::setUp() {
}

void newtestclass1::tearDown() {
}

Cell::Cell();

void newtestclass1::testCell() {
    Cell cell();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

Cell::Cell(char symb);

void newtestclass1::testCell2() {
    char symb;
    Cell cell(symb);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

Bug* Cell::get_occupant();

void newtestclass1::testGet_occupant() {
    Cell cell;
    Bug* result = cell.get_occupant();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Cell::set_occupant(Bug new_occupant);

void newtestclass1::testSet_occupant() {
    Bug new_occupant;
    Cell cell;
    cell.set_occupant(new_occupant);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int Cell::get_food();

void newtestclass1::testGet_food() {
    Cell cell;
    int result = cell.get_food();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Cell::set_food(int new_food);

void newtestclass1::testSet_food() {
    int new_food;
    Cell cell;
    cell.set_food(new_food);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

bool Cell::get_obstructed();

void newtestclass1::testGet_obstructed() {
    Cell cell;
    bool result = cell.get_obstructed();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

bool Cell::is_black_home_area();

void newtestclass1::testIs_black_home_area() {
    Cell cell;
    bool result = cell.is_black_home_area();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

bool Cell::is_red_home_area();

void newtestclass1::testIs_red_home_area() {
    Cell cell;
    bool result = cell.is_red_home_area();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

