#include <stdio.h>
#define MOD 1000000007
typedef long long ll;
//int MOD = 1000000007;
int pow(int a, int b, int mod) 
{
long long int x = 1, y = a;
	while(b > 0) {
		if(b%2 == 1) {
			x=(x*y);
			if(x>mod) x%=mod;
		}
		y = (y*y);
		if(y>mod) y%=mod;
		b /= 2;
	}
	return (int)x;
}

int modInverse(int a, int m=MOD) //uses little fermat's theorem
{
    return pow(a,m-2,m);
}
ll fact[2000005],ans;
int main(void) {
	
	int t,n,i,mi;
	fact[0]=1;
	scanf("%d",&t);
	for(i=1;i<=2*1000000;i++){fact[i]=i*fact[i-1];fact[i]%=MOD;}
	while(t--){
			scanf("%d",&n);
			mi=(int)((fact[n-1]*fact[n-1])%MOD);
			mi=modInverse(mi);
			ans=(mi*fact[2*n-1]);
            if(ans>MOD)ans%=MOD;
			printf("%lld\n",ans);
			}
			return 0;
	}
