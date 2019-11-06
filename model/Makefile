KORALICXX=$(shell python3 -m korali.cxx --compiler)                             
KORALICFLAGS=`python3 -m korali.cxx --cflags`                                   

all: mvf.o rnd.o model.o
	
%.o: %.cpp
	$(KORALICXX) -c $< $(KORALICFLAGS)

clean:; rm -rf $(TARGET) *.o *.a

.PHONY: clean all

