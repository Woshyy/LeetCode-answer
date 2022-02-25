class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int s = 0;
        int n = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
          if (nums[i] < target) ++s;

          if (nums[i] == target) ++n;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) ans.push_back(s + i);
        return ans;
    }
};
