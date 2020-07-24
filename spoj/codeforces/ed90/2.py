for _ in range(int(input())):
    ss = input()
    a = ss.count('0')
    b = ss.count('1')
    mn = min(a,b)
    if mn%2 == 0:
        print("NET")
    else:
        print("DA")
