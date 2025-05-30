# D. Closest Pair of Points

**Problem type**: Geometry, divide and conquer, sweep line optimization.

## Description

You are given a set `A` consisting of `n` pairwise distinct points on the 2D plane.  
Your task is to find **two points whose Euclidean distance is the smallest among all pairs** in the set.

> Note: You are **not allowed to use any associative array or dictionary-like data structures** provided by your programming language.  
> In particular, in C++, it is forbidden to use STL containers whose names contain `set` or `map`.

## Input

- The first line contains an integer `n` (2 ≤ n ≤ 10^6) — the number of points.
- Each of the next `n` lines contains two integers `xᵢ yᵢ` separated by a space, where:
  - −10^7 ≤ xᵢ, yᵢ ≤ 10^7
- All points are distinct.

## Output

- Output two lines, each containing the coordinates of one of the two closest points, in the same format as in the input (`x y`).
- If there are multiple pairs of points with the same minimal distance, you may output any of them.
