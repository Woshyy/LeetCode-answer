class Solution {
public:
    
    string removeKdigits(string num, int k) {
      int n = num.size();

      if (k == n) return "0";

      stack<char> stack;
      string ans = "";

      for (char c : num) 
      {
        while(!st.empty() && st.top() > c && k > 0) 
        {
          st.pop();
          k--;
        }

        if (st.empty() && c == '0') continue;
        st.push(c); 
      }

      while(k > 0 && !st.empty())
      {
        st.pop();
        k--;
      }

      while(!st.empty())
      {
        ans = st.top() + ans;
        st.pop();
      }

      return ans;

    }
};
