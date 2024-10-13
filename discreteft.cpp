#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<double>> fft(vector<ll>poly,ll size){

    double real = 0;
    double ima  = 0;
    vector<vector<double>>ans;

    for(int x=0;x<poly.size();x++){
        for(int y=0;y<poly.size();y++){

            real += poly[y]*cos(((double)(-2*M_PI*x*y))/size);
            ima  += poly[y]*sin(((double)(-2*M_PI*x*y))/size);
        }
        ans.push_back({real,ima});
        real = 0;
        ima  = 0;
    }
    return ans;
}

vector<double> inverse_fft(vector<vector<double>>v){

    vector<double>ans;
    for(int x=0;x<v.size();x++){

        double an = 0;

        for(int y=0;y<v.size();y++){
            double ri = cos(((double)2*M_PI*x*y)/v.size());
            double ii = sin(((double)2*M_PI*x*y)/v.size());

            an += v[y][0]*ri - v[y][1]*ii;

        }
        ans.push_back(an/v.size());
    }
    return ans;
}

int main(){

    int n1,m1;
    cin>>n1>>m1;
    vector<ll>a;
    vector<ll>b;

    for(int x=0;x<n1;x++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    for(int y=0;y<m1;y++){
        int t;
        cin>>t;
        b.push_back(t);
    }

    int n = a.size();
    int m = b.size();

    while(a.size()<n+m-1){
        a.push_back(0);
    }
    while(b.size()<n+m-1){
        b.push_back(0);
    }

    vector<vector<double>>fura = fft(a,n+m-1);
    vector<vector<double>>furb = fft(b,n+m-1);
    vector<vector<double>>ans;

    for(int x=0;x<n+m-1;x++){
        double rt = furb[x][0]*fura[x][0] - fura[x][1]*furb[x][1];
        double it = furb[x][0]*fura[x][1] + furb[x][1]*fura[x][0];
        ans.push_back({rt,it});
    }
    vector<double>b1 = inverse_fft(ans);
    for(auto x:b1){
        cout<<(x<1e-9?0:x)<<" ";
    }
    cout<<endl;

    return 0;
}