import csv
from sys import argv
import cs50

if len(argv) < 2:
    print("usage error, need to pass the house name")
    exit()

# reference the DB
db = cs50.SQL("sqlite:///students.db")

# Query all students from specific house
arrayOfStudents = db.execute("SELECT * FROM students WHERE house = ? GROUP BY first ORDER BY last", argv[1])

# format the response eg:Harry James Potter, born 1980
for student in arrayOfStudents:
    if student['middle'] == None:
        fullName = student['first'] + " " + student['last']
    else:
        fullName = student['first'] + " " + student['middle'] + " " + student['last']
    fullResponse = fullName + ", " + "born " + str(student['birth'])

    print(fullResponse)

