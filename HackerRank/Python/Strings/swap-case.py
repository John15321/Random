'''
https://www.hackerrank.com/challenges/swap-case/problem
'''


def swap_case(s):
    return "".join([i.lower() if 'A' <= i <= 'Z' else i.upper() for i in s])


if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
