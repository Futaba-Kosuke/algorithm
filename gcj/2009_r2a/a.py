from typing import List

def solve (n: int, matrix: List[List[int]]) -> int:
    
    result = 0
    for i in range(n):
        for j in range(i, n):
            if not '1' in matrix[j][i+1:]:
                tmp = matrix.pop(j)
                matrix.insert(i, tmp)
                result += j - i
                break

    return result

def main ():
    
    T = int(input())
    for i in range(T):
        n = int(input())
        matrix = [[x for x in list(input())] for i in range(n)] 

        result = solve(n, matrix)
        print(f'Case #{i + 1}: {result}')

if __name__ == '__main__':
    main()
