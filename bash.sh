#!/bin/bash

mkdir -p ./pomiary

for file in *.csv; do
    base_name=$(echo "$file" | sed -E 's/[0-9]+\.csv$//')
    
    mkdir -p "./pomiary/$base_name"
    
    mv "$file" "./pomiary/$base_name/"
done

echo "Posortowane w ./pomiary"