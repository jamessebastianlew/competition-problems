def solve():
    n = int(input())
    s = input()
    m = len(s)
    nw = []
    for i in range(m):
        nw.append(str((ord(s[i]) - ord('A'))&1))
    nw = ''.join(nw)
    if nw=="0000000" or (nw=="1111111" and n<127):
        print("Impossible")
        return
    if nw=="1111111":
        print(s)
        return

    mx = 0
    mxi = 0
    fnd = False
    for i in range(m):
        tmp = int(nw[i:] + nw[:i], 2)
        if tmp > mx and tmp <= n:
            mx = tmp
            mxi = i
            fnd = True

    if not fnd:
        print("Impossible")
    else:
        print(s[mxi:] + s[:mxi])
        
t = int(input())
for _ in range(t):
    solve()

