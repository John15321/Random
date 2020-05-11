'''
https://www.hackerrank.com/challenges/text-wrap/problem
'''

import textwrap


def wrap(string, max_width):
    return "".join([string[i-1]+'\n' if i % max_width == 0 and i is not len(string) else string[i-1] for i in range(1, len(string)+1)])


if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)
