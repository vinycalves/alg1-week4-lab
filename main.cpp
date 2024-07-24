#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to find a triplet (three identical elements) in an array
void findTriplet(const std::vector<int>& array, int n);

int main()
{
    string line;
    int t;
    cin >> t; // Read the number of test cases

    // Check if the number of test cases is within the allowed range
    if (t < 1 || t > 10000)
    {
        cerr << "Error: t must be between 1 and 10000." << endl;
        return 1;
    }

    // Execute for each test case
    while (t--)
    {
        int n;
        cin >> n; // Read the size of the array

        // Check if the array size is within the allowed range
        if (1 > n || n > 200000)
        {
            std::cerr << "Error: n must be between 1 and 200000." << std::endl;
            continue; // Skip to the next iteration if the array size is out of range
        }

        vector<int> array(n); // Declare a vector of size n
        for (int i = 0; i < n; ++i) {
            cin >> array[i]; // Read the elements of the array
        }
        findTriplet(array, n); // Call the function to find the triplet
    }

    return 0;
}

// Function to find a triplet (three identical elements) in an array
void findTriplet(const vector<int>& array, const int n)
{
    unordered_map<int, int> count; // Map to count the occurrences of each element

    for (int i = 0; i < n; i++)
    {
        count[array[i]]++; // Increment the count of the current element
        if (count[array[i]] == 3) // Check if the current element has appeared 3 times
        {
            cout << array[i] << endl; // Print the element that appeared 3 times
            return; // Exit the function
        }
    }

    cout << -1 << endl; // If no element appeared 3 times, print -1
}
