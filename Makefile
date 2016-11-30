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

CFLAGSSP= -DLINALG_SINGLE_PRECISION $(CFLAGS)
CFLAGSDP= $(CFLAGS)

all: testsp testdp emptysp emptydp

testsp: test.c linalg.h
	$(CC) -o $@ $(CFLAGSSP) test.c $(LDFLAGS) $(LIBS)

testdp: test.c linalg.h
	$(CC) -o $@ $(CFLAGSDP) test.c $(LDFLAGS) $(LIBS)

emptysp: empty.c linalg.h
	$(CC) -o $@ $(CFLAGSSP) empty.c $(LDFLAGS) $(LIBS)

emptydp: empty.c linalg.h
	$(CC) -o $@ $(CFLAGSDP) empty.c $(LDFLAGS) $(LIBS)

check: all
	@echo -n "testsp... " && ./testsp && echo success
	@echo -n "testdp... " && ./testdp && echo success
	@echo -n "emptysp... " && ./emptysp && echo success
	@echo -n "emptydp... " && ./emptydp && echo success

clean:
	rm -f testsp testdp emptysp emptydp gmon.out *.core

.PHONY: all check clean
