
d = {'a': 1, 'c': 3, 'b': 2, 'e': 5, 'd': 4, 'g': 7, 'f': 6, 'i': 9, 'h': 8, 'k': 11, 'j': 10, 'm': 13, 'l': 12, 'o': 15, 'n': 14, 'q': 17, 'p': 16, 's': 19, 'r': 18, 'u': 21, 't': 20, 'w': 23, 'v': 22, 'y': 25, 'x': 24, 'z': 26}

def word_score(word, pos):
    sum = 0
    for elem in word:
        sum = sum+d[elem]
    return sum * pos

total_score=0
f = open('prob22-data')
line = lines = f.readlines()[0]
cleanline = line.replace("\"",'')
words = cleanline.split(',')
words.sort()
for elem in range(len(words)):
    total_score = total_score + word_score(words[elem].lower(),elem+1)
print total_score
