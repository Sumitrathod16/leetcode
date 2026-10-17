
class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for (int num : nums) {
            arr.push_back({digitSum(num), num});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> targetIndex;
        for (int i = 0; i < n; i++) {
            targetIndex[arr[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int current = i;
            int cycleSize = 0;

            while (!visited[current]) {
                visited[current] = true;
                cycleSize++;
                current = targetIndex[nums[current]];
            }

            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }

        return swaps;
    }
};
