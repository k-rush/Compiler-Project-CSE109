/* Kyle Rush
   CSE109
   p5
   this is the implementation of the check function.
*/
#include "check.h"
void check(bool exp, char * str) {
  if(!exp) {
    cout<<str;
    exit(1);
  }
}
