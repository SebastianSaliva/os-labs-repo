#!/bin/bash
# Name of C executable
EXECUTABLE="writer"
# Get the directory of the script
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
# Command to open a new terminal and run the program
gnome-terminal -- bash -c "cd \"$DIR\" && ./\"$EXECUTABLE\"; echo '' ;echo 'writer ended'; read"
