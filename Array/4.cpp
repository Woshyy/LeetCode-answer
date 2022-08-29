class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
        {
            findMedianSortedArrays(nums2, nums1);
        }

        int nums1Size = nums1.size(), nums2Size = nums2.size();
        int total = nums1Size + nums2Size;
        int half = total / 2; 

        int l = 0, r = nums1Size - 1, i, j, nums1Left, nums1Right, nums2Left, nums2Right;
        while (true)
        {
            i = (l + r) / 2; //nums1
            j =  half - i - 2; //nums2

            nums1Left = i >= 0 ? nums1[i] : INT_MIN;
            nums1Right = i + 1 < nums1Size ? nums1[i + 1] : INT_MAX;
            nums2Left = j >= 0 ? nums2[i] : INT_MAX;
            nums2Right = j + 1 < nums2Size ? nums2[i + 1] : INT_MAX;
        }

        if (nums1Left <= nums2Right && nums2Left <= nums1Right)
        {
            //Odd
            if (total % 2 != 0) return min(nums1Right, nums2Right);

            //Even
            return (max(nums1Left, nums2Left) + max(nums1Right, nums2Right))/2;
        }
        else if (nums1Left > nums2Right)
        {
            r = i - 1;
        }
        else
        {
            l = i + 1;
        }
    }
};