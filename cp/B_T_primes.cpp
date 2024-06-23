#include<bits/stdc++.h>
int main() {
    int n;
    long long a, b, j;
    scanf("%d",&n);
    while (n--) {
        scanf("%I64d", &a);
        b = sqrt(a);
        for (j = 2; j * j <= b; j++) {
            if (b % j == 0) {
                break;
            }
        }
        puts((j * j > b && b * b == a && a > 1) ? "YES" : "NO");
    }
}
