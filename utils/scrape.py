#! /usr/bin/env python
""" Scrape problem names from projecteuler.net """
import requests
import BeautifulSoup as bsoup
import sys
import os
EULER = 'http://projecteuler.net/'
def get_html(num):
    """ Get the problem description from projecteuler.net. """
    page = requests.get('%s/problem=%s' % (EULER, num))
    if page.status_code != 200:
        print 'failed to retrieve problem %s, got: %s' % (num, 
                page.status_code)
    soup = bsoup.BeautifulSoup(page.text)

    content = soup.find(id='content')
    heading = content.h2
    problem = content.findAll(role='problem')
    if len(problem) > 1:
        print 'problem is longer than 1 for %s ' % num
    images = []
    images = [img.get('src') for img in problem[0].findAll('img')]
    links  = [lnk.get('href') for lnk in problem[0].findAll('a')]
    return heading, str(problem[0]), images+links

def write_content(num, heading, html, images):
    """ Write the problem description to file."""
    with open(os.path.join('html', 'prob%03d.html' % num), 'wb') as txt_file:
        txt_file.write('<h3>Problem %03d</h3>\n' % num)
        txt_file.write('<h4>'+heading.text+'</h4>\n')
        txt_file.write(html)
    for img in images:
        img_path = os.path.join('html', img)
        if not os.path.exists(img_path):
            print 'fetching image: %s' % img
            data = requests.get('%s%s' % (EULER, img))
            img_path_dir = os.path.join(*os.path.split(img_path)[:-1])
            if not os.path.exists(img_path_dir):
                os.makedirs(img_path_dir)
            with open(img_path, 'wb') as img_file:
                img_file.write(data.content)

def main():
    """ Main function"""
    if len(sys.argv) == 3:
        finish = int(sys.argv[-1])
        start = int(sys.argv[-2])
    else:
        start = finish = int(sys.argv[-1])

    for num in xrange(start, finish+1):
        print 'fetching problem %s' % num
        heading, paras, images = get_html(num)
        write_content(num, heading, paras, images)

if __name__ == '__main__':
    main()
