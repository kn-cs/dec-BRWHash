INCDRS = -I../include/ -I../../root

SPEEDSRC = ./halftime_speed.cpp
SPEEDOBJ = ./halftime_speed.o

RECORDSRC = ./halftime_record_speed.cpp
RECORDOBJ = ./halftime_record_speed.o

EXE2    = halftime_speed
EXE3    = halftime_record_speed

CPPFLAGS = -march=native -mtune=native -O3 -funroll-loops -fomit-frame-pointer -fpermissive

CPP    = g++-10
CC     = gcc-10
LL     = g++-10

all:	$(EXE2) $(EXE3)

$(EXE2): $(SPEEDOBJ) $(OBJFLS)
	$(LL) -o $@ $(OBJFLS) $(SPEEDOBJ) -lm -lcpucycles

$(EXE3): $(RECORDOBJ) $(OBJFLS)
	$(LL) -o $@ $(OBJFLS) $(RECORDOBJ) -lm -lcpucycles

%.o: %.cpp
	$(CPP) $(INCDRS) $(CPPFLAGS) -o $@ -c $<

clean:
	-rm $(EXE2) $(EXE3)
	-rm $(SPEEDOBJ) $(RECORDOBJ)
