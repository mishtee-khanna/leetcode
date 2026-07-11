# 🧩 LeetCode Solutions

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![LeetCode](https://img.shields.io/badge/LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=black)
![Problems Solved](https://img.shields.io/badge/Problems%20Solved-73-brightgreen?style=for-the-badge)
![Last Updated](https://img.shields.io/badge/Updated-2026-blue?style=for-the-badge)

**A personal collection of LeetCode problem solutions in C++, organized by topic for easy reference and interview prep.**

</div>

---

## 📖 Table of Contents

- [About](#-about)
- [Repo Structure](#-repo-structure)
- [Solutions by Topic](#-solutions-by-topic)
  - [Arrays & Hashing](#arrays--hashing)
  - [Two Pointers & Sliding Window](#two-pointers--sliding-window)
  - [Binary Search](#binary-search)
  - [Strings](#strings)
  - [Stacks & Monotonic Structures](#stacks--monotonic-structures)
  - [Linked Lists](#linked-lists)
  - [Trees](#trees)
  - [Graphs (BFS / DFS)](#graphs-bfs--dfs)
  - [Dynamic Programming](#dynamic-programming)
  - [Matrix & Geometry](#matrix--geometry)
  - [Math & Number Theory](#math--number-theory)
  - [Advanced Data Structures](#advanced-data-structures)
- [How to Run a Solution](#-how-to-run-a-solution)
- [Progress](#-progress)
- [Contributing](#-contributing)

---

## 🎯 About

This repo tracks my practice solving [LeetCode](https://leetcode.com/) problems, mainly in **C++**. It's meant as:

- A searchable reference for patterns I've already solved
- A prep log for coding interviews
- A place to revisit and refactor older solutions with cleaner or more optimal approaches

Each file is named after its LeetCode problem number (e.g. `42.cpp` → *Trapping Rain Water*), or a short descriptive name for extra practice problems that aren't numbered.

---

## 📂 Repo Structure

```
leetcode/
├── <problem_number>.cpp     # Solutions named by LeetCode problem #
├── <descriptive_name>.cpp   # Extra practice problems
└── README.md
```

---

## 🗂 Solutions by Topic

<details open>
<summary><h3 id="arrays--hashing">🔢 Arrays &amp; Hashing</h3></summary>

| # | Problem | File |
|---|---------|------|
| 217 | Contains Duplicate | [`217.cpp`](217.cpp) |
| 219 | Contains Duplicate II | [`219.cpp`](219.cpp) |
| 242 | Valid Anagram | [`242.cpp`](242.cpp) |
| 290 | Word Pattern | [`290.cpp`](290.cpp) |
| 350 | Intersection of Two Arrays II | [`350.cpp`](350.cpp) |
| 929 | Unique Email Addresses | [`929.cpp`](929.cpp) |
| 1207 | Unique Number of Occurrences | [`1207.cpp`](1207.cpp) |
| 1408 | String Matching in an Array | [`1408.cpp`](1408.cpp) |
| 1455 | Check If a Word Occurs as a Prefix of Any Word | [`1455.cpp`](1455.cpp) |
| 2185 | Counting Words With a Given Prefix | [`2185.cpp`](2185.cpp) |
| 3866 | First Unique Even Number | [`3866.cpp`](3866.cpp) |
| — | Maximum Number of Balloons | [`maximum_number_of_balloons.cpp`](maximum_number_of_balloons.cpp) |
| — | Count Strings in a Substring (practice) | [`no_of_strings_in_substring.cpp`](no_of_strings_in_substring.cpp) |
| — | Lucky Seven (practice) | [`lseven.cpp`](lseven.cpp) |

</details>

<details open>
<summary><h3 id="two-pointers--sliding-window">↔️ Two Pointers &amp; Sliding Window</h3></summary>

| # | Problem | File |
|---|---------|------|
| 15 | 3Sum | [`15.cpp`](15.cpp) |
| 16 | 3Sum Closest | [`16.cpp`](16.cpp) |
| 18 | 4Sum | [`18.cpp`](18.cpp) |
| 42 | Trapping Rain Water | [`42.cpp`](42.cpp) |
| 167 | Two Sum II – Input Array Is Sorted | [`167.cpp`](167.cpp) |
| 189 | Rotate Array | [`189.cpp`](189.cpp) |
| 345 | Reverse Vowels of a String | [`345.cpp`](345.cpp) |
| 633 | Sum of Square Numbers | [`633.cpp`](633.cpp) |
| 1248 | Count Number of Nice Subarrays | [`1248.cpp`](1248.cpp) |

</details>

<details open>
<summary><h3 id="binary-search">🔍 Binary Search</h3></summary>

| # | Problem | File |
|---|---------|------|
| 74 | Search a 2D Matrix | [`74.cpp`](74.cpp) |
| 162 | Find Peak Element | [`find_peak_element.cpp`](find_peak_element.cpp) |
| 278 | First Bad Version | [`first_bad_version.cpp`](first_bad_version.cpp) |
| 367 | Valid Perfect Square | [`valid_perfect_sqr.cpp`](valid_perfect_sqr.cpp) |
| 374 | Guess Number Higher or Lower | [`guess_number_high_or_low.cpp`](guess_number_high_or_low.cpp) |
| 875 | Koko Eating Bananas | [`koko_eating_banana.cpp`](koko_eating_banana.cpp) |
| 1011 | Capacity To Ship Packages Within D Days | [`capacity_to_ship_packages.cpp`](capacity_to_ship_packages.cpp) |
| 1283 | Find the Smallest Divisor Given a Threshold | [`smallest_divisor.cpp`](smallest_divisor.cpp) |
| 1984 | Minimum Difference Between Highest and Lowest of K Scores | [`1984.cpp`](1984.cpp) |
| 33 | Search in Rotated Sorted Array | [`search_in_rotated_sorted_array.cpp`](search_in_rotated_sorted_array.cpp) |

</details>

<details open>
<summary><h3 id="strings">🔤 Strings</h3></summary>

| # | Problem | File |
|---|---------|------|
| 8 | String to Integer (atoi) | [`str_to_int.cpp`](str_to_int.cpp) |
| 151 | Reverse Words in a String | [`reverse_full_sentence.cpp`](reverse_full_sentence.cpp) |
| 205 | Isomorphic Strings | [`205.cpp`](205.cpp) |
| 387 | First Unique Character in a String | [`387.cpp`](387.cpp) |
| 389 | Find the Difference | [`389.cpp`](389.cpp) |
| 443 | String Compression | [`443.cpp`](443.cpp) · [`string_compress.cpp`](string_compress.cpp) |
| 459 | Repeated Substring Pattern | [`459.cpp`](459.cpp) |
| 557 | Reverse Words in a String III | [`557.cpp`](557.cpp) |
| 796 | Rotate String | [`796.cpp`](796.cpp) |
| 1668 | Max Repeating Substring | [`1688.cpp`](1688.cpp) |
| 1781 | Sum of Beauty of All Substrings | [`1781.cpp`](1781.cpp) |
| 2160 | Minimum Sum of Four Digit Number After Splitting Digits | [`2160.cpp`](2160.cpp) |
| 2578 | Split With Minimum Sum | [`2578.cpp`](2578.cpp) |
| 3407 | Wildcard Pattern Matching (Single `*`) | [`3407.cpp`](3407.cpp) |
| 3756 | Sum and Multiply Queries on a String | [`3756.cpp`](3756.cpp) |

</details>

<details open>
<summary><h3 id="stacks--monotonic-structures">📚 Stacks &amp; Monotonic Structures</h3></summary>

| # | Problem | File |
|---|---------|------|
| 496 | Next Greater Element I | [`496.cpp`](496.cpp) |
| 895 | Maximum Frequency Stack | [`895.cpp`](895.cpp) |
| 1021 | Remove Outermost Parentheses | [`1021.cpp`](1021.cpp) |
| 316 | Remove Duplicate Letters | [`316.cpp`](316.cpp) |
| 321 | Create Maximum Number | [`321.cpp`](321.cpp) |

</details>

<details open>
<summary><h3 id="linked-lists">🔗 Linked Lists</h3></summary>

| # | Problem | File |
|---|---------|------|
| 160 | Intersection of Two Linked Lists | [`160.cpp`](160.cpp) |

</details>

<details open>
<summary><h3 id="trees">🌳 Trees</h3></summary>

| # | Problem | File |
|---|---------|------|
| 94 | Binary Tree Inorder Traversal | [`94.cpp`](94.cpp) |
| 112 | Path Sum | [`112.cpp`](112.cpp) |
| 145 | Binary Tree Postorder Traversal | [`145.cpp`](145.cpp) |

</details>

<details open>
<summary><h3 id="graphs-bfs--dfs">🕸️ Graphs (BFS / DFS)</h3></summary>

| # | Problem | File |
|---|---------|------|
| 79 | Word Search | [`79.cpp`](79.cpp) |
| 2685 | Count the Number of Complete Components | [`2685.cpp`](2685.cpp) |
| 3286 | Find a Safe Walk Through a Grid | [`3286.cpp`](3286.cpp) |

</details>

<details open>
<summary><h3 id="dynamic-programming">🧠 Dynamic Programming</h3></summary>

| # | Problem | File |
|---|---------|------|
| 64 | Minimum Path Sum | [`64.cpp`](64.cpp) |
| 198 | House Robber | [`198.cpp`](198.cpp) |
| 1137 | N-th Tribonacci Number | [`1137.cpp`](1137.cpp) |
| 3020 | Maximum Length of a Symmetric-Pattern Subsequence | [`3020_find_max.cpp`](3020_find_max.cpp) |

</details>

<details open>
<summary><h3 id="matrix--geometry">🧮 Matrix &amp; Geometry</h3></summary>

| # | Problem | File |
|---|---------|------|
| 54 | Spiral Matrix | [`spiral_matrix.cpp`](spiral_matrix.cpp) |
| 118 | Pascal's Triangle | [`118.cpp`](118.cpp) |
| 598 | Range Addition II | [`598.cpp`](598.cpp) |
| 812 | Largest Triangle Area | [`812.cpp`](812.cpp) |
| 836 | Rectangle Overlap | [`836.cpp`](836.cpp) |

</details>

<details open>
<summary><h3 id="math--number-theory">➗ Math &amp; Number Theory</h3></summary>

| # | Problem | File |
|---|---------|------|
| 1232 | Check If It Is a Straight Line | [`1232.cpp`](1232.cpp) |
| 1833 | Maximum Ice Cream Bars | [`1833.cpp`](1833.cpp) |

</details>

<details open>
<summary><h3 id="advanced-data-structures">🏗️ Advanced Data Structures</h3></summary>

| # | Problem | File | Technique |
|---|---------|------|-----------|
| 3737 | Count Subarrays With a Given Sum | [`3737.cpp`](3737.cpp) | Fenwick Tree (BIT) |

</details>

---

## ▶️ How to Run a Solution

Each file is self-contained. Compile and run any solution directly with g++:

```bash
g++ -std=c++17 -O2 -o solution 42.cpp
./solution
```

Most files include a small `main()` with sample test cases so you can verify output immediately.

---

## 📊 Progress

| Metric | Count |
|--------|-------|
| Total solutions | **73** |
| Language | C++ |
| Topics covered | 12 |

> Numbers update as new solutions are added — feel free to open a PR to keep the topic tables current.

---

## 🤝 Contributing

This repo is primarily for personal practice, but if you spot a bug, a more optimal approach, or want to suggest an edge case that isn't handled, PRs and issues are welcome.

---

## ⭐ Support

If this repo helped you study for interviews or learn a new pattern, consider giving it a star!
