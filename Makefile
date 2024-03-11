ll: LLoutput

LLoutput: ./internals/linked_list/linked_list.cpp
	g++ -o LLoutput ./internals/linked_list/linked_list.cpp
	./LLoutput

s: Soutput

Soutput: ./internals/stack/stack.cpp
	g++ -o Soutput ./internals/stack/stack.cpp
	./Soutput
