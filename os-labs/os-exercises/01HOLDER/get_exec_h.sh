#!/bin/bash

# Define source and destination using relative paths
SOURCE_FILE="../supervisor/build/supervisor"
SOURCE_FILE2="../imu_handler/build/imu_handler"
DESTINATION_DIR="./"

# Copy the file
cp "$SOURCE_FILE" "$DESTINATION_DIR"


# Check if the copy was successful
if [ $? -eq 0 ]; then
    echo "File copied successfully."
else
    echo "Error copying file."
fi



# Copy the file
cp "$SOURCE_FILE2" "$DESTINATION_DIR"

# Check if the copy was successful
if [ $? -eq 0 ]; then
    echo "File copied successfully."
else
    echo "Error copying file."
fi

