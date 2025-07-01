#ifndef __DECBRWHASH1305ASM__
#define __DECBRWHASH1305ASM__

/* macros used in the main assembly */

#define brw4x_add_block1(x,y,a,b,c,d,e)	\
						\
	vmovdqa   64*x+0*32(%rsi),%ymm0;	\
	vmovdqa   64*x+1*32(%rsi),%ymm1;	\
						\
	vpunpcklqdq	%ymm1,%ymm0,%ymm2;	\
	vpunpckhqdq	%ymm1,%ymm0,%ymm3;	\
						\
	vpermq	  $216,%ymm2,%ymm2;		\
	vpermq	  $216,%ymm3,%ymm3;		\
						\
	vpand     vecmask26(%rip),%ymm2,a;	\
						\
	vpsrlq    $26,%ymm2,%ymm4;		\
	vpand     vecmask26(%rip),%ymm4,b;	\
						\
	vpsrlq    $52,%ymm2,%ymm4;		\
	vpsllq    $12,%ymm3,%ymm5;		\
	vpor      %ymm4,%ymm5,%ymm4;		\
	vpand     vecmask26(%rip),%ymm4,c;	\
						\
	vpsrlq    $14,%ymm3,%ymm4;		\
	vpand     vecmask26(%rip),%ymm4,d;	\
						\
	vpsrlq    $40,%ymm3,e;			\
						\
	vpaddq    160*y+0*32(%rdi),a,a;	\
	vpaddq    160*y+1*32(%rdi),b,b;	\
	vpaddq    160*y+2*32(%rdi),c,c;	\
	vpaddq    160*y+3*32(%rdi),d,d;	\
	vpaddq    160*y+4*32(%rdi),e,e;	\
	
#define brw4x_add_block2 brw4x_add_block1	\

#define brw4x_add_block3(x,a,b,c,d,e)		\
						\
	vmovdqa   64*x+0*32(%rsi),%ymm5;	\
	vmovdqa   64*x+1*32(%rsi),%ymm11;	\
						\
	vpunpcklqdq	%ymm11,%ymm5,%ymm12;	\
	vpunpckhqdq	%ymm11,%ymm5,%ymm13;	\
						\
	vpermq	  $216,%ymm12,%ymm12;		\
	vpermq	  $216,%ymm13,%ymm13;		\
						\
	vpand     vecmask26(%rip),%ymm12,%ymm6;\
						\
	vpsrlq    $26,%ymm12,%ymm14;		\
	vpand     vecmask26(%rip),%ymm14,%ymm7;\
						\
	vpsrlq    $52,%ymm12,%ymm14;		\
	vpsllq    $12,%ymm13,%ymm15;		\
	vpor      %ymm14,%ymm15,%ymm14;	\
	vpand     vecmask26(%rip),%ymm14,%ymm8;\
						\
	vpsrlq    $14,%ymm13,%ymm14;		\
	vpand     vecmask26(%rip),%ymm14,%ymm9;\
						\
	vpsrlq    $40,%ymm13,%ymm10;		\
						\
	vpaddq    %ymm6,a,a;			\
	vpaddq    %ymm7,b,b;			\
	vpaddq    %ymm8,c,c;			\
	vpaddq    %ymm9,d,d;			\
	vpaddq    %ymm10,e,e;			\
	
#define brw4x_init_zero(a,b,c,d,e)		\
						\
	vpxor     a,a,a;			\
	vpxor     b,b,b;			\
	vpxor     c,c,c;			\
	vpxor     d,d,d;			\
	vpxor     e,e,e;			\
	
