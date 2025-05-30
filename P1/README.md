# A. Sidewalk Construction

**Course**: Algorithms and Data Structures  
**Problem type**: Programming assignment involving greedy search or path construction.

## Description

You are given a collection of paving blocks, each described by three integers: `l`, `m`, and `r` — representing the length of the left connector, the middle part, and the right connector, respectively.

Your task is to choose a subset of the blocks and arrange them in a linear sequence (a sidewalk), such that:

1. The **left connector of the first block** is `0`.
2. The **right connector of each block** matches the **left connector of the next block**.
3. The **right connector of the last block** is `0`.

Each block may be used **at most once** and **cannot be rotated**.

## Input

- The first line contains an integer `n` (1 ≤ n ≤ 200000), the number of available blocks.
- Each of the following `n` lines contains three integers `l`, `m`, and `r`, representing a single block:
  - `l`, `r` ∈ [0, 10 000]
  - `m` ∈ [1, 10 000]
- All blocks are distinct.

## Output

- If it is **impossible** to form a valid sidewalk, output a single line with the word `BRAK` (meaning "NONE").
- Otherwise, output an integer `s` — the number of blocks used in the solution.
- Then, output `s` lines, each with three integers `l`, `m`, `r`, representing the blocks in order.

If multiple valid solutions exist, you may print any of them.
