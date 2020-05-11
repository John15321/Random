'''
https://www.hackerrank.com/challenges/string-validators/problem?h_r=next-challenge&h_v=zen
'''

if __name__ == '__main__':
    s = input()
    s = list(s)

    # Has any alphanumeric
    has_it = False
    for each in s:
        if (each.isalpha() == True or each.isalnum() == True):
            has_it = True
    print(has_it)

    # Has any alphabetic
    has_it = False
    for each in s:
        if (each.isalpha() == True):
            has_it = True
    print(has_it)

    # Has any digits
    has_it = False
    for each in s:
        if (each.isdigit() == True):
            has_it = True
    print(has_it)

    # Has any lowercase
    has_it = False
    for each in s:
        if (each.islower() == True):
            has_it = True
    print(has_it)

    # Has any uppercase
    has_it = False
    for each in s:
        if (each.isupper() == True):
            has_it = True
    print(has_it)
