// CSE_546T
#include "Algorithm/ConvexHull.h"

// Test
#include "gtest/gtest.h"

// std
#include <algorithm>

using namespace BB::Dim2;

namespace CSE_546T
{
   namespace Testing
   {
      class Alg_ConvexHull : public ::testing::Test 
      {
         protected:
            virtual void SetUp() 
            {
               testVertices.clear();
               testVertices.push_back({ 45, 8 });
               testVertices.push_back({ 21, 50 });
               testVertices.push_back({ 22, 24 });
               testVertices.push_back({ 39, 6 });
               testVertices.push_back({ 34, 48 });
               testVertices.push_back({ 17, 16 });
               testVertices.push_back({ 6, 2 });
               testVertices.push_back({ 31, 26 });
               testVertices.push_back({ 3, 19 });
               testVertices.push_back({ 43, 23 });
               testVertices.push_back({ 10, 6 });
               testVertices.push_back({ 8, 11 });
               testVertices.push_back({ 31, 35 });
               testVertices.push_back({ 16, 38 });
               testVertices.push_back({ 35, 7 });
               testVertices.push_back({ 35, 16 });
               testVertices.push_back({ 4, 28 });
               testVertices.push_back({ 47, 0 });
               testVertices.push_back({ 30, 12 });
               testVertices.push_back({ 21, 48 });

               expectedConvexHull.clear();
               expectedConvexHull.push_back({ 3, 19 });
               expectedConvexHull.push_back({ 6, 2 });
               expectedConvexHull.push_back({ 47, 0 });
               expectedConvexHull.push_back({ 43, 23 });
               expectedConvexHull.push_back({ 34, 48 });
               expectedConvexHull.push_back({ 21, 50 });
               expectedConvexHull.push_back({ 4, 28 });
            };

            std::vector<Vertex> testVertices;
            std::vector<Vertex> expectedConvexHull;
      };

      TEST_F(Alg_ConvexHull, GrahamScan)
      {
         std::vector<Vertex> actualConvexHull;
         GrahamScan::ConvexHull(testVertices, actualConvexHull);
         ASSERT_EQ(this->expectedConvexHull.size(), actualConvexHull.size());
         for (int i = 0; i < actualConvexHull.size(); i++)
         {
            EXPECT_EQ(expectedConvexHull[i].x, actualConvexHull[i].x);
            EXPECT_EQ(expectedConvexHull[i].y, actualConvexHull[i].y);
         }
      }

      TEST_F(Alg_ConvexHull, GiftWrap)
      {
         std::vector<Vertex> actualConvexHull;
         GiftWrap::ConvexHull(testVertices, actualConvexHull);
         ASSERT_EQ(this->expectedConvexHull.size(), actualConvexHull.size());
         for (int i = 0; i < actualConvexHull.size(); i++)
         {
            EXPECT_EQ(expectedConvexHull[i].x, actualConvexHull[i].x);
            EXPECT_EQ(expectedConvexHull[i].y, actualConvexHull[i].y);
         }
      }

      TEST_F(Alg_ConvexHull, MergeHull)
      {
         std::vector<Vertex> actualConvexHull;
         // Sort helper expression
         static auto sortByXThenY = [](const Vertex& lhs, const Vertex& rhs)
         {
            return (lhs.x < rhs.x) || (lhs.x == rhs.x && lhs.y < rhs.y);
         };

         // Sort Vertices Left to Right
         std::sort(testVertices.begin(), testVertices.end(), sortByXThenY);

         MergeHull::ConvexHull(testVertices, actualConvexHull);
         ASSERT_EQ(this->expectedConvexHull.size(), actualConvexHull.size());
         for (int i = 0; i < actualConvexHull.size(); i++)
         {
            EXPECT_EQ(expectedConvexHull[i].x, actualConvexHull[i].x);
            EXPECT_EQ(expectedConvexHull[i].y, actualConvexHull[i].y);
         }
      }
   }
}
