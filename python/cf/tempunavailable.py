def solve():
    tmpa,tmpb,c,r = map(int, input().split())
    a = min(tmpa,tmpb); b = max(tmpa,tmpb)
    d = c-r; e = c+r
    tmp = min(e,b) - max(a,d)
    tmp = tmp if tmp>0 else 0 # if the overlap is negative
    print(b-a-tmp)

T = int(input())

for _ in range(T):
    solve()


