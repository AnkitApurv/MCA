shopt -s globstar
for filename in ./**/*.cpp
do
	if [ ! -f "${filename%.cpp}" ]; then
		g++ "${filename}" -Wall -Wextra -g -o "${filename%.cpp}"
		printf "\n${filename} -  Compiled."
	else
		printf "\n${filename}  - Executable exists."
	fi
done

printf "\n\ng++ <filename.cpp> -Wall -Wextra -g -o <filename>\n"
