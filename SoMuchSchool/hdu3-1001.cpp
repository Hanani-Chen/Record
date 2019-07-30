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
#define list list2
/*********************************************/
const double eps=1e-8;
const double PI=acos(-1.0);

int sgn(double x) {
	if(fabs(x)<eps) return 0;
	if(x<0) return -1;
	else return 1;
}

struct Point{ 
	double x,y;
	Point(){}
	Point(double _x,double _y){ x=_x;y=_y;}
	double operator^(const Point & b) const {
		return x*b.y-y*b.x;
	}
	Point operator-(const Point & b) const {
		return Point(x-b.x,y-b.y);
	}
	double operator*(const Point &b) const {
		return x*b.x+y*b.y;
	}
};

struct Line {
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {s=_s; e=_e;}
};


Point PointToline(Point P,Line L) {
	Point result;
	double t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	result.x=L.s.x+(L.e.x-L.s.x)*t;
	result.y=L.s.y+(L.e.y-L.s.y)*t;
	return result;
}

double dist(Point a,Point b) {
	return sqrt((a-b)*(a-b));
}

const int MAXN=5e2+5;
Point list[MAXN];
int Stack[MAXN],top;

Point yuan[MAXN];
ll ans[MAXN][MAXN];
bool vis[MAXN][MAXN];

bool _cmp(Point p1,Point p2) {
	double tmp = (p1-list[0])^(p2-list[0]);
	if(sgn(tmp)>0) return true;
	else if(sgn(tmp)==0 && sgn(dist( p1,list[0]) -dist(p2,list[0])) <=0)
		return true;
	else return false;
}
void Graham(int n) {
	Point p0;
	int k=0;
	p0=list[0];
	for(int i =1;i<n;i++) {
		if((p0.y>list[i].y)||(p0.y==list[i].y&& p0.x>list[i].x)) {
			p0=list[i];
			k=i;
		}
	}
	swap(list[k],list[0]);
	sort(list+1,list+n,_cmp);
	if(n==1) {
		top=1;
		Stack[0]=0;
		return ;
	}
	if(n==2) {
		top=2;
		Stack[0]=0;
		Stack[1]=1;
		return ;
	}
	Stack[0]=0;
	Stack[1]=1;
	top=2;
	for(int i=2;i<n;i++) {
		while(top>1&&
		sgn((list[Stack[top-1]]-list[Stack[top-2]])^(list[i]-list[Stack[top-2]]))<=0)
		top--;
		Stack[top++]=i;
	}
}
int mp[MAXN][MAXN];
ll dp(ll l,ll r) {//dp要熟悉一下
	if(l==r||vis[l][r]) return ans[l][r];
	vis[l][r]=1;
	for(int kk=l+1;kk<r;kk++)
		ans[l][r]=max(ans[l][r],dp(l,kk)+dp(kk,r));
	ans[l][r]+=mp[l][r];
	return ans[l][r];
}

/*
int dp(int l,int r)
{
    if(l==r||vis[l][r]) return f[l][r];
    vis[l][r]=1;
    for(int kk=l+1;kk<r;kk++)
        f[l][r]=max(f[l][r],dp(l,kk)+dp(kk,r));
    f[l][r]+=mp[l][r];
    return f[l][r];
}*/

int main() {
	int t;cin >> t;
	while(t--) {
		mem(mp,0);
		mem(vis,0);
		mem(ans,0);
		int n,m;
		double r;
		cin >> n >> m >> r;
		ff(i,0,n-1) {
			int x,y;
			cin >> x >> y;
			list[i]=Point(x,y);
		}
		Graham(n);
		ff(i,1,m) {
			ll x1,y1;
			cin >> x1 >> y1;
			yuan[i]=Point(x1,y1);
		}
		//ff(i,0,top-1) {dd(list[Stack[i]].x);de(list[Stack[i]].y);}
		ff(i,0,top-1) {
			ff(j,i+2,top-1) if(!(i==0&&j==top-1)) {
				Point xx=Point(list[Stack[i]].x,list[Stack[i]].y);
				Point yy=Point(list[Stack[j]].x,list[Stack[j]].y);
				Line LL=Line(xx,yy);
				bool yes=true;
				ff(k,1,m) if(dist(PointToline(yuan[k],LL),yuan[k])-r<=eps) yes=false;
				if(yes) {
				//	dd(i);
				//	de(j);
					mp[i][j]=1;	
				}
			}
		}
	//	de(top-1);
		cout << dp(0,top-1) << endl;
	}
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/












