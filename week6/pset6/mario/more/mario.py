# in actual submission, cs50 library is used
while True:
    height = int(input("Input height: "))
    if height < 1 or height > 8:
        continue
    else:
        break
for i in range(height):
    print(' ' * (height - i -1), end='')
    print("#" * (i + 1), end = "  ")
    print("#" * (i + 1))

