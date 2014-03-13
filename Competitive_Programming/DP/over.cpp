#include<stdio.h>
unsigned long long a[3],ans[51],b[3];
//dp

main()
{
      a[0]=a[1]=a[2]=1;
      ans[1]=3;
      int i;
      for(i=2;i<51;i++){
                        b[0]=a[0]+a[1];
                        b[1]=b[0]+a[0];
                        b[2]=a[2]+a[1];
                        ans[i]=b[0]+b[1]+b[2];
                        a[0]=b[0];
                        a[1]=b[1];
                        a[2]=b[2];
                        }
      int t,n;
      scanf("%d",&t);
      while(t--){scanf("%d",&n);printf("%llu\n",ans[n]);}
      return 0;
      
}
