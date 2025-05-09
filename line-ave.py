import os
import csv
from datetime import date
from pathlib import Path
from contextlib import closing


###################################################
# Add more folders if necessary
problem_folders: list[str] = [
    r"./atcoder/",
    r"./cf/",
    r"./cses/",
    r"./random/",
]
###################################################


def get_stats(problem_folders: list[str]) -> tuple[int, int]:
    """
    Iterate over the specified problem folders and produce the
    number of files and number of lines in total
    """

    files: int = 0
    lines: int = 0

    for folder in problem_folders:
        for filename in os.listdir(folder):
            # Only count cpp files
            if Path(filename).suffix != ".cpp":
                continue

            files += 1
            with closing(open(os.path.join(folder, filename))) as file:
                file_lines = file.readlines()
                lines += len(file_lines)

    return (files, lines)


def output_stats(stats: tuple[int, int], to_file: bool = True) -> None:
    """
    Output stats to stdout and (optionally) to csv file
    """

    files, lines = stats
    average = lines / files

    print(
        f"Files ever created: {files}\n"
        f"Lines ever wrote: {lines}\n"
        f"Average lines per file: {average}"
    )

    if not to_file:
        return
    
    # Log the result to a csv file
    # We can check if there's any update to cf since last logging
    # If non, ignore this action
    TOTAL_FILE = 1
    LOG_FILE: str = "codelens.csv"
    with closing(open(LOG_FILE, 'r')) as csvfile:
        reader = csv.reader(csvfile)
        file_lines = [line for line in reader]
        last = file_lines[len(file_lines) - 1]
        if int(last[TOTAL_FILE]) == files:
            print("No new files added. Not writing to file.")
            exit(1)

    with open(LOG_FILE, 'a', newline='\n') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow([date.today(), files, lines, average])
    
    return


def main():
    output_stats(get_stats(problem_folders))
    return


if __name__ == "__main__":
    main()
