import os
import csv
from collections import defaultdict

def calculate_directory_averages(directory):
    data = defaultdict(lambda: defaultdict(list))
    columns = []
    
    for file in os.listdir(directory):
        if file.endswith(".csv"):
            filepath = os.path.join(directory, file)
            with open(filepath, 'r') as f:
                reader = csv.reader(f, delimiter=';')
                headers = next(reader)
                if not columns:
                    columns = headers
                
                for row in reader:
                    if row:
                        n = row[0]
                        for i in range(1, len(row)):
                            try:
                                data[n][columns[i]].append(float(row[i]))
                            except ValueError:
                                pass
                            
    output_file = os.path.join(directory, 'srednie.csv')
    with open(output_file, 'w', newline='') as outfile:
        writer = csv.writer(outfile, delimiter=';')
        writer.writerow(columns)
        
        for n in sorted(data.keys(), key=lambda x: int(x)):
            avg_row = [n]
            for col in columns[1:]:
                values = data[n][col]
                avg = sum(values) / len(values) if values else 0
                avg_row.append(round(avg, 2))
            writer.writerow(avg_row)

def main():
    base_dir = "./pomiary"
    for subdir in os.listdir(base_dir):
        subdir_path = os.path.join(base_dir, subdir)
        if os.path.isdir(subdir_path):
            calculate_directory_averages(subdir_path)
            print(f"{subdir} zapisane do {subdir_path}/srednie.csv")

if __name__ == "__main__":
    main()