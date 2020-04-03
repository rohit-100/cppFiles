def is_good(hh,l):
    for i in range(1,l+1):
        if hh[i] == 0:
            return False
    return True



for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    hash1 = [0]*n
    for val in arr:
        hash1[val] += 1
    ans = []
    hash2 = hash1[:]
    temp = [0]*n
    for ind,val in enumerate(arr):
        if temp[val] != 0 and is_good(temp,ind) and is_good(hash1,n-ind):
            ans.append((ind,n-ind))
            break
        if temp[val] == 0:
            temp[val] += 1
            hash1[val] -= 1
        else:
            break
    temp = [0]*n
    for ind in range(len(arr)-1,-1,-1):
        val = arr[ind]
        if temp[val] != 0 and is_good(hash2,ind+1) and is_good(temp,n-ind-1):
            ans.append((ind+1,n-ind-1))
            break
        if temp[val] == 0:
#             print(ind)
            temp[val] += 1
            hash2[val] -= 1
        else:
            break
    ans = list(set(ans))
    print(len(ans))
    for val in ans:
        print(str(val[0]) + " " + str(val[1]))
        
