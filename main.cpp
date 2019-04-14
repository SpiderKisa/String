#include "src/str.h"
#include <iostream>

using namespace std;

int main() {
    String s1;
    String s2("Ok! 3, 2, 1 - let's jam!");
    String s3("See you, space cowboy");
    s3.pos(s2);
    s3.substr(15, 3);
    return 0;
}