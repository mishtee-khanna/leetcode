#include <iostream>

using namespace std;

// Global variable to hold the secret number dynamically in main
int secret_number = 0;

// The pre-defined API required by the problem statement
int guess(int num) {
    if (num > secret_number) return -1;
    if (num < secret_number) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while (left <= right) {
            // Avoid potential integer overflow
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            
            if (res == 0) {
                return mid; // Found the correct number!
            } else if (res == -1) {
                right = mid - 1; // Guess was higher than pick
            } else {
                left = mid + 1;  // Guess was lower than pick
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solver;
    
    // Set your test scenario here
    int n = 100;
    secret_number = 42; // The number to find
    
    cout << "Searching for secret number between 1 and " << n << "..." << endl;
    
    int result = solver.guessNumber(n);
    
    cout << "Algorithm output: " << result << endl;
    cout << "Expected output:  " << secret_number << endl;
    
    if (result == secret_number) {
        cout << "Status: MATCH! 🎉" << endl;
    } else {
        cout << "Status: MISMATCH! ❌" << endl;
    }
    
    return 0;
}