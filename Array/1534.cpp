class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
      int ans = 0;
      int size = arr.size(); 
      for (int i = 0; i < size; ++i)
        {
          for (int j = i + 1; j < size; ++j)
          {
            if (abs(arr[i] - arr[j]) > a) break;
            for (int m = j + 1; m < size; ++m)
            {
              if (abs(arr[j] - arr[m]) <= b && abs(arr[i] - arr[m]) <= c) ++ans;
            }
          }
        }
        return ans;
    }
};
