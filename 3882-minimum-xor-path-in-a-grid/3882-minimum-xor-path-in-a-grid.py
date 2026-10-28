
class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])

        dp = [[set() for _ in range(n)] for _ in range(m)]
        dp[0][0].add(grid[0][0])

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                val = grid[i][j]

                if i > 0:
                    for x in dp[i - 1][j]:
                        dp[i][j].add(x ^ val)

                if j > 0:
                    for x in dp[i][j - 1]:
                        dp[i][j].add(x ^ val)

        return min(dp[m - 1][n - 1])
