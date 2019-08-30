#!/bin/bash

# Set output styles of echo by tput.
RED=`tput setaf 1;`
BOLD=`tput bold;`
RESET=`tput sgr0;`

# Set compiling and executing by gcc in one alias function.
function gcc_exec() {
	if [ ! -d exec ]; then	# mkdir exec if not exist.
		mkdir exec;
	fi

	if [ -n "${1}" ]; then	# Check whether the first parameter exist or not.
		if gcc -o exec/${1} ${1}.c; then
			./exec/${1};
		fi
	else
		echo "${RED}Please input the filename of ${BOLD}.c${RESET}";
	fi
}