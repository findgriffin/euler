import numpy as np

def sum_file(file):
    lines = []
    for elem in file.readlines():
        lines.append(int(elem))
    arr = np.array(lines)
    return arr.sum()


if __name__ == "__main__":
    from sys import argv
    f = open(argv[1])
    sum  = sum_file(f)
    print "the answer is the first ten digits of"+str(sum)

