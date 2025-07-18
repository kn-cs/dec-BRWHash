#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "halftime_basictypes.hpp"

#include <algorithm>
#include <random>
#include <vector>

using namespace std;

#include "cpucycles.h"

#define TIMINGS 524287 
static long long t[TIMINGS+1];

#include "halftime-hash.hpp"

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
  cycles = ((get_median()) / (double)(n));                                     \
  fprintf(fpout, "  %7.4lf", cycles)

void time_several(bool report_blocks_instead_of_bytes, const char *in_filename,
                  const char *out_filename) {
  FILE * fpin = fopen(in_filename, "r"); //"./test_files/halftime_speed_record_test_cases_direct_cmp.txt", "r");
  FILE * fpout = fopen(out_filename, "w"); // "./test_files/halftime_speed_records_direct_cmp.txt","w");
  if (fpin == NULL || fpout == NULL) {
    fprintf(stderr, "\nError opening file of messages!\n\n");
    exit(1);
  }
  vector<uint64_t> entropy(halftime_hash::kEntropyBytesNeeded / sizeof(uint64_t));
  generate(entropy.begin(), entropy.end(), mt19937_64{});
  uint64_t halftime_out[6];
  ssize_t n;
  size_t len;
  auto line = reinterpret_cast<char *>(calloc(16500,sizeof(char)));
  auto msg = reinterpret_cast<char *>(calloc(16500,sizeof(char)));
  char str[3];
  ALIGN32 char m[MAX_MSG_SIZE] = {0};

  while ((n = getline(&line, &len, fpin)) != -1) {
    int msglen;
    sscanf(line, "%s %d", msg, &msglen);
    int l = ((int)n - 1) / 32;
    size_t c = 0;
    const char * ptr = msg;
    for (int i = 1; i <= l; ++i) {
      for (int j = 31; j >= 1; j = j - 2) {
        str[0] = ptr[j - 1];
        str[1] = ptr[j];
        m[c++] = strtol(str, NULL, 16);
      }
      ptr = ptr + 32;
    }
    size_t vlen = ceil(l / 4.0);

    n = msglen % 8 == 0 ? msglen / 8 : msglen / 8 + 1;
    fprintf(fpout, "%4llu", (uint64)(report_blocks_instead_of_bytes ? l : n));

    double cycles;
    MEASURE(V3, 5);
    MEASURE(V3, 4);
    MEASURE(V4, 5);
    MEASURE(V4, 4);

    fprintf(fpout, "\n");
  }
  fclose(fpin);
  fclose(fpout);
  free(line);
  free(msg);
}

int main() {
  time_several(true, "./test_files/halftime_speed_record_test_cases.txt", "./test_files/halftime_speed_records.txt");
  time_several(false, "./test_files/halftime_speed_record_test_cases_direct_cmp.txt", "./test_files/halftime_speed_records_direct_cmp.txt");
	return 0;	
}
