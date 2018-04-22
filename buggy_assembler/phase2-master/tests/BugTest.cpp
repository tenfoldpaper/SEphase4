
#include "newtestclass2.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass2);

newtestclass2::newtestclass2() {
}

newtestclass2::~newtestclass2() {
}

void newtestclass2::setUp() {
}

void newtestclass2::tearDown() {
}

Bug::Bug();

void newtestclass2::testBug() {
    Bug bug();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

Bug::Bug(tcolor i_color, int i_progid, int i_resting);

void newtestclass2::testBug2() {
    tcolor i_color;
    int i_progid;
    int i_resting;
    Bug bug(i_color, i_progid, i_resting);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Bug::start_resting();

void newtestclass2::testStart_resting() {
    Bug bug;
    bug.start_resting();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

bool Bug::rested();

void newtestclass2::testRested() {
    Bug bug;
    bool result = bug.rested();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int Bug::get_progid();

void newtestclass2::testGet_progid() {
    Bug bug;
    int result = bug.get_progid();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

tcolor Bug::get_color();

void newtestclass2::testGet_color() {
    Bug bug;
    tcolor result = bug.get_color();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

tstate Bug::get_state();

void newtestclass2::testGet_state() {
    Bug bug;
    tstate result = bug.get_state();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Bug::set_state(tstate new_state);

void newtestclass2::testSet_state() {
    tstate new_state;
    Bug bug;
    bug.set_state(new_state);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

tdirection Bug::get_direction();

void newtestclass2::testGet_direction() {
    Bug bug;
    tdirection result = bug.get_direction();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Bug::set_direction(tdirection new_direction);

void newtestclass2::testSet_direction() {
    tdirection new_direction;
    Bug bug;
    bug.set_direction(new_direction);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

tposition Bug::get_position();

void newtestclass2::testGet_position() {
    Bug bug;
    tposition result = bug.get_position();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Bug::set_position(tposition new_position);

void newtestclass2::testSet_position() {
    tposition new_position;
    Bug bug;
    bug.set_position(new_position);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

bool Bug::get_food();

void newtestclass2::testGet_food() {
    Bug bug;
    bool result = bug.get_food();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Bug::set_food(bool new_food);

void newtestclass2::testSet_food() {
    bool new_food;
    Bug bug;
    bug.set_food(new_food);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

bool Bug::is_dead();

void newtestclass2::testIs_dead() {
    Bug bug;
    bool result = bug.is_dead();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Bug::kill();

void newtestclass2::testKill() {
    Bug bug;
    bug.kill();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

