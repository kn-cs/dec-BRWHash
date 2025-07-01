#ifndef __DECBRWHASH1271ASM__
#define __DECBRWHASH1271ASM__

/* macros used in the main assembly */

#define brw4x_add_block1(x,y,a,b,c,d,e)		\
							\
	vmovdqu   60*x+0*30(%rsi),%ymm0;		\
	vmovdqu   60*x+1*30(%rsi),%ymm1;		\
							\
	vpand     vecmask240(%rip),%ymm0,%ymm2;	\
	vpsllq    $8,%ymm2,%ymm2;			\
	vpermq	  $148,%ymm0,%ymm3;			\
	vpsrlvq   sh56(%rip),%ymm3,%ymm3;		\
	vpand     vecmask56q1(%rip),%ymm3,%ymm3;	\
	vpor	  %ymm3,%ymm2,%ymm0;			\
							\
	vpand     vecmask240(%rip),%ymm1,%ymm2;	\
	vpsllq    $8,%ymm2,%ymm2;			\
	vpermq	  $148,%ymm1,%ymm3;			\
	vpsrlvq   sh56(%rip),%ymm3,%ymm3;		\
	vpand     vecmask56q1(%rip),%ymm3,%ymm3;	\
	vpor	  %ymm3,%ymm2,%ymm1;			\
							\
	vpunpcklqdq	%ymm1,%ymm0,%ymm2;		\
	vpunpckhqdq	%ymm1,%ymm0,%ymm3;		\
							\
	vpermq	  $216,%ymm2,%ymm2;			\
	vpermq	  $216,%ymm3,%ymm3;			\
							\
	vpand     vecmask26(%rip),%ymm2,a;		\
							\
	vpsrlq    $26,%ymm2,%ymm4;			\
	vpand     vecmask26(%rip),%ymm4,b;		\
							\
	vpsrlq    $52,%ymm2,%ymm4;			\
	vpsllq    $12,%ymm3,%ymm5;			\
	vpor      %ymm4,%ymm5,%ymm4;			\
	vpand     vecmask26(%rip),%ymm4,c;		\
							\
	vpsrlq    $14,%ymm3,%ymm4;			\
	vpand     vecmask26(%rip),%ymm4,d;		\
							\
	vpsrlq    $40,%ymm3,e;				\
							\
	vpaddq    160*y+0*32(%rdi),a,a;		\
	vpaddq    160*y+1*32(%rdi),b,b;		\
	vpaddq    160*y+2*32(%rdi),c,c;		\
	vpaddq    160*y+3*32(%rdi),d,d;		\
	vpaddq    160*y+4*32(%rdi),e,e;		\
	
#define brw4x_add_block2 brw4x_add_block1		\

#define brw4x_add_block3(x,a,b,c,d,e)			\
							\
	vmovdqu   60*x+0*30(%rsi),%ymm5;		\
	vmovdqu   60*x+1*30(%rsi),%ymm11;		\
							\
	vpand     vecmask240(%rip),%ymm5,%ymm12;	\
	vpsllq    $8,%ymm12,%ymm12;			\
	vpermq	  $148,%ymm5,%ymm13;			\
	vpsrlvq   sh56(%rip),%ymm13,%ymm13;		\
	vpand     vecmask56q1(%rip),%ymm13,%ymm13;	\
	vpor	  %ymm13,%ymm12,%ymm5;			\
							\
	vpand     vecmask240(%rip),%ymm11,%ymm12;	\
	vpsllq    $8,%ymm12,%ymm12;			\
	vpermq	  $148,%ymm11,%ymm13;			\
	vpsrlvq   sh56(%rip),%ymm13,%ymm13;		\
	vpand     vecmask56q1(%rip),%ymm13,%ymm13;	\
	vpor	  %ymm13,%ymm12,%ymm11;		\
							\
	vpunpcklqdq	%ymm11,%ymm5,%ymm12;		\
	vpunpckhqdq	%ymm11,%ymm5,%ymm13;		\
							\
	vpermq	  $216,%ymm12,%ymm12;			\
	vpermq	  $216,%ymm13,%ymm13;			\
							\
	vpand     vecmask26(%rip),%ymm12,%ymm6;	\
							\
	vpsrlq    $26,%ymm12,%ymm14;			\
	vpand     vecmask26(%rip),%ymm14,%ymm7;	\
							\
	vpsrlq    $52,%ymm12,%ymm14;			\
	vpsllq    $12,%ymm13,%ymm15;			\
	vpor      %ymm14,%ymm15,%ymm14;		\
	vpand     vecmask26(%rip),%ymm14,%ymm8;	\
							\
	vpsrlq    $14,%ymm13,%ymm14;			\
	vpand     vecmask26(%rip),%ymm14,%ymm9;	\
							\
	vpsrlq    $40,%ymm13,%ymm10;			\
							\
	vpaddq    %ymm6,a,a;				\
	vpaddq    %ymm7,b,b;				\
	vpaddq    %ymm8,c,c;				\
	vpaddq    %ymm9,d,d;				\
	vpaddq    %ymm10,e,e;				\
	
