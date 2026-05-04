#include <iostream>
#include <array>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <vector>

using namespace std;

class SudokuSolver {
private:
    int grid[9][9];
    bool row_used[9][10];   // row_used[i][num] = true if num used in row i
    bool col_used[9][10];   // col_used[j][num] = true if num used in col j  
    bool box_used[9][10];   // box_used[k][num] = true if num used in box k
    int backtracks = 0;
    
    int get_box_index(int r, int c) {
        return (r / 3) * 3 + c / 3;
    }
    
    bool is_valid(int r, int c, int num) {
        int box = get_box_index(r, c);
        return !row_used[r][num] && !col_used[c][num] && !box_used[box][num];
    }
    
    bool find_empty(int& r, int& c) {
        for (r = 0; r < 9; r++) {
            for (c = 0; c < 9; c++) {
                if (grid[r][c] == 0) return true;
            }
        }
        return false;
    }
    
    bool solve() {
        int r, c;
        if (!find_empty(r, c)) return true;
        
        int box = get_box_index(r, c);
        for (int num = 1; num <= 9; num++) {
            if (is_valid(r, c, num)) {
                grid[r][c] = num;
                row_used[r][num] = col_used[c][num] = box_used[box][num] = true;
                
                backtracks++;
                if (solve()) return true;
                
                // Backtrack
                grid[r][c] = 0;
                row_used[r][num] = col_used[c][num] = box_used[box][num] = false;
            }
        }
        return false;
    }
    
public:
    SudokuSolver() {
        // Initialize empty
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j] = 0;
            }
            for (int k = 0; k < 10; k++) {
                row_used[i][k] = col_used[i][k] = box_used[i][k] = false;
            }
        }
    }
    
    bool load_from_user() {
        cout << "\n🎮 ENTER YOUR 9x9 SUDOKU (0 = empty):" << endl;
        for (int i = 0; i < 9; i++) {
            cout << "Row " << (i+1) << ": ";
            for (int j = 0; j < 9; j++) {
                int num;
                if (!(cin >> num) || num < 0 || num > 9) {
                    cout << "\n❌ ERROR: Enter 0-9 only!" << endl;
                    return false;
                }
                grid[i][j] = num;
            }
        }
        setup_tracking();
        return true;
    }
    
    bool load_example() {
        int example[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j] = example[i][j];
            }
        }
        setup_tracking();
        return true;
    }
    
    bool solve_puzzle() {
        auto start = chrono::high_resolution_clock::now();
        bool result = solve();
        auto end = chrono::high_resolution_clock::now();
        
        auto time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "\n⏱️  TIME: " << time_ms << " μs | 🔄 BACKTRACKS: " << backtracks << endl;
        return result;
    }
    
    void print_grid() const {
        cout << "\n╔═══════════════════════════════════════╗" << endl;
        for (int i = 0; i < 9; i++) {
            if (i % 3 == 0 && i != 0) cout << "╠═══╦═══╦═══╪═══╦═══╦═══╪═══╦═══╦═══╗" << endl;
            else cout << "║";
            
            for (int j = 0; j < 9; j++) {
                cout << " " << setw(2) << grid[i][j];
                if (j % 3 == 2) cout << " ║";
            }
            cout << endl;
        }
        cout << "╚═══╩═══╩═══╧═══╩═══╩═══╧═══╩═══╩═══╝" << endl;
    }
    
private:
    void setup_tracking() {
        // Reset tracking
        for (int i = 0; i < 9; i++) {
            for (int k = 0; k < 10; k++) {
                row_used[i][k] = col_used[i][k] = box_used[i][k] = false;
            }
        }
        
        // Mark given numbers
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int num = grid[i][j];
                if (num != 0) {
                    int box = get_box_index(i, j);
                    row_used[i][num] = col_used[j][num] = box_used[box][num] = true;
                }
            }
        }
    }
};

int main() {
    cout << "🔥 SUDOKU SOLVER - FULLY INTERACTIVE 🔥" << endl;
    
    SudokuSolver solver;
    cout << "\n📋 LOADING EXAMPLE PUZZLE..." << endl;
    solver.load_example();
    
    cout << "ORIGINAL:" << endl;
    solver.print_grid();
    
    if (solver.solve_puzzle()) {
        cout << "\n✅ EXAMPLE SOLVED!" << endl;
        solver.print_grid();
    }
    
    // FULL USER INPUT
    cout << "\n🎯 SOLVE YOUR OWN PUZZLE? (y/n): ";
    char choice;
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        SudokuSolver user_solver;
        if (user_solver.load_from_user()) {
            cout << "\nYOUR PUZZLE:" << endl;
            user_solver.print_grid();
            
            if (user_solver.solve_puzzle()) {
                cout << "\n🎉 YOUR PUZZLE SOLVED!" << endl;
                user_solver.print_grid();
            } else {
                cout << "\n❌ NO SOLUTION EXISTS!" << endl;
            }
        }
    }
    
    cout << "\n✨ Thanks for playing!" << endl;
    return 0;
}