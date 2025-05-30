# C. Chessboard Coloring

**Problem type**: Dynamic programming, bitmask optimization, pattern matching.

## Description

You are given a `5 × n` chessboard, where each cell must be colored either black or white.  
A coloring is considered **valid** if it **does not contain any forbidden 3 × 3 pattern**.

Your task is to determine the number of valid colorings of the chessboard using only black and white cells, such that **no 3×3 subgrid** anywhere on the board matches any of the given forbidden patterns.

A 3×3 pattern is defined as a 3-row block of 3 columns anywhere within the board (i.e., any `3 × 3` submatrix). Each cell in the pattern is represented as either:
- `x` – black cell
- `.` – white cell

Patterns may appear anywhere on the board, and overlapping is allowed. The board is **valid** if it does **not contain any forbidden pattern** as a subgrid.

## Input

- The first line contains three integers: `n`, `p`, and `m`, separated by spaces:
  - `3 ≤ n ≤ 5000` — number of columns on the board
  - `p ≤ 100` — number of forbidden patterns
  - `m ≤ 10^6` — modulus for output

- The next `3p` lines describe the forbidden patterns.
  - Each pattern consists of exactly **3 lines of 3 characters**, using characters:
    - `x` for a black cell
    - `.` for a white cell
  - There are `p` such patterns, each spanning 3 lines.

Some patterns may be duplicated.

## Output

- Output a single integer — the number of valid `5 × n` colorings modulo `m`.
