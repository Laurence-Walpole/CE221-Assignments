// using _TIMEX_H_ since _TIME_H_ seems to be used by some C++ systems

#ifndef _TIMEX_H_
#define _TIMEX_H_

#include <iostream>

using namespace std;

class Time {
public:
    Time();

    Time(int h, int m = 0, int s = 0);

    void setTime(int, int, int);

    Time operator+(unsigned int) const;

    Time &operator+=(unsigned int);

    Time &operator++();    // prefix version
    Time operator++(int);  // postfix version

    // new member functions that you have to implement

    bool operator<(const Time &) const;

    bool operator<=(const Time &) const;

    bool operator==(const Time &) const;

    Time operator-(unsigned int) const;

    Time &operator-=(unsigned int);

    Time &operator--();      // prefix version
    Time operator--(int);   // postfix version

private:
    int hour, min, sec;

    friend ostream &operator<<(ostream &, const Time &);

    // new friend functions that you have to implement

    friend bool operator>(const Time &, const Time &);

    friend bool operator>=(const Time &, const Time &);

    friend bool operator!=(const Time &, const Time &);

    friend unsigned int operator%(const Time &, const Time &);
    // t1%t2 should mean the elapsed time in seconds from t1 to t2
    // e.g. if t1 is 10.45am and t2 is 11.55am t1%t2 would be 4200 (i.e. 70 mins)
    // if t1 is later in the day than t2 then you should assume t2 is on the next day
};

#endif
