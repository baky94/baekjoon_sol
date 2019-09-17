arr = list(map(int, input().split()))
result = [1 for x in range(arr[1]+1)]

result[0] = -1
result[1] = -1

for i in range(2,arr[1]//2+1):
    result[2*i] = -1
    if 3*i <= arr[1]:
        result[3*i] = -1
    if 5*i <= arr[1]:
        result[5*i] = -1
    if 7*i <= arr[1]:
        result[7*i] = -1
    if i>7:
        if result[i] == 1:
            tmp = i
            while i*tmp <= arr[1]:
                result[i*tmp] = -1
                tmp += 1


for num in range(arr[0],arr[1]+1):
    if result[num] == 1:
        print(num)
