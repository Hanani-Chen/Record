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
ll n,l,w;
vector<ll> zuo;
vector<ll> you;
bool check(ll x,ll y) {//xx,yy不能用整数
//	dd(x);de(y);
	if(x>=y) return false;
	double xx=double(x+y)/2.;
	double yy=double(-xx+y);
	if(w*yy-xx>0&&-w*yy-xx<0) return true;
	else return false;
}
int main() {
	cin >> n >> l >> w;
	zuo.clear();
	you.clear();
	ff(i,1,n) {
		ll z,op;
		cin >>z >> op;
		if(op==1) you.pb(z);
		else zuo.pb(z+l);
	}
	sort(all(zuo));
	ll lenz=zuo.size();
	ll len=you.size();
	len--;
	ll ans=0;
	ff(i,0,len) {
	//	cout << endl;
	//	de(i);
		ll l=0,r=zuo.size();	
		r--;
		ll hh=-1;
		while(l<=r) {		
		//	dd(l);dd(r)
			ll mid=(l+r)/2;
		//	de(mid);	
			if(check(you[i],zuo[mid])) {
				hh=mid;
				r=mid-1;
			}else l=mid+1;
		}
	//	de(hh);
		if(hh!=-1)ans+=(lenz-hh);
	}
	cout << ans << endl;
}
	
	

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/
