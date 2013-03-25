#! /usr/bin/python
"""Sum of all the even numbers in the fibonacci sequence below four million"""

FOUR_MILLION = 4000000

n = 1
total = 0
n1 = 1
n2 = 1
while n < FOUR_MILLION:
    if n % 2 == 0:
        total += n
    n2 = n1
    n1 = n
    n = n1 + n2
print total
