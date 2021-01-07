from typing import List

import numpy as np

def solve (n: int, x: List[int], y: List[int]) -> int:
    x_np = np.array(x)
    y_np = np.array(y)

    x_np_ascending = np.sort(x_np)
    y_np_descending = np.sort(y_np)[::-1]

    return np.dot(x_np_ascending, y_np_descending)

def main ():
    T = int(input())
    
    for i in range(T):
        n = int(input())

        x = [int(x) for x in input().split()]
        y = [int(x) for x in input().split()]

        result = solve(n, x, y)
        print(f'Case #{i + 1}: {result}')
    
if __name__ == '__main__':
    main()
