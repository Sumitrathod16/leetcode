class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Case 1: nums is a cyclic rotation of [0, 1, ..., n-1]
        bool ascending = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n) {
                ascending = false;
                break;
            }
        }

        if (ascending) {
            int s = nums[0];

            if (s == 0) return 0;

            // Rotate left directly, or reverse twice
            return min(n - s, s + 2);
        }

        // Case 2: nums is a cyclic rotation of [n-1, ..., 1, 0]
        bool descending = true;

        for (int i = 0; i < n; i++) {
            int expected = (nums[0] - i + n) % n;

            if (nums[i] != expected) {
                descending = false;
                break;
            }
        }

        if (descending) {
            int s = (n - 1 - nums[0] + n) % n;

            // Rotate then reverse, or reverse then rotate
            return min(s + 1, n - s + 1);
        }

        return -1;
    }
};