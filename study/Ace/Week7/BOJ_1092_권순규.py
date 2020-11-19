'''
https://www.acmicpc.net/problem/1092
'''
import sys
N = int(input())
limit = list(map(int,input().split()))
limit.sort(key=lambda x:-x)
M = int(input())
weight = list(map(int,input().split()))
weight.sort()
answer = 0

while True:
    flag = False
    stack=[]
    for i in limit:
        if weight[-1] <= i:
            weight.pop()
            flag = True
            if not weight:
                answer += 1
                print(answer)
                sys.exit(0)
            
    if flag:
        answer += 1
    else:
        break
if weight:
    print(-1)
else:
    print(answer)

