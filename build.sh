#!/usr/bin/bash

if [[ -z "$1" ]]; then
  echo "Please provide a pathname to a project."
  exit 1
fi

path=$(realpath "$1")

if ! [ -z "$2" ]; then
  if [ "$2" = "clean" ]; then
    make clean PROJECT_PATH="$path"
  elif [ "$2" = "debug" ]; then
    make debug PROJECT_PATH="$path"
  fi
else
  make PROJECT_PATH="$path"
fi
