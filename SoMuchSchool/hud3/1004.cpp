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

#define ls rt<<1
#define rs (rt<<1)|1

#define INF 0x3f3f3f3f3f3f3f
#define mem(a,b)   memset(a,b,sizeof(a))
#define file freopen("in.txt","r",stdin)
#define jkl ios::sync_with_stdio(false);cin.tie(0);
/*********************************************/
const int N=2e5+5;
ll a[N];
ll sum[N];
vector<ll> v;
struct node {
    ll l,r,w=0;
}tr[N<<2];
ll t,n,k,x,m;
ll max(ll a,ll b) {if(a>b) return a;else return b;}
void build(int l,int r,int rt) {
    tr[rt].l=l,tr[rt].r=r;tr[rt].w=0;
    if(l==r) return ;
    ll mid=(l+r)/2;
    build(mid+1,r,rs);
    build(l,mid,ls);
    return ;
}

void update(int rt,int pos,ll val) {
    ll l=tr[rt].l,r=tr[rt].r;
    ll mid=(l+r)/2;
    if(l==r) {tr[rt].w=max(tr[rt].w,val);return ;}
    if(pos<=mid) update(ls,pos,val);
    else update(rs,pos,val);
    tr[rt].w=max(tr[ls].w,tr[rs].w);
    return ;
}
    
ll query(int rt,int L,int R) {
//    de(rt);
    ll ans=0;
    ll l=tr[rt].l,r=tr[rt].r;
//    dd(l);de(r);
    ll mid=(l+r)/2;
    if(L<=l&&r<=R) return tr[rt].w;
    if(mid>=L) ans=max(ans,query(ls,L,R));
    if(mid<R) ans=max(ans,query(rs,L,R));
    return ans;    
}

bool check(ll x) {
    build(1,n,1);
    ff(i,1,n) {
         ll l=lower_bound(all(v),sum[i]-x)-v.begin()+1;
         ll r=lower_bound(all(v),sum[i])-v.begin()+1;
//         for(auto aa:v) dd(aa);cout << endl;
//         de(sum[i]);
//    dd(x);dd(l);dd(r);
         if(l>m) {
             if(sum[i]<=x) update(1,r,1);
             continue;
         }
        ll w=query(1,l,m);
//        de(w);
        if(w) {
            update(1,r,w+1);
        }else if(sum[i]<=x) update(1,r,1);
    }
    ll hh=query(1,1,m);
//    de(hh);
//    de(k);
    return hh>=k;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        v.clear();
        mem(sum,0);
        mem(a,0);
        ff(i,1,n) {
            cin >> a[i];
            sum[i]=sum[i-1]+a[i];
            v.pb(sum[i]);
        }
        sort(all(v));
        v.erase(unique(all(v)),v.end());
        m=v.size();
        ll l1=-INF,r1=INF;
    //    de(INF);
        ll ans=2e14;
        while(l1<=r1) {
            ll mid=(l1+r1)/2;
        //    dd(l1);dd(r1);de(mid);
            if(check(mid)) {
                ans=mid;
                r1=mid-1;
            }else l1=mid+1;
        }
        cout << ans << endl;
    }
}
        

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/
