INCDRS = -I../include/

SRCFLS = ../source/decbrwhash1305_const.S 		\
	 ../source/decbrwhash1305_t5_avx2_maax.S	\
	 ../source/decbrwhash1305_keypowers.S		\
	 ../source/decbrwhash1305_input.c 		\
	 ../source/decbrwhash1305.c
         
OBJFLS = ../source/decbrwhash1305_const.o 		\
	 ../source/decbrwhash1305_t5_avx2_maax.o	\
	 ../source/decbrwhash1305_keypowers.o		\
	 ../source/decbrwhash1305_input.o 		\
	 ../source/decbrwhash1305.o

TESTSRC = ./decbrwhash1305_t5_verify.c
TESTOBJ = ./decbrwhash1305_t5_verify.o

SPEEDSRC = ./decbrwhash1305_t5_speed.c
SPEEDOBJ = ./decbrwhash1305_t5_speed.o

RECORDSRC = ./decbrwhash1305_t5_record_speed.c
RECORDOBJ = ./decbrwhash1305_t5_record_speed.o
	  
EXE1    = decbrwhash1305_t5_verify
EXE2    = decbrwhash1305_t5_speed
EXE3    = decbrwhash1305_t5_record_speed

CFLAGS = -march=native -mtune=native -mavx2 -m64 -O3 -funroll-loops -fomit-frame-pointer

CC     = gcc-10
LL     = gcc-10

all:	$(EXE1) $(EXE2) $(EXE3)

$(EXE1): $(TESTOBJ) $(OBJFLS)
	$(LL) -o $@ $(OBJFLS) $(TESTOBJ) -lm -lcpucycles
	
$(EXE2): $(SPEEDOBJ) $(OBJFLS)
	$(LL) -o $@ $(OBJFLS) $(SPEEDOBJ) -lm -lcpucycles
	
$(EXE3): $(RECORDOBJ) $(OBJFLS)
	$(LL) -o $@ $(OBJFLS) $(RECORDOBJ) -lm -lcpucycles

.c.o:
	$(CC) $(INCDRS) $(CFLAGS) -o $@ -c $<

clean:
	-rm $(EXE1) $(EXE2) $(EXE3)
	-rm $(TESTOBJ) $(SPEEDOBJ) $(RECORDOBJ)
	-rm $(OBJFLS)
