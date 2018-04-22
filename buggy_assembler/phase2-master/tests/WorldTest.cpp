

#include "newtestclass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

World::World();

void newtestclass::testWorld() {
    World world();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void World::set_width(int w);

void newtestclass::testSet_width() {
    int w;
    World world;
    world.set_width(w);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void World::set_length(int len);

void newtestclass::testSet_length() {
    int len;
    World world;
    world.set_length(len);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int World::get_width();

void newtestclass::testGet_width() {
    World world;
    int result = world.get_width();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int World::get_length();

void newtestclass::testGet_length() {
    World world;
    int result = world.get_length();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void World::load(string filename);

void newtestclass::testLoad() {
    string filename;
    World world;
    world.load(filename);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

Cell World::get_cell(tposition pos);

void newtestclass::testGet_cell() {
    tposition pos;
    World world;
    Cell result = world.get_cell(pos);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

tposition World::adjacent(tdirection dir, tposition pos);

void newtestclass::testAdjacent() {
    tdirection dir;
    tposition pos;
    World world;
    tposition result = world.adjacent(dir, pos);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

tcolor World::other_color(tcolor col);

void newtestclass::testOther_color() {
    tcolor col;
    World world;
    tcolor result = world.other_color(col);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int World::red_food();

void newtestclass::testRed_food() {
    World world;
    int result = world.red_food();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int World::black_food();

void newtestclass::testBlack_food() {
    World world;
    int result = world.black_food();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int World::black_count();

void newtestclass::testBlack_count() {
    World world;
    int result = world.black_count();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int World::red_count();

void newtestclass::testRed_count() {
    World world;
    int result = world.red_count();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

tcolor World::winner();

void newtestclass::testWinner() {
    World world;
    tcolor result = world.winner();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

