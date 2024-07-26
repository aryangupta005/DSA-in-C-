class Solution{
public:
    string reverseWords(string s){
        int n = s.length();
        int j = 0;
        while (s[j] == ' '){
            j++;
        }
        string result = "";
        string helper = "";
        while (j < n){
            if (s[j] != ' '){
                while (j < n && s[j] != ' '){
                    helper.push_back(s[j++]);
                }
                result = helper + " " + result;
                helper = "";
            }
            j++;
        }
        result.pop_back();
        return result;
    }
};
