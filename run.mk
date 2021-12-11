KERNEL_SCR=kernel/scr
DRIVERS_SCR=kernel/scr/drivers/scr
BOOT_SCR=boot/scr
BUILD=build
C_SOURCES = $(wildcard kernel/scr/*.cpp kernel/scr/drivers/*.cpp kernel/scr/Security/*.cpp kernel/scr/Security/IDT/*.cpp kernel/scr/printing/*.cpp)
HEADERS = $(wildcard kernel/scr/*.h kernel/scr/drivers/*.h)
OBJ = ${C_SOURCES:.cpp=.o}
$(BUILD)/bootimage.bin: $(BOOT_SCR)/boot.asm
	nasm $(BOOT_SCR)/boot.asm -f bin -o $(BUILD)/bootimage.bin
$(BUILD)/kernel.o: $(KERNEL_SCR)/kernel.cpp
	gcc -ffreestanding -c $(KERNEL_SCR)/kernel.cpp -o $(BUILD)/kernel.o -w -O0
$(BUILD)/kernel.tmp: $(BUILD)/kernel.o $(BUILD)/kernelE.o $(OBJ)
	ld -T NUL -o $(BUILD)/kernel.tmp -Ttext 0x1000 $(OBJ)
$(BUILD)/kernel.bin: $(BUILD)/kernel.tmp
	objcopy -O binary -j .text  $(BUILD)/kernel.tmp $(BUILD)/kernel.bin 
$(BUILD)/kernelE.o: $(BOOT_SCR)/kernel.asm
	nasm $(BOOT_SCR)/kernel.asm -f elf -o $(BUILD)/kernelE.o
os-image: $(BUILD)/kernel.bin $(BUILD)/bootimage.bin
	copy /b $(BUILD)\bootimage.bin+$(BUILD)\kernel.bin os-image	
	copy /b $(BUILD)\bootimage.bin+$(BUILD)\kernel.bin os-image.test	
%.o : %.cpp $(HEADERS)
	gcc -ffreestanding -c $< -o $@ -w -O0
run: os-image
	qemu-system-i386 -drive format=raw,file=os-image,if=floppy
build: os-image
runT: 
	qemu-system-i386 -drive format=raw,file=os-image.test,if=floppy
commit: os-image
	git add .
	git commit -m "Switched from C to CPP"
	git push origin master
