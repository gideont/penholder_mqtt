#include "greetings.hpp"

using namespace std;

string now_date(tm *ltm)
{
    string ndate;

    switch(ltm->tm_wday)
    {
        case 0 :
            ndate = "Sunday";
            break;
        case 1 :
            ndate = "Monday";
            break;
        case 2 :
            ndate = "Tuesday";
            break;
        case 3 :
            ndate = "Wednesday";
            break;
        case 4 :
            ndate = "Thursday";
            break;
        case 5 :
            ndate = "Friday";
            break;
        case 6 :
            ndate = "Saturday";
            break;
        default :
            cout << "Invalid date";
    }
    return ndate;
}

string greetings_rand()
{
    vector <string> greetings;
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, 6);

    greetings.push_back("Happy");
    greetings.push_back("Lucky");
    greetings.push_back("Joyful");
    greetings.push_back("Cheerful");
    greetings.push_back("Beautiful");
    greetings.push_back("Splendid");
    greetings.push_back("Fabulous");
    greetings.push_back("Wonderful");

    return greetings[distr(eng)];
}
