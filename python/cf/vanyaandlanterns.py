n, l = map(int,input().split())
lst = list(map(int,input().split()))
lst += [0,l]
lst.sort()
lst[0] = -lst[1]
lst[len(lst)-1] = lst[len(lst)-1] - lst[len(lst)-2] + lst[len(lst)-1]

mx = 0
for i in range(len(lst)-1):
    if lst[i+1]-lst[i] > mx:
        mx = lst[i+1]-lst[i]

print(mx/2)
    





