import sys
from typing import List

import numpy as np

def solve (N: int, K: int, h: List[int]) -> int:

    dp = np.zeros(N, dtype=int)
    h = np.array(h)
    for i in range(1, N):
        dp[i] = min(dp[max(0, i-K): i] + np.abs(h[i] - h[max(0, i-K): i]))

    return dp[N-1]

def main () -> None:

    input = sys.stdin.readline

    N, K = [int(x) for x in input().split()]
    h = [int(x) for x in input().split()]

    result = solve(N, K, h)
    print(result)

    return

if __name__ == '__main__':
    main()
