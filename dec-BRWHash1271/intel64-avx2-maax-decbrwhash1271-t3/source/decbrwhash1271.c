#include <math.h>
#include "decbrwhash1271.h"

void decbrwhash1271(uchar8 *h,const uchar8 *m,const vec *k,const uint64 b,const uint64 l) {

	uint64 *p;
	double d;
	
	if (l == 0) {
	
		p = (uint64 *)h;
		*p = 0; *(p+1) = 0;
		return;
	}
	
	d = log2(b) + 1;
	
	/* 
	 *  h : output
	 *  m : input message
	 *  k : key powers
	 *  b : number of blocks
	 *  l : bitsize of the message
	 *  d : parameter for last poly computation
	 */
	decbrwhash1271_t3_avx2_maax((uint64 *)h,(uint64 *)m,k,b,l,(uint64)d);
}
