#include <iostream>
#include <unordered_set>

using namespace std;

bool is_valid_date(const int date)
{
    if (date < 0 || date > 1000000000)
    {
        cerr << "Error: Invalid date. Date must be between 0 and 1,000,000,000." << endl;
        return false;
    }
    return true;
}

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> professor_dates;
    int N; // Number of professor dates
    cin >> N;

    if (!is_valid_number_of_dates(N, 15000))
        return 1;

    for (int i = 0; i < N; ++i)
    {
        int professor_date;
        cin >> professor_date;

        if (!is_valid_date(professor_date))
            return 1;

        professor_dates.insert(professor_date);
    }

    int M; // Number of student dates
    cin >> M;

    if (!is_valid_number_of_dates(M, 1000000))
        return 1;

    int matching_dates_count = 0;
    for (int i = 0; i < M; ++i)
    {
        int student_date;
        cin >> student_date;

        if (!is_valid_date(student_date))
            return 1;

        if (professor_dates.contains(student_date))
            matching_dates_count++;
    }

    cout << matching_dates_count << endl;

    return 0;
}
