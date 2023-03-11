#!/usr/bin/bash

if [[ -z "$1" ]]; then
  echo "Please provide a pathname to a project."
  exit 1
fi

path=$(realpath "$1")

if ! [ -z "$2" ] && [ "$2" = "clean" ]; then
  make clean PROJECT_PATH="$path"
else
  make PROJECT_PATH="$path"
fi
