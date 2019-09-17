import itertools
arr = []

for i in range(9):
    arr.append(int(input()))

arr.sort()
solve = []

for i in itertools.permutations(arr,7):
    tmp = 0
    for num in i:
        tmp += num
    if tmp == 100:
        solve = i
        break

for num in solve:
    print(num)
