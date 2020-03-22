import math
for _ in range(int(input())):
    n,m = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    if sum(arr) < n:
        print("-1")
        continue

    fre  = [0]*64
    for val in arr:
        fre[math.floor(math.log2(val))]+=1
    mx = 1<<64
    twos = []
    while n>0:
        if n>=mx:
            twos.append(mx)
            n-=mx
        mx>>=1
    twos.sort()
    summ = 0
    ans = 0
#     for ind,val in enumerate(fre):
#         two = 1<<ind
#         summ+=(two*val)
#         if two in twos:
#             summ-= two
#             twos.remove(two)
#         elif summ>= two:
#             summ-=two
#         else:
    for i in range(64):
        summ+=(fre[i]*(1<<i))
        fre[i] = 0
        if 1<<i not in twos:
            continue
        if summ >= 1<<i:
            summ-=(1<<i)
            continue
        else:
            for j in range(i+1,64):
                if fre[j] != 0:
                    for k in range(j-1,i-1,-1):
                        fre[k]+=1
                    ans += (j-i)
                    fre[j]-=1
                    break
        summ+=fre[i]*(1<<i)
    print(ans)