#define brw4x_init_msg_block(x,a,b,c,d,e)	\
						\
	vmovdqa   64*x+0*32(%rsi),%ymm5;	\
	vmovdqa   64*x+1*32(%rsi),%ymm11;	\
						\
	vpunpcklqdq	%ymm11,%ymm5,%ymm12;	\
	vpunpckhqdq	%ymm11,%ymm5,%ymm13;	\
						\
	vpermq	  $216,%ymm12,%ymm12;		\
	vpermq	  $216,%ymm13,%ymm13;		\
						\
	vpand     vecmask26(%rip),%ymm12,a;	\
						\
	vpsrlq    $26,%ymm12,%ymm14;		\
	vpand     vecmask26(%rip),%ymm14,b;	\
						\
	vpsrlq    $52,%ymm12,%ymm14;		\
	vpsllq    $12,%ymm13,%ymm15;		\
	vpor      %ymm14,%ymm15,%ymm14;	\
	vpand     vecmask26(%rip),%ymm14,c;	\
						\
	vpsrlq    $14,%ymm13,%ymm14;		\
	vpand     vecmask26(%rip),%ymm14,d;	\
						\
	vpsrlq    $40,%ymm13,e;		\
	
#define brw4x_mul()				\
						\
	vpmuludq  %ymm11,%ymm6,%ymm0;		\
						\
	vpmuludq  %ymm11,%ymm7,%ymm1;		\
	vpmuludq  %ymm12,%ymm6,%ymm5;		\
	vpaddq    %ymm5,%ymm1,%ymm1;		\
						\
	vpmuludq  %ymm11,%ymm8,%ymm2;		\
	vpmuludq  %ymm12,%ymm7,%ymm5;		\
	vpaddq    %ymm5,%ymm2,%ymm2;		\
	vpmuludq  %ymm13,%ymm6,%ymm5;		\
	vpaddq    %ymm5,%ymm2,%ymm2;		\
						\
	vpmuludq  %ymm11,%ymm9,%ymm3;		\
	vpmuludq  %ymm12,%ymm8,%ymm5;		\
	vpaddq    %ymm5,%ymm3,%ymm3;		\
	vpmuludq  %ymm13,%ymm7,%ymm5;		\
	vpaddq    %ymm5,%ymm3,%ymm3;		\
	vpmuludq  %ymm14,%ymm6,%ymm5;		\
	vpaddq    %ymm5,%ymm3,%ymm3;		\
						\
	vpmuludq  %ymm11,%ymm10,%ymm4;	\
	vpmuludq  %ymm12,%ymm9,%ymm5;		\
	vpaddq    %ymm5,%ymm4,%ymm4;		\
	vpmuludq  %ymm13,%ymm8,%ymm5;		\
	vpaddq    %ymm5,%ymm4,%ymm4;		\
	vpmuludq  %ymm14,%ymm7,%ymm5;		\
	vpaddq    %ymm5,%ymm4,%ymm4;		\
	vpmuludq  %ymm15,%ymm6,%ymm5;		\
	vpaddq    %ymm5,%ymm4,%ymm4;		\
						\
	vpmuludq  vec5(%rip),%ymm12,%ymm11;	\
	vpmuludq  vec5(%rip),%ymm13,%ymm12;	\
	vpmuludq  vec5(%rip),%ymm14,%ymm13;	\
	vpmuludq  vec5(%rip),%ymm15,%ymm14;	\
						\
	vpmuludq  %ymm11,%ymm10,%ymm5;	\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
						\
	vpmuludq  %ymm12,%ymm9,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
	vpmuludq  %ymm12,%ymm10,%ymm5;	\
	vpaddq    %ymm5,%ymm1,%ymm1;		\
						\
	vpmuludq  %ymm13,%ymm8,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
	vpmuludq  %ymm13,%ymm9,%ymm5;		\
	vpaddq    %ymm5,%ymm1,%ymm1;		\
	vpmuludq  %ymm13,%ymm10,%ymm5;	\
	vpaddq    %ymm5,%ymm2,%ymm2;		\
						\
	vpmuludq  %ymm14,%ymm7,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
	vpmuludq  %ymm14,%ymm8,%ymm5;		\
	vpaddq    %ymm5,%ymm1,%ymm1;		\
	vpmuludq  %ymm14,%ymm9,%ymm5;		\
	vpaddq    %ymm5,%ymm2,%ymm2;		\
	vpmuludq  %ymm14,%ymm10,%ymm5;	\
	vpaddq    %ymm5,%ymm3,%ymm3;		\
	
