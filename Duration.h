#ifndef DURATION_H
#define DURATION_H

class Duration {

private:

    int hours, minutes, seconds;    
    
public:

   inline int getHours() const;
   
   inline int getMinutes() const;
   
   inline int getSeconds() const;

   inline operator int() const;
   
   Duration(int hours = 0, int minutes = 0, int seconds = 0);

   friend std::ostream& operator<<(std::ostream &os, const Duration &d);
};

inline int Duration::getHours() const
{
   return hours;
}

inline int Duration::getMinutes() const
{
   return minutes;
}

inline int Duration::getSeconds() const
{
   return seconds;
}

inline Duration::operator int() const
{
   return seconds + 60*(minutes + 60*hours);    
}

inline bool operator<(const Duration &a, const Duration &b)
{
    return int(a) < int(b);
}

inline bool operator>=(const Duration &a, const Duration &b)
{
    return !(a < b);
}

inline bool operator>(const Duration &a, const Duration &b)
{
    return int(a) > int(b);
}

inline bool operator<=(const Duration &a, const Duration &b)
{
    return !(a > b);
}

inline bool operator==(const Duration &a, const Duration &b)
{
    return int(a) == int(b);
}

inline bool operator!=(const Duration &a, const Duration &b)
{
    return !(a == b);
}

inline Duration operator+(const Duration& a, const Duration &b)
{
    return Duration(0,0, int(a) + int(b));
}

inline Duration operator-(const Duration& a, const Duration &b)
{
    return Duration(0,0, int(a) - int(b));
}

inline Duration operator*(const Duration& a, int n)
{
    return Duration(0,0, n*int(a));
}

inline Duration operator*(int n, const Duration& a)
{
    return Duration(0,0, n*int(a));
}

inline Duration operator/(const Duration &a, int n)
{
    return Duration(0,0,int(a)/n);
}

inline int operator%(const Duration &a, int n)
{
    return int(a)%n;
}

inline std::ostream& operator<<(std::ostream &os, const Duration &d)
{
   return os << std::setw(2) << std::setfill('0') << d.hours   << ":" 
             << std::setw(2) << std::setfill('0') << d.minutes << ":"
             << std::setw(2) << std::setfill('0') << d.seconds;
}

std::istream& operator>>(std::istream &is, Duration &d);

#endif /* DURATION_H */

