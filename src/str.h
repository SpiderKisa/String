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

    int length();

    int pos (String &s); //количество символов в строке до начала подстроки s (т.е., s входит в строку, начиная с pos+1). Если s не входит в строку, то -1

    String substr (int src, int n); //выделить n символов строки после src. (src +1, src +2, .., src + n)

    String insert(String &s, int n); //ставить s в строку после позиции n

    String remove (int src, int n);

    friend std::ostream& operator<< (std::ostream &out, const String &s);

    String &operator= (const String &s);
    String &operator= (const char *s);

    friend String operator+ (const String &s1, const String &s2);
    friend String operator+ (const String &s1, const char *s2);
    friend String operator+ (const char *s1, const String &s2);

    friend bool operator== (String &s1, String &s2);
    friend bool operator== (String &s1, const char *s2);
    friend bool operator== (const char *s1, String &s2);

    friend bool operator!= (String &s1, String &s2);
    friend bool operator!= (String &s1, const char *s2);
    friend bool operator!= (const char *s1, String &s2);

    friend bool operator< (String &s1, String &s2);
    friend bool operator< (String &s1, const char *s2);
    friend bool operator< (const char *s1, String &s2);

    friend bool operator> (String &s1, String &s2);
    friend bool operator> (String &s1, const char *s2);
    friend bool operator> (const char *s1, String &s2);

    friend bool operator<= (String &s1, String &s2);
    friend bool operator<= (String &s1, const char *s2);
    friend bool operator<= (const char *s1, String &s2);

    friend bool operator>= (String &s1, String &s2);
    friend bool operator>= (String &s1, const char *s2);
    friend bool operator>= (const char *s1, String &s2);

};

std::ostream& operator<< (std::ostream &out, const String &s);

bool operator< (String &s1, String &s2);
bool operator< (String &s1, const char *s2);
bool operator< (const char *s1, String &s2);

bool operator> (String &s1, String &s2);
bool operator> (String &s1, const char *s2);
bool operator> (const char *s1, String &s2);

bool operator<= (String &s1, String &s2);
bool operator<= (String &s1, const char *s2);
bool operator<= (const char *s1, String &s2);

bool operator>= (String &s1, String &s2);
bool operator>= (String &s1, const char *s2);
bool operator>= (const char *s1, String &s2);

bool operator== (String &s1, String &s2);
bool operator== (String &s1, const char *s2);
bool operator== (const char *s1, String &s2);

bool operator!= (String &s1, String &s2);
bool operator!= (String &s1, const char *s2);
bool operator!= (const char *s1, String &s2);

String operator+ (const String &s1, const String &s2);
String operator+ (const String &s1, const char *s2);
String operator+ (const char *s1, const String &s2);

#endif //STRING_STR_H
