KERNEL_SCR=kernel/scr
DRIVERS_SCR=kernel/drivers/scr
BOOT_SCR=boot/scr
BUILD=build
$(BUILD)/bootimage.bin: $(BOOT_SCR)/boot.asm
	nasm $(BOOT_SCR)/boot.asm -f bin -o $(BUILD)/bootimage.bin
$(BUILD)/kernel.o: $(KERNEL_SCR)/kernel.c
	gcc -ffreestanding -c $(KERNEL_SCR)/kernel.c -o $(BUILD)/kernel.o
$(BUILD)/kernel.tmp: $(BUILD)/kernel.o $(BUILD)/kernelE.o
	ld -T NUL -o $(BUILD)/kernel.tmp -Ttext 0x1000 $(BUILD)/kernelE.o $(BUILD)/kernel.o
$(BUILD)/kernel.bin: $(BUILD)/kernel.tmp
	objcopy -O binary -j .text  $(BUILD)/kernel.tmp $(BUILD)/kernel.bin 
$(BUILD)/kernelE.o: $(BOOT_SCR)/kernel.asm
	nasm $(BOOT_SCR)/kernel.asm -f elf -o $(BUILD)/kernelE.o
os-image: $(BUILD)/kernel.bin $(BUILD)/bootimage.bin
	copy /b $(BUILD)\bootimage.bin+$(BUILD)\kernel.bin os-image	
run: os-image
	qemu-system-x86_64 -fda os-image
