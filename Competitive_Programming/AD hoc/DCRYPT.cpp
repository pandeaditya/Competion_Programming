#include<stdio.h>
//ad-hoc and strings
char s[100005];
main()
{
      int t,n,i;
      scanf("%d",&t);
      while(t--){
                 scanf("%d",&n);
                
                 scanf("%s",s);
                 for(i=0;s[i];i++){
                                   if(s[i]=='.')s[i]=' ';
                                   else{
                                        if(s[i]>96){s[i]=(s[i]-'a'+n)%26+'a';
                                                    if(n>25)s[i]-=32;
                                                    }
                                        else{
                                             s[i]=(s[i]-'A'+n)%26+'A';
                                             if(n>25)s[i]+=32;
                                             }
                                        }
                                   }
                 puts(s);
                 }
      return 0;
      }
