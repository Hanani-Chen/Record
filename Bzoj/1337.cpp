/**************************************************************
    Problem: 1337
    User: Hanani
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:2856 kb
****************************************************************/
 
#include<bits/stdc++.h>
using   namespace  std;
typedef  long long  ll;
typedef pair<ll,ll>pll;
typedef    double   db;
 
#define fi  first
#define se second
#define endl "\n"
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
const int N=1e5+5;
struct node{
    db x,y;
};
node P[N];
node ans;
db R;
inline db sqr(db x) {return x*x;}
inline db dis(node x,node y) {return sqrt(sqr(x.x-y.x)+sqr(x.y-y.y));}
bool incircle(node x) { if(dis(ans,x)<=R+eps) return true;else return false;}
node solve(db a,db b,db c,db d,db e,db f) {
    db y=(f*a-c*d)/(b*d-e*a);
    db x=(f*b-c*e)/(a*e-b*d);
    return (node){x,y};
}
int main() {
    int n;cin >> n;
    ff(i,1,n) cin >> P[i].x >> P[i].y;
    random_shuffle(P+1,P+n+1);
    R=0;
    ff(i,1,n) if(!incircle(P[i])) {
        ans.x=P[i].x;ans.y=P[i].y;R=0;
        ff(j,1,i-1) if(!incircle(P[j])) {
            ans.x=(P[i].x+P[j].x)/2.0;
            ans.y=(P[i].y+P[j].y)/2.0;
            R=dis(ans,P[i]);
            ff(k,1,j-1) if(!incircle(P[k])) {
                ans=solve(
                    P[i].x-P[j].x,P[i].y-P[j].y,
                    (sqr(P[j].x)+sqr(P[j].y)-sqr(P[i].x)-sqr(P[i].y))/2.0,
                    P[i].x-P[k].x,P[i].y-P[k].y,
                    (sqr(P[k].x)+sqr(P[k].y)-sqr(P[i].x)-sqr(P[i].y))/2.0
                );
                R=dis(P[i],ans);
            }
        }
    }
    printf("%.3f\n",R);
}
    
