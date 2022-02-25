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

        void solve_backtracking(int i, vector<int>& arr, vector<int>& temp, int target)
        {
            //We have found an combination so include it to our
            //answers vector and return.
            if (target == 0)
            {
                ans.push_back(temp);
                return;
            }
            
            //If the target is less than zero than there is not any possibly combination
            //Or if we have checked every possible combination than return.
            if (target < 0 || i == arr.size()) return;

            //There is know to choice either addid the current element to the
            //combination of out answers or not.
            
            //Move to the next element without using the current element.
            solve_backtracking(i + 1, arr, temp, target);

            //Move to the next element but using the current element.
            temp.push_back(arr[i]);
            solve_backtracking(i, arr, temp, target - arr[i]);
            temp.pop_back();
        }

        vector<vector<int>> combinationSum_recursion(vector<int>& candidates, int required_target)
        {
            ans.clear();

            target = required_target;
            vector<int> op;
            sort(candidates.begin(), candidates.end());
            solve_recursion(candidates, 0, 0, op);

            return ans;
        }

        vector<vector<int>> combinationSum_backtracking(vector<int>& candidates, int required_target)
        {
            ans.clear();

            vector<int> temp;

            solve_backtracking(0, candidates, temp, target);
            
            return ans;
        }
};
