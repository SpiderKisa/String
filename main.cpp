#include "src/str.h"
#include <iostream>

using namespace std;

int main() {
    String s1;
    String s2("See you,  cowboy");
    String s3("space");
    s1 = s2.insert(s3, 9);
    cout << s1 << endl;
    String s4 = s1.remove(s1.pos(s3), s3.length() + 1);
    cout << s4 << endl;
    return 0;
}