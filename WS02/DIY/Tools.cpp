//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 27, 2023

#define _CRT_SECURE_NO_WARNINGS
#include "Tools.h"

namespace sdds {
   void strCpy(char* str1, const char* str2) {
      while(*str2) {
         *str1++ = *str2++;
      }
      *str1 = 0;
   }
}
