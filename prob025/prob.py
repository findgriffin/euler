
def fib_next(last, two):
    return [last + two, last]

def digits(num):
    """ returns the number of digits in an int
    """
    return len(str(num))

def first_elem(d):
    """ finds the first term in the fibonnaci
    sequence with d digits 
    """
    len = int(d)
    last = 1
    two = 1
    term = 2
    while digits(last) < len:
        new = fib_next(last, two)
        last = new[0]
        two = new[1]
        term = term + 1
    return term

if __name__ == "__main__":
    from sys import argv
    print first_elem(argv[1])

