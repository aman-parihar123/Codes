#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

#define int long long
#define ll long long
#define pb push_back
#define pp pop_back
#define f(i, x) for (int i = 0; i < x; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define inf 1e18
#define mod 998244353

ll gcd(ll a, ll b) { if (b > a) { return gcd(b, a); } if (b == 0) { return a; } return gcd(b, a % b); }
ll expo(ll a, ll b, ll m) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b = b >> 1; } return res % m; }
int nCr(int n, int r) {
    if (n < r) return 0;
    if (r > n - r) r = n - r;
    ll ans = 1; ll i;
    for (i = 1; i <= r; i++) { ans = (ans * (n - r + i)); ans /= i; } return ans;
}
ll modinv(ll a, ll m) { return expo(a, m - 2, m) % m; } // m is prime

bool comp(string a,string b){
    if(a.size()!=b.size()) return a.size()<b.size();
    return a<b;
}

int32_t main() {
    fastio; 
    
   
   //  vector<string> v={"de","acb"};

   // sort(v.begin(),v.end(),comp);

   // cout<<v[1];

    vector<int> v={2,3,3,3,4,5};
    auto x = upper_bound(all(v),1);
    
    cout<<*x;

  





















}
