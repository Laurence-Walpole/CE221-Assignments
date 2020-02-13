#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time() {
    hour = min = sec = 0;
}

Time::Time(int h, int m, int s) {
    setTime(h, m, s);
}

void Time::setTime(int h, int m, int s) {
    hour = (h >= 0 && h < 24) ? h : 0;
    min = (m >= 0 && m < 60) ? m : 0;
    sec = (s >= 0 && s < 60) ? s : 0;
}

Time &Time::operator+=(unsigned int n) {
    sec += n;
    if (sec >= 60) {
        min += sec / 60;
        sec %= 60;
        if (min >= 60) {
            hour = (hour + min / 60) % 24;
            min %= 60;
        }
    }
    return *this;
}

Time Time::operator+(unsigned int n) const {
    Time tCopy(*this);
    tCopy += n;
    return tCopy;
}

Time &Time::operator++() {
    *this += 1;
    return *this;
}

Time Time::operator++(int n){
    Time tCopy(*this);
    *this += 1;
    return tCopy;
}

ostream &operator<<(ostream &o, const Time &t) {
    o << setfill('0') << setw(2) << t.hour << ':' << setw(2) << t.min << ':' << setw(2) << t.sec;
    return o;
}

bool Time::operator<(const Time &t) const {
    if(this->hour < t.hour) return true; //Return true if hour is less
    if ((this->min < t.hour) && (this->hour == t.hour)) return true; //Return true if hour is equal and min is less
    return ((this->sec < t.sec)  && (this->hour == t.hour) && (this->min == t.min)); // Return true if hour and min equal and sec less
}

bool Time::operator<=(const Time &t) const {
    if (*this == t) return true; //If equal return
    return (*this < t); //If less, return
}

bool Time::operator==(const Time &t) const {
    return ((this->hour == t.hour) && (this->min == t.min) && (this->sec == t.sec)); //All equal, return
}

Time Time::operator-(unsigned int i) const {
    Time tCopy(*this);
    tCopy -= i; //Remove x from time
    return tCopy;
}

Time &Time::operator-=(unsigned int i) {
    int seconds = (this->sec + (this->min * 60) + ((this->hour * 60) * 60)) - i; //Convert to seconds
    if (seconds < 0) seconds += 86400; //Un-minus the seconds
    int minutes = seconds / 60; //Find the new minutes
    int hours = minutes / 60; //Find the new hours
    this->min = minutes % 60; //Set the values
    this->sec = seconds % 60;
    this->hour = hours;
    return *this;
}

Time &Time::operator--() {
    *this -= 1;
    return *this;
}

Time Time::operator--(int i) {
    Time tCopy(*this);
    *this -= 1;
    return tCopy;
}

bool operator>(const Time &time1, const Time &time2) {
    if(time1.hour > time2.hour) return true; //Return if hour greater
    if ((time1.min > time2.min) && (time1.hour == time2.hour)) return true; //Return if hour equal and min greater
    return ((time1.sec > time2.sec)  && (time1.hour == time2.hour) && (time1.min == time2.min)); //Return if min and hour equal and sec greater
}

bool operator>=(const Time &time1, const Time &time2) {
    return (time1 == time2) || (time1 > time2); //Return if equal or greater
}

bool operator!=(const Time &time1, const Time &time2) {
    return (time1.hour != time2.hour) || (time1.min != time2.min) || (time1.sec != time2.sec); //Return if all not equal
}

unsigned int operator%(const Time &time1, const Time &time2) {
    int time1Seconds = ((time1.hour*3600)+(time1.min*60)+(time1.sec)); //Find the seconds for first time
    int time2Seconds = ((time2.hour*3600)+(time2.min*60)+(time2.sec)); //Find the seconds for 2nd time
    if(time1 < time2){ return time2Seconds - time1Seconds; //If time greater than time2, remove time 1 from time 2
    } else { return time2Seconds - time1Seconds + 86400; } //Otherwise do the same and add 24 hours
}

