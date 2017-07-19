led.bin:led.S
	arm-linux-gnueabihf-gcc -c -o led.o led.S
	arm-linux-gnueabihf-ld -Ttext 0x82000000 led.o -o led.elf 
	arm-linux-gnueabihf-objcopy -O binary led.elf led.bin
clean:
	rm *.o *.elf *.bin 

