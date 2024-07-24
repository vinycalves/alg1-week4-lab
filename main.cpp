#include <iostream>
#include <unordered_set>

using namespace std;

// Function to validate the given date
bool is_valid_date(const int date)
{
    if (date < 0 || date > 1000000000)
    {
        cerr << "Error: Invalid date. Date must be between 0 and 1,000,000,000." << endl;
        return false;
    }
    return true;
}

// Function to validate the number of dates
bool is_valid_number_of_dates(const int num_dates, const int max_limit)
{
    if (num_dates < 1 || num_dates > max_limit)
    {
        cerr << "Error: Invalid number of dates. Number must be between 1 and " << max_limit << "." << endl;
        return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); // Optimize input and output operations
    cin.tie(nullptr); // Untie cin and cout for faster input and output

    unordered_set<int> professor_dates; // Set to store unique professor dates
    int N; // Number of professor dates
    cin >> N;

    // Validate the number of professor dates
    if (!is_valid_number_of_dates(N, 15000))
        return 1;

    // Read professor dates and store them in the set
    for (int i = 0; i < N; ++i)
    {
        int professor_date;
        cin >> professor_date;

        // Validate each professor date
        if (!is_valid_date(professor_date))
            return 1;

        professor_dates.insert(professor_date); // Insert the date into the set
    }

    int M; // Number of student dates
    cin >> M;

    // Validate the number of student dates
    if (!is_valid_number_of_dates(M, 1000000))
        return 1;

    int matching_dates_count = 0; // Counter for matching dates
    for (int i = 0; i < M; ++i)
    {
        int student_date;
        cin >> student_date;

        // Validate each student date
        if (!is_valid_date(student_date))
            return 1;

        // Check if the student date is in the professor dates set
        if (professor_dates.contains(student_date))
            matching_dates_count++;
    }

    cout << matching_dates_count << endl; // Output the count of matching dates

    return 0;
}
