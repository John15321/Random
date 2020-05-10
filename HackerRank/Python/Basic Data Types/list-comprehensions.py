'''
https://www.hackerrank.com/challenges/list-comprehensions/problem
'''

if __name__ == '__main__':
    # Input
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())

    print([[xs, ys, zs] for xs in range(0, x+1) for ys in range(0, y+1)
           for zs in range(0, z+1) if(zs+xs+ys != n)])
