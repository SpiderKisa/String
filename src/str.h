#ifndef STRING_STR_H
#define STRING_STR_H

#include <ostream>

struct List {
    char value;
    struct List *next;
};

class String {
    List *head = nullptr;

public:
    String ();                              //????

    String (const char* s);

    String (const String &s);

    ~String();                              //А он нужен?

   /* String &operator= (const String &s);

    friend bool operator< (const String &s1, const String &s2);

    friend bool operator> (const String &s1, const String &s2);

    friend bool operator<= (const String &s1, const String &s2);//???

    friend bool operator>= (const String &s1, const String &s2);//???

    friend String operator+ (const String &s1, const String &s2);*/

    int length();

    int pos (String &s); //возвращает индекс (отсчет с 0), начиная с которого в строке содержится s ТАК?!

    /*String substr (const String &s, int src, int n); //выделить n символов строки s, начиная с src ???????

    friend std::ostream& operator<< (std::ostream &out, const String &s);*/
};


bool operator< (const String &s1, const String &s2);

bool operator> (const String &s1, const String &s2);

bool operator<= (const String &s1, const String &s2);//???

bool operator>= (const String &s1, const String &s2);//???

String operator+ (const String &s1, const String &s2);


#endif //STRING_STR_H
