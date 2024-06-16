                    #include <bits/stdc++.h>
                    #include <iostream>
                    #include <algorithm>
                    #include <cmath>
                    #include <vector>
                    #include <queue>
                    #include <set>
                    #include <map>
                    #include <string>
                    #include <ext/pb_ds/assoc_container.hpp>
                    #include <ext/pb_ds/tree_policy.hpp>
                    using namespace std;
                    using namespace __gnu_pbds;


                                    #define F              first
                                    #define S              second
                                    #define pb             push_back
                                    #define si             set <int>
                                    #define vi             vector <int>
                                    #define pii            pair <int, int>
                                    #define vpi            vector <pii>
                                    #define vpp            vector <pair<int, pii>>
                                    #define mii            map <int, int>
                                    #define mpi            map <pii, int>
                                    #define spi            set <pii>
                                    #define endl           "\n"
                                    #define sz(x)          ((int) x.size())
                                    // #define double         long double
                                    #define que_max        priority_queue <int>
                                    #define que_min        priority_queue <int, vi, greater<int>>
                                    #define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
                                    #define print(a)       for(auto x : a) cout << x << " "; cout << endl
                                    #define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
                                    #define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl




                    #define int long long int
                    #define lld long double
                    #define ull unsigned long long int
                    #define pll pair<long long, long long>
                    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


                    #define f(i,s,e) for(int i=s;i<e;i++)
                    #define rf(i,e,s) for(int i=e-1;i>=s;i--)
                    #define fll(i,s,e) for(long long int i=s;i<e;i++)
                    #define rfll(i,e,s) for(long long int i=e-1;i>=s;i--)
                    #define pb push_back
                    #define eb emplace_back
                    #define all(a) (a).begin(),(a).end()
                    #define rall(a) (a).rbegin(),(a).rend()
                    #define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

                    template <class T>
                    void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

                    #define MOD 1000000007
                    #define PI 3.1415926535897932384626433832795
                    #define read(type) readInt<type>()

                    string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
                    string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
                    bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
                    void yes() { cout<<"YES\n"; }
                    void no() { cout<<"NO\n"; }

                                    inline inpower(int a, int b)
                                    {
                                        int x = 1;
                                        while (b)
                                        {
                                            if (b & 1) x *= a;
                                            a *= a;
                                            b >>= 1;
                                        }
                                        return x;
                                    }

                                    template <typename Arg1>
                                    void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
                                    template <typename Arg1, typename... Args>
                                    void __f (const char* names, Arg1&& arg1, Args&&... args)
                                    {
                                        const char* comma = strchr (names + 1, ',');
                                        cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
                                    }


                                    const int N = 1e5,M=20;

                                    vector<int>gr[N];
                                    int dep[N],Par[N][M];

                                    void dfs(int curr, int par){
                                        dep[curr]=dep[par]+1;
                                        Par[curr][0]=par;
                                        for(int j=1;j<M;j++){
                                            Par[curr][j]=Par[Par[curr][j-1]][j-1];
                                        }
                                        for(auto x:gr[curr]){
                                            if(x!=par){
                                                dfs(x,curr);
                                            }
                                        }
                                    }

                                    int LCA(int u, int v){
                                        if(u==v)return u;
                                        if(dep[u]<dep[v])swap(u,v);
                                        int diff=dep[u]-dep[v];
                                        for(int j=M-1;j>=0;j--){
                                            if((diff>>j)& 1){
                                                u=Par[u][j];
                                            }
                                        }
                                        if(u==v)return u;
                                        for (int j = M - 1; j >= 0; j--) {
                                            if (Par[u][j] != Par[v][j]) {
                                                u = Par[u][j];
                                                v = Par[v][j];
                                            }
                                        }
                                        return Par[u][0];
                                    }

                                    int gcd(int a,int b){
                                        if(b==0){
                                            return a;
                                        }
                                        return gcd(b,a%b);
                                    }


                               bool compare(pii a, pii b){
                                   if(a.F>b.F){
                                       return true;
                                   }
                                   if(a.F==b.F){
                                    return a.S<b.S;
                                   }
                                   return false;
                              }             


                                  

                                    bool isSorted(vector<int>v,int n){
                                        if(v.size()==0)return true;

                                        for(int i=n+1;i<v.size();i++){
                                            if(v[i-1]>v[i]){
                                                return false;
                                            }
                                        }
                                        return true;
                                    }


                                    int mod=1e9+7;

                                    int sumofDigits(string s){
                                        int val=0;
                                        for(int i=0;i<s.size();i++){
                                            val+=s[i]-'0';
                                        }
                                        return val;
                                    }
                                    bool ispossible(vpi v, int mid){
                                        int curr=0;
                                        for(int i=0;i<v.size();i++){
                                            if(curr>v[i].second){
                                                return false;
                                            }
                                            curr=min(curr+mid,v[i].second);
                                            if(curr<v[i].first){
                                                return false;
                                            }
                                        }
                                        return true;
                                    }

                     
                    bool subArrayExists(vi arr, int N)
                    {
                        set<int> sumSet;
                     
                        int sum = 0;
                        for (int i = 0; i < N; i++) {
                            sum += arr[i];
                     
                            if (sum == 0 || sumSet.find(sum) != sumSet.end())
                                return true;
                     
                            sumSet.insert(sum);
                        }
                        return false;
                    }

                int possible(int a,int b,int d){
                    vi v;
                    for(int i=1;i<=sqrt(d);i++){
                        if(d%i==0){
                            v.push_back(i);
                        }
                    }
                    int n=v.size();
                    if(v[n-1]==b && v[n-2]==a){
                        return 0;
                    }
                    if(v[n-1]>b || v[n-2]>a)
                        return 1;
                    return 2;
                }

                bool isSquare(int i){
                    int k=sqrt(i);
                    return k*k==i;
                }


                int min(int a,int b){
                    if(a<b)return a;
                    return b;
                }
                int max(int a,int b){
                    if(a>b)return a;
                    return b;
                }

                bool isthere(vi ar,int d,int se,int m){
                    for(int i=0;i<se;i++){
                        set<int>s;
                        for(int j=0;j<d;j++){
                            int k=(ar[se*j+i])%m;
                            s.insert(k);
                        }
                        if(s.size()!=1){
                            return false;

                        }
                        s.clear();
                    }
                    return true;
                }

                vi SieveOfEratosthenes(int n)
                {
                    
                    bool prime[n + 1];
                    memset(prime, true, sizeof(prime));
                 
                    for (int p = 2; p * p <= n; p++) {
                        if (prime[p] == true) {
                            
                            for (int i = p * p; i <= n; i += p)
                                prime[i] = false;
                        }
                    }
                    vi v;
                 
                    for (int p = 2; p <= n; p++)
                        if (prime[p])
                            v.pb(p);
                    return v;
                }


            bool is(int mid, int x, int n){
                if(x%mid==0){
                    int val=x/mid;
                    if(n<=val){
                        return true;
                    }
                }
                return false;
            }
            bool istrue(string a, string b){
                for(int i=0;i<a.size();i++){
                    for(int j=0;j<b.size();j++){
                        if(a[i]==b[j])return false;
                    }
                }
                return true;
            }
            int minDistance(string word1, string word2) {
            int n = word1.size(), m = word2.size();
            vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
            for(int i=0;i<=n;i++) dp[i][0] = i;
            for(int j=0;j<=m;j++) dp[0][j] = j;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = 1 + min(dp[i-1][j], 
            min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
            return dp[n][m];
        }

    vector<int> Prefix_Mex(vector<int> A, int n)
    {
        int mx_element = *max_element(A.begin(), A.end());
     
        set<int> s;
        for (int i = 0; i <= mx_element + 1; i++) {
            s.insert(i);
        }
        vector<int> B(n);
        for (int i = 0; i < n; i++) {
     
            auto it = s.find(A[i]);
     
            if (it != s.end()){
                s.erase(it);
            }
            B[i] = *s.begin();
        }
     
        return B;
    }

    vector<int>mex(vi a,int n){
        map<int,int>m;
        vi b(n);
        int v=0;
        for(int i=0;i<n;i++){
            m[a[i]]++;
            if(m.find(v)==m.end()){
                b[i]=v;
            }
            else{
                while(m.find(v)!=m.end()){
                    v++;
                }
                b[i]=v;
            }
        }
        return b;

    }
int maxSubArraySum(vi a, int size)
{
    vector<int> dp(size, 0);
    dp[0] = a[0];
    int ans = dp[0];
    for (int i = 1; i < size; i++) {
        dp[i] = max(a[i], a[i] + dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    return max(0,ans);
}

int power(int x,  int y, int p) 
{ 
    int res = 1;     
 
    x = x % p; 
  
    if (x == 0) return 0;   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 


int findClosestRecursive(vi arr, int target) {
    int n=arr.size();
    int l=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    int res=LLONG_MAX;
    if(l<n){
        res=arr[l]-target;
    }
    if(l>0){
        res=min(res,target-arr[l-1]);
    }
    return res;

}

bool possible(vector<vi>v,int k,int n, int m){
    vector<vector<bool>>dp(n,vector<bool>(m,false));
    dp[0][0]=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0 && v[i][j]%k==0){
                dp[i][j]=dp[i][j] || dp[i-1][j];
            }
            if(j>0 && v[i][j]%k==0){
                dp[i][j]=dp[i][j]||dp[i][j-1];
            }
        }
    }
    return dp[n-1][m-1];

}
int fnc(int a){
    vi v(a,0);
    if(a<=2){
        return 1;
    }
    v[0]=1;
    v[1]=1;
    for(int i=2;i<a;i++){
        v[i]=v[i-1]+v[i-2];
    }
    return v[a-1];
}

void primeFactors(int n,map<int,int>&m) 
{ 
    while (n % 2 == 0) 
    { 
        m[2]++;
        n = n/2; 
    } 
 

    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            m[i]++;
            n = n/i; 
        } 
    // } 
    if (n > 2) 
        m[n]++;
} 
}


