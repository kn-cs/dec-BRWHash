#ifndef __DECBRWHASH1305__
#define __DECBRWHASH1305__

#include "decbrwhash1305_basictypes.h"

#define ALIGN32 __attribute__ ((aligned(32)))

typedef uint64 ALIGN32 vec[4];

#define KEY_LENGTH 128
#define BLOCK_LENGTH 128
#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define MAX_MSG_SIZE 4194304
#define MAX_MSG_LENGTH 33554432
#define MAX_KP_SIZE 85

void decbrwhash1305(uchar8 *,const uchar8 *,const vec *,const uint64,const uint64);

extern void decbrwhash1305_t3_avx2_maax(uint64 *,const uint64 *,const vec *,const uint64,const uint64,const uint64);
extern void decbrwhash1305_keypowers(vec *,const uint64,const uint64);

#endif
