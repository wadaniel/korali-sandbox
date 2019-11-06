BINARIES = main
KORALICXX=$(shell python3 -m korali.cxx --compiler)
KORALICFLAGS=`python3 -m korali.cxx --cflags`
KORALILIBS=`python3 -m korali.cxx --libs`
SUBDIRS=$(wildcard */.)

.SECONDARY:
.PHONY: all 
all: $(BINARIES)
	

$(BINARIES) : % : %.o model/mvf.o model/rnd.o model/model.o suite/testsuite.o suite/enginefactory.o
	$(KORALICXX) -o $@ $^ $(KORALILIBS)

model/%.o:
	$(MAKE) -C model all

suite/%.o:
	$(MAKE) -C suite all

%.o: %.cpp
	$(KORALICXX) -c $< $(KORALICFLAGS)

.PHONY: clean
clean:
	$(MAKE) -C model clean
	$(MAKE) -C suite clean
	$(RM) $(BINARIES) *.o
