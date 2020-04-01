from cs50 import get_int
while True:
    height = get_int("Height: ")
    if height <= 8 and height > 0:
        break;
for i in range(height):
    s = "#" * (i+1)
    print(" " * (height - (i+1)), end="")
    print("#" * (i+1), end=f"  {s}\n")
