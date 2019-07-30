#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;

#define fi  first
#define se second
#define pb(x)       push_back(x)
#define mp(a,b)  make_pair(a,b);
#define sz(a)  ((int)(a).size())
#define all(x) x.begin(),x.end()

#define ff(i,a,b) for(ll i=a;i<=b;++i)

#define de(a) cout << #a << " = " << a << endl;
#define dd(a) cout << #a << " = " << a << "  ";

#define INF 0x3f3f3f3f
#define mem(a,b)   memset(a,b,sizeof(a))
#define file freopen("in.txt","r",stdin)
#define jkl ios::sync_with_stdio(false);cin.tie(0);
/*********************************************/
const int N=1e3+5;
char a[N][N];
bool vis[N][N];
ll ans[N][N];
ll anss[N][N];
ll mp[N*N]; //别用map存
ll tot=0;
int n,m;
ll xx[56]={0,1,-1,0,0};
ll yy[56]={0,0,0,1,-1};
bool ok(int x,int y) {
	if(x>=1&&y>=1&&x<=n&&y<=m&&a[x][y]=='.'&&vis[x][y]==false) return true;
	else return false;
}
bool ok2(int x,int y) {
	if(x>=1&&y>=1&&x<=n&&y<=m) return true;
	else return false;
}
void bfs(int x,int y) {
	queue<pair<int,int> > q;
	while(!q.empty()) q.pop();
	q.push(make_pair(x,y));
	ans[x][y]=tot;
	mp[tot]++;
	while(!q.empty()) {
		int nox=q.front().fi;
		int noy=q.front().se;
		q.pop();
		ff(i,1,4) {
			int hx=nox+xx[i];
			int hy=noy+yy[i];
			if(ok(hx,hy)) {
				vis[hx][hy]=true;
				ans[hx][hy]=tot;
				mp[tot]++;
				q.push(make_pair(hx,hy));
			}
		}
	}
}
int main() {
	cin >> n >> m;
	ff(i,1,n) ff(j,1,m) cin >> a[i][j];
	mem(vis,0);
	ff(i,1,n) ff(j,1,m) if(vis[i][j]==false&&a[i][j]=='.') {
		vis[i][j]=true;
		tot++;
		bfs(i,j);
	}
	ff(i,1,n) ff(j,1,m) if(a[i][j]=='*') {
		vector<ll> qu;
		ll cnt=1;
		ll now=0;
		ff(k,1,4) {
			ll hx=i+xx[k];
			ll hy=j+yy[k];
			if(ok2(hx,hy)) {
				qu.pb(ans[hx][hy]);
			}
		}
		sort(all(qu));
		qu.erase(unique(all(qu)),qu.end());
		
		ll m=qu.size();
		ff(i,0,m-1) now+=mp[qu[i]];
		anss[i][j]=now;
	}
	ff(i,1,n) {
		ff(j,1,m) {
			if(a[i][j]=='.') cout << a[i][j];
			else cout << (anss[i][j]+1)%10;
		}
		cout << endl;
	}
		
	
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/
