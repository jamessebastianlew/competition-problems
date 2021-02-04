S = int(input())
solds = input().split('|')
solds = list(map(lambda x: x.replace(' ',''), solds))

matrix = [[0] * S for _ in range(S)]
curr_pos = {}

n = len(solds)
for i in range(n):
    temp = list(map(int, solds[i].split(':')))
    pos = ((temp[1]-1)//S, (temp[1]-1)%S)
    print(pos[0], pos[1])
    matrix[pos[0]][pos[1]] = temp[0]
    solds[i] = int(temp[0])
    curr_pos[solds[i]] = pos

solds.sort()

print(curr_pos)

for _ in range(100000):
    for sold in range(n):



print(solds)
