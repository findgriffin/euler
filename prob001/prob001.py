#! /usr/bin/python
""" prob001.py """
# add all the multiples of 3 and 5 below 1000
# 

TOTAL = 0

for i in xrange(1000):
    if i % 3 == 0 or i % 5 == 0:
        TOTAL += i
print TOTAL

