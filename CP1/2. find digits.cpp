#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int findDigits (int);
    int n, y, count = 0, rem;
    cin >> n;
    // y = findDigits(n);
    int num = n;
    while(n != 0)
    {
        rem = n%10;
        // if( rem == 0)
        // rem = n % 10;
        if( num % rem == 0 && rem != 0)
        {
            count++;
            n = n/10;
        }
        else
        n = n/10;
    }
    cout << count;

    return 0;
}

// int findDigits(int n) {

//     int count = 0, rem;
//     int num = n;
//     do
//     {
//         rem = n % 10;
//         if( rem == 0)
//         rem = n % 10;
//         else if( num % rem == 0 )
//         count++;
//         else
//         n = n/10;
//     }while(n > 9);
//     return count;
// }
