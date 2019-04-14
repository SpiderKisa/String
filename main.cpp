#include "src/str.h"
#include <iostream>

using namespace std;

int main() {
    String s1;
    String s2("Ok! 3, 2, 1");
    String s3(" - let's jam!");
    String s4(s3);
    s4 = "BOOM " + s2 + s3 + " BOOM";
    cout << s4;
    return 0;
}