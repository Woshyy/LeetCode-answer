class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        char *start, *end;
        for (string &word : words)
        {
            start = &word.front();
            end = &word.back();
            while (start < end)
            {
                if (*start != *end) break;
                ++start;
                --end;
            }
            if (start >= end) return word;
        }
        return "";
    }
};
