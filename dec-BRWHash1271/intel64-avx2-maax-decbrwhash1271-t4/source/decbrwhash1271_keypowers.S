/* assembly to compute the key powers */

#include "decbrwhash1271_macro.h"
		
	.p2align 5
	.globl decbrwhash1271_keypowers
		
decbrwhash1271_keypowers:

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

	movq    0(%rdi),%rax
	movq    8(%rdi),%rcx
	movq	%rax,56(%rsp)
	movq	%rcx,64(%rsp)	
	addq	$32,%rdi	
	
	movq    %rax,%r8
	andq    pmask1(%rip),%r8
	movq    %r8,0(%rdi)
	movq    %r8,8(%rdi)
	movq    %r8,16(%rdi)
	movq    %r8,24(%rdi)

	movq    %rax,%r8
	andq    pmask2(%rip),%r8
	shrq    $26,%r8
	movq    %r8,32(%rdi)
	movq    %r8,40(%rdi)
	movq    %r8,48(%rdi)
	movq    %r8,56(%rdi)

	movq    %rax,%r8
	andq    pmask3(%rip),%r8
	shrq    $52,%r8
	movq    %rcx,%r9
	andq    pmask4(%rip),%r9
	shlq    $12,%r9
	orq     %r9,%r8
	movq    %r8,64(%rdi)
	movq    %r8,72(%rdi)
	movq    %r8,80(%rdi)
	movq    %r8,88(%rdi)

	movq    %rcx,%r8
	andq    pmask5(%rip),%r8
	shrq    $14,%r8
	movq    %r8,96(%rdi)
	movq    %r8,104(%rdi)
	movq    %r8,112(%rdi)
	movq    %r8,120(%rdi)

	movq    %rcx,%r8
	andq    pmask6(%rip),%r8
	shrq    $40,%r8
	movq    %r8,128(%rdi)
	movq    %r8,136(%rdi)
	movq    %r8,144(%rdi)
	movq    %r8,152(%rdi)

	tau_squaren()

	addq	$160,%rdi
		
	movq    %rax,%r8
	andq    pmask1(%rip),%r8
	movq    %r8,0(%rdi)
	movq    %r8,8(%rdi)
	movq    %r8,16(%rdi)
	movq    %r8,24(%rdi)

	movq    %rax,%r8
	andq    pmask2(%rip),%r8
	shrq    $26,%r8
	movq    %r8,32(%rdi)
	movq    %r8,40(%rdi)
	movq    %r8,48(%rdi)
	movq    %r8,56(%rdi)

	movq    %rax,%r8
	andq    pmask3(%rip),%r8
	shrq    $52,%r8
	movq    %rcx,%r9
	andq    pmask4(%rip),%r9
	shlq    $12,%r9
	orq     %r9,%r8
	movq    %r8,64(%rdi)
	movq    %r8,72(%rdi)
	movq    %r8,80(%rdi)
	movq    %r8,88(%rdi)

	movq    %rcx,%r8
	andq    pmask5(%rip),%r8
	shrq    $14,%r8
	movq    %r8,96(%rdi)
	movq    %r8,104(%rdi)
	movq    %r8,112(%rdi)
	movq    %r8,120(%rdi)

	movq    %rcx,%r8
	andq    pmask6(%rip),%r8
	shrq    $40,%r8
	movq    %r8,128(%rdi)
	movq    %r8,136(%rdi)
	movq    %r8,144(%rdi)
	movq    %r8,152(%rdi)
	
	cmpq	$2,%rbp
	jl	.L1

.L0:
	tau_squaren()

	addq	$160,%rdi
		
	movq    %rax,%r8
	andq    pmask1(%rip),%r8
	movq    %r8,0(%rdi)
	movq    %r8,8(%rdi)
	movq    %r8,16(%rdi)
	movq    %r8,24(%rdi)

	movq    %rax,%r8
	andq    pmask2(%rip),%r8
	shrq    $26,%r8
	movq    %r8,32(%rdi)
	movq    %r8,40(%rdi)
	movq    %r8,48(%rdi)
	movq    %r8,56(%rdi)

	movq    %rax,%r8
	andq    pmask3(%rip),%r8
	shrq    $52,%r8
	movq    %rcx,%r9
	andq    pmask4(%rip),%r9
	shlq    $12,%r9
	orq     %r9,%r8
	movq    %r8,64(%rdi)
	movq    %r8,72(%rdi)
	movq    %r8,80(%rdi)
	movq    %r8,88(%rdi)

	movq    %rcx,%r8
	andq    pmask5(%rip),%r8
	shrq    $14,%r8
	movq    %r8,96(%rdi)
	movq    %r8,104(%rdi)
	movq    %r8,112(%rdi)
	movq    %r8,120(%rdi)

	movq    %rcx,%r8
	andq    pmask6(%rip),%r8
	shrq    $40,%r8
	movq    %r8,128(%rdi)
	movq    %r8,136(%rdi)
	movq    %r8,144(%rdi)
	movq    %r8,152(%rdi)
	
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
