#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int day;
    cin >> day;
    while (day != 0)
    {
        string month;
        cin >> month;

        int daysWinter = 0;

        if (month == "Aug")
        {
            daysWinter = 31 - day + 30 + 31 + 30 + 21;
        }
        else if (month == "Sep")
        {
            daysWinter = 30 - day + 31 + 30 + 21;
        }
        else if (month == "Oct")
        {
            daysWinter = 31 - day + 30 + 21;
        }
        else if (month == "Nov")
        {
            daysWinter = 30 - day + 21;
        }
        else if (month == "Dec")
        {
            daysWinter = 21 - day;
        }

        if (daysWinter > 0)
            cout << daysWinter << " days to winter" << endl;
        else
            cout << "Winter is here" << endl;

        cin >> day;
    }

    return 0;
}