#define brw4x_init_zero(a,b,c,d,e)			\
							\
	vpxor     a,a,a;				\
	vpxor     b,b,b;				\
	vpxor     c,c,c;				\
	vpxor     d,d,d;				\
	vpxor     e,e,e;				\
	
#define brw4x_init_msg_block(x,a,b,c,d,e)		\
							\
	vmovdqu   60*x+0*30(%rsi),%ymm5;		\
	vmovdqu   60*x+1*30(%rsi),%ymm11;		\
							\
	vpand     vecmask240(%rip),%ymm5,%ymm12;	\
	vpsllq    $8,%ymm12,%ymm12;			\
	vpermq	  $148,%ymm5,%ymm13;			\
	vpsrlvq   sh56(%rip),%ymm13,%ymm13;		\
	vpand     vecmask56q1(%rip),%ymm13,%ymm13;	\
	vpor	  %ymm13,%ymm12,%ymm5;			\
							\
	vpand     vecmask240(%rip),%ymm11,%ymm12;	\
	vpsllq    $8,%ymm12,%ymm12;			\
	vpermq	  $148,%ymm11,%ymm13;			\
	vpsrlvq   sh56(%rip),%ymm13,%ymm13;		\
	vpand     vecmask56q1(%rip),%ymm13,%ymm13;	\
	vpor	  %ymm13,%ymm12,%ymm11;		\
							\
	vpunpcklqdq	%ymm11,%ymm5,%ymm12;		\
	vpunpckhqdq	%ymm11,%ymm5,%ymm13;		\
							\
	vpermq	  $216,%ymm12,%ymm12;			\
	vpermq	  $216,%ymm13,%ymm13;			\
							\
	vpand     vecmask26(%rip),%ymm12,a;		\
							\
	vpsrlq    $26,%ymm12,%ymm14;			\
	vpand     vecmask26(%rip),%ymm14,b;		\
							\
	vpsrlq    $52,%ymm12,%ymm14;			\
	vpsllq    $12,%ymm13,%ymm15;			\
	vpor      %ymm14,%ymm15,%ymm14;		\
	vpand     vecmask26(%rip),%ymm14,c;		\
							\
	vpsrlq    $14,%ymm13,%ymm14;			\
	vpand     vecmask26(%rip),%ymm14,d;		\
							\
	vpsrlq    $40,%ymm13,e;			\
	
