class Solution {
public:
    /*
        - either 1 or 2 steps, total n step
        - no_of_ways(i th step) = no_of_ways(i - 1 th step) + no_of_ways(i - 2 th step)
        - no_of_ways(1) = 1
        - no_of_ways(2) = 2
    */
    int climbStairs(int n) {
        if (n <= 2 ) return n;
        vector<int> no_of_ways(n+1);
        no_of_ways[1] = 1;
        no_of_ways[2] = 2;

        for (int i = 3; i <= n; i++) {
            no_of_ways[i] = no_of_ways[ i-1 ] + no_of_ways[ i-2 ];
        }

        return no_of_ways[n];
    }
};
