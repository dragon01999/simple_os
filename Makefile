CC = gcc

CFLAGS = -Wall -Wextra -ffreestanding -fno-stack-protector \
         -fno-pic -fno-pie -O2
LDFLAGS = -nostdlib -Wl,-Tlinker.ld -Wl,-no-pie

all: kernel8.elf

kernel8.elf: boot.o kernel.o
	$(CC) $(LDFLAGS) -o $@ $^

boot.o: boot.S
	$(CC) -c boot.S $(CFLAGS)

kernel.o: kernel.c
	$(CC) -c kernel.c $(CFLAGS)

run: kernel8.elf
	qemu-system-aarch64 -M virt -cpu cortex-a57 -m 512 \
		-kernel kernel8.elf -nographic

clean:
	rm -f *.o *.elf
