#ifndef BB_STRUCTURES_H
#define BB_STRUCTURES_H

namespace BB
{
   namespace Dim2
   {
      struct Vertex
      {
         float x = 0.0f;
         float y = 0.0f;
         Vertex();
         Vertex(float x, float y) : x(x), y(y) {};
         Vertex(const Vertex& rhs) : x(rhs.x), y(rhs.y) {};
         Vertex& operator=(const Vertex& rhs) { x = rhs.x; y = rhs.y; return *this; };
         bool operator==(const Vertex& rhs) const { return x == rhs.x && y == rhs.y; };
         bool operator!=(const Vertex& rhs) const { return !(*this == rhs); };
      };

      struct Edge
      {
         Vertex start;
         Vertex end;
         Edge();
         Edge(Vertex start, Vertex end) : start(start), end(end) {};
         Edge(const Edge& rhs) : start(rhs.start), end(rhs.end) {};
         Edge& operator=(const Edge& rhs) { start = rhs.start; end = rhs.end; return *this; };
         bool operator==(const Edge& rhs) const { return start == rhs.start && end == rhs.end; };
      };
   }
}
#endif