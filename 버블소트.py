n = int(input())

arr=[]
for i in range(n):
    arr.append([int(input()), i])

solarr = sorted(arr)

max=0
for i in range(0,n):
    a, b = solarr[i]
    if (b-i) > max:
        max = b-i

print(max+1)