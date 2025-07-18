#ifndef __DECBRWHASH1305_BASICTYPES__
#define __DECBRWHASH1305_BASICTYPES__

typedef unsigned char uchar8;
typedef unsigned long long uint64;

#define ALIGN32 __attribute__ ((aligned(32)))

typedef uint64 ALIGN32 vec[4];

#define KEY_LENGTH 128
#define BLOCK_LENGTH 128
#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define MAX_MSG_SIZE 4194304
#define MAX_MSG_LENGTH 33554432
#define MAX_KP_SIZE 85

#endif
