class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, bool> visited;
        int longest = 0;

        if (nums.size() == 0) return longest;

        for (auto a: nums) {
            visited[a] = true;
        }

        for (auto a: nums) {
            if(!visited[a-1] && visited[a]) {
                int lngst = 1;
                int curr = a;
                
                while(visited[curr + 1]) {
                    curr++;
                    lngst++;
                }

                longest = max(lngst, longest);
            }
        }
        return longest;
    }
};
