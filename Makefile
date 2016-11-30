CC= clang
CFLAGS= -Weverything -g -fcolor-diagnostics
LDFLAGS=
LIBS= -lm

#CC= gcc
#CFLAGS= -Wall -Wextra -g
#LDFLAGS=
#LIBS= -lm

#CC= icc
#CFLAGS= -Wall -Wextra -g
#LDFLAGS=
#LIBS= -lm

ALLSP_O= testsp.o
ALLDP_O= testdp.o

all: testsp testdp

testsp: $(ALLSP_O)
	$(CC) -o $@ $(CFLAGS) $(ALLSP_O) $(LDFLAGS) $(LIBS)

testdp: $(ALLDP_O)
	$(CC) -o $@ $(CFLAGS) $(ALLDP_O) $(LDFLAGS) $(LIBS)

testsp.o: test.c linalg.h
	$(CC) $(CFLAGS) -c -DLINALG_SINGLE_PRECISION -o testsp.o test.c

testdp.o: test.c linalg.h
	$(CC) $(CFLAGS) -c -o testdp.o test.c

check: testsp testdp
	@./testsp && echo success
	@./testdp && echo success

clean:
	rm -f $(ALLSP_O) $(ALLDP_O) testsp testdp gmon.out *.core

.PHONY: all check clean
