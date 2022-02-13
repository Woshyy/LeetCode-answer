class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0, current;
        for (string &sentence : sentences) {
            current = 1;
            for (char c : sentence) {
                if (c == ' ') ++current;
            }
            if (current > max) max = current;
        }
        return max;
    }
};