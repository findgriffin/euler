# a library to help with solving project euler problems
import numpy as np

def triangle(x):
    """ returns  the x'th triangle number
    """
    return (x*x+1)/2

def factors(x):
    """ returns the number of divisors for
    x
    """
    factors = []
    poss = range(1,x/2+1)
    poss.reverse()
    for i in poss:
        if not x % i:
            factors.append(i)
            factors.append(i/x)
            try:
                poss.remove(i/x)
            except ValueError:
                pass
                # val not in list anyway
    return factors

def get_digits(num):
    """returns an array of the digits of num
    """
    digits = []
    n = 10
    digits.append(num % n)
    while int(num / n):
        digits.append(int(num/n) - 10*int(num/(n*10)))
        n *=10
    digits.reverse()
    return digits
