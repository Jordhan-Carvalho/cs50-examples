import csv
from sys import argv
import cs50

if len(argv) < 2:
    print("usage error, need to pass the the database.csv")
    exit()

# Open and close db to erase previous data
open("students.db", "w").close()
# get reference
db = cs50.SQL("sqlite:///students.db")

# Recreate table
db.execute("CREATE TABLE students ( id INTEGER PRIMARY KEY AUTOINCREMENT, first VARCHAR(255), middle VARCHAR(255), last VARCHAR(255), house VARCHAR(10), birth INTEGER )")

# read the dna sequence from the file
with open(argv[1]) as charfile:
    reader = csv.DictReader(charfile)
    for row in reader:
        # break the name into first middle and last
        nameArray = row['name'].split()
        if len(nameArray) == 3:
            first = nameArray[0]
            middle = nameArray[1]
            last = nameArray[2]
        else:
            first = nameArray[0]
            middle = None
            last = nameArray[1]
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ? , ?, ?, ?)", first, middle, last, row['house'], row['birth'])
