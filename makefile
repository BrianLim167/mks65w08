all: stat.c
	gcc stat.c -o stat
run: all
	./stat
clean:
	rm -f *~
	rm -f *.o
