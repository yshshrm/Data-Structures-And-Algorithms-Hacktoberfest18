class Solution {
public:
    double myPow(double x, int n) {
        long long k=n;
        double ans=1;
        double temp=x;
        if(x==1.0)
            return 1.0;
        if(n<0)
        {
            temp=1/x;
            x=1/x;
            k=-k;     
        }
        if(n==0)
            return 1.0;
        //cout<<x<<" "<<n<<" "<<k;
        // for(int i=1;i<k;i++)
        // {
        //     x=x*temp;
        // }
        while(k>0)
        {
            if(k&1)
               ans=ans*x;
            x=x*x;
            k=k/2;
        }
            
        return ans;
    }
};
