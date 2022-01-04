from cs50 import get_string


def main():

    # to get the text from user
    text = get_string("hello, enter the text here: ")
    letters = 0
    words = 0
    sentences = 0
    i = 0
    n = len(text)

    # a loop through the sentences and words and letters
    for i in range(n):
        # calculate the number of letters in text
        if text[i].isalpha():
            letters += 1
            # handle base case
            if letters == 0:
                print("sorry, there's something wrong with counting letters:(")
                return False
        # calculate the number of words in text
        if text[i] == " ":
            words += 1
            # handle base case
            if words == 0:
                print("sorry, there's something wrong with counting words:(")
                return False
        # calculate the number of sentences
        if text[i] == "!" or text[i] == "?" or text[i] == ".":
            sentences += 1
            # handle base case
            if sentences == 0:
                print("sorry there's something wrong with counting sentences:(")
                return False
    # to be honest add it because of a bug
    words += 1

    # calculate the number of letters and sentences per words in text with colmen-lau formula
    L = (letters / words) * 100
    S = (sentences / words) * 100
    # colmen-lau formula
    index = 0.0589 * L - 0.296 * S - 15.8

    # calculate which grade is text
    grade = round(index)

    # if its lower than one, so ts before grade 1
    if grade < 1:
        print("Before Grade 1")

    # if its higher than 16, so its grade 16+
    elif grade > 16:
        print("Grade 16+")
    # son check the grade between 1 to 16
    else:
        print(("Grade:"), grade)


main()
# thats it:)