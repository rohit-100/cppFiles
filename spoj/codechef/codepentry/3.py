for _ in range(int(input())):
    line = input()
    res = ""
    prev = "$"
    count = 0
    for ch in line:
        if prev == ch:
            count += 1
        elif prev.isdigit():
            res = res + count*str(prev)
            count = 1
        else:
            if count > 1:
                res = res + prev + str(count)
            else:
                res = res + prev
            count = 1
        prev = ch
    
    if count > 1:
        res = res + prev + str(count)
    else:
        res = res + prev
    ans = 0
    for ch in line:
        if ch.isdigit():
            ans += 32
        else:
            ans += 8
    res = res[1:]
    for ch in res:
        if ch.isdigit():
            ans -= 32
        else:
            ans -= 8
    print(ans)
