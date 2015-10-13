#include <iostream>
#include <string>

#include <unicode/unistr.h>

using namespace std;

int main(int argc, char **argv)
{  
  if (argc < 2)
  {
    cout << "error , pls enter ./harf SomeText" << endl;
    return -1;
  }

  string str, str2, str3;
  icu::UnicodeString uni_str(argv[1]); //create object 
  uni_str.toUTF8String(str); //convert it to UTF8
  int32_t capacity = 300;
  UChar32 utf32[capacity];
  UErrorCode errorCode = U_ZERO_ERROR;
  int32_t length = uni_str.toUTF32(utf32, capacity, errorCode); //convert it from Utf8 to Utf32
  if (U_FAILURE(errorCode)) 
  {
    cout << "FAILED!" << endl;
    return 1;
  }
  UnicodeString uni_str32 = UnicodeString::fromUTF32(utf32, length); //Create a UnicodeString from a UTF-32 string
  cout << uni_str32.toUTF8String(str2) << endl; // convert it from utf32 
 
  icu::UnicodeString uni_stre(uni_str.getBuffer()); //convert it from utf8 to utf16
  uni_stre.toUTF8String(str3); // convert it from utf16 to utf8
  cout << str3 << endl;	
  return 0;
}
 
