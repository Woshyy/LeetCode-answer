class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for (int &n : nums) n |= ((nums[n] & 0xffff) << 16);
        for (int &n : nums) n >>= 16;
        return nums;
    }
};