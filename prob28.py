# problem 28! hooray

import numpy as np

DIM = 1001    # must be an odd number
MIDDLE = DIM/2
arr = np.zeros((DIM,DIM))

def make_spiral():
    level = 1
    c = 2
    arr[MIDDLE][MIDDLE] = 1
    for i in range(1,MIDDLE+1):
        c = build_level(i, c)


def build_level(level, count):
    x = MIDDLE - level + 1
    y = MIDDLE + level
    # build right side
    while x < MIDDLE + level:
        arr[x][y] = count
    #    print "{%d, %d} is now %d" %(x, y, count)
        x += 1
        count += 1
    # build bottom
    while y > MIDDLE - level:
        arr[x][y] = count
        y -= 1
        count += 1
    # build left side
    while x > MIDDLE - level:
        arr[x][y] = count
        x -= 1
        count += 1
    # build top
    while y < MIDDLE + level:
        arr[x][y] = count
        y += 1
        count += 1
    arr[x][y] = count
    count += 1
    return count
def sum_diagonals():
    sum = 0
    for i in range(0,MIDDLE):
        sum += arr[i][i]
        sum += arr[i][DIM-i-1]
        sum += arr[DIM-i-1][i]
        sum += arr[DIM-i-1][DIM-i-1]
    return sum+1
make_spiral()

print arr
print sum_diagonals()
