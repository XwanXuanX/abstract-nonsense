# How to Tackle a Problem?

In this section I will breifly describe some techniques and thought-processes I learned through practices. In my opinion, being clever and creative in problem solving strategies is the hardest skill to pick up (definitely harder than learning any well-known algorithms or data structures). And, to be frank, learning all kinds of algorithms and data structures **ALONE** is just useless. This has to do with the problem-solving mindset that you should have when you are solving a problem, which we will discuss first.

## Problem-solving mindset

When you are given a problem to solve, how should you think?

## Problem-solving strategies

In this section, I will discuss some high-level problem-solving strategies that we should always be aware of. Each problem (excluding adhoc ones) must have a major "theme" so that they can be pattern-matched and classified. Once the "theme" of the problem is correctly identified, the rest almost always follows naturally.

> **Important Note 1:** It is crucial to understand the distinction between problem-solving strategies and implementation details. Problem-solving strategies are all about identifying theme(s), decomposing into subproblems, and verifying correctness. On the contrary, implementation cares about transforming your strategy into efficient algorithms that doesn't TLE (note that `DFS` and `BFS` is absent from the list below). For example, when someone said that they solved a problem using post-order `DFS`, they are talking about implementation details. At a higher level, it is likely that they've noticed that the problem can be broken down into subproblems and used the `Divide and Conquer` approach to solve it. By now, I believe you already know what we are discussing here.

> **Important Note 2:** A problem-solving strategy is not limited to solve one type of problems (duh). For example, people may think the section `Graph` only applies to problems that explicitly contains the word "graph" or "tree". This is a huge misconception, and, as a matter of fact, the topics of `Graph` show up *much* *much* more often than you think, in *many* different forms. You'll be amazed by this.

> **Important Note 3:** In simpler problems, it generally involves only 1 of those strategies. However, in harder problems, one often needs to employ multiple strategies at different stages to construct a working solution. The complexity of a problem generally shows in 2 dimensions: 1. the combination of different strategies; 2. the difficulty in identifying or using one particular strategy.

> **Less Important Note:** Graph-problems can be solved in non-`Graph` ways, while problems that seems unrelated to graphs can only be solved using their equivalent graph-based formalization. Graph is the most powerful data structure of all time. It is very well researched, and there exists all kinds of well-known algorithms that are designed to solve all kinds of problems! Feeling stuck? Try translating to graph! It's like solving linear PDEs in time domain is hard, but doing so in frequency domain is a breeze. So, in conclusion, `Graph == Fourier Transform`?

> **Another Less Important Note:** I love graphs because they are black magic! 😍

### Reduction

### Well-known Pattern(s)

### Enumeration

### Data Structures

### Divide and Conquer

### Greedy
Greedy is all about vibes. Yes, you heard me correct, it's all about vibes.

### DP

### Sorting

### Binary Search

### Graph

### Adhoc
Oops, bad luck, no help for you buddy 🤣

# Algorithm Collection

* [Primes generating algorithms: Trial Division, Sieve of Eratosthenes, Dijkstra's Approach](https://www.youtube.com/watch?v=fwxjMKBMR7s)

* [Willan's formula, Wilson's theorem, Bertrand's postulate](https://www.youtube.com/watch?v=j5s0h42GfvM)

* [Floyd's cycle detection algorithm (Tortoise and hare)](https://www.youtube.com/watch?v=PvrxZaH_eZ4)

* [Kosaraju's algorithm - finding SCC](https://www.youtube.com/watch?v=Jb1XlDsr46o)

* [Binary lifting (a.k.a. jump pointers)](https://www.youtube.com/watch?v=oib-XsjFa-M)

* [LCA = Eulerian tour + RMQ](https://www.youtube.com/watch?v=sD1IoalFomA&t=743s)

* [Eulerian paths existence](https://www.youtube.com/watch?v=xR4sGgwtR2I)

* [Hierholzer’s algorithm - finding Eulerian path](https://www.youtube.com/watch?v=8MpoO2zA2l4&t=692s)

* [Sparse table - query range](https://www.youtube.com/watch?v=uUatD9AudXo&t=327s)

* [Fenwick tree - query range sum](https://www.youtube.com/watch?v=RgITNht_f4Q)

  * [Imp: Zero-based, pt update, rng query](https://cp-algorithms.com/data_structures/fenwick.html#implementation)

* [Finding bridge in graph](https://www.youtube.com/watch?v=qrAub5z8FeA)

* [Finding articulation point in graph](https://www.youtube.com/watch?v=j1QDfU21iZk)

* [Chicken McNugget Theorem](https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem)

* [Divisibility rules](https://en.wikipedia.org/wiki/Divisibility_rule)

* [Prime factorization & Generating all divisors](https://www.geeksforgeeks.org/generating-all-divisors-of-a-number-using-its-prime-factorization/)

* [Nth Fibonacci number: Fast Doubling Method](https://cp-algorithms.com/algebra/fibonacci-numbers.html#fast-doubling-method)

* [Modular arithmetic: Modular Inverse using Binary Exponentiation](https://cp-algorithms.com/algebra/module-inverse.html#finding-the-modular-inverse-using-binary-exponentiation)

* [Erdős–Szekeres theorem](https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Szekeres_theorem)

* [Graph strong orientation: $Ud \rightarrow SCC$](https://cp-algorithms.com/graph/strong-orientation.html)

# Useful Tools

* [Prime Numbers from 0 to 1,000,000 (1e6)](https://www.mathematical.com/primes0to1000k.html)

* [Prime Numbers from 0 to 1000 billion](http://compoasso.free.fr/primelistweb/page/prime/liste_online_en.php)

* [Prime Factorization Calculator](https://www.calculatorsoup.com/calculators/math/prime-factors.php)

* [Permutation and Combination Calculator](https://www.calculator.net/permutation-and-combination-calculator.html)

* [Powers of 2](http://www.thealmightyguru.com/Pointless/PowersOf2.html)

* [First 500 Fibonacci numbers](https://gist.github.com/brchiu/71bf87f51be35d6e334f4898b1ebd011)

* [Divisors of a Number](https://www.dcode.fr/divisors-list-number)

* [Graph visualizer](https://csacademy.com/app/graph_editor/)

* [*GREATEST TEMPLATE COLLECTION*](https://github.com/the-tourist/algo)

# Techniques

* [Count of smaller elements on right side of each element in an Array using Merge sort](https://www.geeksforgeeks.org/count-of-smaller-elements-on-right-side-of-each-element-in-an-array-using-merge-sort/?ref=ml_lbp)