#define brw4x_mul()					\
							\
	vpmuludq  %ymm11,%ymm6,%ymm0;			\
							\
	vpmuludq  %ymm11,%ymm7,%ymm1;			\
	vpmuludq  %ymm12,%ymm6,%ymm5;			\
	vpaddq    %ymm5,%ymm1,%ymm1;			\
							\
	vpmuludq  %ymm11,%ymm8,%ymm2;			\
	vpmuludq  %ymm12,%ymm7,%ymm5;			\
	vpaddq    %ymm5,%ymm2,%ymm2;			\
	vpmuludq  %ymm13,%ymm6,%ymm5;			\
	vpaddq    %ymm5,%ymm2,%ymm2;			\
							\
	vpmuludq  %ymm11,%ymm9,%ymm3;			\
	vpmuludq  %ymm12,%ymm8,%ymm5;			\
	vpaddq    %ymm5,%ymm3,%ymm3;			\
	vpmuludq  %ymm13,%ymm7,%ymm5;			\
	vpaddq    %ymm5,%ymm3,%ymm3;			\
	vpmuludq  %ymm14,%ymm6,%ymm5;			\
	vpaddq    %ymm5,%ymm3,%ymm3;			\
							\
	vpmuludq  %ymm11,%ymm10,%ymm4;		\
	vpmuludq  %ymm12,%ymm9,%ymm5;			\
	vpaddq    %ymm5,%ymm4,%ymm4;			\
	vpmuludq  %ymm13,%ymm8,%ymm5;			\
	vpaddq    %ymm5,%ymm4,%ymm4;			\
	vpmuludq  %ymm14,%ymm7,%ymm5;			\
	vpaddq    %ymm5,%ymm4,%ymm4;			\
	vpmuludq  %ymm15,%ymm6,%ymm5;			\
	vpaddq    %ymm5,%ymm4,%ymm4;			\
							\
	vpsllq    $3,%ymm12,%ymm11;			\
	vpsllq    $3,%ymm13,%ymm12;			\
	vpsllq    $3,%ymm14,%ymm13;			\
	vpsllq    $3,%ymm15,%ymm14;			\
							\
	vpmuludq  %ymm11,%ymm10,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;			\
							\
	vpmuludq  %ymm12,%ymm9,%ymm5;			\
	vpaddq    %ymm5,%ymm0,%ymm0;			\
	vpmuludq  %ymm12,%ymm10,%ymm5;		\
	vpaddq    %ymm5,%ymm1,%ymm1;			\
							\
	vpmuludq  %ymm13,%ymm8,%ymm5;			\
	vpaddq    %ymm5,%ymm0,%ymm0;			\
	vpmuludq  %ymm13,%ymm9,%ymm5;			\
	vpaddq    %ymm5,%ymm1,%ymm1;			\
	vpmuludq  %ymm13,%ymm10,%ymm5;		\
	vpaddq    %ymm5,%ymm2,%ymm2;			\
							\
	vpmuludq  %ymm14,%ymm7,%ymm5;			\
	vpaddq    %ymm5,%ymm0,%ymm0;			\
	vpmuludq  %ymm14,%ymm8,%ymm5;			\
	vpaddq    %ymm5,%ymm1,%ymm1;			\
	vpmuludq  %ymm14,%ymm9,%ymm5;			\
	vpaddq    %ymm5,%ymm2,%ymm2;			\
	vpmuludq  %ymm14,%ymm10,%ymm5;		\
	vpaddq    %ymm5,%ymm3,%ymm3;			\
	
