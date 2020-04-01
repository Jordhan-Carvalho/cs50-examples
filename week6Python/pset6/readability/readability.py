from cs50 import get_string

text = get_string("Text: ")

countWords = len(text.split())
# create a list of characters and remove the non alphanumerics and get the length
countLetter = len(list(filter(lambda x: x.isalpha(), list(text))))
countSentences = 0
for c in text:
    if c == "." or c == "!" or c == "?":
        countSentences += 1
# TO DO Find the average of lettters and setences per 100 words
L = (countLetter * 100) / countWords
S = (countSentences * 100) / countWords

colemanIndex = 0.0588 * L - 0.296 * S - 15.8

if colemanIndex < 1:
    print("Before Grade 1")
elif colemanIndex > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(colemanIndex)}")
