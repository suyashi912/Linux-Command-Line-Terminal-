default: 
	make all
	make run 
	make clean 
all : preprocess compile assembly external result

preprocess : part2.c
	gcc -E part2.c -o part2.i

compile : part2.i 
	gcc -S part2.i -o part2.s

assembly : part2.s 
	gcc -c part2.s -o part2.o 

external : cat1.c rm1.c mkdir1.c ls1.c date1.c
	gcc cat1.c -o cat1 
	gcc rm1.c -o rm1
	gcc mkdir1.c -o mkdir1
	gcc ls1.c -o ls1
	gcc date1.c -o date1 

result : part2.o
	gcc part2.o -o result 

run : 
	./result

clean: 
	rm part2.i part2.s part2.o
	rm result 
	rm cat1 
	rm rm1
	rm mkdir1
	rm ls1
	rm date1