class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>store1(256,-1);
        vector<int>store2(256,-1);

        for(int i=0; i<s.length(); i++) {
            if(store1[s[i]] != store2[t[i]]) {
                return false;
            }

            store1[s[i]] = i;
            store2[t[i]] = i;
        }
        return true;
    }
};