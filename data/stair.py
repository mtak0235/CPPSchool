import sys
import time
input = sys.stdin.readline
n = int(input())
memo = [[], [[1]], [[1, 1], [2]]] + [[] for _ in range(1000)]
start = time.time()
def recurse(i):
    if len(memo[i]) != 0:
        return memo[i]
    for j in recurse(i - 1):
        memo[i].append(j + [1])
    for k in recurse(i - 2):
        memo[i].append(k + [2])
    return memo[i]
recurse(n)
# for p in memo[n]:
#     for pp in p:
#         print(pp, end=", ")
#     print()
print(len(memo[n]))
end = time.time()
print(end - start)