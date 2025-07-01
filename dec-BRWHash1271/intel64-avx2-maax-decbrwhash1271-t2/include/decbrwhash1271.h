#ifndef __DECBRWHASH1271__
#define __DECBRWHASH1271__

#include "decbrwhash1271_basictypes.h"

#define ALIGN32 __attribute__ ((aligned(32)))

typedef uint64 ALIGN32 vec[4];

#define KEY_LENGTH 126
#define BLOCK_LENGTH 120
#define KEY_SIZE 16
#define BLOCK_SIZE 15
#define MAX_MSG_SIZE 4194304
#define MAX_MSG_LENGTH 33554432
#define MAX_KP_SIZE 85

void decbrwhash1271(uchar8 *,const uchar8 *,const vec *,const uint64,const uint64);

extern void decbrwhash1271_t2_avx2_maax(uint64 *,const uint64 *,const vec *,const uint64,const uint64,const uint64);
extern void decbrwhash1271_keypowers(vec *,const uint64,const uint64);

#endif
