## Vectorised Hashing Based on Bernstein-Rabin-Winograd Polynomials over Prime Order Fields

This is the source code repository of the work [Vectorised Hashing Based on Bernstein-Rabin-Winograd Polynomials over Prime Order Fields](https://eprint.iacr.org/2025/1262), authored by [Kaushik Nath](kaushik.nath@yahoo.in) & [Palash Sarkar](palash@isical.ac.in) of [Indian Statistical Institute, Kolkata, India](https://www.isical.ac.in). The paper is also available at https://arxiv.org/abs/2507.06490.

This work focuses on developing vectorised (avx2) assembly implementations of hash functions based on BRW polynomials over the primes 2^{127}-1 and 2^{130}-5.

To report a bug or make a comment regarding the implementations please drop a mail to: [Kaushik Nath](kaushik.nath@yahoo.in).

---

### Compilation and execution of programs 
    
* Please compile the ```makefile``` in the **test** directory and execute the generated executable file. 
* CPU cycles have been recorded using the microlibrary “libcpucycles” (see https://cpucycles.cr.yp.to/) through the amd64-pmc counter (see https://cpucycles.cr.yp.to/counters.html) which requires a 64-bit Intel/AMD platform and Linux perf event interface. The amd64-pmc counter accesses a cycle counter through RDPMC and requires /proc/sys/kernel/perf_event_paranoid to be at most 2 for user-level RDPMC access. This counter runs at clock frequency of the CPU core. Additionally, turbo boost and hyperthreading options were turned off while recording the timings.
	
