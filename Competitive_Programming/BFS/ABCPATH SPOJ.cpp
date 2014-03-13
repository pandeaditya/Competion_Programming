//bfs (using queues ) for grid

#include <iostream>
#include<stdio.h>
#include<queue>
using namespace std;
const int dim = 55;
char X[dim][dim];
struct T{
	int x,y,d;};
const int dir=8;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,-1,-1,1,1};
int main() {
	register int r,c,i,j,cas=1;
	while(scanf("%d%d",&r,&c),r){
		queue <T> Q;
		bool seen[dim][dim]={0};
        int ans[dim][dim]={0};
		
		//gets(X[0]);
		for(i=0;i<r;i++)scanf("%s",X[i]);
		
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)if(X[i][j]=='A'){
											T temp;
											temp.x=i;
											temp.y=j;
											temp.d=ans[i][j]=1;
											
											seen[i][j]=1;
											Q.push(temp);
											//printf("   %d %d\n",i,j);
											}
			T z,f;
			while(!Q.empty()){
								z=Q.front();
								seen[z.x][z.y]=1;
								//printf("%d %d\n",z.x,z.y);
								for(i=0;i<dir;i++){f.x=z.x+dx[i];
												f.y=z.y+dy[i];
											if(seen[f.x][f.y]==0&&f.x>=0&&f.x<r&&f.y>=0&f.y<c)
                                            if (X[f.x][f.y]==X[z.x][z.y]+1){
												
												
                                                    seen[f.x][f.y]=1;
    												f.d=z.d+1;
    												ans[f.x][f.y]=f.d;
    												Q.push(f);
                                                    
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
			int max=0;
			/*for(int ii=0;ii<r;ii++){
                                for(int jj=0;jj<c;jj++){
                                              printf("%d ",ans[ii][jj]);
                                             
                                             }
                                             puts("");
                                             
                                 }*/
           for(int ii=0;ii<r;ii++){
                                for(int jj=0;jj<c;jj++){
                                              if(ans[ii][jj]>max)max=ans[ii][jj];
                                             
                                             }
                                             
                                             
                                 }
           printf("Case %d: %d\n",cas++,max);
		
	
	}
	
	return 0;
}