int findk(int n)
{ int k; int i=0; int val=pow(2,i);
   
 while(val<=n)
 { 
     k=i; i++;
    val=pow(2,i);
 }
  return k;
}
 
int countSetBits(int N)
{
    int count = 0;
    int k=findk(N);
    int val , x;
   
  
    for (int i = k; i >= 0; i--)
    {
        val=pow(2,i);
        x=val & N; 
       
       if(x > 0)
       { count++;
       }
    }
    return count;
}

struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = max(st[node * 2 + 1],st[node * 2 + 2]);
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return max(q1, q2);
    }

    void update(int start, int ending, int node, int index, int value) {
        // base case
        if (start == ending) {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = max(st[node * 2 + 1],st[node * 2 + 2]);

        return;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};


segmenttree segment(vector<int> v){
    segmenttree tree;
    tree.init(v.size());

    tree.build(v);
    return tree;
}

                void solve(){

                    int n,c;
                    cin>>n>>c;
                    vi v(n);
                    for(int i=0;i<n;i++){
                        cin>>v[i];
                    }
                    v[0]+=c;
                    int ind = 0,maxi = v[0];
                    for(int i = 0;i<v.size();i++){
                        if(maxi<v[i]){
                            maxi = v[i];
                            ind=i;
                        }    
                    }
                    fnc(10);

                    int pre = 0;
                    vi res;
                    for(auto i = 0;i<v.size();i++){
                        pre+=v[i];
                        if(i==ind){
                            res.push_back(0);
                        }
                        else{
                            if(pre>=maxi){
                                res.pb(i);
                            }
                            else{
                                res.pb(i+1);
                            }
                         
                        }
                    }
                    fnc(10);

                    print(res);
                }







                    int32_t main()
                    {
                        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
                    #ifndef ONLINE_JUDGE
                        freopen("input.txt",  "r",  stdin);
                        freopen("output.txt", "w", stdout);
                    #endif
                        clock_t z = clock();
                        int t = 1;
                        cin >> t;
                        while (t--) solve();

                        cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

                        return 0;
                    }            
                                        


                            // 279 337

                            //279 1639}


