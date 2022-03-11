#!/bin/bash

echo "Enter the path to the key:"

read key_path

key=$(cat "$key_path")

echo "Enter the path to the message:"

read message

tr "A-Z" "a-z" <"$message" | tr "a-z" "$key"

# Дешифровка:
# cat "$@" | tr "$key" "A-Z"

exit 0
