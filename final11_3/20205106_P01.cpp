#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pss std::pair<std::string, std::string>
#define vs std::vector<std::string>
#define vp std::vector<pss>
const long long MAX = 1000000;
#define ft(i, x, y) for (int i = x; i <= y; i++)
#define fdt(i, x, y) for (int i = x; i >= y; i--)
typedef long long ll;
std::map<std::string, std::string> date;
std::map<std::string, int> my_customer;
std::map<std::string, vp> allMyTrip;
std::map<pss, int> myTrip;
int countTrip;
int totalQty;
bool compareDays(std::string days1, std::string days2)
{
    std::string day1 = days1.substr(0, 2);
    std::string day2 = days2.substr(0, 2);
    std::string month1 = days1.substr(3, 2);
    std::string month2 = days2.substr(3, 2);
    std::string year1 = days1.substr(6, 4);
    std::string year2 = days2.substr(6, 4);
    if (year1 < year2)
        return true;
    if (year1 == year2)
    {
        if (month1 < month2)
            return true;
        if (month1 == month2)
        {
            if (day1 < day2)
                return true;
        }
    }
    return false;
}
bool copareTime(std::string time1, std::string time2)
{
    std::string hour1 = time1.substr(0, 2);
    std::string hour2 = time2.substr(0, 2);
    std::string minute1 = time1.substr(3, 2);
    std::string minute2 = time2.substr(3, 2);
    std::string second1 = time1.substr(6, 2);
    std::string second2 = time2.substr(6, 2);
    if (hour1 < hour2)
        return true;
    if (hour1 == hour2)
    {
        if (minute1 < minute2)
            return true;
        if (minute1 == minute2)
        {
            if (second1 < second2)
                return true;
        }
    }
    return false;
}
int totalTime(std::string days1, std::string days2, std::string time1, std::string time2)
{

    std::string day1 = days1.substr(0, 2);
    std::string day2 = days2.substr(0, 2);
    std::string month1 = days1.substr(3, 2);
    std::string month2 = days2.substr(3, 2);
    std::string year1 = days1.substr(6, 4);
    std::string year2 = days2.substr(6, 4);
    std::string hour1 = time1.substr(0, 2);
    std::string hour2 = time2.substr(0, 2);
    std::string minute1 = time1.substr(3, 2);
    std::string minute2 = time2.substr(3, 2);
    std::string second1 = time1.substr(6, 2);
    std::string second2 = time2.substr(6, 2);
    int day = std::stoi(day2) - std::stoi(day1);
    int month = std::stoi(month2) - std::stoi(month1);
    int year = std::stoi(year2) - std::stoi(year1);
    int hour = std::stoi(hour2) - std::stoi(hour1);
    int minute = std::stoi(minute2) - std::stoi(minute1);
    int second = std::stoi(second2) - std::stoi(second1);
    int total = second + minute * 60 + hour * 3600 + day * 86400 + month * 2592000 + year * 31104000;
    return total;
}
void processDays(vp timeTravel)
{
    std::vector<std::string> days;
    std::vector<std::string> times;
    for (pss s : timeTravel)
    {
        days.push_back(s.first);
        times.push_back(s.second);
    }
    if (days.size() == 1)
    {
        std::cout << 0 << std::endl;
        return;
    }
    ft(i, 0, days.size() - 2)
    {
        mp(days[i], days[i + 1]);
    }
    sort(days.begin(), days.end());
    sort(times.begin(), times.end());
    std::string startDay = days[0];
    std::string startTime = times[0];
    std::string endTime = times[times.size() - 1];
    std::string endDay = days[days.size() - 1];
    std::cout << totalTime(startDay, endDay, startTime, endTime) << std::endl;
}
int qtyMaxperiod(std::string days1, std::string days2, std::string time1, std::string time2)
{
    // tìm thời điểm có lượng hàng giao lớn nhất trong khoảng thời gian đã cho
    vp timeTravel;
    for (auto s : myTrip)
    {
        if (compareDays(s.first.first, days1) && compareDays(days2, s.first.first))
        {
            if (copareTime(time1, s.first.second) && copareTime(s.first.second, time2))
            {
                timeTravel.push_back(s.first);
            }
        }
    }
    int max = 0;
    for (pss s : timeTravel)
    {
        if (myTrip[s] > max)
            max = myTrip[s];
    }
    return max;
}
// void maxConflixTrip()
// {
//     int max = 0;
//     std::string trip;
//     for (auto s : allMyTrip)
//     {
//         if (s.second.size() > max)
//         {
//             max = s.second.size();
//             trip = s.first;
//         }
//     }
//     std::cout << trip << std::endl;
// }

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    std::string s;
    std::cin >> s;
    while (s != "*")
    {
        date[s] = "";
        std::cin >> s;
    }
    std::string trip, customer, day, time;
    int qty;
    do
    {
        std::cin >> trip;
        if (trip == "***")
            continue;
        std::cin >> customer >> day >> time >> qty;
        my_customer[customer] += qty;
        totalQty += qty;
        allMyTrip[trip].push_back(mp(day, time));
        myTrip[mp(day, time)] = qty;

    } while (trip != "***");
    std::string cmd;
    do
    {
        std::cin >> cmd;
        if (cmd == "***")
            return 0;
        if (cmd == "TOTAL_QTY")
        {
            std::cout << totalQty << std::endl;
        }
        if (cmd == "QTY_CUSTOMER")
        {
            std::string cus;
            std::cin >> cus;
            std::cout << my_customer[cus] << std::endl;
        }
        if (cmd == "TOTAL_TRIPS")
        {
            std::cout << allMyTrip.size() << std::endl;
        }
        if (cmd == "TRAVEL_TIME_TRIP")
        {
            std::string searchTrip;
            std::cin >> searchTrip;
            vp timeTravel = allMyTrip[searchTrip];
            processDays(timeTravel);
        }
        if (cmd == "QTY_MAX_PERIOD")
        {
            std::string startTime, endTime, startDay, endDays;
            std::cin >> startDay >> startTime >> endDays >> endTime;
            std::cout << qtyMaxperiod(startDay, endDays, startTime, endTime) << std::endl;
        }
        if (cmd == "MAX_CONFLICT_TRIPS")
        {
            // maxConflixTrip();
            std::cout << 0 << std::endl;
        }
    } while (cmd != "***");
    return 0;
}