#define brw4x_mul_tau(m,t)			\
						\
	vmovdqa   64*m+0*32(%rsi),%ymm0;	\
	vmovdqa   64*m+1*32(%rsi),%ymm1;	\
						\
	vpunpcklqdq	%ymm1,%ymm0,%ymm2;	\
	vpunpckhqdq	%ymm1,%ymm0,%ymm3;	\
						\
	vpermq	  $216,%ymm2,%ymm2;		\
	vpermq	  $216,%ymm3,%ymm3;		\
						\
	vpand     vecmask26(%rip),%ymm2,%ymm6;\
						\
	vpsrlq    $26,%ymm2,%ymm4;		\
	vpand     vecmask26(%rip),%ymm4,%ymm7;\
						\
	vpsrlq    $52,%ymm2,%ymm4;		\
	vpsllq    $12,%ymm3,%ymm5;		\
	vpor      %ymm4,%ymm5,%ymm4;		\
	vpand     vecmask26(%rip),%ymm4,%ymm8;\
						\
	vpsrlq    $14,%ymm3,%ymm4;		\
	vpand     vecmask26(%rip),%ymm4,%ymm9;\
						\
	vpsrlq    $40,%ymm3,%ymm10;		\
						\
	vmovdqa   160*t+0*32(%rdi),%ymm11;	\
	vmovdqa   160*t+1*32(%rdi),%ymm12;	\
	vmovdqa   160*t+2*32(%rdi),%ymm13;	\
	vmovdqa   160*t+3*32(%rdi),%ymm14;	\
	vmovdqa   160*t+4*32(%rdi),%ymm15;	\
						\
	vpmuludq  %ymm11,%ymm6,%ymm0;		\
						\
	vpmuludq  %ymm11,%ymm7,%ymm1;		\
	vpmuludq  %ymm12,%ymm6,%ymm5;		\
	vpaddq    %ymm5,%ymm1,%ymm1;		\
						\
	vpmuludq  %ymm11,%ymm8,%ymm2;		\
	vpmuludq  %ymm12,%ymm7,%ymm5;		\
	vpaddq    %ymm5,%ymm2,%ymm2;		\
	vpmuludq  %ymm13,%ymm6,%ymm5;		\
	vpaddq    %ymm5,%ymm2,%ymm2;		\
						\
	vpmuludq  %ymm11,%ymm9,%ymm3;		\
	vpmuludq  %ymm12,%ymm8,%ymm5;		\
	vpaddq    %ymm5,%ymm3,%ymm3;		\
	vpmuludq  %ymm13,%ymm7,%ymm5;		\
	vpaddq    %ymm5,%ymm3,%ymm3;		\
	vpmuludq  %ymm14,%ymm6,%ymm5;		\
	vpaddq    %ymm5,%ymm3,%ymm3;		\
						\
	vpmuludq  %ymm11,%ymm10,%ymm4;	\
	vpmuludq  %ymm12,%ymm9,%ymm5;		\
	vpaddq    %ymm5,%ymm4,%ymm4;		\
	vpmuludq  %ymm13,%ymm8,%ymm5;		\
	vpaddq    %ymm5,%ymm4,%ymm4;		\
	vpmuludq  %ymm14,%ymm7,%ymm5;		\
	vpaddq    %ymm5,%ymm4,%ymm4;		\
	vpmuludq  %ymm15,%ymm6,%ymm5;		\
	vpaddq    %ymm5,%ymm4,%ymm4;		\
						\
	vpmuludq  vec5(%rip),%ymm12,%ymm11;	\
	vpmuludq  vec5(%rip),%ymm13,%ymm12;	\
	vpmuludq  vec5(%rip),%ymm14,%ymm13;	\
	vpmuludq  vec5(%rip),%ymm15,%ymm14;	\
						\
	vpmuludq  %ymm11,%ymm10,%ymm5;	\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
						\
	vpmuludq  %ymm12,%ymm9,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
	vpmuludq  %ymm12,%ymm10,%ymm5;	\
	vpaddq    %ymm5,%ymm1,%ymm1;		\
						\
	vpmuludq  %ymm13,%ymm8,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
	vpmuludq  %ymm13,%ymm9,%ymm5;		\
	vpaddq    %ymm5,%ymm1,%ymm1;		\
	vpmuludq  %ymm13,%ymm10,%ymm5;	\
	vpaddq    %ymm5,%ymm2,%ymm2;		\
						\
	vpmuludq  %ymm14,%ymm7,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
	vpmuludq  %ymm14,%ymm8,%ymm5;		\
	vpaddq    %ymm5,%ymm1,%ymm1;		\
	vpmuludq  %ymm14,%ymm9,%ymm5;		\
	vpaddq    %ymm5,%ymm2,%ymm2;		\
	vpmuludq  %ymm14,%ymm10,%ymm5;	\
	vpaddq    %ymm5,%ymm3,%ymm3;		\
	
