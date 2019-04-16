#include "src/str.h"
#include <iostream>

using namespace std;

String supersede(String string, String substring, const String& substitution){
    String changed;
    int step = substring.length();
    while (string.pos(substring) >= 0){
        changed = changed + string.substr(0, string.pos(substring)) + substitution;
        string = string.remove(0, string.pos(substring) + step);
    }
    changed = changed + string;
    return changed;
}

int main() {
   /* String s1("See you, space cowboy");//в строке s1
    String s2("See you, space cowboy");//найти все вхождения s2
    String s3("Whatever happens, happens");//и заменить их на s3
    String s4 = supersede(s1, s2, s3);
    cout << s4;
*/
   String s("hello");
    if (s < s){
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}