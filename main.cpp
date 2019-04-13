#include "src/str.h"
#include <iostream>

using namespace std;

int main() {
    String s1;
    String s2("cow");
    String s3("See you, space cowboy");
    s3.pos(s2);
    return 0;
}