#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>
#include "Vector.h"

#define CHECK_VEC3(vec, xx, yy, zz)\
CHECK(vec.x == Approx(xx));\
CHECK(vec.y == Approx(yy));\
CHECK(vec.z == Approx(zz));

TEST_CASE("Vector", "[arithmetic]") {
 Vector v1(1, 2, 3), v2;

 SECTION("ctors") {
  CHECK_VEC3(v1, 1, 2, 3);
  CHECK_VEC3(v2, 0, 0, 0);
 }
}