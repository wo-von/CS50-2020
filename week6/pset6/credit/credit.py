import re

# get user input
cardNo = input("Number: ")
sum = 0
for i in range(1, len(cardNo) + 1):
    if i % 2 == 0:
        if cardNo[-i] in "56789":
            sum += 2 * (int(cardNo[-i]) - 4) - 1
        else:
            sum += int(cardNo[-i]) * 2
    else:
        sum += int(cardNo[-i])
if sum % 10 != 0:
    print("INVALID")
else:
    if re.search("^3[47]", cardNo) and len(cardNo) == 15:
        print("AMEX")
    elif re.search("^5[1-5]", cardNo) and len(cardNo) == 16:
        print("MASTERCARD")
    elif re.search("^4", cardNo) and len(cardNo) in [13, 16]:
        print("VISA")
    else:
        print("INVALID")