'''
hackerrank.com/challenges/finding-the-percentage/problem?isFullScreen=true&h_r=next-challenge&h_v=zen
'''


def split_and_join(line):

    return "-".join(line.split(" "))


if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)
