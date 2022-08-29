#include <stdio.h>
#include <iostream>

using namespace std;

string convert(string s, int numRows);

int main() {
    cout << convert("PAYPALISHIRING", 4) << endl;
    return 0;
}

string convert(string s, int numRows)
{
    if (numRows <= 1) return s;

    int inc = (numRows - 1) * 2, size = s.size(), inc_c;
    string ans;

    //first row
    int i = 0;
    while (i < size) {
        ans.push_back(s[i]);
        i += inc;
    }

    for (int n = 1; n < numRows - 1; ++n) {
        i = n;
        inc_c = (numRows-1 - n) * 2;
        while (i < size) {
            ans.push_back(s[i]);
            if (i + inc_c < size) {
                ans.push_back(s[i + inc_c]);
            }
            i += inc;
        }
    }

    //last row
    i = numRows - 1;
    while (i < size) {
        ans.push_back(s[i]);
        i += inc;
    }

    return ans;
}