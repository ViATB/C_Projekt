RSA.bin: RSA.o calculate.o
	gcc -o RSA.bin RSA.o calculate.o -lm

RSA.o: RSA.c 					# Objekt-File, nicht gelinked
	gcc -c RSA.c

calculate.o: calculate.c
	gcc -c calculate.c

clean:
	@echo --- cleaning
	rm *.o *.bin
