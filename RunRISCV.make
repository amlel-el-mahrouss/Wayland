export IMG=qemu-img
export QEMU=qemu-system-$(MACHINE)
export GDB=$(MACHINE)-unknown-elf-gdb

export QEMU_FLAGS_RISCV64=-device VGA -machine virt -smp 8 -bios none -m 4G -drive if=none,format=raw,file=os.dsk,id=x0 \
							-device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0 -serial stdio -d int

.PHONY: run-riscv64
run-riscv64: create-hdd
	$(QEMU) $(QEMU_FLAGS_RISCV64) -kernel $(INIT)

.PHONY: run-riscv64
run-riscv64-debug: create-hdd
	$(QEMU) $(QEMU_FLAGS_RISCV64) -kernel $(INIT) -s -S

.PHONY: run-debugger
run-debugger:
	$(GDB) -q -x ./gdbinit


.PHONY: create-hdd
create-hdd:
	$(IMG) create -f raw os.dsk 2048