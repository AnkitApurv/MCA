shopt -s globstar
for filename in ./**/*.c
do
	if [ ! -f "${filename%.c}" ]; then
		gcc "${filename}" -Wall -Wextra -g -o "${filename%.c}"
		printf "\n${filename} -  Compiled."
	else
		printf "\n${filename}  - Executable exists."
	fi
done

printf "\n\ngcc <filename.c> -Wall -Wextra -g -o <filename>\n"

shopt -s globstar
for filename in ./**/*.cpp
do
	if [ ! -f "${filename%.cpp}" ]; then
		gcc "${filename}" -Wall -Wextra -g -o "${filename%.cpp}"
		printf "\n${filename} -  Compiled."
	else
		printf "\n${filename}  - Executable exists."
	fi
done

printf "\n\ng++ <filename.cpp> -Wall -Wextra -g -o <filename>\n"