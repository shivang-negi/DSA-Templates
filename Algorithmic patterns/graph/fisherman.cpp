#include<iostream>
using namespace std;

int n, gp1, gp2, gp3, nf1, nf2, nf3, c_m;
int max(int a, int b) {
    if(a>b)
        return a;
    return b;
}

int absa(int a) {
    if(a>0) return a;
    return -a;
}

void solve() {
    for(int i=1;i<=n-nf2-nf3;i++) {
        for(int j=i+nf1;j<=n-nf3;j++) {
            for(int k=j+nf2;k<=n;k++) {
                int c = 0;
                for(int p=i;p<i+nf1;p++)
                    c += absa(gp1-p);
                for(int p=j;p<j+nf2;p++)
                    c += absa(gp2-p);
                for(int p=k;p<k+nf3;p++)
                    c += absa(gp3-p);
                c += nf1 + nf2 + nf3;
                c_m = min(c_m, c);
            }
        }
    }
}
int main() {
        cin>>n;
        cin>>gp1>>gp2>>gp3;
        cin>>nf1>>nf2>>nf3;
        c_m = 99999;
        solve();    
        cout<<c_m<<endl;
        return 0; 
}