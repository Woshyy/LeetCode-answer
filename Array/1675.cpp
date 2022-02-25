class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
      int min = INT_MAX;
      priority_queue<int> pq;
      for (int i = 0; i < nums.size(); ++i)
      {
        if (!isEven(nums[i])) 
        {
          pq.push(nums[i] * 2);
          if (nums[i] < min) min = nums[i] * 2;
        }
        else 
        {
          pq.push(nums[i]);
          if (nums[i] < min) min = nums[i];
        }
      }

      int temp;
      while(isEven(pq.top())) 
      {
        temp = pq.top();
        pq.pop();
        temp /= 2;
        min = Math.min(temp, min);
        pq.push(temp);
      }

      return pq.top() - min;
    }

    bool isEven(int n)
    {
      return n % 2 == 0 ? true : false;
    }
};
