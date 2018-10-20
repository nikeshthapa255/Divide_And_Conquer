def inint():
    return int(input())
def inlist():
    return list(map(int,input().split()))
count=0
a1=0;b1=0;c=str();num=0
def work(i,m1,n1,carry=0,m='',n=''):
    global count,a1,b1,num,c
    #print('index-',i,';c-',c,carry,n,'m1-',m1,'n1-',n1)
    if i == num+1 :
        if m1==a1 and n1==b1:
            if m not in sola or n not in solb:count+=1;sola.add(m);solb.add(n);print(m,n)
        elif m1==b1 and n1==a1:
            if n not in sola or m not in solb:count+=1;sola.add(n);solb.add(m);print(n,m)
        #print('sol',m,n,count)
        return
    if (m1>a1 and m1>b1) or (n1>a1 and n1>b1):return
    #print(i,c,c[i],m1,n1)
    if carry==1:
        if c[i]=='1':
            #print(1,0,0);
            work(i+1,m1,n1,0,m+'0',n+'0')
            #print(1,1,1);
            work(i+1,m1+1,n1+1,1,m+'1',n+'1')
        else:
            #print(1,0,1);
            work(i+1,m1,n1+1,0,m+'0',n+'1')
            #print(1,1,0);
            work(i+1,m1+1,n1,0,m+'1',n+'0')
    else:
        if c[i]=='1':
            #print(0,1,0);
            work(i+1,m1+1,n1,0,m+'1',n+'0')
            #print(0,0,1);
            work(i+1,m1,n1+1,0,m+'0',n+'1')
        else:
            #print(0,0,0);
            work(i+1,n1,m1,0,m+'0',n+'0')
            #print(0,1,1);
            work(i+1,n1+1,m1+1,1,m+'1',n+'1')



for i in range(inint()):
    count=0;sola=set();solb=set()
    a,b,cc=inlist()
    c=bin(cc)[::-1]
    a1=bin(a).count('1');b1=bin(b).count('1')
    from math import log as ln
    num=int(ln(cc,2))
    work(0,0,0)
    print(count)
