CC= clang
CFLAGS= -Weverything -g -fcolor-diagnostics
CXX= clang++
CXXFLAGS= -Weverything -Wno-old-style-cast -g -fcolor-diagnostics
LDFLAGS=
LIBS= -lm

#CC= gcc
#CFLAGS= -Wall -Wextra -g
#CXX= g++
#CXXFLAGS= -Wall -Wextra -g
#LDFLAGS=
#LIBS= -lm

#CC= icc
#CFLAGS= -Wall -Wextra -g
#CC= icpc
#CXXFLAGS= -Wall -Wextra -g
#LDFLAGS=
#LIBS= -lm

CFLAGSSP= -DLINALG_SINGLE_PRECISION $(CFLAGS)
CFLAGSDP= $(CFLAGS)
CXXFLAGSSP= -DLINALG_SINGLE_PRECISION $(CXXFLAGS)
CXXFLAGSDP= $(CXXFLAGS)

ALL= testsp testdp emptysp emptydp emptycppsp emptycppdp

all: $(ALL)

testsp: test.c linalg.h
	$(CC) -o $@ $(CFLAGSSP) test.c $(LDFLAGS) $(LIBS)

testdp: test.c linalg.h
	$(CC) -o $@ $(CFLAGSDP) test.c $(LDFLAGS) $(LIBS)

emptysp: empty.c linalg.h
	$(CC) -o $@ $(CFLAGSSP) empty.c $(LDFLAGS) $(LIBS)

emptydp: empty.c linalg.h
	$(CC) -o $@ $(CFLAGSDP) empty.c $(LDFLAGS) $(LIBS)

emptycppsp: empty.cpp linalg.h
	$(CXX) -o $@ $(CXXFLAGSSP) empty.cpp $(LDFLAGS) $(LIBS)

emptycppdp: empty.cpp linalg.h
	$(CXX) -o $@ $(CXXFLAGSDP) empty.cpp $(LDFLAGS) $(LIBS)

check: $(ALL)
	@echo -n "testsp... " && ./testsp && echo success
	@echo -n "testdp... " && ./testdp && echo success
	@echo -n "emptysp... " && ./emptysp && echo success
	@echo -n "emptydp... " && ./emptydp && echo success
	@echo -n "emptycppsp... " && ./emptycppsp && echo success
	@echo -n "emptycppdp... " && ./emptycppdp && echo success

clean:
	rm -f $(ALL) gmon.out *.core

.PHONY: all check clean
