
months = {1:31,2:28,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:31}
days = ['MON','TUE','WED','THU','FRI','SAT','SUN']
DAYS_IN_WK = 7
FOUR_YRS = 4
CENTURY = 100

def years_total(first, last, f_day):
    total = 0
    day = f_day
    for elem in range(first, last+1):
        result = year_total(elem, day)
        total = total + result[0]
        day = result[1]
    return total

def year_total(year, f_day):
    if is_leap(year):
        months[2] = 29
    else:
        months[2] = 28
#    print "%d is it leap? %d: feb has %d days" % (year, is_leap(year), months[2])

    sundays = 0
    f_month = f_day
    for month in range(1,13):
 #       print 'the first day of %d is %d' %(month, f_month)
        if f_month == 6:
            sundays = sundays + 1
        increment = months[month] % DAYS_IN_WK
  #      print "%d days in %d, mod %d" % (months[month], month, increment)
        f_month = f_month + increment
        f_month = f_month % DAYS_IN_WK
    return [sundays, f_month]

def is_leap(year):
    if year % FOUR_YRS:
        return False
    elif not year % CENTURY: # if we are at the turn of the century
        if year % CENTURY*4: # if 
            return True
        else:
            return False
    else:
        return True
