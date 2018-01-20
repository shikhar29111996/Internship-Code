int Solution::pow(int x, int n, int d) {
    
    long long r=1;
    int c=0;
    if(x==0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    if(x<0)
    {
        x=abs(x);
        if(n%2!=0)
        {
            c=1;
        }
    }
    
    long long int t=x%d;
    
    while(n!=0)
    {
        if(n%2!=0)
        {
            r=(r*t)%d;
        }
        
        t=t*t;
        t=t%d;
        n=n/2;
        if(r>d)
        {
            r=r%d;
        }
    }
    
    if(c==1)
    {
        return d-(int)r;
    }
    
    return (int)r;
}