#define brw4x_reduce(a,b,c,d,e)		\
						\
	vpsrlq    $26,%ymm0,%ymm5;		\
	vpaddq    %ymm5,%ymm1,%ymm1;		\
	vpand     vecmask26(%rip),%ymm0,%ymm0;\
						\
	vpsrlq    $26,%ymm1,%ymm5;		\
	vpaddq    %ymm5,%ymm2,%ymm2;		\
	vpand     vecmask26(%rip),%ymm1,%ymm1;\
						\
	vpsrlq    $26,%ymm2,%ymm5;		\
	vpaddq    %ymm5,%ymm3,%ymm3;		\
	vpand     vecmask26(%rip),%ymm2,c;	\
						\
	vpsrlq    $26,%ymm3,%ymm5;		\
	vpaddq    %ymm5,%ymm4,%ymm4;		\
	vpand     vecmask26(%rip),%ymm3,d;	\
						\
	vpsrlq    $26,%ymm4,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
	vpsllq    $2,%ymm5,%ymm5;		\
	vpaddq    %ymm5,%ymm0,%ymm0;		\
	vpand     vecmask26(%rip),%ymm4,e;	\
						\
	vpsrlq    $26,%ymm0,%ymm5;		\
	vpaddq    %ymm5,%ymm1,b;		\
	vpand     vecmask26(%rip),%ymm0,a;	\
	
#define brw4x_stack_push()			\
						\
	vmovdqa   %ymm0,0*32(%r11);		\
	vmovdqa   %ymm1,1*32(%r11);		\
	vmovdqa   %ymm2,2*32(%r11);		\
	vmovdqa   %ymm3,3*32(%r11);		\
	vmovdqa   %ymm4,4*32(%r11);		\

#define brw4x_stack_add_top()			\
						\
	vpaddq    0*32(%r11),%ymm0,%ymm0;	\
	vpaddq    1*32(%r11),%ymm1,%ymm1;	\
	vpaddq    2*32(%r11),%ymm2,%ymm2;	\
	vpaddq    3*32(%r11),%ymm3,%ymm3;	\
	vpaddq    4*32(%r11),%ymm4,%ymm4;	\
	
#define pack5lto3l()				\
						\
	shlq    $26,%r9;			\
	orq     %r8,%r9;			\
	movq    %r10,%rbx;			\
	andq    pmask11(%rip),%rbx;		\
	shlq    $52,%rbx;			\
	orq     %rbx,%r9;			\
						\
	andq    pmask8(%rip),%r10;		\
	shrq    $12,%r10;			\
	movq    %r11,%rbx;			\
	andq    pmask1(%rip),%rbx;		\
	shlq    $14,%rbx;			\
	orq     %rbx,%r10;			\
	movq    %rax,%rbx;			\
	andq    pmask9(%rip),%rbx;		\
	shlq    $40,%rbx;			\
	orq     %rbx,%r10;			\
						\
	andq    pmask10(%rip),%rax;		\
	shrq    $24,%rax;			\
	
