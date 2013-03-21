
class Pyramid():
    val = 0
    sum = 0
    left = None
    right = None
    summed = False

    def __init__(self, num):
        self.val = num
        self.sum = num
    def set_left(self, l):
        self.left = l
    def set_right(self, r):
        self.right = r
    
    def get_sum(self):
        if not self.summed:
            l = 0
            r = 0
            if self.left:
                l = self.left.get_sum()
            if self.right:
                r = self.right.get_sum()
            self.sum = self.val+max(l,r)
            self.summed = True
            return self.sum
        else:
            return self.sum

def new_line(prev, this):
    """ prev is a list of pyramids created in the previous line
    this is a string 34 34 23 etc... to be inserted on this line
    """
    pyramids = []
    for elem in this.split():
        p = Pyramid(int(elem))
        pyramids.append(p)
        
    for elem in range(len(prev)):
        prev[elem].set_left(pyramids[elem])
        prev[elem].set_right(pyramids[elem+1])
    return pyramids

def read_file(file):
    pyr = []
    lines = file.readlines()
    root = Pyramid(int(lines[0].strip().split()[0]))
    firstlevel = [root]
    pyr.append(firstlevel)
    for elem in range(1,len(lines)):
        pyr.append(new_line(pyr[elem-1],lines[elem]))
    return pyr
        
    

if __name__ == "__main__":
    import sys
    f = open(sys.argv[1])
    pyramid = read_file(f)
    print 'read file'
    print pyramid[0][0].get_sum()
