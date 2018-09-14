def give(a):
    return (a if len(a)<4 else give([max(a[i*2],a[i*2+1]) for i in range(int(len(a)/2))]))

a=list(map(int,input().split()))
print(sorted(give(a))[-2])

