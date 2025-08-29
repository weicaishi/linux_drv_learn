#!/bin/bash

# define colors for special output
GREEN='\033[0;32m'
# no Color
NC='\033[0m' 

if [[ $EUID -ne 0 ]]; then
    echo "Permission Denied: Root privileges required" >&2
    echo "Please run with:"
    echo -e "    ${GREEN}sudo $0 $@${NC}" >&2
    echo "" >&2
    exit 1
fi

while [ true ]; 
do 
    dmesg -c;
    sleep 1; 
done