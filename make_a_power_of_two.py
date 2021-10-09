# https://codeforces.com/contest/1560/problem/D

ds = []
i = 1
while(i<=1000000000000000000):
    ds.append(str(i))
    i*=2
    
 
    
for _ in range(int(input())):
    s = input()
    minans = 10000
    for i in range(len(ds)):
        mxat = 0
        s1, s2 = 0, 0
        cps = s
        while(s1<len(s) and s2<len(ds[i])):
            if(cps[s1]==ds[i][s2]):
                s2+=1
                s1+=1
                mxat+=1
            else:
                cps = cps[0:s1]+'*'+cps[s1+1:]
                s1+=1
        asd = len(s)-mxat
        asd+=(max(0, len(ds[i])-mxat))
        minans = min(minans, asd)        
 
        
    print(minans)
    
