#include "src/str.h"
#include <iostream>

using namespace std;

int main() {
    String s1;
    String s2("Ok! 3, 2, 1 - let's jam!");
    String s3("See you, space cowboy");
    String s4(s3);
    s3.pos(s2);
    s3.substr(15, 3);
    cout << s3 << endl;
    s4 = s2;
    s4 = s4;
    s4 = s1 = s2;
    cout << s4 << endl;
    cout << s1;
    return 0;
}