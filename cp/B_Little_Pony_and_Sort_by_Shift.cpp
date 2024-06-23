#include<bits/stdc++.h>
using namespace std;

int n,a[100007],m,k,i;
main(){
    for(cin>>n;i<n;) cin>>a[i++];
    for(i=0;i<n;i++){
        if(a[i]>a[(i+1)%n]){
            m++;
            if(m>1){
                return puts("-1");
            }
            k=i+1;
        }
    }
    cout<<(n-k)%n<<"\n";
}