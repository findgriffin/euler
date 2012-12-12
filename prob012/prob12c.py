def triangle_number(x):
        """The nth triangle number is defined as the sum of [1,n] values.
        A brute-force approach could be sum(xrange(1, x+1)), but let's
        take pencil&paper, some draws to get..."""
        return (x*(x+1))/2
                 
def triangle_numbers(start=1):
        """Generate triangle numbers tn(n) = 1+2+3+....+n"""
        first = triangle_number(start-1)
        return ireduce(operator.add, count(start), first)
                             
def euler12(ndivisors):
        """What is the first triangle number to have over five-hundred divisors?"""
        num_factors = lambda x: mul((exp+1) for (base, exp) in factorize(x))
        return head(x for x in triangle_numbers() if num_factors(x) > ndivisors)

euler12(500)