#define mul_taud(m,t)				\
						\
	xorq    %r15,%r15;			\
	movq    m+0(%rsp),%rdx;    		\
						\
	mulx    t+0(%rsp),%r8,%r12;		\
	mulx    t+8(%rsp),%rbx,%r13;		\
	adcx    %rbx,%r12;			\
	adcx    %r15,%r13;			\
						\
	mulx    t+16(%rsp),%rbx,%r14;		\
	adcx    %rbx,%r13;			\
	adcx    %r15,%r14;			\
						\
	xorq    %rax,%rax;			\
	movq    m+8(%rsp),%rdx;		\
	   					\
	mulx    t+0(%rsp),%r9,%rbp;		\
	adcx    %r12,%r9;			\
	adox    %rbp,%r13;			\
						\
	mulx    t+8(%rsp),%rbx,%rbp;		\
	adcx    %rbx,%r13;			\
	adox    %rbp,%r14;			\
	    					\
	mulx    t+16(%rsp),%rbx,%rbp;		\
	adcx    %rbx,%r14;			\
	adox    %rbp,%r15;			\
	adcx    %rax,%r15;			\
						\
	xorq    %rax,%rax;			\
	movq    m+16(%rsp),%rdx;		\
	    					\
	mulx    t+0(%rsp),%r10,%rbp;		\
	adcx    %r13,%r10;			\
	adox    %rbp,%r14;			\
	    					\
	mulx    t+8(%rsp),%r11,%rbp;		\
	adcx    %r14,%r11;			\
	adox    %rbp,%r15;			\
						\
	mulx    t+16(%rsp),%r12,%rbp;		\
	adcx    %r15,%r12;			\
	
#define mul_taudr(t)				\
						\
	xorq    %r15,%r15;			\
	movq    %r8,%rdx;    			\
						\
	mulx    t+0(%rsp),%r8,%r12;		\
	mulx    t+8(%rsp),%rbx,%r13;		\
	adcx    %rbx,%r12;			\
	adcx    %r15,%r13;			\
						\
	mulx    t+16(%rsp),%rbx,%r14;		\
	adcx    %rbx,%r13;			\
	adcx    %r15,%r14;			\
						\
	xorq    %rax,%rax;			\
	movq    %r9,%rdx;			\
	   					\
	mulx    t+0(%rsp),%r9,%rbp;		\
	adcx    %r12,%r9;			\
	adox    %rbp,%r13;			\
						\
	mulx    t+8(%rsp),%rbx,%rbp;		\
	adcx    %rbx,%r13;			\
	adox    %rbp,%r14;			\
	    					\
	mulx    t+16(%rsp),%rbx,%rbp;		\
	adcx    %rbx,%r14;			\
	adox    %rbp,%r15;			\
	adcx    %rax,%r15;			\
						\
	xorq    %rax,%rax;			\
	movq    %r10,%rdx;			\
	    					\
	mulx    t+0(%rsp),%r10,%rbp;		\
	adcx    %r13,%r10;			\
	adox    %rbp,%r14;			\
	    					\
	mulx    t+8(%rsp),%r11,%rbp;		\
	adcx    %r14,%r11;			\
	adox    %rbp,%r15;			\
						\
	mulx    t+16(%rsp),%r12,%rbp;		\
	adcx    %r15,%r12;			\
	
