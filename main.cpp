#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string line;
    int n, m;

    // Read the first line and parse n and m
    getline(cin, line);
    istringstream iss(line);
    iss >> n >> m;

    // Validate n and m
    if (m < 1 || m > n || n > 100)
    {
        cerr << "Error: Invalid values for n or m." << endl;
        return 1;
    }

    vector<int> prices;
    for (int i = 0; i < n; ++i)
    {
        int price;
        cin >> price;

        // Validate price
        if (price < -1000 || price > 1000)
        {
            cerr << "Error: Invalid value for price." << endl;
            return 1;
        }

        if (price < 0)
        {
            prices.push_back(price);
        }
    }

    // Sort the prices in ascending order
    sort(prices.begin(), prices.end());

    int total_price = 0;
    for (int i = 0; i < m && i < prices.size(); ++i)
    {
        total_price += -prices[i];
    }

    cout << total_price << endl;

    return 0;
}
