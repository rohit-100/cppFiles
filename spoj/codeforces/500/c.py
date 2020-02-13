n = int(input())
arr = list(map(int,input().split()))
arr.sort()
n*=2
print((arr[n//2-1]-arr[0])*(arr[-1]-arr[n//2]))
