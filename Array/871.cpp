class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       priority_queue<int> pq;
       int ans = 0, prev = 0, size = stations.size();
       for (int i = 0; i < size; i++)
       {
        startFuel -= stations[i][0] - prev;
        while (!pq.empty() && startFuel < 0)
        {
            startFuel += pq.top();
            pq.pop();
            ans++;
        }

        if (startFuel < 0) return -1;
        pq.push(stations[i][1]);
        prev = stations[i][0];
       }

       startFuel -= target - prev;
       while (!pq.empty() && startFuel < 0)
       {
        startFuel += pq.top();
        pq.pop();
        ans++;
       }
       if (startFuel < 0) return -1;
       return ans;
    }
};