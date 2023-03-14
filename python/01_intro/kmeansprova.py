#download s3....
'''given a set of points
1. select k points

2. repeat:
-label all points according to the 'cluster' they belong
-update centroids
'''


from pprint import pprint
from typing import Tuple, Sequence, Mapping , Callable
import matplotlib.pyplot as plt  #???forse
from random import sample
from collections import defaultdict
from functools import partial
from statistics import mean
#quasi tutto viene da matplotlib, pure python standard



with open("s3.txt") as f:      #context manager is not a scope, vars survive
    points = [tuple(map(float, line.split() )) for line in f]

#pprint(points, width= 40)


X,Y = list(zip(*points)) 
#ZIP: traspone zippando insieme tutte le x in una tupla, le y in unaltra

# d = kmeans(points, k=15, n_iter=10, dist= distance)
# centroids= d.keys()


plt.scatter(X,Y, s=0.5)
#plt.scatter(Xc, Yc)
plt.show()
