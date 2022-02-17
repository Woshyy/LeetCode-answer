class Solution {
    public:
        int target;

        vector<vector<int>> ans;

        void solve_recursion(vector<int>& arr, int i, int sum, vector<int> op)
        {
            //If we have gotten out of our array then there is no more
            //possibility so return.
            if (i >= arr.size())
            {
                return;
            }

            //If they are the same than we have found and answer.
            if (arr[i] + sum == target)
            {
                op.push_back(arr[i]);
                ans.push_back(op);
                return;
            }

            //If the value is smaller than we have choice to either
            //use it or not to use it.
            if (arr[i] + sum < target)
            {
                vector<int> op1 = op;
                vector<int> op2 = op;

                op2.push_back(arr[i]);
                solve(arr, i, sum + arr[i], op2);
                solve(arr, i + 1, sum, op1);
            }
            //If it is larger don't useit and move on the next element.
            else
            {
               solve(arr, i + 1, sum , op); 
            }
        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int required_target)
        {
            ans.clear();

            target = required_target;
            vector<int> op;
            sort(candidates.begin(), candidates.end());
            solve_recursion(candidates, 0, 0, op);

            return ans;
        }
};
