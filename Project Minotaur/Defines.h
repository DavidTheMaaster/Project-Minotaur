#ifndef _DEFINES_H__
#define _DEFINES_H__

#include <stdio.h>

#define RELEASE( x ) \
    {\
    if( x != NULL )\
	    {\
      delete x;\
	  x = NULL;\
	    }\
    }

typedef unsigned int uint;
typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;

#define SHORT_STR	32
#define MID_STR		255
#define HUGE_STR	8192

#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

#endif // !__DEFINES_H__
