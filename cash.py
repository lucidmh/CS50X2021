#import get_float
from cs50 import get_float
# money that we owed, cent(value of coins), count(number of coins)
change = 0.00
# a loop for get the change from someone
while change == 0:
    change = get_float("owed change: ")
    count = 0
    # cent is an int value so we should round the change
    cent = round(change * 100)
# a loop for he 25, 10, 5, 1 cent
while count == 0:
    while cent >= 25:
        cent -= 25
        count += 1

    while cent >= 10:
        cent -= 10
        count += 1

    while cent >= 5:
        cent -= 5
        count += 1

    while cent >= 1:
        cent -= 1
        count += 1
# print number of coins that we gave
if cent == 0:
    print("counted coins: ", count)