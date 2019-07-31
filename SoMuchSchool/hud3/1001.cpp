#include<bits/stdc++.h>
using   namespace  std;
typedef  long long  ll;
typedef pair<ll,ll>pll;
typedef    double   db;

#define fi  first
#define se second
#define pb(x)       push_back(x)
#define mp(a,b)  make_pair(a,b);
#define sz(a)  ((int)(a).size())
#define all(x) x.begin(),x.end()

#define ff(i,a,b) for(ll i=a;i<=b;++i)

#define de(a) cout << #a << " = " << a << endl;
#define dd(a) cout << #a << " = " << a << "  ";

#define mem(a,b)   memset(a,b,sizeof(a))
#define file freopen("in.txt","r",stdin)
#define jkl ios::sync_with_stdio(false);cin.tie(0);
#define list list2

const ll INF     =    0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const ll MOD     =   1e9+7;
const double eps =    1e-8;
const double PI=acos(-1.0);
/*************************************************/
typedef db T;
int sgn(T x) { return (x > eps) - (x < -eps); }
struct P {
    T x, y; P () {} P(T x, T y) : x(x), y(y) {}
    P operator - (const P &b) const { return P(x - b.x, y - b.y); }  // ÏòÁ¿¼õ
    T operator / (const P &b) const { return x * b.y - y * b.x; }    // ÏòÁ¿²æ»ý
    bool operator < (const P &b) const { return sgn(x - b.x) ? x < b.x : y < b.y; }  // ×óÐ¡ÓÒ´ó£¬ÏÂÐ¡ÉÏ´ó
    T abs() { return sqrt(x * x + y * y); }  // ÏòÁ¿Ä£³¤
    void scan() { db tx, ty; scanf("%lf%lf", &tx, &ty); x = tx; y = ty; }  // ÊäÈë
};
T cross(P o, P a, P b) { return (a - o) / (b - o); }         // ÏòÁ¿ oa Óë ob µÄ²æ»ý
int crossSgn(P o, P a, P b) { return sgn(cross(o, a, b)); }  // ÏòÁ¿ oa Óë ob µÄ²æ»ý·ûºÅ
struct L { P s, t; L () {} L(P s, P t) : s(s), t(t) {} };
db disPL(P p, L a) { return fabs( (a.t-a.s) / (p-a.s) ) / (a.t-a.s).abs(); }  // µã p µ½Ö±Ïß a µÄ¾àÀë
typedef vector<P> polygon;
polygon Convex(polygon A) {  // ÇóÍ¹°ü£¬ÄæÊ±ÕëÅÅÐò£¨ ÄÚ½Ç <180 : (<=) ; ÄÚ½Ç <=180 : (<) £©
    int n = sz(A); if (n <= 1) return A;
    sort(all(A));
    polygon B;
    for (int i = 0; i < n; B.pb(A[i++]))
        while (sz(B) > 1 && crossSgn(B[sz(B)-2], B.back(), A[i]) < 0) B.pop_back();  // ¸ü¸ÄÕâÀïµÄ <
    for (int i = n - 2, t = sz(B); i >= 0; B.pb(A[i--]))
        while (sz(B) > t && crossSgn(B[sz(B)-2], B.back(), A[i]) < 0) B.pop_back();  // Í¬ÉÏ
    B.pop_back(); return B;
}

const int N=5e2+5;
int ans[N][N];
bool vis[N][N];
int mp[N][N];

polygon convex;
P O[N];

int main() {
	int t;cin >> t;
	while(t--) {
		convex.clear();
		mem(mp,0); mem(vis,0); mem(ans,0);
		int n,m;double r;
		cin >> n >> m >> r;
		ff(i,1,n) {
			P p; p.scan();
			convex.pb(p);
		}
		sort(all(convex));
		convex=Convex(convex);
		ff(i,1,m) O[i].scan();
		ll len=convex.size();
		ff(i,0,len-1) {
			ff(j,i+2,len-1) if(!(i==0&&j==len-1)) {
				L LL=L(convex[i],convex[j]);
				bool yes=true;
				ff(k,1,m) if(sgn(disPL(O[k],LL)-r)<=0) {yes=false;break;}
				if(yes) mp[i][j]=1;
			}
		}
		ff(d,2,len-1) {
			ff(i,0,len-d-1) {
				int j=i+d;
				ff(k,i+1,j-1) ans[i][j]=max(ans[i][j],ans[i][k]+ans[k][j]+mp[i][j]);
			}
		}
		cout << ans[0][len-1] << endl;
	}
}/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/
