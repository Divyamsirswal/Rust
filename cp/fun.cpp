#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main(){
 	int a[] = {1,1,2,3,1};
 	int xr = 0;
 	int n = sizeof(a)/sizeof(a[0]);

 	for(int i=0;i<n;i++){
 		xr = xr ^ a[i];
 	}
 	for(int i=0;i<n;i++){
 		int k = xr ^ a[i];
 		if(k!=0) cout << k << " ";
 	}
}