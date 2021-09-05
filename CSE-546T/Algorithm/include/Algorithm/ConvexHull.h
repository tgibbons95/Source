#ifndef BB_CONVEX_HULL_H
#define BB_CONVEX_HULL_H

#include "BuildingBlocks/Structures.h"
#include <vector>

namespace BB
{
   namespace Dim2
   {
      namespace GrahamScan
      {
         void ConvexHull(const std::vector<Vertex>& vertices, std::vector<Vertex>& convexHull);
      }

      namespace GiftWrap
      {
         void ConvexHull(const std::vector<Vertex>& vertices, std::vector<Vertex>& convexHull);
      }

      namespace MergeHull
      {
         void ConvexHull(const std::vector<Vertex>& vertices, std::vector<Vertex>& convexHull);
      }
   }
}
#endif