#define brw4x_mul_tau(m,t)				\
							\
	vmovdqu   60*m+0*30(%rsi),%ymm0;		\
	vmovdqu   60*m+1*30(%rsi),%ymm1;		\
							\
	vpand     vecmask240(%rip),%ymm0,%ymm2;	\
	vpsllq    $8,%ymm2,%ymm2;			\
	vpermq	  $148,%ymm0,%ymm3;			\
	vpsrlvq   sh56(%rip),%ymm3,%ymm3;		\
	vpand     vecmask56q1(%rip),%ymm3,%ymm3;	\
	vpor	  %ymm3,%ymm2,%ymm0;			\
							\
	vpand     vecmask240(%rip),%ymm1,%ymm2;	\
	vpsllq    $8,%ymm2,%ymm2;			\
	vpermq	  $148,%ymm1,%ymm3;			\
	vpsrlvq   sh56(%rip),%ymm3,%ymm3;		\
	vpand     vecmask56q1(%rip),%ymm3,%ymm3;	\
	vpor	  %ymm3,%ymm2,%ymm1;			\
							\
	vpunpcklqdq	%ymm1,%ymm0,%ymm2;		\
	vpunpckhqdq	%ymm1,%ymm0,%ymm3;		\
							\
	vpermq	  $216,%ymm2,%ymm2;			\
	vpermq	  $216,%ymm3,%ymm3;			\
							\
	vpand     vecmask26(%rip),%ymm2,%ymm6;	\
							\
	vpsrlq    $26,%ymm2,%ymm4;			\
	vpand     vecmask26(%rip),%ymm4,%ymm7;	\
							\
	vpsrlq    $52,%ymm2,%ymm4;			\
	vpsllq    $12,%ymm3,%ymm5;			\
	vpor      %ymm4,%ymm5,%ymm4;			\
	vpand     vecmask26(%rip),%ymm4,%ymm8;	\
							\
	vpsrlq    $14,%ymm3,%ymm4;			\
	vpand     vecmask26(%rip),%ymm4,%ymm9;	\
							\
	vpsrlq    $40,%ymm3,%ymm10;			\
							\
	vmovdqa   160*t+0*32(%rdi),%ymm11;		\
	vmovdqa   160*t+1*32(%rdi),%ymm12;		\
	vmovdqa   160*t+2*32(%rdi),%ymm13;		\
	vmovdqa   160*t+3*32(%rdi),%ymm14;		\
	vmovdqa   160*t+4*32(%rdi),%ymm15;		\
							\
	vpmuludq  %ymm11,%ymm6,%ymm0;			\
							\
	vpmuludq  %ymm11,%ymm7,%ymm1;			\
	vpmuludq  %ymm12,%ymm6,%ymm5;			\
	vpaddq    %ymm5,%ymm1,%ymm1;			\
							\
	vpmuludq  %ymm11,%ymm8,%ymm2;			\
	vpmuludq  %ymm12,%ymm7,%ymm5;			\
	vpaddq    %ymm5,%ymm2,%ymm2;			\
	vpmuludq  %ymm13,%ymm6,%ymm5;			\
	vpaddq    %ymm5,%ymm2,%ymm2;			\
							\
	vpmuludq  %ymm11,%ymm9,%ymm3;			\
	vpmuludq  %ymm12,%ymm8,%ymm5;			\
	vpaddq    %ymm5,%ymm3,%ymm3;			\
	vpmuludq  %ymm13,%ymm7,%ymm5;			\
	vpaddq    %ymm5,%ymm3,%ymm3;			\
	vpmuludq  %ymm14,%ymm6,%ymm5;			\
	vpaddq    %ymm5,%ymm3,%ymm3;			\
							\
	vpmuludq  %ymm11,%ymm10,%ymm4;		\
	vpmuludq  %ymm12,%ymm9,%ymm5;			\
	vpaddq    %ymm5,%ymm4,%ymm4;			\
	vpmuludq  %ymm13,%ymm8,%ymm5;			\
	vpaddq    %ymm5,%ymm4,%ymm4;			\
	vpmuludq  %ymm14,%ymm7,%ymm5;			\
	vpaddq    %ymm5,%ymm4,%ymm4;			\
	vpmuludq  %ymm15,%ymm6,%ymm5;			\
	vpaddq    %ymm5,%ymm4,%ymm4;			\
							\
	vpsllq    $3,%ymm12,%ymm11;			\
	vpsllq    $3,%ymm13,%ymm12;			\
	vpsllq    $3,%ymm14,%ymm13;			\
	vpsllq    $3,%ymm15,%ymm14;			\
							\
	vpmuludq  %ymm11,%ymm10,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;			\
							\
	vpmuludq  %ymm12,%ymm9,%ymm5;			\
	vpaddq    %ymm5,%ymm0,%ymm0;			\
	vpmuludq  %ymm12,%ymm10,%ymm5;		\
	vpaddq    %ymm5,%ymm1,%ymm1;			\
							\
	vpmuludq  %ymm13,%ymm8,%ymm5;			\
	vpaddq    %ymm5,%ymm0,%ymm0;			\
	vpmuludq  %ymm13,%ymm9,%ymm5;			\
	vpaddq    %ymm5,%ymm1,%ymm1;			\
	vpmuludq  %ymm13,%ymm10,%ymm5;		\
	vpaddq    %ymm5,%ymm2,%ymm2;			\
							\
	vpmuludq  %ymm14,%ymm7,%ymm5;			\
	vpaddq    %ymm5,%ymm0,%ymm0;			\
	vpmuludq  %ymm14,%ymm8,%ymm5;			\
	vpaddq    %ymm5,%ymm1,%ymm1;			\
	vpmuludq  %ymm14,%ymm9,%ymm5;			\
	vpaddq    %ymm5,%ymm2,%ymm2;			\
	vpmuludq  %ymm14,%ymm10,%ymm5;		\
	vpaddq    %ymm5,%ymm3,%ymm3;			\
	
