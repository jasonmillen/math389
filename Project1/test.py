import numpy as np
from scipy.special import comb

# calculated forumulas

forumulas = {
	1: np.poly1d([1, 0]),
	2: np.poly1d([1.0/2, -1.0/2, 0]),
	3: np.poly1d([1.0/3, 0, -1.0/3, 0])
};

def partition(number):
    answer = set()
    answer.add((number, ))
    for x in range(1, number):
        for y in partition(number - x):
            answer.add(tuple(sorted((x, ) + y)))
    return answer


from operator import mul    # or mul=lambda x,y:x*y
from fractions import Fraction

def nCk(n,k): 
  return int( reduce(mul, (Fraction(n-i, i+1) for i in range(k)), 1) )



with open('partition.txt', 'r') as file:
	for line in file:
		print line,


p1 = np.poly1d([1, 2]);
p2 = np.poly1d([2, 0]);

print(nCk(p1, 2));