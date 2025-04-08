#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Użycie: $0 <plik_csv>"
    echo "Wypisze co 5000 linii i sformatuje do LaTeX (; → &, nowa linia → \\\\ \\hline)"
    exit 1
fi

csv_file="$1"

if [ ! -f "$csv_file" ]; then
    echo "Plik $csv_file nie istnieje!"
    exit 1
fi

# 1. Wybierz co 5000 linii (pomijając nagłówek, jeśli istnieje)
# 2. Zamień średniki na & 
# 3. Dodaj \\ \hline na końcu każdej linii
awk -F ';' 'NR % 50 == 49 { 
    for (i=1; i<=NF; i++) {
        printf "%s", $i
        if (i < NF) printf " & "
    }
    printf " \\\\ \\hline \n"
}' "$csv_file"
