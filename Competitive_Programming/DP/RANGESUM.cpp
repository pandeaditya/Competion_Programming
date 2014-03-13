#include<stdio.h>
long long int a[100001],b[200001],nsum=0,ans;
main(){
       int n,q,z,i,p,nb=0,l,r;
       scanf("%d",&n);
       a[0]=0;
       b[0]=0;
       for(i=1;i<=n;i++){scanf("%d",&z);a[i]=a[i-1]+z;}
       scanf("%d",&q);
       while(q--){
                  scanf("%d",&p);
                  if(p==1){
                        scanf("%d%d",&l,&r);
                        if(l<=nb){
                                  if(r<=nb){
                                            ans=b[nb+1-l]-b[nb-r];
                                            }
                                  else{
                                       ans=b[nb+1-l]+a[r-nb];
                                       }
                                  
                                  }
                        else{
                             ans=a[r-nb]-a[l-nb-1];
                             }
                        printf("%lld\n",ans);
                        }
                  else{
                       scanf("%d",&z);
                       b[nb+1]=b[nb]+z;
                       nb++;
                       //nsum+=z;
                       }
                  
                  }
       return 0;
       }

