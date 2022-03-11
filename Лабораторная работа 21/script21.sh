#!/bin/bash

echo "Enter the path to the directory:"

read dir_path

if [ -d "$dir_path" ]
then

find "$dir_path" -type f -name "makefile*" -print0 | xargs -0 sed -i 'y,\\,\/,'

else

echo "This path does not lead to a directory!"

fi

exit 0
