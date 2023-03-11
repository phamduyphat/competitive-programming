#!/usr/bin/env bash
Help()
{
 echo "Syntax: ./makedir.sh [DIRECTORY (string)] [Amount of copys (int)]"
 echo
 echo "Maximum amount of copys: 26"
}
while getopts ":hv" option; do
   case $option in
      h) # display Help
         Help
         exit;;
   help) # display Help
           Help
           exit;;
     \?) # incorrect option
         echo "Error: Invalid option: $option"
         echo "Use ./makedir.sh -h to display help."
         exit;;
   esac
done
directory=$1
amount=$2
actual_amount=$((0))
if [[ -d "$directory" ]]; then
  echo "$directory already exists"
  exit
fi
if [[ $amount -gt 26 ]]; then
  echo "Too many files. Maximum is 26"
  exit
fi

mkdir "$1"
cd "$1"
shopt -s dotglob
cp -r ../"make dir other files"/* ./
cp ../"c++_template.cpp" ./generator/generator.cpp
cp ../"c++_template.cpp" ./validator/validator.cpp
for x in {A..Z}
do
  if ((actual_amount == amount)); then
    break
  fi
  let "actual_amount++"
  cp ../"c++_template.cpp" ./"$x.cpp"
done
echo "Successfully created $amount copy of c++ template"
