import math
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    st = set()
    arr = list(set(arr))
    ans = 0
    arr.sort()
    for val in arr:
        m = val
        while val not in st and val%2 == 0:
            ans += 1
            val/=2
        st.add(m)


    print(ans)
