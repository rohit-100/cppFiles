for _ in range(int(input())):
    ss = input()
    first = ss.find("1")
    if first == -1:
        print("0")
        continue
    second = ss.rfind("1")
    ans = 0
    for i in range(first,second+1):
        if ss[i] == "0":
            ans +=1
    print(ans)
