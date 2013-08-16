#! /usr/bin/python
""" Find the largest prime factor of NUMBER """
import math

NUMBER = 600851475143
NO_OF_FACTORS = 100000

def p_test(num):
    """A test for primality."""
    i = 2
    sqrt_num = math.sqrt(num);
#   print "about to start while loop half_num=%d \n" % half_num
    while i <= sqrt_num:
        if p_test(i) and num % i == 0:
            return 0
        i += 1
    return 1

def main():
    num = NUMBER
    i =  2
    while i < NUMBER/2:
        if i % 10000000 == 0:
            print 'looping for %s' % i
        if num % i == 0:
            if p_test(i) == 1:
                print "%d is a prime factor of %d\n" % (i, num)
            
        
        i += 1
    return 0

if __name__ == "__main__":
    main()

