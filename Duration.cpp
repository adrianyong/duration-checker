#include <iostream>
#include <iomanip>

#include "Duration.h"

using namespace std;

Duration::Duration(int hours, int minutes, int seconds) 
{ 
   seconds       = seconds + 60*(minutes + 60*hours);
   minutes       = seconds/60;
   this->seconds = seconds%60;
   this->hours   = minutes/60;
   this->minutes = minutes%60;   
}

std::istream& operator>>(istream &is, Duration &d)
{
   char c1, c2;
   
   int hours, minutes, seconds;    

   if (is >> hours >> c1 >> minutes >> c2 >> seconds)
   {
      if (c1 == ':' && c2 == ':')
      {
         d = Duration(hours, minutes, seconds);    
      }
      else
      {
         is.clear(ios_base::failbit);
      }
   }
   
   return is;
}

