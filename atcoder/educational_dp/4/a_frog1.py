from typing import List

def solve (N: int, h: List[int]) -> int:

    dp = [float('inf')] * N
    dp[0] = 0
    for i in range(1, N):
        dp[i] = min(
                    [dp[i]] + 
                    [x + abs(h[i] - h[max(0, i - 2) + j]) for j, x in enumerate(dp[max(0, i - 2): i])]
                )

    return dp[N-1]

def main () -> None:
    N = int(input())
    h = [int(x) for x in input().split()]

    result = solve(N, h)

    print(result)

    return

if __name__ == '__main__':
    main()
