# B. Multiplication Table

**Problem type**: Efficient data structures, custom heap implementation.

## Description

You are given an `M × M` multiplication table, where each cell at the intersection of the `i`-th row and the `j`-th column contains the product `i × j`.  
Your task is to find the **`k` largest distinct values** in the table and print them in **descending order**.

For example, when `M = 4`, the table looks like:
1 2 3 4
2 4 6 8
3 6 9 12
4 8 12 16
The largest distinct values here are: `16, 12, 9, 8, 6, 4, 3, 2, 1`.

## Input

- One line with two integers `M` and `k`, separated by a space:
  - `1 ≤ M ≤ 10^6`
  - `1 ≤ k ≤ 2·10^6`
- It is guaranteed that the `M × M` table contains **at least `k` distinct values**.

## Output

- Print `k` lines, each containing one of the `k` largest **distinct** values in descending order.

## Constraints

- **Priority queues from standard libraries are not allowed.**
  - In particular:
    - In C++, it is forbidden to use any STL container whose name contains `set`, `map`, or `priority_queue`.
    - You must implement your own solution (e.g., a custom heap or alternative approach).
