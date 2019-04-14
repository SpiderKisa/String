#include "src/str.h"
#include <iostream>

using namespace std;

int main() {
    String s1;
    String s2("See you, space cowboy");
    String s3 = s2.substr(15,3);
    cout << s3 << endl;
    cout << s2.pos(s3);
    return 0;
}