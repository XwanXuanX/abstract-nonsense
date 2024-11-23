# Print the average number of lines of code that I've ever written
# Goal: THE FEWER THE BETTER!

import os
import csv
from datetime import date
from pathlib import Path
from contextlib import closing

count: int = 0
total: int = 0

for filename in os.listdir(r"./archive/"):
    # only count cpp files
    if Path(filename).suffix != ".cpp":
        continue

    count += 1

    with closing(open(os.path.join(r"./archive", filename))) as file:
        lines = file.readlines()
        total += len(lines)

# output the result
result = total / count
print(f"Average number lines of code: {result}")

# log the result to a csv file
with open("codelens.csv", 'a', newline='\n') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow([date.today(), count, total, result])
