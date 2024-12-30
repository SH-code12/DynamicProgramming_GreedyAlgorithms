# Problem Description

This repository contains C++ solutions to a set of
computational problems related to algorithms and 
data structures.

## Part 1: Dynamic Programming

### Question 1:  Minimal Difference in Coin Division
### Description
Determine the most fair division of coins between two people by minimizing the difference between their respective totals.
#### Input
- A line with the number of problems `n`.
- For each problem:
    - A line with a non-negative integer `m` (number of coins, `m ≤ 100`).
    - A line with `m` integers representing coin values (1 to 500).

#### Output
For each problem, output the minimal positive difference between the two totals.

---

### Question 2: Original String Possibilities
#### Description
Given a string `s` received by a faulty sender, calculate the number of possible original strings.
- `w` becomes `uu`
- `m` becomes `nn`

#### Input
- A string `s` (1 ≤ |s| ≤ 10^5), containing only lowercase Latin letters.

#### Output
An integer representing the number of original string possibilities modulo 10^9+7.

---

### Question 3: Maximum Value Stolen
#### Description
Given the maximum weight a truck can carry and information about bags, calculate the maximum value the robber can steal.

#### Input
- The first line contains an integer `N` (number of test cases).
- For each test case:
    - A line with integers `K` (maximum weight, 8 ≤ K ≤ 1000) and `M` (number of bags, 1 ≤ M ≤ 50).
    - `M` lines, each with two integers:
        - `A` (weight, 8 ≤ A ≤ 200)
        - `B` (value, 1 ≤ B ≤ 25)

#### Output
For each test case, output a sentence:  
`Hey stupid robber, you can get P.` where `P` is the maximum value.

--- 

### Question 4: Treasure Diving
#### Description
Maximize the amount of gold recovered by selecting treasures subject to time constraints for diving and resurfacing.

#### Input
- Several test cases:
    - The first line contains integers `t` (time in seconds) and `w` (time constant for diving and resurfacing).
    - The second line contains the number of treasures `n`.
    - The next `n` lines each contain two integers:
        - `di` (depth)
        - `vi` (quantity of gold)

#### Output
For each dataset:
- Maximum amount of gold that can be recovered.
- Number of treasures recovered.
- Each recovered treasure's depth and value.

---

### Question 5: Longest Increasing Subsequence
#### Description
Find the length of the longest increasing subsequence in a list.

#### Input
- An integer `N` (1 ≤ N ≤ 10).
- A line with `N` integers (1 ≤ each number ≤ 20).

#### Output
The length of the longest increasing subsequence.

## Part 2: Greedy Algorithms and MST

### Question 1: Maximize Content Children
#### Description
You are an awesome parent who wants to give cookies to your children. Each child has a "greed factor," and each cookie has a size. A child will only be content if the cookie size is greater than or equal to their greed factor. The goal is to maximize the number of content children.

#### Input
- An array `g` of integers, representing greed factors.
- An array `s` of integers, representing cookie sizes.

#### Output
The maximum number of content children.

**Explanation:** Both children can be satisfied.

---

### Question 2: Minimum CPU Intervals
#### Description
Given an array of tasks labeled with uppercase English letters and a cooldown period `n`, find the minimum number of CPU intervals required to complete all tasks, adhering to the cooldown constraints.

#### Input
- An array `tasks` of characters (`A-Z`).
- An integer `n`, representing the cooldown period.

#### Output
The minimum number of intervals required to complete all tasks.

**Explanation:** A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

---

### Question 3: Valid Path in Solution
#### Description
Determine whether there is a valid path between a source and a destination in a given undirected graph represented by its edges.

#### Input
- An integer `n`, the number of vertices.
- A 2D array `edges`, where `edges[i] = [u, v]` denotes an edge between vertices `u` and `v`.
- Two integers `source` and `destination`.

#### Output
`true` if there is a valid path from `source` to `destination`, otherwise `false`.

**Explanation:** There are two paths from vertex 0 to vertex 2: 0 -> 1 -> 2 and 0 -> 2.

---

### Question 4: Minimal Cost of Safe Roads
#### Description
In the kingdom of Olympia, you must create a gift of gold and silver coins to make all roads safe. Find the minimal cost of such a gift that ensures a safe path between every pair of cities.

#### Input
- Integers `N` (cities) and `M` (roads).
- Integers `G` (gold coin cost) and `S` (silver coin cost).
- An array of roads, each represented as `[xi, yi, gi, si]`:
    - `xi`, `yi`: cities connected by the road.
    - `gi`, `si`: minimum gold and silver coins required.

#### Output
The minimal cost in Olympian tugriks, or `-1` if no such gift exists.

---

### Question 5: Minimum Distance Sum in Binary
#### Description
In HackerLand, all road lengths are powers of two. Determine the sum of minimum distances between each pair of cities and return the result in binary format.

#### Input
- Integers `N` (cities) and `M` (roads).
- An array of roads, each represented as `[Ai, Bi, Ci]`:
    - `Ai`, `Bi`: cities connected by the road.
    - `Ci`: power of two for the road length.

#### Output
The sum of minimum distances in binary.

---




