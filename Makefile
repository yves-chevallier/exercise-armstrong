CSRCS=$(wildcard *.c)
COBJS=$(patsubst %.c,%.o,$(CSRCS))
EXEC=$(patsubst %.c,%, $(word 1, $(CSRCS)))

CFLAGS=-std=c99 -g -Wall -pedantic
LDFLAGS=-lm

all: build test

build: $(EXEC)

ifeq (, $(shell which colordiff))
DIFF=diff
else
DIFF=colordiff
endif

format: $(CSRCS)
	clang-format $< | $(DIFF) $< -

%: %.c
	@echo -e '\e[1;34mCompilation...\e[m'
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

test: $(EXEC)
	@echo -e '\e[1;34mRun tests...\e[m'
	EXEC=./$< ./test.sh

clean:
	@echo -e '\e[1;34mCleaning...\e[m'
	$(RM) $(EXEC) *.o a.out

.PHONY: test all format build
