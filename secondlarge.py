def give(a):return (a if len(a)<4 else give([max(a[i*2],a[i*2+1]) for i in range(int(len(a)/2))]))
import random
a=list(map(int,input().split()))
ans=[sorted(give(random.sample(a,len(a))))[-2] for i in range(1000)]
print(max(set(ans),key=ans.count))
