class Solution{
public:
    long long gcd(long long a,long long b){
        while(b){
            long long t=b;
            b=a%b;
            a=t;
        }
        return a;
    }

    int nthMagicalNumber(int n,int a,int b){
        const long long MOD=1000000007;
        long long l=min(a,b);
        long long r=(long long)n*min(a,b);
        long long lcm=(long long)a*b/gcd(a,b);
        while(l<r){
            long long mid=l+(r-l)/2;
            long long cnt=mid/a+mid/b-mid/lcm;
            if(cnt<n) l=mid+1;
            else r=mid;
        }
        return l%MOD;
    }
};
