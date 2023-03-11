#!/usr/bin/env bash
Help()
{
	echo "Syntax: ./stress.sh [tests]"
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
         echo "Use ./stress.sh -h to display help."
         exit;;
   esac
done
wrongoutput=0
carg=stdinp
for ((testNum=1;testNum<=$1;testNum++))
do
    
    ../generator/a "$carg" > input
    ../'smart shit code'/a "$carg" < input > outWrong
    ../'dumb fuck'/a "$carg" < input > outSlow
    H1=`md5sum outWrong`
    H2=`md5sum outSlow`
    if !(cmp -s "outWrong" "outSlow")
    then
        echo "Error found!"
	echo Test: $testNum
        echo "Input:"
        cat input
        echo "Wrong Output:"
        cat outWrong
        echo "Slow Output:"
        cat outSlow
        echo
	echo
	let "wrongoutput++"
    fi
    maxwrong=5
    if [ $wrongoutput -gt $maxwrong ]
    then 
	echo "Exit due to you having fucked-up code(s) (More than $maxwrong errors)"
	exit
    fi
done
right=$(($1-$wrongoutput))	
echo Passed $right tests


