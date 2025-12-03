#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define multiordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
 
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ld long double
 
const int MOD = 1e9 +7;
const int maxN = 2e5+1;
 
int binpow(int a,int b,int m){
    if(a==0 && b==0) return 1;
    if(a==0) return 0;
    if(b==0) return 1;
    int ans=1;
    a=(a+m)%m;
 
    while(b){
        if(b&1)
            ans=(ans*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ans%m;
}
 
// can give correct answer up to 1e18
bool isprime1(int n){
    if(n<2) return false;
    for(int i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e5;++it){
        int i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        if(binpow(i,n-1,n)!=1) return false;
    }
    return true;
}
bool isprime(int x) {
    if(x==1) return 0;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) 
            return false;
    }
    return true;
}
 
int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}
 
int lcm(int x,int y){
    return (x*y)/gcd(x,y);
}
 
#define F first
#define S second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define vpi vector<pair<int,int>>
#define pi pair<int,int>

int n,m,k,x,y,z;

bool comp1(pair<int,pi>&a, pair<int,pi>&b){
    if(a.S.F==b.S.F){
        return a.F>b.F;
    }
    return a.S.F<b.S.F;
}

bool comp2(pair<int,pi>&a, pair<int,pi>&b){
    if(a.F==b.F) return a.S.F>b.S.F;
    return a.F<b.F;
}

void solve(){
    cin>>n;
    vector<pair<int,pair<int,int>>>v;
    rep(i,0,n){
        cin>>x>>y;
        v.pb({x,{y,i}});
    }

    sort(all(v),comp1);
    bool contains[n] = {0};
    int l = v[0].F,ind = 0;
    rep(i,1,n){
        if(v[i].F<=l){
            contains[v[i].S.S] = 1;
            if(v[i].F==l && v[ind].S.F==v[i].S.F){
                contains[v[ind].S.S] = 1;
            }
        }
        if(l<v[i].F){
            l = v[i].F;
            ind = i;
        }
    }
    
    sort(all(v),comp2);
    bool contained[n] = {0};
    int r = v[0].S.F;
    ind = 0;
    rep(i,1,n){
        if(v[i].S.F<=r){
            contained[v[i].S.S] = 1;
            if(v[i].S.F==r && v[i].F==v[ind].F) contained[v[ind].S.S] = 1;
        }
        if(v[i].S.F>r){
            r = v[i].S.F;
            ind = i;
        }
    }

    rep(i,0,n) cout<<contains[i]<<" ";
    cout<<endl;
    rep(i,0,n) cout<<contained[i]<<" ";
    cout<<endl;

}


 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}