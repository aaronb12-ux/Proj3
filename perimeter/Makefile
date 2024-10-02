all: create_binary_shape.out print_binary_file.out
.PHONY: all

create_binary_shape.out: create_binary_shape.c
	gcc -g -Wall -Werror -o create_binary_shape.out create_binary_shape.c

print_binary_file.out: print_binary_file.c
	gcc -g -Wall -Werror -o print_binary_file.out print_binary_file.c

.PHONY: clean
clean:
	rm -rf *.out *.o