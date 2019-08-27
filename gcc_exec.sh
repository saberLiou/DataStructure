#!/bin/bash

# Set compiling and executing by gcc in one alias function.
function gcc_exec() {
	if [ ! -d exec ]; then mkdir exec; fi	# mkdir exec if not exist.
	if gcc -o exec/${1} ${1}.c; then ./exec/${1}; fi
}