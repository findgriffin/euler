#! /usr/bin/env python
""" Scrape problem names from projecteuler.net """
import requests
import BeautifulSoup as bsoup
import sys
import os

def get_content(num):
    """ Get the problem description from projecteuler.net. """
    page = requests.get('http://projecteuler.net/problem=%s' % num)

    if page.status_code != 200:
        print 'failed to retrieve problem %s, got: %s' % (num, 
                page.status_code)
    soup = bsoup.BeautifulSoup(page.text)

    content = soup.find(id='content')
    heading = content.h2.string
    problem = content.findAll(role='problem')
    if len(problem) > 1:
        print 'problem is longer than 1 for %s ' % num
    fun_f = lambda para: para.string
    fun_g = lambda para: type(para) == bsoup.Tag
    paras = [fun_f(para) for para in problem[0].contents if fun_g(para)]

    return heading, paras

def write_content(num, heading, paras):
    """ Write the problem description to file."""
    pdir = 'prob%03d' % num
    if not os.path.isdir(pdir):
        os.mkdir(pdir)
    lines = ['Problem %03d' % num,'']
    lines.append(heading)
    lines.append('=' * len(heading))
    lines.append('')
    for para in paras:
        lines.extend([para, '']) 
    with open(os.path.join(pdir, 'problem.txt'), 'wb') as txt_file:
        for line in lines:
            txt_file.write(line) 
def main():
    """ Main function"""
    num = int(sys.argv[-1])
    heading, paras = get_content(num)
    write_content(num, heading, paras)

if __name__ == '__main__':
    main()
