#!/bin/python

import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(s):
    s = s.split(" ")
    s = list(s)
    for i in range(len(s)):
        s[i] = s[i][0].upper() + s[i][1:]
    return s

# przyklad jest zly sam w sobie XD lmao
print(solve(input()))
# if __name__ == '__main__':
#     fptr = open(os.environ['OUTPUT_PATH'], 'w')

#     s = input()

#     result = solve(s)

#     fptr.write(result + '\n')

#     fptr.close()
