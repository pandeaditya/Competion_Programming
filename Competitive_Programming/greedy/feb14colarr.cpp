#include<stdio.h>
#include<algorithm>
/*

input
1
4 2 1
1 1 2 2
1 1
1 1
1 1
3 1
0 1
0 1
1 0
1 0

output
1 1 1 2 
2

*/
using namespace std;
int B[1000][1000],C[1000][1000],a[1001],ma[1000];
int main()
{
    
      int t,i,k,n,m,j;
      scanf("%d",&t);
      while(t--)
      {
                int sum=0;
                scanf("%d%d%d",&n,&m,&k);
                for(i=0;i<n;i++){scanf("%d",a+i);a[i]--;}
                for(i=0;i<n;i++)ma[i]=0;
                
                
                for(i=0;i<n;i++)for(j=0;j<m;j++)
                {
                         scanf("%d",&B[i][j]);
                         
                }
				for(i=0;i<n;i++)sum+=B[i][a[i]];
                for(i=0;i<n;i++)for(j=0;j<m;j++)
                {
                         scanf("%d",&C[i][j]);
                         
                }
                for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                {
                      ma[i]=std::max(ma[i],B[i][j]-C[i][j]-B[i][a[i]]);
                }
                sort(ma,ma+n);
                //for(j=0;j<n;j++)printf("%d ",ma[j]);
                //puts("");
                for(j=n-1;k--;j--){
                                   sum+=ma[j];
                                   }
                printf("%d\n",sum);
      }
      return 0;
}