#define brw4x_reduce(a,b,c,d,e)			\
							\
	vpsrlq    $26,%ymm0,%ymm5;			\
	vpaddq    %ymm5,%ymm1,%ymm1;			\
	vpand     vecmask26(%rip),%ymm0,%ymm0;	\
							\
	vpsrlq    $26,%ymm1,%ymm5;			\
	vpaddq    %ymm5,%ymm2,%ymm2;			\
	vpand     vecmask26(%rip),%ymm1,%ymm1;	\
							\
	vpsrlq    $26,%ymm2,%ymm5;			\
	vpaddq    %ymm5,%ymm3,%ymm3;			\
	vpand     vecmask26(%rip),%ymm2,c;		\
							\
	vpsrlq    $26,%ymm3,%ymm5;			\
	vpaddq    %ymm5,%ymm4,%ymm4;			\
	vpand     vecmask26(%rip),%ymm3,d;		\
							\
	vpsrlq    $23,%ymm4,%ymm5;			\
	vpaddq    %ymm5,%ymm0,%ymm0;			\
	vpand     vecmask23(%rip),%ymm4,e;		\
							\
	vpsrlq    $26,%ymm0,%ymm5;			\
	vpaddq    %ymm5,%ymm1,b;			\
	vpand     vecmask26(%rip),%ymm0,a;		\
	
#define brw4x_stack_push()				\
							\
	vmovdqa   %ymm0,0*32(%r11);			\
	vmovdqa   %ymm1,1*32(%r11);			\
	vmovdqa   %ymm2,2*32(%r11);			\
	vmovdqa   %ymm3,3*32(%r11);			\
	vmovdqa   %ymm4,4*32(%r11);			\

#define brw4x_stack_add_top()				\
							\
	vpaddq    0*32(%r11),%ymm0,%ymm0;		\
	vpaddq    1*32(%r11),%ymm1,%ymm1;		\
	vpaddq    2*32(%r11),%ymm2,%ymm2;		\
	vpaddq    3*32(%r11),%ymm3,%ymm3;		\
	vpaddq    4*32(%r11),%ymm4,%ymm4;		\
	
#define pack5lto2l()					\
							\
	shlq    $26,%r9;				\
	orq     %r8,%r9;				\
	movq    %r10,%rbx;				\
	andq    pmask11(%rip),%rbx;			\
	shlq    $52,%rbx;				\
	orq     %rbx,%r9;				\
							\
	andq    pmask8(%rip),%r10;			\
	shrq    $12,%r10;				\
	andq    pmask1(%rip),%r11;			\
	shlq    $14,%r11;				\
	orq     %r11,%r10;				\
	andq    pmask9(%rip),%rax;			\
	shlq    $40,%rax;				\
	orq     %rax,%r10;				\
						
#define mul_taud(m,t)					\
							\
	xorq    %rdx,%rdx;				\
	movq    m+0(%rsp),%rdx;   			\
							\
	mulx    t+0(%rsp),%r8,%r9;   			\
	mulx    t+8(%rsp),%rbx,%r10;			\
	adcx    %rbx,%r9;				\
	adcx    zero(%rip),%r10;    			\
							\
	xorq    %r11,%r11;				\
	movq    m+8(%rsp),%rdx;			\
	   						\
	mulx    t+0(%rsp),%rbx,%rbp;			\
	adcx    %rbx,%r9;				\
	adox    %rbp,%r10;				\
	    						\
	mulx    t+8(%rsp),%rbx,%rbp;			\
	adcx    %rbx,%r10;				\
	adox    %rbp,%r11;				\
	adcx    zero(%rip),%r11;			\
	
