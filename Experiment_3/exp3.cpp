#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> mp;
    int s = 0;
    int maxi = 0;
    mp[0] = -1;

    vector<char> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (array[i] == 'P')
            s += 1;
        else if (array[i] == 'A')
            s -= 1;

        if (mp.find(s) != mp.end())
        {
            maxi = max(maxi, i - mp[s]);
        }
        else
        {
            mp[s] = i;
        }
    }

    cout << maxi << endl;
    return 0;
}
