Gc = gcc
Sources = main.o hash_tables.o hash_funcs.o Generate_And_Print.o

all: base 

base: $(Sources)
		$(Gc) $(Sources) -o base 


main.o: main.c
		$(Gc) -c main.c


hash_tables.o: hash_tables.c
		$(Gc) -c hash_tables.c


hash_funcs.o: hash_funcs.c
		$(Gc) -c hash_funcs.c


Generate_And_Print.o: Generate_And_Print.c
		$(Gc) -c Generate_And_Print.c

clean:
		rm -rf *.o base
