# import get_int function from cs50 library
from cs50 import get_int
import sys


def main():

    # height of hashes
    Height = 0
    # hashes block
    hashes = 0
    # row for the hashes
    row = 0

    # check if Hash between 1 and 8
    Height = get_int("the height for the hashes?:")

    if Height > 8 or Height < 1:
        Height = get_int("the height of the hashes?:")

    # a loop through the lines(row)
    while row < Height:
        row += 1
        # print spaces before the hashes
        print(" " * (Height - row), end="")
        # print hashes after the spaces
        print("#" * (row))
        # handle base case
        if row == 0:
            print("hey, i think theres something wrong with me...")


main()