/* assembly to compute decbrwhash1305 using t = 2  */

#include "decbrwhash1305_macro.h"
	
	.p2align 5
	.globl decbrwhash1305_t2_avx2_maax
	 
decbrwhash1305_t2_avx2_maax:

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
	
	/* h */
	movq 	%rdi,56(%rsp)
	/* key */	
	movq	0(%rdx),%r14
	movq	8(%rdx),%r15	
	movq	%r14,64(%rsp)
	movq	%r15,72(%rsp)
	/* msg-len */	
	movq 	%r8,80(%rsp)
		
	/* key powers */
	addq	$32,%rdx	
	movq 	%rdx,%r10
	
	/* store l/4 and l%4 */	
	xorq 	%rdx,%rdx
	movq	%rcx,%rax
	movq	$4,%rbx
	divq	%rbx
	
	/* d */
	movq 	%r9,%rcx	
	
	/* hamming weight of l/4 */
	popcnt	%rax,%rbp

	/* skip BRW loop if l/4 equals to 0 */
	cmpq	$0,%rax
	je	.L0

	/* initialize and store stack top address */
	leaq	96(%rsp),%r11

	/* initialize counter for .LBRW loop */
	movq	$1,%rbx
	
.LBRW:
	/* manage keypowers array using %rdi */
	movq	%r10,%rdi

	/* compute unreduced BRW over three message blocks */
	brw4x_add_block1(0,0,%ymm6,%ymm7,%ymm8,%ymm9,%ymm10)
	brw4x_add_block2(1,1,%ymm11,%ymm12,%ymm13,%ymm14,%ymm15)
	brw4x_mul()
	brw4x_add_block3(2,%ymm0,%ymm1,%ymm2,%ymm3,%ymm4)
	
	/* number of trailing zeroes in %rbx */
	tzcnt	%rbx,%r13	

	/* skip stack pop if number of trailing zeros is 0 */ 
	cmp	$0,%r13
	je	.LPUSH

	/* initialize counter for .LPOP0 loop */
	movq	$0,%r12	

.LPOP0:
	/* add stack top to the running unreduced field element */
	brw4x_stack_add_top()
	/* update stack top */
	subq	$160,%r11
	
	incq	%r12
	cmpq	%r13,%r12
	jl	.LPOP0
	
.LPUSH:	
	/* reduce */
	brw4x_reduce(%ymm6,%ymm7,%ymm8,%ymm9,%ymm10)

	/* access keypowers[t+k], first get the offset */
	movq	$2,%rdi
	addq	%r13,%rdi
	imul	$160,%rdi,%rdi
	/* then add the offset to the base address of keypowers array */
	addq	%r10,%rdi
	
	/* add the appropriate key power to the fourth message block */
	brw4x_add_block1(3,0,%ymm11,%ymm12,%ymm13,%ymm14,%ymm15)
	
	/* compute unreduced field multiplication */
	brw4x_mul()	

	/* update and store the stack top address */
	addq	$160,%r11
	
	/* push the unreduced field element to the stack */
	brw4x_stack_push()
	
	/* update message block address */
	addq	$256,%rsi

	addq    $1,%rbx
	cmpq    %rax,%rbx
	
	jle     .LBRW

.L0:
	/* number of remainder blocks is 0 */
	cmpq	$0,%rdx
	je	.LR0

	/* number of remainder blocks is 1 */
	cmpq	$1,%rdx
	je	.LR1

	/* number of remainder blocks is 2 */
	cmpq	$2,%rdx
	je	.LR2
	
	/* number of remainder blocks is 3 */
	cmpq	$3,%rdx
	je	.LR3

.LR0:
	/* initialize to zero */
	brw4x_init_zero(%ymm0,%ymm1,%ymm2,%ymm3,%ymm4)
	
	jmp	.L1
.LR1:
	/* initialize to the current message block */
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
	/* skip stack pop operations if hamming weight is 0 */
	cmpq	$0,%rbp
	je	.LF

	/* initialize counter for .LPOP1 loop */
	movq	$0,%r12

.LPOP1:
	/* add stack top to the running unreduced field element */
	brw4x_stack_add_top()
	
	/* update stack top address */
	subq	$160,%r11
	
	incq	%r12
	cmpq	%rbp,%r12
	jl	.LPOP1

.LF:	
	/* final reduction */
	brw4x_reduce(%ymm0,%ymm1,%ymm2,%ymm3,%ymm4)
	
	vmovdqa   %ymm0,96(%rsp)
	vmovdqa   %ymm1,128(%rsp)
	vmovdqa   %ymm2,160(%rsp)
	vmovdqa   %ymm3,192(%rsp)
	vmovdqa   %ymm4,224(%rsp)
	
	/* compute tau^d */
	tau_square(64)
	cmpq	$1,%rcx
	je	.LD1
.LD0:
	tau_squaren()
	
	decq	%rcx
	cmpq	$1,%rcx
	jg	.LD0	

.LD1:
	movq	%r8,256(%rsp)
	movq	%r9,264(%rsp)
	movq	%r10,272(%rsp)

	movq    96(%rsp),%r8
	movq    128(%rsp),%r9
	movq    160(%rsp),%r10
	movq    192(%rsp),%r11
	movq    224(%rsp),%rax

	pack5lto3l()
	
	movq	%r9,280(%rsp)
	movq	%r10,288(%rsp)
	movq	%rax,296(%rsp)
	
	movq    104(%rsp),%r8
	movq    136(%rsp),%r9
	movq    168(%rsp),%r10
	movq    200(%rsp),%r11
	movq    232(%rsp),%rax
	
	pack5lto3l()
	
	movq	%r9,304(%rsp)
	movq	%r10,312(%rsp)
	movq	%rax,320(%rsp)
	
	movq    112(%rsp),%r8
	movq    144(%rsp),%r9
	movq    176(%rsp),%r10
	movq    208(%rsp),%r11
	movq    240(%rsp),%rax
	
	pack5lto3l()
	
	movq	%r9,328(%rsp)
	movq	%r10,336(%rsp)
	movq	%rax,344(%rsp)

	movq    120(%rsp),%r8
	movq    152(%rsp),%r9
	movq    184(%rsp),%r10
	movq    216(%rsp),%r11
	movq    248(%rsp),%rax
	
	pack5lto3l()
	
	movq	%r9,352(%rsp)
	movq	%r10,360(%rsp)
	movq	%rax,368(%rsp)
	
	/* Q(x) = ((c0r + c1)r + c2)r + c3 */
	mul_taud(280,256)
	reduce_5limb(%r9,%r10,%r11,%r12)
	add_msg_block(304)
	mul_taudr(256)
	reduce_5limb(%r9,%r10,%r11,%r12)
	add_msg_block(328)
	mul_taudr(256)
	reduce_5limb(%r9,%r10,%r11,%r12)
	add_msg_block(352)
	
	/* P(x) */
	mul_taur(64)	
	reduce_5limb(%r9,%r10,%r11,%r12)
	addmul_len_tau(80,64)
	reduce_5limb(%r9,%r10,%r11,%r12)
	reduce_3limb(%r8,%r9,%r10)
	make_unique()

	/* store the final value */	
	movq 	56(%rsp),%rdi
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
