# import sys and csv reader library
import sys
from sys import argv
import csv

# main function


def main():
    # check if the argv lenght is ok and do the whole pset
    if len(argv) == 3:
        # open database file as an csv file and read it into memmory
        with open(argv[1], "r") as csv_file:
            # read the csv file with csv.reader function "why dict reader? because we want to turn the file into a dict(key and the values) so the fields are keys"
            csvreader = csv.DictReader(csv_file)
            for row in csvreader:
                dictlist = list(csvreader)
                # at first, i was doing a wrong solution and this comments are for that and remember that i shouldn't do that again
                # if dictlist == ['name']:
                # name = ['name']
                # else:
                # STR = ['AATG', 'AGATC', 'GAAA', 'GATA', 'TATC', 'TCTAG', 'TCTG','TTTTTTCT']

        # open a text file(persons dna)
        with open(argv[2], "r") as text_file:
            sequences = text_file.read()
            # we should store the reapetion of STR's into a holder like list or dict(although i choosed list for this)
            str_reapet = []
            # equal some values to handle the len x, len y and... reapet.
            len_dictlist = len(dictlist)
            len_sequences = len(sequences)
            len_field = len(csvreader.fieldnames)
            # a loop through the first file so we're saying that "hey, go and choose "AGAT" and "ACTC" and... row from the csv file)
            for i in range(1, len_field):
                # DNA STR's
                STR = csvreader.fieldnames[i]
                # loop to count the reapeted str's
                # again a loop(i should mention that sequences, is people file) so it seems that app should notice that there's some str's in you and if they're reapet after each other, count them(for loop while loop)
                for j in range(len_sequences):
                    str_count = 0
                    # Note: "append" add something to the end of the list
                    str_reapet.append(0)
                    if sequences[j:(j + len(STR))] == STR:
                        temp = 0
                        while sequences[(j + temp):(j + temp + len(STR))] == STR:
                            # handle base case(everytime after checking some strs, it would go to the next part and avoid counting from the first step)
                            str_count += 1
                            temp += len(STR)
                            # update max count
                            # if there is a higher count of reapeted str's after the last one, update the count to a higher value
                            if str_count > str_reapet[i - 1]:
                                str_reapet[i - 1] = str_count
                # compare counted STR's, with persons's STR'S(database and dna file)
                # compare data
                for i in range(len_dictlist):
                    match = 0
                    for j in range(1, len_field):
                        # check that number in our database list, match with counted str from upper part
                        # check if str num match
                        if int(str_reapet[j - 1]) == int(dictlist[i][csvreader.fieldnames[j]]):
                            match += 1
                            # if matches was equal to fieldnames str reapet number, the print the person name and return true
                            # print person name
                        if match == ((len_field) - 1):
                            print(dictlist[i]['name'])
                            sys.exit(0)
                            # at first, else condition was here and it would create a bug
            # i acsidantaly move it here, and horai!
            print("no match")
    # what if the argv was more or less than 3?
    # handle base case
    else:
        print("Usage: pythone dna.py data.csv sequencess.text")


main()