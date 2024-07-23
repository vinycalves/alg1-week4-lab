#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string line;
    int n, m;

    getline(cin, line);
    istringstream iss(line);
    iss >> n >> m;

    if (1 > m || m > n || n > 100)
    {
        cerr << "Error: Input of an value at n or m was invalid" << endl;
    }

    vector<int> prices;
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;

        if (price < -1000 || price > 1000)
            cerr << "Error: Input of an value at price was invalid" << endl;

        if (price < 0)
        {
            prices.push_back(price);
        }
    }

    ranges::sort(prices);

    int total_price = 0;
    for (const int price : prices)
    {
        if (m == 0)
            break;

        total_price += price * -1;
        m--;
    }

    cout << total_price << endl;

    return 0;
}
