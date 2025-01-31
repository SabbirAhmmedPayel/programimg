#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        vector<int> ans;
        char c;
        int rows;
        cin >> rows;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                cin >> c;
                if (c == '#')
                {
                    ans.push_back(j);
                }
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << endl;
        }
        ans.clear();
    }

    return 0;
}