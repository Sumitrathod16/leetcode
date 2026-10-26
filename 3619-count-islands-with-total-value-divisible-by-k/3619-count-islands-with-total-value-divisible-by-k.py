
class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        count = 0

        def dfs(i, j):
            stack = [(i, j)]
            total = 0

            while stack:
                x, y = stack.pop()

                if (x < 0 or x >= m or y < 0 or y >= n
                        or grid[x][y] == 0):
                    continue

                total += grid[x][y]
                grid[x][y] = 0  # Mark visited

                stack.append((x + 1, y))
                stack.append((x - 1, y))
                stack.append((x, y + 1))
                stack.append((x, y - 1))

            return total

        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    island_sum = dfs(i, j)

                    if island_sum % k == 0:
                        count += 1

        return count
