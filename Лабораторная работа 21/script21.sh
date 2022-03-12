#!/bin/bash

dir_path=$1

help="?"


if [ -z "$dir_path" ]
then

echo "Enter the path to the directory:"
read dir_path

else

if [ "$dir_path" = "$help" ]
then

echo "Put parameter like this: home/username/"
exit
 
fi
fi


if [ -d "$dir_path" ]
then

find "$dir_path" -type f -name "Makefile*" -print0 | xargs -0 sed -i 'y,\\,\/,'

else

echo "This path does not lead to a directory! Put parameter like this: home/username/"

fi


