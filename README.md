# 🧩 Advanced Sudoku Solver (C++ CLI Application)

---

## 🔍 1. Introduction

This project is a high-performance, command-line based Sudoku Solver developed in C++. It is capable of solving any valid 9×9 Sudoku puzzle using an optimized backtracking algorithm combined with constraint tracking.

The application is designed not only to solve puzzles but also to demonstrate efficient algorithm design, performance optimization, and clean software architecture.

---

## 🎯 2. Objective

* Automatically solve 9×9 Sudoku puzzles
* Accept both predefined and user-input grids
* Ensure correctness using strict constraint validation
* Optimize solving time using efficient data structures
* Provide performance metrics (execution time & backtracking count)

---

## 🧠 3. System Description

The solver uses a **recursive backtracking algorithm**, which systematically fills empty cells while ensuring that Sudoku rules are satisfied.

To improve efficiency, the program maintains three constraint tracking structures:

* **Row tracking** → ensures no duplicate numbers in rows
* **Column tracking** → ensures no duplicate numbers in columns
* **Box tracking** → ensures no duplicates in 3×3 sub-grids

This avoids repeated validation checks and significantly reduces computation time compared to naive approaches.

Whenever a number cannot lead to a valid solution, the algorithm **backtracks** and tries the next possible value. This continues until the puzzle is solved or determined unsolvable.

---

## ⚙️ 4. Key Features

* 🧠 Optimized backtracking with constraint pruning
* 📊 Efficient lookup using boolean tracking arrays
* 🎮 Interactive user input for custom puzzles
* ⚡ Fast execution (microsecond-level solving)
* 🔄 Backtracking counter for performance analysis
* 🖥️ Structured and formatted Sudoku grid output
* 📦 Preloaded example puzzle for demonstration

---

## 🏗️ 5. System Architecture

### 🔹 Core Components:

* **Grid Manager**
  Stores and manages the 9×9 Sudoku board

* **Constraint Tracker**
  Maintains row, column, and box constraints using boolean arrays

* **Solver Engine**
  Implements recursive backtracking algorithm

* **Input Module**
  Handles user input and validation

* **Output Module**
  Displays formatted Sudoku grid

* **Performance Module**
  Tracks execution time and backtracking steps

---

## 🛠️ 6. Technologies Used

* **C++**
* **Standard Template Library (STL)**
* **Chrono Library** (performance measurement)

---

## 📥 7. Sample Input

```id="sudoku_input2"
Puzzle (0 = empty cells):

5 3 0 | 0 7 0 | 0 0 0
6 0 0 | 1 9 5 | 0 0 0
0 9 8 | 0 0 0 | 0 6 0
------+-------+------
8 0 0 | 0 6 0 | 0 0 3
4 0 0 | 8 0 3 | 0 0 1
7 0 0 | 0 2 0 | 0 0 6
------+-------+------
0 6 0 | 0 0 0 | 2 8 0
0 0 0 | 4 1 9 | 0 0 5
0 0 0 | 0 8 0 | 0 7 9
```

---

## 📤 8. Sample Output

```id="sudoku_output2"
Solved Sudoku:

5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
------+-------+------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
------+-------+------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9
```

---

## 📊 9. Performance Analysis

```id="sudoku_perf2"
Execution Time : 180 – 300 μs (depends on puzzle complexity)
Backtracks     : ~1000 – 5000 (varies with difficulty)
Grid Size      : 9 × 9
```

### 🔹 Time Complexity

* Worst Case: **O(9^(n²))**
* Optimized using constraint tracking → reduces practical runtime significantly

---

## ⚠️ 10. Error Handling

* ❌ Invalid inputs (non-numeric or out of range)
* ❌ Incorrect grid size
* ❌ Unsolvable puzzle detection

---

## 🚀 11. Future Enhancements

* 🎨 GUI-based Sudoku Solver
* 🧠 AI-based solving strategies (heuristics)
* 🎮 Difficulty level classification
* 🔄 Step-by-step solving visualization
* 🧩 Sudoku puzzle generator

---

## 🏁 12. Conclusion

This project demonstrates strong knowledge of algorithm design, recursion, and optimization techniques. By combining backtracking with constraint tracking, it achieves high performance while maintaining accuracy.

It showcases practical software development skills such as modular design, efficient data handling, and interactive CLI development, making it highly suitable for software development internships and technical interviews.

---
