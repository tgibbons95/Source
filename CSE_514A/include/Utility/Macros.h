#ifndef UTILITY_MACROS_H
#define UTILITY_MACROS_H

#define SAFE_DELETE(x) if (x) { delete x; x = nullptr; }
#define SAFE_DELETE_ARRAY(x) if (x) { delete[] x; x = nullptr; }

#define MIN_VALUE(x,y) ((x < y) ? x : y)
#define MAX_VALUE(x,y) ((x > y) ? x : y)
#define SWAP(x,y,t) {t = x; x = y; y = t;}
#endif