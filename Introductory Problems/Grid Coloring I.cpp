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

int n,m,k,x,y;

void solve(){
    cin>>n>>m;
    char g[n][m];
    rep(i,0,n){
        rep(j,0,m) cin>>g[i][j];
    }

    rep(i,0,n){
        rep(j,0,m){
            int a[4] = {0};
            a[g[i][j]-'A'] = 1;
            if(i-1>=0) a[g[i-1][j]-'A'] = 1;
            if(j-1>=0) a[g[i][j-1]-'A'] = 1;
            rep(k,0,4){
                if(!a[k]) g[i][j] = 'A'+k;
            }
            cout<<g[i][j];
        }
        cout<<endl;
    }

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
