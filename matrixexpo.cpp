#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod = 1e9+7;

ll** once(ll** arr,ll** arr1){
    ll** ans = new ll*[2];

    for(int x=0;x<2;x++){
        ans[x]=new ll[2];
    }

    ans[0][0]=(arr[0][0]*arr1[0][0]%mod +arr[0][1]*arr1[1][0]%mod)%mod;
    ans[0][1]=(arr[0][0]*arr1[0][1]%mod +arr[0][1]*arr1[1][1]%mod)%mod;
    ans[1][0]=(arr[1][0]*arr1[0][0]%mod +arr[1][1]*arr1[1][0]%mod)%mod;
    ans[1][1]=(arr[1][0]*arr1[0][1]%mod +arr[1][1]*arr1[1][1]%mod)%mod;
    
    return ans;
}

ll** matmul(ll n) {
    ll **result = new ll*[2]; 
    ll **ans = new ll*[2];
    for (int i = 0; i < 2; ++i) {
        result[i] = new ll[2]; 
        ans[i] = new ll[2]; 
    }
    result[0][0]=1;result[0][1]=1;result[1][0]=1;result[1][1]=0;
    ans[0][0]=1;ans[0][1]=1;ans[1][0]=1;ans[1][1]=1;
    n -=2;

    // part doing matrix exponentiation in log(n) time

    while(n){
        if(n&1){ans = once(ans,result);}
        n>>=1;
        result = once(result,result);
    }

    //end
    return ans; 
}
void solve() {
    ll n;
    cin >> n; 
    if(n<2){cout<<n<<endl;return;}
    ll** ans = matmul(n); 
    cout<<ans[0][0]<<endl;
}
int main() {
    solve();
    return 0;
}
