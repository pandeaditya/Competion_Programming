#include <stdio.h>
#define MOD 1000000007

//@author: Aditya Pande
// USED (p-1)!%p=(p-1) and mul_inv

typedef long long ll;
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

int main()
{
	int t,n,p,i,g;
	scanf("%d",&t);
	while(t--)
	{
         scanf("%d%d",&n,&p);
         if(n>=p)printf("0\n");
         else{
              ll a=1;
              for(i=n+1;i<p;i++)
                  {
                       a*=i;
                       if(a>p)a%=p;
                  }
              g=modInverse((int)a,p);
              a=(p-1);
              a*=g;
              a=a%p;
              printf("%d\n",(int)a);
              }
    }
}
