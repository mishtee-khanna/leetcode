#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        int rightSum = 0;
        int maxPoints = 0;

        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }

        maxPoints += leftSum;

        int n = cardPoints.size();
        for(int i = 0; i < k; i++){
            leftSum -= cardPoints[k - 1 - i];
            rightSum += cardPoints[n - 1 - i];
            maxPoints = max(maxPoints, leftSum + rightSum);
        }

        return maxPoints;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1}; // Input array of card points
    int k = 3; // Number of cards to pick

    int maxScore = sol.maxScore(cardPoints, k);
    cout << "The maximum score by picking " << k << " cards is: " << maxScore << endl;

    return 0;
}