#!/bin/bash

echo "Enter the path to the key:"

read key_path

alpha=abcdefghijklmnopqrstuvwxyz

key=$(cat "$key_path")

echo "Enter the path to the message:"

read message

sed 'y/'"$alpha"'/'"$key"'/' <"$message"

exit 0
