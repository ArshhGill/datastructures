ll: LLoutput

LLoutput: ./internals/linked_list/linked_list.c
	gcc -o LLoutput ./internals/linked_list/linked_list.c
	./LLoutput



bst: BSToutput

BSToutput: ./internals/bst/bst.c
	gcc -o BSToutput ./internals/bst/bst.c
	./BSToutput


clean:
	rm ./LLoutput ./BSToutput
