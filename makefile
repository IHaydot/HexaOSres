C_SOURCES=$(wildcard kernel/*.cpp)
ASM_SOURCES=$(wildcard kernel/*.cpp)

BUILD_DIR=build/

IMAGE=randomos-amd64.osi
QEMU_FORMAT=raw
GCC=gcc
LD=ld
GCC_FLAGS=-ffreestanding -mno-red-zone -w -O0 -Wall
LD-FLAGS=-n -T target/linker.ld 
NASM=nasm
NASM_FLAGS_BIN=-f bin
NASM_FLAGS_ELF=-f elf64

buildenv:
	mkdir boot 
	mkdir boot/sect1 ; mkdir boot/sect2
	mkdir build
	mkdir kernel
	

build: $(C_SOURCES) $(ASM_SOURCES) 


run: build
	qemu-system-x86_64 -drive file=$(IMAGE),format=$(QEMU_FORMAT) -d cpu-reset -D qemu-logs -serial serial.log
