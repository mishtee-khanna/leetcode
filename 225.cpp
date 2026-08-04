#include<bits/stdc++.h>

using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    void push(int x) {
        q.push(x);      
        int sz = q.size();
        for(int i = 0; i < sz - 1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main(){
    MyStack stack;

    // Example usage
    stack.push(1);
    stack.push(2);
    cout << "Top element: " << stack.top() << endl; // Should print 2
    cout << "Popped element: " << stack.pop() << endl; // Should print 2
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Should print No

    return 0;
}