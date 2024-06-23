/*
    Author : Divyam Sirswal
*/
#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define vvi(x,y) vector<vector<ll>>(x,vector<ll>(y));
#define rep(i,s,e) for(long long int i=s;i<e;i++)
#define repi(i,s,e) for(long long int i=s;i<=e;i++)
#define repr(i,e,s) for(long long int i=e-1;i>=s;i--)
#define fora(a) for(auto u:a)
#define lld long double
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define all(a) (a).begin(), (a).end()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define mp make_pair
#define ppb pop_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define vi vector<ll>
#define vit vector<int>::iterator

const ll N = 1e5+1;
const ll MOD = 1e9 + 7;

void google(int t) {cout << "Case #" << t << ": ";}

ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};

void solve(){
      ll a,b;
      cin>>a>>b;
      string p;
      cin>>p;
      vi v(b);
      rep(i,0,b) cin>>v[i];
      string q;
      cin>>q;

      sort(all(v));
      sort(all(q));

      ll j=0;
      for(int i=0;i<b;i++){
            if(i==0){
                  p[v[i]-1]=q[j];
                  j++;
            }else{
                  if(v[i]==v[i-1]) continue;
                  else{
                        p[v[i]-1]=q[j];
                        j++;
                  }
            }
      }
      cout<<p<<endl;
}

int main(){
    fastio();

    ll tt=1;
    cin>>tt;

    while(tt--){
        solve(); //don't worry i dont care about rating keep grinding
    }
}