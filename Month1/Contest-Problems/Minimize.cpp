#include <bits/stdc++.h>
using namespace std;

//Aliases
using ll= long long;
using lld= long double;
using ull= unsigned long long;

#define for0(i, n) for (int i = 0; i < (int)(n); ++i)            // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)           // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)      // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)          // reverse 1 based

// short hand for usual tokens
#define pb push_back
#define fi first
#define se second
#define mp make_pair

//Math functions
#define max3(a, b, c) max(a, max(b, c))
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}

// For debugging
#define debug(x) cout << #x << " = " << x << endl


// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end()  // Forward traversal
#define rall(x) (x).rbegin, (x).rend() // reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c, i) for (__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c, x) ((c).find(x) != (c).end())

// find version works for all containers. This is present in std namespace.
#define cpresent(c, x) (find(all(c), x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())

// Shorthand for commonly used types
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;

void solve() {
    int n;
    cin >> n;

    vector<int> ans(n+1);

    cout<<"? "<< 1 << " "<< 2 <<endl;
    fflush(stdout);
    int sum12;
    cin >> sum12;

    cout<<"? "<< 2 << " "<< 3 <<endl;
    fflush(stdout);
    int sum23;
    cin >> sum23;

    cout<<"? "<< 1 << " "<< 3 <<endl;
    fflush(stdout);
    int sum13;
    cin >> sum13;

    //calculate a1, a2, a3

    ans[3] = (sum13 - sum12 + sum23) / 2;   
    ans[2] = sum23 - ans[3];
    ans[1] = sum12 - ans[2];

    //calculate the rest element of the array

    for(int i = 4; i <=n; i++) {
        cout<< "? " << 1 << " " << i <<endl;
        fflush(stdout);
        int sum1i;
        cin >> sum1i;
        ans[i] = sum1i - ans[1];
    }    

    //Print the array output
    cout<<"! ";
    for(int i = 1; i <= n; i++) {
        cout<< ans[i] << " ";
    }
    cout<<endl;
    fflush(stdout);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    
    cout.precision(10);
    cout << fixed;

    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }


    return 0;
}