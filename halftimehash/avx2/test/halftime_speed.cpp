#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <algorithm>
#include <random>
#include <vector>

#include "cpucycles.h"

#include "halftime_basictypes.hpp"
#include "halftime-hash.hpp"

using namespace std;


#define TIMINGS 524287
static long long t[TIMINGS+1];

long long get_median() {

	long long median = 0;

	for (long long i = 0;i < TIMINGS;++i)
    		t[i] = t[i+1]-t[i];
  	for (long long j = 0;j < TIMINGS;++j) {
    		long long belowj = 0;
    		long long abovej = 0;
    		for (long long i = 0;i < TIMINGS;++i) if (t[i] < t[j]) ++belowj;
    		for (long long i = 0;i < TIMINGS;++i) if (t[i] > t[j]) ++abovej;
    		if (belowj*2 < TIMINGS && abovej*2 < TIMINGS) {
      			median = t[j];
      			break;
    		}
  	}
  	return median;
}

#define MEASURE(SIMD, SECURITY)                                                \
  for (long long i = 0; i <= TIMINGS; ++i) {                                   \
    t[i] = cpucycles();                                                        \
    halftime_hash::advanced::SIMD<SECURITY>(entropy.data(),                    \
                                            reinterpret_cast<const char *>(m), \
                                            msglen / CHAR_BIT, halftime_out);  \
  }                                                                            \
  printf("CPU-cycles per byte for HalftimeHash" #SECURITY " width " #SIMD      \
         " on a message of length %llu bits: %6.4lf\n\n",                      \
         msglen, ((get_median()) / (double)(n)))

int main(int argc, char **argv) {

	FILE *fp;
	uint64 msglen,l,n,r,vlen;
	vec kp[MAX_KP_SIZE]={0};
        uint64 *q;	
               
	int c,i,j;        

	uchar8 h[BLOCK_SIZE]={0};
	uchar8 k[KEY_SIZE];
	ALIGN32 uchar8 m[MAX_MSG_SIZE]={0};
	
	if (argc != 2) { 
		printf("\nMissing message length as input. Aborting!\n\n" );
		exit(1);
	}
	msglen = atoi(argv[1]);
	if (msglen < 0 || msglen > MAX_MSG_LENGTH ) {
		printf("\nInvalid message length. Aborting!\n\n" );
		exit(1);
	}
		
	if (msglen > 0) {
		
        	l = msglen / BLOCK_LENGTH; r = msglen % BLOCK_LENGTH;

     		if (r>0) l = l + 1;
   	
		q = (uint64 *)k; kp[0][0] = q[0]; kp[0][1] = q[1];
      		vlen = ceil(l/4.0); 
        	r = (uint64)(log2(vlen));
        }
        
     	printf("\nComputing CPU-cycles...\n\n");	
	n = msglen%8 == 0 ? msglen/8 : msglen/8+1;
	if (msglen == 0) n = 1;
	
        vector<uint64_t> entropy(halftime_hash::kEntropyBytesNeeded / sizeof(uint64_t));
        generate(entropy.begin(), entropy.end(), mt19937_64{});
        uint64_t halftime_out[6];
        MEASURE(V3,5);
        MEASURE(V3,4);
        MEASURE(V4,5);
        MEASURE(V4,4);

    	remove("./test_files/halftime_speed_c_output.txt");    	
    	remove("./test_files/halftime_speed_msgfile.txt");   	
		
	return 0;
}
