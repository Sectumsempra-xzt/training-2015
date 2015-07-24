#include<iostream>
#include<cstdio>
#include<cstring>
#define rep(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
typedef long long ll;
const int maxn = 52;
int rem[maxn][maxn],n,m,h[maxn][maxn];
ll g[maxn][maxn];
bool vis[maxn][maxn];
int f(int x,int y){
	if(rem[x][y] != -1)return rem[x][y];
	rem[x][y] = 0;
	rep(i,-1,1)
		rep(j,-1,1)
			if(i*j ==0 && !(i==0 && j==0) && x+i >=1 && x+i<=n &&y+j>=1 &&y+j<=m)
				if(h[x+i][y+j] < h[x][y] ){
					rem[x][y] = max(rem[x][y],f(x+i,y+j));
					vis[x+i][y+j]=1;
				}
	rep(i,-1,1)
		rep(j,-1,1)
			if(i*j ==0 && !(i==0 && j==0) && x+i >=1 && x+i<=n &&y+j>=1 &&y+j<=m)
				if(h[x+i][y+j] < h[x][y] )
					g[x][y]+=g[x+i][y+j];
	if(!g[x][y])g[x][y]++;
	//printf("x=%d y=%d g=%d\n",x,y,g[x][y]);
	return rem[x][y];
}
int main(){
	int Case;
	cin >> Case;
	rep(cnt,1,Case){
		cin >> n >> m;
		int ans = 0;
		ll  sum = 0;
		memset(rem,-1,sizeof(rem));
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		rep(i,1,n)rep(j,1,m)scanf("%d",&h[i][j]);
		rep(i,1,n)rep(j,1,m)ans=max(ans,f(i,j));
		rep(i,1,n)rep(j,1,m)if(!vis[i][j]){
			//printf("i=%d j=%d g=%d\n",i,j,g[i][j]);
			sum += g[i][j];
		}
		printf("Case #%d: ",cnt);
		cout<< sum << endl;
	}
	return 0;
}