#define mul_taur(t)				\
						\
	xorq    %r15,%r15;			\
	movq    %r8,%rdx;    			\
						\
	mulx    t+0(%rsp),%r8,%r12;		\
	mulx    t+8(%rsp),%rbx,%r13;		\
	adcx    %rbx,%r12;			\
	adcx    %r15,%r13;			\
						\
	xorq    %r14,%r14;			\
	movq    %r9,%rdx;			\
	   					\
	mulx    t+0(%rsp),%r9,%rbp;		\
	adcx    %r12,%r9;			\
	adox    %rbp,%r13;			\
						\
	mulx    t+8(%rsp),%rbx,%rbp;		\
	adcx    %rbx,%r13;			\
	adox    %rbp,%r14;			\
	adcx    %r15,%r14;			\
	    					\
	xorq    %r12,%r12;			\
	movq    %r10,%rdx;			\
	    					\
	mulx    t+0(%rsp),%r10,%rbp;		\
	adcx    %r13,%r10;			\
	adox    %rbp,%r14;			\
	    					\
	mulx    t+8(%rsp),%r11,%rbp;		\
	adcx    %r14,%r11;			\
	adox    %rbp,%r12;			\
	adcx    %r15,%r12;			\
	
#define addmul_len_tau(m,t)			\
						\
	addq    m+0(%rsp),%r8;			\
	adcq    zero(%rip),%r9;		\
	adcq    zero(%rip),%r10;		\
						\
	xorq    %r15,%r15;			\
	movq    %r8,%rdx;    			\
						\
	mulx    t+0(%rsp),%r8,%r12;		\
	mulx    t+8(%rsp),%rbx,%r13;		\
	adcx    %rbx,%r12;			\
	adcx    %r15,%r13;			\
						\
	xorq    %r14,%r14;			\
	movq    %r9,%rdx;			\
	   					\
	mulx    t+0(%rsp),%r9,%rbp;		\
	adcx    %r12,%r9;			\
	adox    %rbp,%r13;			\
						\
	mulx    t+8(%rsp),%rbx,%rbp;		\
	adcx    %rbx,%r13;			\
	adox    %rbp,%r14;			\
	adcx    %r15,%r14;			\
	    					\
	xorq    %r12,%r12;			\
	movq    %r10,%rdx;			\
	    					\
	mulx    t+0(%rsp),%r10,%rbp;		\
	adcx    %r13,%r10;			\
	adox    %rbp,%r14;			\
	    					\
	mulx    t+8(%rsp),%r11,%rbp;		\
	adcx    %r14,%r11;			\
	adox    %rbp,%r12;			\
	adcx    %r15,%r12;			\
	
#define reduce_5limb(a,b,c,d)			\
						\
	movq    %r10,%r13;			\
	andq    mask2(%rip),%r10;		\
	andq    mask2c(%rip),%r13;		\
						\
	xorq	%rdx,%rdx;			\
	adcx    %r13,%r8;			\
	adcx    %r11,%r9;			\
	adcx    %r12,%r10;			\
						\
	shrd    $2,%r11,%r13;			\
	shrd    $2,%r12,%r11;			\
	shrq    $2,%r12;			\
						\
	addq    %r13,%r8;			\
	adcq    c,a;				\
	adcq    d,b;				\
	
#define reduce_3limb(a,b,c)			\
						\
	movq    c,%r13;			\
	andq    mask2(%rip),c;			\
	shrq    $2,%r13;			\
						\
	imul    $5,%r13,%r13;			\
	xorq	%rdx,%rdx;			\
	adcx    %r13,a;			\
	adcx    zero(%rip),b;			\
	adcx    zero(%rip),c;			\
	
#define add_msg_block(m)			\
						\
	addq    m+0(%rsp),%r8;			\
	adcq    m+8(%rsp),%r9;			\
	adcq    m+16(%rsp),%r10;		\

#define make_unique()				\
						\
	movq    %r8,%r11;			\
	movq    %r9,%r12;			\
	movq    %r10,%r13;			\
						\
	subq    p0(%rip),%r8;			\
	sbbq    p1(%rip),%r9;			\
	sbbq    p2(%rip),%r10;			\
						\
	movq    %r10,%r14;			\
	shlq    $62,%r14;			\
						\
	cmovc   %r11,%r8;			\
	cmovc   %r12,%r9;			\
	cmovc   %r13,%r10;			\


