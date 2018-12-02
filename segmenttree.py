class segmenttree:
    n=0;la=[];ra=[];ma=[];a=[];comparison=None;delta=[]
    def __init__(self,a,n,f):
        import math
        self.comparison=f
        self.n=2**(math.ceil(math.log(n,2))+1)+1
        self.a=a[:]
        self.la=[0 for i in range(self.n+1)];self.ra=self.la[:];self.ma=self.la[:];self.delta=self.la[:]
        self.formtree(1,0,n-1)
    def formtree(self,x,i,j):
        self.la[x]=i;self.ra[x]=j
        if i==j:self.ma[x]=self.a[i];return
        self.formtree(2*x,i,(i+j)//2)
        self.formtree(2*x+1,(i+j)//2+1,j)
        self.ma[x]=self.comparison(self.ma[2*x+1],self.ma[2*x])
    def findquery(self,i,j,x=1):
        from sys import maxsize
        if j<self.la[x] or i>self.ra[x]:
            return maxsize
        if self.la[x]>=i and self.ra[x]<=j:
            return self.ma[x]
        self.propogation(x)
        min1=self.findquery(i,j,2*x)
        min2=self.findquery(i,j,2*x+1)
        self.update(x)
        return self.comparison(min1,min2)%maxsize
    #lazy propogation part
    def propogation(self,x):
        self.delta[2*x]+=self.delta[x]
        self.delta[2*x+1]+=self.delta[x]
        self.delta[x]=0
    def update(self,x):
        l=lambda x:self.ra[x]-self.la[x]+1 if self.comparison(1,2)==3 else 1
        self.ma[x]=self.comparison(self.ma[2*x]+l(2*x)*self.delta[2*x],self.ma[2*x+1]+l(2*x+1)*self.delta[2*x+1])
    def increment(self,i,j,val,x=1):
        if j<self.la[x] or i>self.ra[x]:return 
        if self.la[x]>=i and self.ra[x]<=j:self.delta[x]+=val;return
        self.propogation(x)
        self.increment(i,j,val,2*x)
        self.increment(i,j,val,2*x+1)
        self.update(x)


a=list(map(int,input().split()))
st=segmenttree(a,len(a),lambda x,y:x+y)
print(len(a))
while input('want to ask increment-(Y/N)')=='Y':
    a,b,x=map(int,input().split())
    st.increment(a,b,x)
while input('want to ask query-(Y/N)')=='Y':
    a,b=map(int,input().split())
    print(st.findquery(a,b))
if input('print raw tree-'):
    for i in range(st.n):print(st.la[i],st.ra[i],st.ma[i],st.delta[i])        


