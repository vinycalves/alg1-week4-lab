#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

bool is_valid_date(const int date)
{
    if (date < 0 || date > 1000000000)
    {
        cerr << "Invalid date." << endl;
        return false;
    }
    return true;
}

int main()
{
    unordered_map<int, int> professor_dates;
    int N; // Number of professsor dates
    cin >> N;

    if (N < 1 || N > 15000)
    {
        cerr << "Invalid number of dates from professor." << endl;
        return 1;
    }

    for (int i = 0; i < N; ++i)
    {
        int professor_date;
        cin >> professor_date;

        if (!is_valid_date(professor_date))
            return 1;

        professor_dates[professor_date] = 0;
    }

    int M;
    cin >> M;

    if (M < 1 || M > 1000000)
    {
        cerr << "Invalid number of dates from student." << endl;
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < M; ++i)
    {
        int student_date;
        cin >> student_date;

        if (!is_valid_date(student_date))
            return 1;

        if (professor_dates.contains(student_date))
        {
            sum++;
        }
    }

    cout << sum << endl;

    return 0;
}
