// CSE_546T
#include "BuildingBlocks/Api.h"

// Test
#include "gtest/gtest.h"

using namespace BB::Dim2;

namespace CSE_546T
{
   namespace Testing
   {
      TEST(BB_Orientation, CCW)
      {
         Vertex p1 = { 0, 0 };
         Vertex p2 = { 4, 4 };
         Vertex p3 = { 1, 2 };
         EXPECT_EQ(ORIENTATION_CCW, Orientation(p1, p2, p3));
      }

      TEST(BB_Orientation, CW)
      {
         Vertex p1 = { 0, 0 };
         Vertex p2 = { 4, 4 };
         Vertex p3 = { 1, 0 };
         EXPECT_EQ(ORIENTATION_CW, Orientation(p1, p2, p3));
      }

      TEST(BB_Orientation, Linear)
      {
         Vertex p1 = { 0, 0 };
         Vertex p2 = { 4, 4 };
         Vertex p3 = { 1, 1 };
         EXPECT_EQ(ORIENTATION_LINEAR, Orientation(p1, p2, p3));
      }
   }

}
