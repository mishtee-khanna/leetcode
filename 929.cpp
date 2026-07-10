#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        
        for (const string& email : emails) {
            string cleanedLocal = "";
            
            // Find the split point between local and domain
            size_t atPos = email.find('@');
            string local = email.substr(0, atPos);
            string domain = email.substr(atPos); // Keeps the '@' and the domain name together
            
            // Process the local name according to rules
            for (char c : local) {
                if (c == '+') {
                    break; // Ignore everything after '+'
                }
                if (c == '.') {
                    continue; // Skip dots entirely
                }
                cleanedLocal += c;
            }
            
            // Combine them back together and insert into our unique tracking set
            uniqueEmails.insert(cleanedLocal + domain);
        }
        
        return uniqueEmails.size();
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<string> emails1 = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
    cout << "Test 1 Output: " << solver.numUniqueEmails(emails1) << " (Expected: 2)" << endl;
    
    // Test Case 2
    vector<string> emails2 = {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"};
    cout << "Test 2 Output: " << solver.numUniqueEmails(emails2) << " (Expected: 3)" << endl;
    
    return 0;
}