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
    String s1("See you, space cowboy");
    String s2("Ok!");
    String s3("Hell yeah!");
    String s4 = supersede(s1, s2, s3);
    cout << s4;
    return 0;
}