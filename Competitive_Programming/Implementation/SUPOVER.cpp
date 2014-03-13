#include<stdio.h>
#include<algorithm>
//std swap and implementation
using namespace std;
char s[10000];
main(){
       int b[3]={0};
       int st=0,nst=1,w=0;
       while(~scanf("%s",s)){
                             if(s[0]>='0'&&s[0]<='9'){b[st]+=(s[0]-'0');if(s[0]%2==1)swap(st,nst);
                             }
                             else if(s[0]=='O'){w++;if(w>1)break;st=2;}
                             //else if(s[0]=='W')
                             
                             }
       printf("%d\n%d\n%d\n",b[0],b[1],b[2]);
       return 0;
       }
