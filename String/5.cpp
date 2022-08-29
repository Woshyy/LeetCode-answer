#include <stdio.h>
#include <iostream>

using namespace std;

string longestPalindrome(string s);
int searchForPalindrome(const string &s, int start, int end);

int main() {
    cout << longestPalindrome("babad") << endl;
    return 0;
}

string longestPalindrome(string s) {
    int size = s.size(), c_len, start = 0, end = 0;
    
    if (size < 2) return s;
    
    for (int i = 0; i < size; ++i)
    {
        c_len = max(searchForPalindrome(s, i, i), searchForPalindrome(s, i, i+1)); 
        
        if (c_len > end - start + 1)
        {
            start = i - (c_len - 1)/2;
            end = i + c_len/2;
            cout << start << " " << end << endl;
        }
    }
    
    return s.substr(start, end - start + 1);
}
    
int searchForPalindrome(const string &s, int start, int end)
{
    while (start >= 0 && end < s.size() && s[end] == s[start])
    {
        start--;
        end++;
    }

    return end - start - 1;
}