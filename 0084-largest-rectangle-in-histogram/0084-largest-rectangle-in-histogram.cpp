class Solution {
public:
    int nextSmallerLeft(int ind, vector<int>& heights) {
        stack<int> st;
        int i = 0;
        while (i < ind) {
            st.push(i);
            while (!st.empty() && heights[st.top()] >= heights[ind]) {
                st.pop();
            }
            i++;
        }
        if (!st.empty())
            return st.top();
        return -1;
    }
    int nextSmallerRight(int ind, vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int i = n - 1;
        while (i > ind) {
            st.push(i);
            while (!st.empty() && heights[st.top()] >= heights[ind]) {
                st.pop();
            }
            i--;
        }
        if (!st.empty())
            return st.top();
        return n;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        for (int i = 0; i < n; i++) {
            int left = nextSmallerLeft(i, heights);
            int right = nextSmallerRight(i, heights);
            cout<<left<<" "<<right<<endl;
            int width = right - left - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};