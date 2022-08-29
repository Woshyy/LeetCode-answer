class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        vector<int> count(256, -1);
        int len = 0, l = 0;
        for (int i = 0; i < length; i++)
        {
            if (count[s[i]] >= l)
            {
                l = count[s[i]] + 1;
                len = max(len,(i-l+1));
            }
            count[s[i]] = i;
        }
        return max(len, length-l);
    }
};