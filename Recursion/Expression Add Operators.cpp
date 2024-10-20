class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, num, target, "", ans, 0, 0);
        return ans;
    }
private:
    void solve(int index, const string& num, int target, string curr, vector<string>& ans, long prev, long res) {
        if (index == num.size()) {
            if (res == target) {
                ans.push_back(curr);
            }
            return;
        }
        string st = "";
        long currRes = 0;
        for (int i = index; i < num.size(); i++) {
 
            if (i > index && num[index] == '0') break;

            st = num.substr(index, i - index + 1);
            currRes = stol(st);

            if (index == 0) {
                solve(i + 1, num, target, st, ans, currRes, currRes);
            } else {
                solve(i + 1, num, target, curr + "+" + st, ans, currRes, res + currRes);
                solve(i + 1, num, target, curr + "-" + st, ans, -currRes, res - currRes);
                solve(i + 1, num, target, curr + "*" + st, ans, prev * currRes, res - prev + prev * currRes);
            }
        }
    }
};
