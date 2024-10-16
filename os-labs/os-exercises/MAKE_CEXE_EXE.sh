#!/bin/bash

while true; do
    # Ask user for executable name
    read -p "create laucher of: " exe_name

    # Check if user wants to exit
    if [ "$exe_name" = "exit" ]; then
        echo "creator closed."
        break
    fi
    if [ "$exe_name" = "e" ]; then
        echo "creator closed."
        break
    fi
    if [ "$exe_name" = "q" ]; then
        echo "creator closed."
        break
    fi
    if [ "$exe_name" = "quit" ]; then
        echo "creator closed."
        break
    fi
    # Create the launch script filename
    launch_script="execute-${exe_name}-cexe.sh"

    # Create the launch script
    cat > "./01HOLDER/$launch_script" << EOL
#!/bin/bash
# Name of C executable
EXECUTABLE="${exe_name}"
# Get the directory of the script
DIR="\$( cd "\$( dirname "\${BASH_SOURCE[0]}" )" && pwd )"
# Command to open a new terminal and run the program
gnome-terminal -- bash -c "cd \"\$DIR\" && ./\"\$EXECUTABLE\"; echo '' ;echo '${exe_name} ended'; read"
EOL

    # Make the launch script executable
    chmod +x "./01HOLDER/$launch_script"

    echo "created: ${exe_name} launcher"
done
