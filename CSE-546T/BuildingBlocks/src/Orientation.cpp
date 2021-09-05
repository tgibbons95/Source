#include "BuildingBlocks/Api.h"

#include "BuildingBlocks/Structures.h"
#include "BuildingBlocks/Enums.h"

namespace BB
{
   namespace Dim2
   {
      /// <summary>
      /// Source: https://www.geeksforgeeks.org/orientation-3-ordered-points/
      /// To find orientation of ordered triplet (p1, p2, p3).
      /// The function returns following values
      /// ORIENTATION_LINEAR --> p, q and r are colinear
      /// ORIENTATION_CW --> Clockwise
      /// ORIENTATION_CCW --> Counterclockwise 
      /// </summary>
      OrientationType Orientation(Vertex p1, Vertex p2, Vertex p3)
      {
         OrientationType ret = ORIENTATION_LINEAR;

         int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
         if (val > 0)
         {
            ret = ORIENTATION_CW;
         }
         else if (val < 0)
         {
            ret = ORIENTATION_CCW;
         }
         return ret;
      }
   };
};