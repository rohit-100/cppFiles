def hasloop(gg,src,done,par):
#     print()
    if done[src] :
        return True
    done[src]= True
    loop = False
    for val in gg[src]:
        if val != par:
            loop = loop or hasloop(gg,val,done,src)
    return loop
    
def getpath(gg,src,ans,par,done):
    done[src] = True
    for val in gg[src]:
        if val != par:
            getpath(gg,val,ans,src,done)
    ans.append(chr(src+ord("a")))
#     for val in gg[src]:
#         if val != par:
#             if flag:
#                 getpath(gg,val,ans,src,done)
#                 flag = False
#                 ans.append(chr(i+ord("a")))
#             else:
#                 getpath(gg,val,ans,src,done)
#                 flag = True
   
timer = 1
def dfs(gg,src,par,time):
    global timer
    time[src] = timer
    timer+=1
    for val in gg[src]:
        if val != par:
            dfs(gg,val,src,time)


def mothervertex(gg,src):

    time = [0]*26
    dfs(gg,src,src,time)
    mv = -1
    ans = -1
    for ind,val in enumerate(time):
        if val>ans:
            ans = val
            mv = ind
#     print(time)
    return mv

    
for _ in range(int(input())):
    ss = input()
    gg = [set() for i in range(27)]
    src = -1
    for i in range(len(ss)):
        if i-1>=0 and i+1<len(ss):
            gg[ord(ss[i])-ord("a")].add(ord(ss[i-1])-ord("a"))
            gg[ord(ss[i])-ord("a")].add(ord(ss[i+1])-ord("a"))
        elif i-1>=0:
            gg[ord(ss[i])-ord("a")].add(ord(ss[i-1])-ord("a"))
        elif i+1<len(ss):
            gg[ord(ss[i])-ord("a")].add(ord(ss[i+1])-ord("a"))
    ans = True
    for edge in gg:
        if len(set(edge)) > 2:
            ans = False
            break
    if ans is False:
        print("NO")
        continue
    done = [False]*26
    loop = False
    for i in range(26):
        if done[i] == False:
            loop = loop or hasloop(gg,i,done,i)
    if loop:
        print("NO")
        continue
    print("YES")
    ans = []
    done = [False]*26
#     for i in range(26):
#         if not done[i]:
#             if len(gg[i]) == 0:
#                 ans.append(chr(i+ord("a")))
#             elif len(gg[i]) == 1:
#                 getpath(gg,i,ans,i,done)
#             else:
#                 val = [x for x in gg[i]]
# 
#                 done[i] = True
#                 getpath(gg,val[0],ans,val[0],done)
#                 ans.append(chr(i+ord("a")))
#                 getpath(gg,val[1],ans,val[1],done)



    for i in range(26):
        if not done[i] and len(gg[i])<2:
#             mv = mothervertex(gg,i)
            mv = i
            getpath(gg,mv,ans,mv,done)

           
    for val in ans:
        print(val,end="")
    print()
            

