class Solution {
void solve(int k, int n, vector<int>& curr, vector<vector<int>>& result, int idx) {
        // Base case: if n becomes negative or we have too many elements in curr
        if(n < 0 || curr.size() > k) 
            return;
        
        // If n is 0 and the size of curr is exactly k, we've found a valid combination
        if(n == 0 && curr.size() == k) {
            result.push_back(curr);
            return;
        }
        
        // Iterate through numbers 1 to 9 starting from idx
        for(int i = idx; i <= 9; i++) {
            curr.push_back(i);        // Include i in the current combination
            solve(k, n - i, curr, result, i + 1); // Recur for the next number
            curr.pop_back();          // Backtrack to explore the next candidate
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(k, n, curr, result, 1);
        return result;
    }
};
