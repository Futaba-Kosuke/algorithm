import sys
from typing import List

import numpy as np

def solve (N: int, a: List[List[int]]) -> int:

    dp = np.zeros([N + 1, 3], dtype=int)

    for i in range(1, N + 1):
        # こっちの方が早かった
        for j in range(3):
            dp[i][j] = max(dp[i-1][(j+1)%3] + a[i-1][(j+1)%3], dp[i-1][(j+2)%3] + a[i-1][(j+2)%3])
        # 選択肢が多い場合は使えそう？
        # dp[i] = np.maximum(
        #             np.concatenate([dp[i-1][-2:], dp[i-1][:1]]) + np.concatenate([a[i-1][-2:], a[i-1][:1]]),
        #             np.concatenate([dp[i-1][-1:], dp[i-1][:2]]) + np.concatenate([a[i-1][-1:], a[i-1][:2]])
        #         )

    return max(dp[N])

def main () -> None:

    input = sys.stdin.readline

    N = int(input())
    a = np.array([list(map(int, input().split())) for _ in range(N)])

    result = solve(N, a)
    print(result)

    return

if __name__ == '__main__':
    main()
