Gc = gcc
Sources = main.o hash_tables.o hash_funcs.o Generate_And_Print_List.o Save_To_CSV.o

all: base 

base: $(Sources)
		$(Gc) $(Sources) -o base 


main.o: main.c
		$(Gc) -c main.c


hash_tables.o: hash_tables.c
		$(Gc) -c hash_tables.c


hash_funcs.o: hash_funcs.c
		$(Gc) -c hash_funcs.c


Generate_And_Print_List.o: Generate_And_Print_List.c
		$(Gc) -c Generate_And_Print_List.c


Save_To_CSV.o: Save_To_CSV.c
		$(Gc) -c Save_To_CSV.c

clean:
		rm -rf *.o base
