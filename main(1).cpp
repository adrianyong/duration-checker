#include <cstdlib>

#include <iostream>
#include <iomanip>

#include "duration.h"

using namespace std;

int main(int argc, char** argv) 
{
   Duration d1, d2, hour(1,0,0);
   
   cout << "d1 = " << flush;
   
   cin >> d1;
   
   cout << "d1 = " << d1 << endl;

   cout << "d2 = " << flush;
   
   cin >> d2;
   
   cout << "d2 = " << d2 << endl;
      
   if (d1 + 2*d2 < hour)
   {
       cout << d1 + 2*d2 << " is less than "  << hour << endl;
   }
   else
   {
      cout << d1 + 2*d2 << " is not less than "  << hour << endl;
   }
      
   return EXIT_SUCCESS;
}