/* macros used for computing the key powers */

#define tau_square(t)				\
						\
	movq    t+0(%rsp),%rdx;		\
    	mulx    t+8(%rsp),%r9,%r10;		\
    	movq    $0,%r11;			\
    	shld    $1,%r10,%r11;			\
    	shld    $1,%r9,%r10;			\
    	shlq    $1,%r9;			\
  						\
      	xorq    %r12,%r12;			\
    	mulx    %rdx,%r8,%rbx;			\
    	adcx    %rbx,%r9;			\
						\
    	movq    t+8(%rsp),%rdx;		\
    	mulx    %rdx,%rax,%rbx;		\
    	adcx    %rax,%r10;			\
    	adcx    %rbx,%r11;			\
						\
	movq    %r10,%r13;			\
	andq    mask2(%rip),%r10;		\
	andq    mask2c(%rip),%r13;		\
						\
	addq    %r13,%r8;			\
	adcq    %r11,%r9;			\
	adcq    %r12,%r10;			\
						\
	shrd    $2,%r11,%r13;			\
	shrq    $2,%r11;			\
						\
	addq    %r13,%r8;			\
	adcq    %r11,%r9;			\
	adcq    %r12,%r10;			\
						\
	movq    %r10,%r13;			\
	andq    mask2(%rip),%r10;		\
	shrq    $2,%r13;			\
						\
	imul    $5,%r13,%r13;			\
	addq    %r13,%r8;			\
	adcq    $0,%r9;			\
	adcq    $0,%r10;			\

#define tau_squaren()				\
						\
	xorq    %r15,%r15;			\
    	movq    %r8,%rdx;			\
    						\
    	mulx    %r9,%r12,%r13;			\
						\
    	mulx    %r10,%rbx,%r14;		\
    	adcx    %rbx,%r13;			\
    	adcx    %r15,%r14;			\
						\
    	xorq    %rax,%rax;			\
    	movq    %r9,%rdx;			\
    						\
    	mulx    %r10,%rbx,%rdx;		\
    	adcx    %rbx,%r14;			\
    	adox    %rdx,%r15;			\
    	adcx    %rax,%r15;			\
    						\
    	shld    $1,%r14,%r15;			\
    	shld    $1,%r13,%r14;			\
    	shld    $1,%r12,%r13;			\
    	shlq    $1,%r12;			\
     						\
    	xorq    %rdx,%rdx;			\
    	movq    %r8,%rdx;			\
    	mulx    %rdx,%r11,%rbx;		\
    	adcx    %rbx,%r12;			\
						\
    	movq    %r9,%rdx;			\
    	mulx    %rdx,%r8,%r9;			\
    	adcx    %r13,%r8;			\
    	adcx    %r14,%r9;			\
						\
    	movq    %r10,%rdx;			\
    	mulx    %rdx,%rax,%rbx;		\
    	adcx    %rax,%r15;			\
						\
	movq    %r8,%r10;			\
	andq    mask2(%rip),%r10;		\
	andq    mask2c(%rip),%r8;		\
						\
	addq    %r8,%r11;			\
	adcq    %r9,%r12;			\
	adcq    %r15,%r10;			\
						\
	shrd    $2,%r9,%r8;			\
	shrd    $2,%r15,%r9;			\
	shrq    $2,%r15;			\
						\
	addq    %r11,%r8;			\
	adcq    %r12,%r9;			\
	adcq    %r15,%r10;			\
						\
	movq    %r10,%r15;			\
	andq    mask2(%rip),%r10;		\
	shrq    $2,%r15;			\
						\
	imul    $5,%r15,%r15;			\
	addq    %r15,%r8;			\
	adcq    $0,%r9;			\
	adcq    $0,%r10;			\
	
#endif
