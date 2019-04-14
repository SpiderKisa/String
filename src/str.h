#ifndef STRING_STR_H
#define STRING_STR_H

#include <ostream>

struct List {
    char value;
    struct List *next;
};

class String {
    List *head = nullptr;

    void cleanup();

    void copy(const String &s);

    void initWithChar(const char *s);
public:
    String ();                              //????

    String (const char* s);

    String (const String &s);

    ~String();                              //А он нужен?

    String &operator= (const String &s);

    String &operator= (const char *s);

    /*friend bool operator< (const String &s1, const String &s2);

    friend bool operator> (const String &s1, const String &s2);

    friend bool operator<= (const String &s1, const String &s2);//???

    friend bool operator>= (const String &s1, const String &s2);//???*/

    friend String operator+ (const String &s1, const String &s2);

    int length();

    int pos (String &s); //возвращает индекс (отсчет с 1), начиная с которого в строке содержится s ТАК?! или с 1 отсчет?

    String substr (unsigned int src, unsigned int n); //выделить n символов строки, начиная с src ???????

    friend std::ostream& operator<< (std::ostream &out, const String &s);
};

std::ostream& operator<< (std::ostream &out, const String &s);

bool operator< (const String &s1, const String &s2);

bool operator> (const String &s1, const String &s2);

bool operator<= (const String &s1, const String &s2);//???

bool operator>= (const String &s1, const String &s2);//???

String operator+ (const String &s1, const String &s2);


#endif //STRING_STR_H
