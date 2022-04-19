#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<ll>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 10000000000000000
#define input freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define endl "\n"
#define INT_M 1000000007
#define SET(n) cout << fixed << setprecision(n)
#define fo(i, j, n) for (ll i = j; i < n; ++i)
#define dbg(x) cout << #x << ": " << x << endl;

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
vector<ll> sieve1(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

vector<pair<int,int>> ans;
void helper(int i,vi tmpv,int &a,int&b)
{
    if(i==tmpv.size())
    {
        ans.push_back({a,b});
        return;
    }
    a*= tmpv[i];
    helper(i+1,tmpv,a,b);
    a/=tmpv[i];
    b*= tmpv[i];
    helper(i+1,tmpv,a,b); 
    b/=tmpv[i]; 
}
void best()
{
    ll l,r,hcf,lcm;
    cin>>l>>r>>hcf>>lcm;
    ll n = lcm/hcf;
    if(lcm%hcf!=0)
    {
        cout<<0<<endl; return;
    }
    vi sieve= sieve1(1000000);
    // dbg(sieve.size())
    vi tmpv;
    int i=0;
    for(int i=0;i<(sieve).size();i++)
    {
        int tmp=1;
        while(n%sieve[i]==0)
        {
            n/=sieve[i];
            tmp*=sieve[i];
        }
        if(tmp>1)
        tmpv.push_back(tmp);
        if(n==1)break;
        bool f=2;
        for(int j=2;j*j<=n;j++)
        {
            if(n%j==0){
                f=0;break;
            }
        }
        if(f)
        {
            // dbg(n)
            tmpv.push_back(n);
            break;
        }
    }   
    int a=1,b=1;
    // cout<<tmpv.size()<<endl;
    helper(0,tmpv,a,b);
    ll cnt = 0;
    sort(all(ans));
    // for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;

    for(auto it: ans)
    {
        if((it.first*hcf>= l and it.first*hcf<=r) and (it.second*hcf>=l and it.second*hcf<=r))
            cnt++;
    }
    cout<<cnt<<endl;

}
int main()
{
    fast;
    ll T=1;
    // cin>>T;
    while (T--)
    {  
        best();
    }
}