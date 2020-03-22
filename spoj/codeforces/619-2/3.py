def calc(n):
    return (n*(n+1))//2


from sys import stdin,stdout
for _ in range(int(input())):
    n,m = [int(x) for x in stdin.readline().split()]
    if m ==0:
        print("0")
        continue
    total = calc(n)
    n -= m
    m+=1
    if n%m == 0:
        if n<m:
            m=n
        val = (total - m*calc(n//m))
        stdout.write(str(val) + "\n")
    else:
        val = total - ((m-1)*calc(n//m) + calc(n%m + n//m))
        stdout.write(str(val) + "\n")
