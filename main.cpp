#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

void findTriplet(const std::vector<int>& array, int n);

int main()
{
    string line;
    int t;
    cin >> t;

    if (t < 1 || t > 10000)
    {
        cerr << "Erro: o valor de t deve estar entre 1 e 10000." << endl;
        return 1;
    }

    while (t--)
    {
        int n;
        cin >> n;

        if (1 > n || n > 200000)
        {
            std::cerr << "Erro: o valor de n deve estar entre 1 e 200000." << std::endl;
        }

        vector<int> array(n);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }
        findTriplet(array, n);
    }

    return 0;
}

void findTriplet(const vector<int>& array, const int n)
{
    unordered_map<int, int> count;

    for (int i = 0; i < n ; i++)
    {
        count[array[i]]++;
        if (count[array[i]] == 3)
        {
            cout << array[i] << endl;
            return;
        }
    }

    cout << -1 << endl;
}
