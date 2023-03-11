#!/usr/bin/env bash
Help()
{
        echo "Syntax: ./validator.sh [tests]"
}
if [ "$#" -eq 0 ]
then
        #display Help
        Help
        exit
fi
while getopts ":h" option; do
   case $option in
      h) # display Help
         Help
         exit;;
   help) # display Help
         Help
         exit;;
     \?) # incorrect option
         echo "Error: Invalid option"
         echo "Use ./validator.sh -h to display help."
         exit;;
   esac
done
wrongoutput=0
carg=stdinp
for ((testNum=0;testNum<$1;testNum++))
do
    ../generator/a "$carg" > input
    ../'smart shit code'/a "$carg" < input > out
    cat input out > data
    ../validator/a "$carg" < data > res
    result=$(cat res)
    if [ "${result:0:2}" != "OK" ];
    then
        echo "Error found!"
        echo "Input:"
        cat input
        echo "Output:"
        cat out
        echo "Validator Result:"
        cat res 
        echo
	let "wrongoutput++"
    fi
    maxwrong=2
    if [ $wrongoutput -gt $maxwrong ]
    then
        echo "Exit due to you having fucked-up code(s) (More than $maxwrong errors)"
        exit
    fi
done
right=$(($1-$wrongoutput))
echo Passed $right tests
