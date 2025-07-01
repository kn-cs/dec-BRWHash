/* assembly to compute the key powers */

#include "decbrwhash1305_macro.h"
		
	.p2align 5
	.globl decbrwhash1305_keypowers
		
decbrwhash1305_keypowers:

	movq 	%rsp,%r11
	andq    $-32,%rsp
	subq 	$72,%rsp

	movq 	%r11,0(%rsp)
	movq 	%r12,8(%rsp)
	movq 	%r13,16(%rsp)
	movq 	%r14,24(%rsp)
	movq 	%r15,32(%rsp)
	movq 	%rbx,40(%rsp)
	movq 	%rbp,48(%rsp)
	
	movq	%rdx,%rbp	

	movq    0(%rdi),%r14
	movq    8(%rdi),%r15
	movq	%r14,56(%rsp)
	movq	%r15,64(%rsp)	
	addq	$32,%rdi	
	
	/* pack and store 5-limb tau */
	movq    %r14,%r8
	andq    pmask1(%rip),%r8
	movq    %r8,0(%rdi)
	movq    %r8,8(%rdi)
	movq    %r8,16(%rdi)
	movq    %r8,24(%rdi)

	movq    %r14,%r8
	andq    pmask2(%rip),%r8
	shrq    $26,%r8
	movq    %r8,32(%rdi)
	movq    %r8,40(%rdi)
	movq    %r8,48(%rdi)
	movq    %r8,56(%rdi)

	movq    %r14,%r8
	andq    pmask3(%rip),%r8
	shrq    $52,%r8
	movq    %r15,%r9
	andq    pmask4(%rip),%r9
	shlq    $12,%r9
	orq     %r9,%r8
	movq    %r8,64(%rdi)
	movq    %r8,72(%rdi)
	movq    %r8,80(%rdi)
	movq    %r8,88(%rdi)

	movq    %r15,%r8
	andq    pmask5(%rip),%r8
	shrq    $14,%r8
	movq    %r8,96(%rdi)
	movq    %r8,104(%rdi)
	movq    %r8,112(%rdi)
	movq    %r8,120(%rdi)

	movq    %r15,%r8
	andq    pmask6(%rip),%r8
	shrq    $40,%r8
	movq    %r8,128(%rdi)
	movq    %r8,136(%rdi)
	movq    %r8,144(%rdi)
	movq    %r8,152(%rdi)
	
	/* tau^2 */
	tau_square(56)

	/* pack and store 5-limb tau^2 */
	addq	$160,%rdi
		
	movq    %r8,%r11
	andq    pmask1(%rip),%r11
	movq    %r11,0(%rdi)
	movq    %r11,8(%rdi)
	movq    %r11,16(%rdi)
	movq    %r11,24(%rdi)

	movq    %r8,%r11
	andq    pmask2(%rip),%r11
	shrq    $26,%r11
	movq    %r11,32(%rdi)
	movq    %r11,40(%rdi)
	movq    %r11,48(%rdi)
	movq    %r11,56(%rdi)

	movq    %r8,%r11
	andq    pmask3(%rip),%r11
	shrq    $52,%r11
	movq    %r9,%r12
	andq    pmask4(%rip),%r12
	shlq    $12,%r12
	orq     %r12,%r11
	movq    %r11,64(%rdi)
	movq    %r11,72(%rdi)
	movq    %r11,80(%rdi)
	movq    %r11,88(%rdi)

	movq    %r9,%r11
	andq    pmask5(%rip),%r11
	shrq    $14,%r11
	movq    %r11,96(%rdi)
	movq    %r11,104(%rdi)
	movq    %r11,112(%rdi)
	movq    %r11,120(%rdi)

	movq    %r9,%r11
	andq    pmask6(%rip),%r11
	shrq    $40,%r11
	movq    %r10,%r12
	andq    pmask7(%rip),%r12
	shlq    $24,%r12
	orq     %r12,%r11
	movq    %r11,128(%rdi)
	movq    %r11,136(%rdi)
	movq    %r11,144(%rdi)
	movq    %r11,152(%rdi)
	
	cmpq	$2,%rbp
	jl	.L1

	/* pack and store 5-limb tau^n, n>1 */
.L0:
	tau_squaren()

	addq	$160,%rdi
		
	movq    %r8,%r11
	andq    pmask1(%rip),%r11
	movq    %r11,0(%rdi)
	movq    %r11,8(%rdi)
	movq    %r11,16(%rdi)
	movq    %r11,24(%rdi)

	movq    %r8,%r11
	andq    pmask2(%rip),%r11
	shrq    $26,%r11
	movq    %r11,32(%rdi)
	movq    %r11,40(%rdi)
	movq    %r11,48(%rdi)
	movq    %r11,56(%rdi)

	movq    %r8,%r11
	andq    pmask3(%rip),%r11
	shrq    $52,%r11
	movq    %r9,%r12
	andq    pmask4(%rip),%r12
	shlq    $12,%r12
	orq     %r12,%r11
	movq    %r11,64(%rdi)
	movq    %r11,72(%rdi)
	movq    %r11,80(%rdi)
	movq    %r11,88(%rdi)

	movq    %r9,%r11
	andq    pmask5(%rip),%r11
	shrq    $14,%r11
	movq    %r11,96(%rdi)
	movq    %r11,104(%rdi)
	movq    %r11,112(%rdi)
	movq    %r11,120(%rdi)

	movq    %r9,%r11
	andq    pmask6(%rip),%r11
	shrq    $40,%r11
	movq    %r10,%r12
	andq    pmask7(%rip),%r12
	shlq    $24,%r12
	orq     %r12,%r11
	movq    %r11,128(%rdi)
	movq    %r11,136(%rdi)
	movq    %r11,144(%rdi)
	movq    %r11,152(%rdi)
	
	decq	%rsi
	cmpq	$1,%rsi
	jg	.L0

.L1:	
	movq 	0(%rsp),%r11
	movq 	8(%rsp),%r12
	movq 	16(%rsp),%r13
	movq 	24(%rsp),%r14
	movq 	32(%rsp),%r15
	movq 	40(%rsp),%rbx
	movq 	48(%rsp),%rbp

	movq 	%r11,%rsp

	ret
