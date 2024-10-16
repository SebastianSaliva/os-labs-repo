#!/bin/bash

# Define source and destination using relative paths
SOURCE_FILE="./reader/build/reader"
SOURCE_FILE2="./writer/build/writer"
DESTINATION_DIR="./01HOLDER/"

# Copy the file
cp "$SOURCE_FILE" "$DESTINATION_DIR"


# Check if the copy was successful
if [ $? -eq 0 ]; then
    echo "File copied successfully."
else
    echo "Error copying file."
fi


# Define source and destination using relative paths


# Copy the file
cp "$SOURCE_FILE2" "$DESTINATION_DIR"

# Check if the copy was successful
if [ $? -eq 0 ]; then
    echo "File copied successfully."
else
    echo "Error copying file."
fi

