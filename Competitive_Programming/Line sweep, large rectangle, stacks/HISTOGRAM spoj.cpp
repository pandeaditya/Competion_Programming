//refer http://tech-queries.blogspot.in/2011/03/maximum-area-rectangle-in-histogram.html

//stack
#include<stdio.h>
#include<stack>
using namespace std;
int a[100005],dp_l[100005],dp_r[100005];
void print(stack<int> x)
{
     while(!x.empty())
     {
                      printf("v=%d i=%d, ",a[x.top()],x.top());x.pop();
     }
     puts("");
}
main()
{
    long long sum,max;
    int i,n;
    while(scanf("%d",&n),n)
    {
             sum=0;
             
             for(i=1;i<=n;i++)
             {
                    scanf("%d",&a[i]);
             }
             dp_l[0]=dp_l[1]=0;
             
             stack<int> s;
             for(i=1;i<=n;i++)
             {
                   //print(s);
                    while(!s.empty()&&a[s.top()]>=a[i])
                              s.pop();
                    
                   if(s.empty()){
                                  dp_l[i]=(i-1);
                                  }
                    else{
                         dp_l[i]=i-s.top()-1;
                         }
                    //if(dp_l[i])dp_l[i]=i-s.top();
                    s.push(i);
             }
             
             

             while(!s.empty())s.pop();
             dp_r[n]=dp_r[n+1]=0;
             for(i=n;i;i--)
             {
                    while(!s.empty()&&a[s.top()]>=a[i])
                              s.pop();
                    if(s.empty()){
                                  dp_r[i]=(n-i);
                                  }
                    else{
                         dp_r[i]=s.top()-i-1;
                         }
                    //dp_r[i]=s.size();
                    s.push(i);
             }
             
             
             //for(i=1;i<=n;i++){
                               //printf("%d %d, ",dp_l[i],dp_r[i]);}
             
             
             
             max=dp_l[1]+dp_r[1]+1;
             max*=a[1];
             for(i=2;i<=n;i++){
                               sum=dp_l[i]+dp_r[i]+1;
                               sum*=a[i];
                               if(max<sum)max=sum;
                               
                               }
             
             printf("%lld\n",max);
             
             
    }
    return 0;
}
