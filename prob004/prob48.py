
def next_pow(num):
    return num**num

def sum_pows(max):
    num = int(max)
    sum = 0
    for i in range(1,num+1):
        sum = sum+next_pow(i)
    return sum

if __name__ == "__main__":
    from sys import argv
    print sum_pows(argv[1])
