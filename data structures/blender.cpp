#include <iostream>
#include <math.h>

using namespace std;
int main()
{

    int testcases;
    cin >> testcases;

    while (testcases--)
    {
        int n, k;
        cin >> n >> k;
        if(n==1){
            cout << "NO" << endl;
            continue;
        }

        int ans = 0;

        for (int i = 0; i < k; i++)
        {
            ans += pow(n - i, n - i);
        }

        if (ans % 2 == 0)
        {
            cout <<"YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
