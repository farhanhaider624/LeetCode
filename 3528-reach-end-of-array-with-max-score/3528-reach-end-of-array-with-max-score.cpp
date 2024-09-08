class Solution {
public:
#define ll long long
    long long findMaximumScore(vector<int>& arr) {
        ll totalScore = 0;
        ll currentPos = 0, n = arr.size();

        while (currentPos < n - 1) {
            ll nextPos = currentPos + 1;
            while (nextPos < n && arr[nextPos] <= arr[currentPos]) {
                nextPos++;
            }

            if (nextPos >= n) {
                nextPos = n - 1;
            }

            totalScore += (nextPos - currentPos) * arr[currentPos];
            currentPos = nextPos;
        }

        return totalScore;
    }
};