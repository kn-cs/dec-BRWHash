/* assembly to compute decbrwhash1271 using t = 2  */

#include "decbrwhash1271_macro.h"
	
	.p2align 5
	.globl decbrwhash1271_t2_avx2_maax
	 
decbrwhash1271_t2_avx2_maax:

	movq 	%rsp,%r11
	andq    $-32,%rsp
	subq 	$2496,%rsp 

	movq 	%r11,0(%rsp)
	movq 	%r12,8(%rsp)
	movq 	%r13,16(%rsp)
	movq 	%r14,24(%rsp)
	movq 	%r15,32(%rsp)
	movq 	%rbx,40(%rsp)
	movq 	%rbp,48(%rsp)
	
	movq 	%rdi,56(%rsp)

	movq	0(%rdx),%r14
	movq	8(%rdx),%r15	
	movq	%r14,64(%rsp)
	movq	%r15,72(%rsp)

	movq 	%r8,80(%rsp)
			
	addq	$32,%rdx	
	movq 	%rdx,%r10
	
	xorq 	%rdx,%rdx
	movq	%rcx,%rax
	movq	$4,%rbx
	divq	%rbx
	
	movq 	%r9,%rcx	
	
	popcnt	%rax,%rbp

	cmpq	$0,%rax
	je	.L0

	leaq	96(%rsp),%r11

	movq	$1,%rbx
	
.LBRW:
	movq	%r10,%rdi

	brw4x_add_block1(0,0,%ymm6,%ymm7,%ymm8,%ymm9,%ymm10)
	brw4x_add_block2(1,1,%ymm11,%ymm12,%ymm13,%ymm14,%ymm15)
	brw4x_mul()
	brw4x_add_block3(2,%ymm0,%ymm1,%ymm2,%ymm3,%ymm4)
	
	tzcnt	%rbx,%r13	

	cmp	$0,%r13
	je	.LPUSH

	movq	$0,%r12	

.LPOP0:
	brw4x_stack_add_top()

	subq	$160,%r11
	
	incq	%r12
	cmpq	%r13,%r12
	jl	.LPOP0
	
.LPUSH:	
	brw4x_reduce(%ymm6,%ymm7,%ymm8,%ymm9,%ymm10)

	movq	$2,%rdi
	addq	%r13,%rdi
	imul	$160,%rdi,%rdi

	addq	%r10,%rdi
	
	brw4x_add_block1(3,0,%ymm11,%ymm12,%ymm13,%ymm14,%ymm15)
	
	brw4x_mul()	

	addq	$160,%r11
	
	brw4x_stack_push()
	
	addq	$240,%rsi

	addq    $1,%rbx
	cmpq    %rax,%rbx
	
	jle     .LBRW
	
.L0:
	cmpq	$0,%rdx
	je	.LR0

	cmpq	$1,%rdx
	je	.LR1

	cmpq	$2,%rdx
	je	.LR2
	
	cmpq	$3,%rdx
	je	.LR3

.LR0:
	brw4x_init_zero(%ymm0,%ymm1,%ymm2,%ymm3,%ymm4)
	
	jmp	.L1
.LR1:
	brw4x_init_msg_block(0,%ymm0,%ymm1,%ymm2,%ymm3,%ymm4)
	
	jmp	.L1

.LR2:
	movq	%r10,%rdi

	brw4x_mul_tau(0,0)		
	brw4x_add_block3(1,%ymm0,%ymm1,%ymm2,%ymm3,%ymm4)
	
	jmp	.L1

.LR3:
	movq	%r10,%rdi

	brw4x_add_block1(0,0,%ymm6,%ymm7,%ymm8,%ymm9,%ymm10)
	brw4x_add_block2(1,1,%ymm11,%ymm12,%ymm13,%ymm14,%ymm15)
	brw4x_mul()
	brw4x_add_block3(2,%ymm0,%ymm1,%ymm2,%ymm3,%ymm4)
	
.L1:
	cmpq	$0,%rbp
	je	.LF

	movq	$0,%r12

.LPOP1:
	brw4x_stack_add_top()
	
	subq	$160,%r11
	
	incq	%r12
	cmpq	%rbp,%r12
	jl	.LPOP1
	
.LF:	
	brw4x_reduce(%ymm0,%ymm1,%ymm2,%ymm3,%ymm4)

	vmovdqa   %ymm0,96(%rsp)
	vmovdqa   %ymm1,128(%rsp)
	vmovdqa   %ymm2,160(%rsp)
	vmovdqa   %ymm3,192(%rsp)
	vmovdqa   %ymm4,224(%rsp)

	movq 	%rcx,%rbp	
	
	movq	64(%rsp),%rax
	movq	72(%rsp),%rcx
	
	tau_squaren()
	
	cmpq	$1,%rbp
	je	.LD1
.LD0:
	tau_squaren()
	
	decq	%rbp
	cmpq	$1,%rbp
	jg	.LD0	

.LD1:
	movq	%rax,256(%rsp)
	movq	%rcx,264(%rsp)

	movq    96(%rsp),%r8
	movq    128(%rsp),%r9
	movq    160(%rsp),%r10
	movq    192(%rsp),%r11
	movq    224(%rsp),%rax

	pack5lto2l()	

	movq	%r9,272(%rsp)
	movq	%r10,280(%rsp)

	movq    104(%rsp),%r8
	movq    136(%rsp),%r9
	movq    168(%rsp),%r10
	movq    200(%rsp),%r11
	movq    232(%rsp),%rax	

	pack5lto2l()	

	movq	%r9,288(%rsp)
	movq	%r10,296(%rsp)

	movq    112(%rsp),%r8
	movq    144(%rsp),%r9
	movq    176(%rsp),%r10
	movq    208(%rsp),%r11
	movq    240(%rsp),%rax

	pack5lto2l()	

	movq	%r9,304(%rsp)
	movq	%r10,312(%rsp)

	movq    120(%rsp),%r8
	movq    152(%rsp),%r9
	movq    184(%rsp),%r10
	movq    216(%rsp),%r11
	movq    248(%rsp),%rax	
	
	pack5lto2l()	
	
	movq	%r9,320(%rsp)
	movq	%r10,328(%rsp)
	
	mul_taud(272,256)
	reduce_4limb()
	reduce_2limb()		
	add_msg_block(288)
	reduce_2limb()	
	mul_taudr(256)
	reduce_4limb()
	reduce_2limb()
	add_msg_block(304)
	reduce_2limb()		
	mul_taudr(256)
	reduce_4limb()
	reduce_2limb()
	add_msg_block(320)
	reduce_2limb()	
	
	mul_taudr(64)	
	reduce_4limb()
	reduce_2limb()
	addmul_len_tau(80,64)
	reduce_4limb()
	reduce_2limb()	
	make_unique()

	movq 	56(%rsp),%rdi
	andq	mask62(%rip),%r9
	movq    %r8,0(%rdi)
	movq    %r9,8(%rdi)

	movq 	0(%rsp),%r11
	movq 	8(%rsp),%r12
	movq 	16(%rsp),%r13
	movq 	24(%rsp),%r14
	movq 	32(%rsp),%r15
	movq 	40(%rsp),%rbx
	movq 	48(%rsp),%rbp

	movq 	%r11,%rsp

	ret
