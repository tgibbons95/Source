#ifndef BB_API_H
#define BB_API_H

#include "BuildingBlocks/Enums.h"
#include "BuildingBlocks/Structures.h"

namespace BB
{
   namespace Dim2
   {
      OrientationType Orientation(Vertex p1, Vertex p2, Vertex p3);
   }
}
#endif