from string import ascii_letters


def process_text(string):
    numW = text.split().__len__()
    numL = numS = 0
    for letter in string:
        if letter in ascii_letters:
            numL += 1
        elif letter in ".!?":
            numS += 1
    return numL, numW, numS
def calculate_grade(stats):
    lcount, wcount, scount = stats
    return round(0.0588 * lcount / wcount * 100 - 0.296 * scount / wcount * 100 - 15.8)

text = input("Text: ")
text_stats_tuple = process_text(text)
grade = calculate_grade(text_stats_tuple)

if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print("Grade:", grade)
