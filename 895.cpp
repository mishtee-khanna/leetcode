#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class FreqStack {
private:
    unordered_map<int, int> frequency_map; // Maps value -> total frequency
    unordered_map<int, stack<int>> group_map; // Maps frequency -> stack of elements
    int max_frequency;

public:
    FreqStack() {
        max_frequency = 0;
    }
    
    void push(int val) {
        // Increment the frequency of the value
        int freq = ++frequency_map[val];
        
        // Update the global maximum frequency if this surpasses it
        if (freq > max_frequency) {
            max_frequency = freq;
        }
        
        // Push the value into the stack corresponding to its current frequency level
        group_map[freq].push(val);
    }
    
    int pop() {
        // The most frequent element closest to the top is at group_map[max_frequency]
        int val = group_map[max_frequency].top();
        group_map[max_frequency].pop();
        
        // Decrement the frequency of the popped element in our main map
        frequency_map[val]--;
        
        // If the stack for the current max_frequency becomes empty,
        // we decrement the max_frequency level
        if (group_map[max_frequency].empty()) {
            max_frequency--;
        }
        
        return val;
    }
};

int main() {
    FreqStack* freqStack = new FreqStack();
    
    freqStack->push(5); // stack: [5]
    freqStack->push(7); // stack: [5, 7]
    freqStack->push(5); // stack: [5, 7, 5]
    freqStack->push(7); // stack: [5, 7, 5, 7]
    freqStack->push(4); // stack: [5, 7, 5, 7, 4]
    freqStack->push(5); // stack: [5, 7, 5, 7, 4, 5]
    
    // Most frequent is 5 (appears 3 times)
    cout << "Popped: " << freqStack->pop() << " (Expected: 5)" << endl; 
    
    // Remaining tie for max frequency (2) between 5 and 7. 
    // 7 is closer to the top, so 7 is popped.
    cout << "Popped: " << freqStack->pop() << " (Expected: 7)" << endl; 
    
    // Remaining max frequency is 2 for 5.
    cout << "Popped: " << freqStack->pop() << " (Expected: 5)" << endl; 
    
    // Remaining max frequency is 1. Order of stack: [5, 7, 4]. 4 is closest to top.
    cout << "Popped: " << freqStack->pop() << " (Expected: 4)" << endl; 

    delete freqStack;
    return 0;
}