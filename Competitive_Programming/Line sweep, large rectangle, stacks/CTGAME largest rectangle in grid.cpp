# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <cstdio>
# include <cmath>
# include <numeric>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>
# include <complex>

#define MAX 1005
using namespace std;
/*inline int ni()
{
	register int r=0,c;
	for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
	if(c=='-') 
		return -ni();
	for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
	return r;
}*/





int a[MAX],dp_l[MAX],dp_r[MAX];
/*void print(stack<int> x)
{
     while(!x.empty())
     {
                      printf("v=%d i=%d, ",a[x.top()],x.top());x.pop();
     }
     puts("");
}*/

long long int largest_rect_in_histo(int histo[],int n)
{   
    stack<int> s;
    int i;
    long long sum=0,max;
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
                    
                    s.push(i);
             }
    
     max=dp_l[1]+dp_r[1]+1;
     max*=a[1];
     for(i=2;i<=n;i++){
                               sum=dp_l[i]+dp_r[i]+1;
                               sum*=a[i];
                               if(max<sum)max=sum;
                               
                               }
             
     
     
     return max;
}


main()
{
    int i,n,m,f,j,t;
    long long int max,temp;
    char s[MAX];
    scanf("%d",&t);
    while(t--)
    {
             scanf("%d%d",&n,&m);
             //scanf("%d",&f);      
             //gets(s);
             max=0;
             for(j=1;j<=m;j++)a[j]=0;  
             for(i=1;i<=n;i++)
             {
                    //gets(s);
                    //puts(s);
                    for(j=0;j<m;j++){
                                     scanf("%s",s);
                                     if(s[0]=='R'){
                                                   a[j+1]=0;
                                                   }
                                     else{
                                          a[j+1]++;
                                          }
                                     }
                    temp=largest_rect_in_histo(a,m);
                    //printf("%   lld\n",temp);
                    if(temp>max)max=temp;
             }
             printf("%lld\n",max*3);
    }
    return 0;
}
