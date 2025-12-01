# This setting will make the script stop if any command fails
set -e

# Running cmake if necessary
if [ ! -d "./build" ]
then
	echo "Running cmake"
	# Checking for Windows
	if [[ `uname -s` =~ MINGW ]] 
	then
		echo "Windows detected. MinGW Makefile option added."
		cmake -S . -B ./build ${CMAKE_ARGS} -G "MinGW Makefiles"
	else
		cmake -S . -B ./build ${CMAKE_ARGS}
	fi
else
	echo "Build directory exists. Skipping cmake step."
fi

# Building
make -C ./build

# Running
./build/app
