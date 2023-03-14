#download s3....
'''given a set of points
1. select k points

2. repeat:
-label all points according to the 'cluster' they belong
-update centroids
'''


from pprint import pprint
from typing import Tuple, Sequence, Map , Callable
import matplotlib.pyplot as plt  #???forse
from random import sample
from collections import defaultdict
from functools import partial
from statistics import mean
#quasi tutto viene da matplotlib, pure python standard


Point = Tuple[float, float]
Centroid = Point              #type aliasing
Cluster = Sequence[Point]
Distfunc = Callable[[Point,Point], float]

def guesscentroids(dataset: Sequence[Point], k:int) -> Sequence[Centroid]:
    return sample(dataset, k=k)

def distance(p: Point, q: Point, /):
    return (p[0]-q0)*(p0-q0) + (p1-q1)*(p1-q1)


def label(dataset, centroids, dist) -> Map[Centroid, Cluster]:
    d = defaultdict(list)
    for p in dataset:
        pdist= partial(dist, p)
        centroid = min(centroids, key = pdist)
        d[centroid].append(p)
    return d


def updatecentroids(clusters: Sequence[Cluster])   -> Sequence[Centroid]:
    centroids = []
    for cluster in clusters:
        xc, yc= list(zip(*cluster))
        centroids.append((mean(xc), mean(yc)))
    return centroids

def distortion(labeled_dataset: Mapping[Centroid, Cluster], distance: Distfunc):
    #diocann


    

def _kmeans(dataset, k, n_iter, dist: Distfunc) -> Map[Centroid, Cluster]:
    centroids= guesscentroids(dataset, k)
    for _ in range(n_iter):
        labeled = label(dataset, centroids)
        centroids= updatecentroids(labeled.values())
    labeled = label(dataset, centroids, dist)
    return labeled, distortion(labeled)


def kmeans(dataset, k, inner, outer, dist):
    bestdistorsion = float("inf")
    bestmapping= {}
    for _ in range(outer):
        mapping, distortion= _kmeans(dataset, k, inner)
        if distortion <bestdistorsion:
            bestmapping = mapping
            bestdistorsion= distorsion
    return bestmapping, bestdistorsion


points: Sequence[Point]    #

with open("s3.txt") as f:      #context manager is not a scope, vars survive
    points = [tuple(map(float, line.split() )) for line in f]

#pprint(points, width= 40)


X,Y = list(zip(*points)) 
#ZIP: traspone zippando insieme tutte le x in una tupla, le y in unaltra

d = kmeans(points, k=15, n_iter=10, dist= distance)
centroids= d.keys()


plt.scatter(X,Y, s=0.5)
plt.scatter(Xc, Yc)
plt.show()
