#!/usr/bin/env bash
Help()
{
        echo Syntax: ./build.sh [OPTIONS] [Files]
	  echo
	  echo Options:
	  echo -h \|\| --help: Print this help
	  echo -v:             Validator mode
	  echo
	  echo 'Files: files directory or files name if this script is in the same directory'
}
validator=$((0))
while getopts ":hv" option; do
   case $option in
      h) # display Help
         Help
         exit;;
   help) # display Help
	   Help
	   exit;;
      v) # validator mode
	   validator=$((1))
         break
	   ;;
     \?) # incorrect option
         echo "Error: Invalid option: $option."
	 echo "Use ./build.sh -h to display help."
         exit;;
   esac
done
if [ $validator -eq $((0)) ]
then
	g++ -w -O2  "$1" -o ./'smart shit code'/a
	g++ -w -O2  "$2" -o ./'dumb fuck'/a
	g++ -w -O2  ./generator/generator.cpp -o ./generator/a
else
	g++ -w -O2  "$2" -o ./'smart shit code'/a
	g++ -w -O2  ./validator/validator.cpp -o ./'validator'/a
	g++ -w -O2  ./generator/generator.cpp -o ./generator/a
fi

