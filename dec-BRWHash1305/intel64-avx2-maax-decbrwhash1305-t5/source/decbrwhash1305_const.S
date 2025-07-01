/* assembly constants */

.data

.globl p0
.globl p1
.globl p2
.globl mask2
.globl mask2c
.globl zero

.globl pmask1
.globl pmask2
.globl pmask3
.globl pmask4
.globl pmask5
.globl pmask6
.globl pmask7

.globl pmask8
.globl pmask9
.globl pmask10
.globl pmask11

.globl vec5
.globl vecmask26

.p2align 5

p0		: .quad 0xFFFFFFFFFFFFFFFB
p1		: .quad 0xFFFFFFFFFFFFFFFF
p2		: .quad 0x0000000000000003
mask2		: .quad 0x0000000000000003
mask2c		: .quad 0xFFFFFFFFFFFFFFFC
zero		: .quad 0x0

pmask1		: .quad 0x0000000003FFFFFF
pmask2		: .quad 0x000FFFFFFC000000
pmask3		: .quad 0xFFF0000000000000
pmask4		: .quad 0x0000000000003FFF
pmask5		: .quad 0x000000FFFFFFC000
pmask6		: .quad 0xFFFFFF0000000000
pmask7		: .quad 0x000000000000000F

pmask8		: .quad 0x0000000003FFF000
pmask9		: .quad 0x0000000000FFFFFF
pmask10 	: .quad 0x000000000F000000
pmask11 	: .quad 0x0000000000000FFF

vec5		: .quad 5,5,5,5
vecmask26	: .quad 0x3FFFFFF,0x3FFFFFF,0x3FFFFFF,0x3FFFFFF
