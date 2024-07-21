class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if (a.empty()) {
        return 0;
        }

        sort(a.begin(), a.end());
        int longestCount = 1;
        int currentCount = 1;

        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i - 1] + 1) {
                currentCount++;
                }
            else if (a[i] != a[i - 1]) {
                currentCount = 1;
            }
                longestCount = max(longestCount, currentCount);
        }    

    return longestCount;
    }
};

