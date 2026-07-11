#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list graph representation
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int completeComponentsCount = 0;
        
        // Step 2: Iterate through all vertices to find individual components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertexCount = 0;
                int totalDegreeSum = 0;
                
                // Launch BFS to explore the current component
                queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    
                    vertexCount++;
                    totalDegreeSum += adj[curr].size(); // Accumulate the degree of this vertex
                    
                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                
                // Step 4: Verify if the component is complete
                // In a complete graph, total degree sum must equal V * (V - 1)
                if (totalDegreeSum == vertexCount * (vertexCount - 1)) {
                    completeComponentsCount++;
                }
            }
        }
        
        return completeComponentsCount;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    int n1 = 6;
    vector<vector<int>> edges1 = {{0,1}, {0,2}, {1,2}, {3,4}};
    cout << "Test 1 Output: " << solver.countCompleteComponents(n1, edges1) << " (Expected: 3)" << endl;
    // Explanation: Components are {0,1,2} (complete), {3,4} (complete), and {5} (isolated vertex is complete by definition).
    
    // Test Case 2
    int n2 = 6;
    vector<vector<int>> edges2 = {{0,1}, {0,2}, {1,2}, {3,4}, {3,5}};
    cout << "Test 2 Output: " << solver.countCompleteComponents(n2, edges2) << " (Expected: 1)" << endl;
    // Explanation: {0,1,2} is complete. {3,4,5} forms a path tree but lacks the edge between 4 and 5, so it is not complete.
    
    return 0;
}