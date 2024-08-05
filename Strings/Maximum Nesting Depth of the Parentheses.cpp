class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int openBrackets = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openBrackets++;
            } else if (s[i] == ')') {
                openBrackets--;
            }
            result = max(result, openBrackets);
        }
        return result;
    }
};
