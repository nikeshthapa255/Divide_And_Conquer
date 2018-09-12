import math
def mergesort(a):
    l=len(a)
    al=a[:int(l/2)]
    ar=a[int(l/2):]
    if len(al)>1:
        al=mergesort(al)
    if len(ar)>1:
        ar=mergesort(ar)
    ta=list()
    i=0
    j=0
    while i<len(al) and j<len(ar):
        if al[i]>ar[j]:
            ta.append(ar[j])
            j=j+1
        else:
            ta.append(al[i])
            i=i+1
    if i is not len(al):
        while i<len(al):
            ta.append(al[i])
            i=i+1
    if j is not len(ar):
        while j<len(ar):
            ta.append(ar[j])
            j=j+1
    a=ta
    return a

    
def split(ax,ay,a,b):
    p1=list();q1=list();p2=list();q2=list()
    if len(ax)>8:
        qx=ax[:int(len(ax)/2)]
        rx=ax[int(len(ax)/2):]
        qy=ay[:int(len(ay)/2)]
        ry=ay[int(len(ay)/2):]
        p2,q2=split(rx,ry,a,b)
        p1,q1=split(qx,qy,a,b)
    else:
        p2,q2=[ax[0],a[ax[0]]],[ax[1],a[ax[1]]]
        ddd=distance(p2,q2);
        pmin=list();
        qmin=list();
        for i in range(len(ax)):
            for j in ax[i+1:]:
                if ddd>distance([ax[i],a[ax[i]]],[j,a[j]]):
                    ddd=distance([ax[i],a[ax[i]]],[j,a[j]])
                    pmin=[ax[i],a[ax[i]]];qmin=[j,a[j]]
    return pmin,qmin;



def splitd(x,y,d,a,b):
    ps=list()
    _x=x[int(len(x)/2)]
    for i in x:
        if i < (_x+d) and i>(_x-d):
            ps.append(a[i])
    bestd=d
    p,q=0,0
    for i in range((len(ps)-1)):
        for j in range(min(7,(len(ps)-i-1))):
            dis=distance([b[ps[i]],ps[i]],[b[ps[i+j+1]],ps[i+j+1]])
            if dis< bestd:
                bestd=dis
                p,q=[b[ps[i]],ps[i]],[b[ps[i+j+1]],ps[i+j+1]]
    return p,q

    


def distance(a1,a2):return math.sqrt((a1[0]-a2[0])**2+(a1[1]-a2[1])**2)
def closestpairs(a):#points will be in form of dictionary as all x are unique
    b=dict()
    for i in a:
        b[a[i]]=i
    px=list(a)
    py=list(a.values())

    px=mergesort(px)
    py=mergesort(py)
    p1=list();q1=list()
    p1,q1=split(px,py,a,b)
    d=distance(p1,q1)
    p3,q3=splitd(px,py,d,a,b)
    if p3 is not 0 and q3 is not 0:
        return p3,q3
    else:
        return p1,q1
    
inp=dict()
while True:
    print("enter x and then y")
    try:
        x,y=list(map(int,input().split())) 
    except:
        break
    inp[x]=y
p,q=closestpairs(inp)
print('(',p,',',q,') distance -',distance(p,q))
    
    
