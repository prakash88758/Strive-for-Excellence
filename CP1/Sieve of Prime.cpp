#include<bits/stdc++.h>
using namespace std;

void primeSieve(int *p){
    // first we marked all odd no. is prime and all even no is not prime
    for(int i = 3; i <= 10e4; i += 2)
        p[i] = 1;

    // Sieve
    for (int i = 3; i <= 10e4; i += 2)
        if(p[i] == 1)
            for(int j = i*i; j <= 10e4; j += i)
                p[j] = 0;
    // base or corner case
    p[2] = 1;
}

int main(){
    int t;
    cin >> t;
    int p[10001] = {0};

    primeSieve(p);

    for(int i = 0; i <= t; i++)
        if(p[i] == 1)
            cout << p[i] << " ";
    // getch();
    return 0;
}
