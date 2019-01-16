shopt -s globstar
for filename in ./**/*.c
do
	if [ ! -f "${filename%.c}" ]; then
		printf "\n${filename} - Started compiling."
		gcc "${filename}" -Wall -Wextra -g -o "${filename%.c}"
	else
		printf "\n${filename}  - Executable exists."
	fi
done

printf "\n\ngcc <filename.c> -Wall -Wextra -g -o <filename>\n"
