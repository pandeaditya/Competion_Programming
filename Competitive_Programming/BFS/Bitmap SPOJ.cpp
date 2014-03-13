#include <iostream>
#include<stdio.h>
#include<queue>
using namespace std;
char X[186][186];
int ans[186][186];
struct T{
	int x,y,d;};
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main() {
	int t,r,c,i,j;
	scanf("%d",&t);
	while(t--){
		queue <T> Q;
		bool seen[186][186]={0};
        
		scanf("%d%d",&r,&c);
		gets(X[0]);
		for(i=0;i<r;i++)gets(X[i]);
		
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)if(X[i][j]=='1'){
											T temp;
											temp.x=i;
											temp.y=j;
											temp.d=ans[i][j]=0;
											
											seen[i][j]=1;
											Q.push(temp);
											//printf("   %d %d\n",i,j);
											}
			T z,f;
			while(!Q.empty()){
								z=Q.front();
								seen[z.x][z.y]=1;
								//printf("%d %d\n",z.x,z.y);
								for(i=0;i<4;i++){f.x=z.x+dx[i];
												f.y=z.y+dy[i];
											if(dx[i]+z.x>=0&&dx[i]+z.x<r&&dy[i]+z.y>=0&&dy[i]+z.y<c){
												
												if(seen[f.x][f.y]==0)
                                                    {
                                                    seen[f.x][f.y]=1;
    												f.d=z.d+1;
    												ans[f.x][f.y]=f.d;
    												Q.push(f);
                                                    }
												}
								
											}
								Q.pop();
								/*for(int ii=0;ii<r;ii++){
                                for(int jj=0;jj<c;jj++){
                                              printf("%d ",ans[ii][jj]);
                                             
                                             }
                                             puts("");
                                             
                                 }
								puts("");*/
							}
			
			for(int ii=0;ii<r;ii++){
                                for(int jj=0;jj<c;jj++){
                                              printf("%d ",ans[ii][jj]);
                                             
                                             }
                                             puts("");
                                             
                                 }
		
	
	}
	
	return 0;
}

