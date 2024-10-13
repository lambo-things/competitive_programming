#include <bits/stdc++.h>
using namespace std;
int powe[1000001];
typedef long long int ll;
ll mod = 1e9+7;
int exp(ll x, ll y, ll p) {
    ll res = 1;  // Initialize result
    x = x % p;   // Update x if it is more than or equal to p

    while (y > 0) {
        if (y & 1)  // If y is odd, multiply x with result
            res = (res * x) % p;
        y = y >> 1;  // y = y / 2
        x = (x * x) % p;  // Change x to x^2
    }

    return res;
}
int main(){

    powe[0]=1;
    ll n,m;
    cin>>n>>m;
    for(ll x=1;x<1000001;x++){
        powe[x]=m*powe[x-1]%mod;
    }

    ll sum = 0;
    for(ll x=0;x<n;x++){
        ll hcf = powe[__gcd(x,n)];

        sum = (sum + hcf)%mod;
    }

    ll inv = exp(n,mod-2,mod);

    cout<< sum*inv%mod<<endl;
    return 0;
}