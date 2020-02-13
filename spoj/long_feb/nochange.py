for _ in range(int(input())):
    n,p = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    
    if(all(p%val==0 for val in arr)):
        print("NO")
        continue
    
    print("YES",end = " ")
    done = False
    for val in arr:

        if p%val == 0 or done is True:
            print(0,end = " ")

        elif p%val != 0 and done is False:
            print((p+val-1)//val,end = " ")
            done = True
    print()
