class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);
        
        // These variables represent dp[i+1], dp[i+2], and dp[i+3]
        // next1 starts at step n, which just costs costs[n]
        int next1 = costs[n]; 
        // next2 and next3 start out of bounds, so they act as infinity
        int next2 = 1e9; 
        int next3 = 1e9; 

        // Bottom-up transitions: step i goes from n-1 down to 0
        for (int i = n - 1; i >= 0; i--) {
            // Calculate costs for jumping 1, 2, or 3 steps
            int jump1 = 1 + next1; // 1^2 = 1
            int jump2 = 4 + next2; // 2^2 = 4
            int jump3 = 9 + next3; // 3^2 = 9
            
            // Current step cost
            int curr = costs[i] + min({jump1, jump2, jump3});
            
            // Shift the variables for the next iteration (moving backward)
            next3 = next2;
            next2 = next1;
            next1 = curr;
        }

        // The answer is the cost starting from step 0 (now stored in next1)
        return next1;
    }
};