#define mul_taudr(t)					\
							\
	xorq    %rdx,%rdx;				\
	movq    %r8,%rdx;   				\
							\
	mulx    t+0(%rsp),%r8,%r12;   		\
	mulx    t+8(%rsp),%rbx,%r10;			\
	adcx    %rbx,%r12;				\
	adcx    zero(%rip),%r10;    			\
							\
	xorq    %r11,%r11;				\
	movq    %r9,%rdx;				\
	   						\
	mulx    t+0(%rsp),%r9,%rbp;			\
	adcx    %r12,%r9;				\
	adox    %rbp,%r10;				\
	    						\
	mulx    t+8(%rsp),%rbx,%rbp;			\
	adcx    %rbx,%r10;				\
	adox    %rbp,%r11;				\
	adcx    zero(%rip),%r11;			\
	
#define addmul_len_tau(m,t)				\
							\
	addq    m+0(%rsp),%r8;				\
	adcq    zero(%rip),%r9;			\
							\
	xorq    %rdx,%rdx;				\
	movq    %r8,%rdx;   				\
							\
	mulx    t+0(%rsp),%r8,%r12;   		\
	mulx    t+8(%rsp),%rbx,%r10;			\
	adcx    %rbx,%r12;				\
	adcx    zero(%rip),%r10;    			\
							\
	xorq    %r11,%r11;				\
	movq    %r9,%rdx;				\
	   						\
	mulx    t+0(%rsp),%r9,%rbp;			\
	adcx    %r12,%r9;				\
	adox    %rbp,%r10;				\
	    						\
	mulx    t+8(%rsp),%rbx,%rbp;			\
	adcx    %rbx,%r10;				\
	adox    %rbp,%r11;				\
	adcx    zero(%rip),%r11;			\
	
#define reduce_5limb()					\
							\
	shld    $2,%r11,%r12;				\
							\
	andq	mask62(%rip),%r11;			\
	xorq    %rdx,%rdx;				\
	adcx    %r12,%r8;				\
	adcx    %rdx,%r9;				\
	adcx    %rdx,%r10;				\
	adcx    %rdx,%r11;				\
	
#define reduce_4limb()					\
							\
	shld    $1,%r10,%r11;				\
	shld    $1,%r9,%r10;				\
							\
	andq	mask63(%rip),%r9;			\
	xorq    %rdx,%rdx;				\
	adcx    %r10,%r8;				\
	adcx    %r11,%r9;				\

#define reduce_2limb()					\
							\
	movq    %r9,%r10;				\
	shrq    $63,%r10;				\
	andq	mask63(%rip),%r9;			\
	addq    %r10,%r8;				\
	adcq    zero(%rip),%r9;			\
	
#define add_msg_block(m)				\
							\
	addq    m+0(%rsp),%r8;				\
	adcq    m+8(%rsp),%r9;				\
	
#define make_unique()					\
							\
	movq    %r8,%r11;				\
	movq    %r9,%r12;				\
							\
	subq    p0(%rip),%r8;				\
	sbbq    p1(%rip),%r9;				\
							\
	movq    %r9,%r10;				\
	shlq    $1,%r10;				\
							\
	cmovc   %r11,%r8;				\
	cmovc   %r12,%r9;				\


/* macro used for computing the key powers */

#define tau_squaren()					\
							\
	movq    %rcx,%rdx;				\
	addq    %rdx,%rdx;				\
	mulx    %rax,%r9,%r10;				\
							\
	movq    %rax,%rdx;  				\
	mulx    %rdx,%rax,%rdx;			\
	addq    %rdx,%r9;				\
							\
	movq    %rcx,%rdx;				\
	mulx    %rdx,%rcx,%r11;			\
	adcq    %rcx,%r10;				\
	adcq    $0,%r11;				\
							\
	shld    $1,%r10,%r11;				\
	shld    $1,%r9,%r10;				\
							\
	andq	mask63(%rip),%r9;			\
	xorq	%rdx,%rdx;				\
	adcx    %r10,%rax;				\
	adcx    %r11,%r9;				\
							\
	movq    %r9,%rcx;				\
	andq	mask63(%rip),%rcx;			\
	shrq    $63,%r9;				\
	addq    %r9,%rax;				\
	adcq    $0,%rcx;				\
	
#endif
