OUTPUT=warp.elf

LD_SCRIPT=CRT0/Link.ld

CROSS_LD=riscv64-unknown-elf-ld

LD_FLAGS=--script=$(LD_SCRIPT)

CROSS_CC=riscv64-unknown-elf-g++

SOURCES=$(wildcard *.cpp) $(wildcard *.s)
OBJECTS=$(wildcard *.o)

CC_INC=-I./

CC_FLAGS=-Wall -trigraphs -Werror -c -nostdlib -ffreestanding -fno-builtin -mcmodel=medany -mno-relax -mno-explicit-relocs -D__KDEBUG__ -D__KERNEL -D__KSTRICT__ -D__KBOOT__ -O2 -fstack-protector-all

.PHONY: all
all:
	$(CROSS_CC) $(CC_INC) $(CC_FLAGS) $(SOURCES)

.PHONY: link
link:
	$(CROSS_LD) $(LD_FLAGS) $(OBJECTS) -o $(OUTPUT)

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(wildcard *.elf)