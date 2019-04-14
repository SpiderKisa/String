#include "str.h"
#include <iostream>

#define FAIL -1


String::String() = default; //???


void String::initWithChar(const char *s) {
    List *current = new List;
    current->value = s[0];
    current->next = nullptr;
    head = current;
    int i(0);
    while (s[i + 1] != '\0'){
        i++;
        current->next = new List;
        current->next->value = s[i];
        current->next->next = nullptr;
        current = current->next;
    }
    current = nullptr;
}


String::String(const char *s) {
    initWithChar(s);
}


void String::copy(const String &s) {
    List *current_s = s.head;
    List *current_this = head = new List;
    current_this->value = current_s->value;
    current_this->next = nullptr;
    current_s = current_s->next;
    while (current_s != nullptr){
        current_this->next = new List;
        current_this->next->value = current_s->value;
        current_this->next->next = nullptr;
        current_this = current_this->next;
        current_s = current_s->next;
    }
}


String::String(const String &s) {
    copy(s);
}


void String::cleanup() {
    List *next = head;
    while (head != nullptr){
        if (next != nullptr) {
            next = next->next;
        }
        delete head;
        head = next;
    }
}


String::~String() {                             // А он нужен?
    cleanup();
}


int String::length() {
    int count(0);
    List *current = head;
    while (current != nullptr){
        count++;
        current = current->next;
    }
    return count;
}


int String::pos(String &s) {
    int length_s = s.length();
    if (length_s > length()){
        return FAIL;
    }
    List *current_this;
    List *current = head;
    List *current_s;
    int count(0);
    int match;
    while (current != nullptr) {
        match = 0;
        current_this = current;
        current_s = s.head;
        while (current_s != nullptr && current_this != nullptr
                && current_s->value == current_this->value){
            match++;
            current_s = current_s->next;
            current_this = current_this->next;
        }
        if (match == length_s){
            return count;
        }
        count++;
        current = current->next;
    }
    return FAIL;
}


String String::substr(unsigned int src, unsigned int n) {
    int length = this->length();
    String sub;
    if (src >= length){
        return sub;
    }
    List *current = head;
    for (int i = 0; i < src; i++){
        current = current->next;
    }
    List *current_sub = sub.head = new List;
    current_sub->value = current->value;
    current_sub->next = nullptr;
    current = current->next;
    n--;
    while (current != nullptr && n > 0){
        current_sub->next = new List;
        current_sub->next->value = current->value;
        current_sub->next->next = nullptr;
        current_sub = current_sub->next;
        current = current->next;
        n--;
    }
    return sub;
}


String String::remove (unsigned int src, unsigned int n){
    String begin = substr(0, src);
    String end = substr(src + n, length() - src + n);
    return (begin + end);
}


String String::insert(String &s, unsigned int n) {
    String begin = substr(0, n);
    String end = substr(n, length() - n);
    return (begin + s + end);
}


std::ostream& operator<< (std::ostream &out, const String &s){
    List *current = s.head;
    while (current != nullptr){
        out << current->value;
        current = current->next;
    }
    return out;
}


String& String::operator=(const String &s) {
    if (this == &s){
        return *this;
    }
    cleanup();
    copy(s);
    return *this;
}


String& String::operator=(const char *s) {
    cleanup();
    initWithChar(s);
}


String operator+ (const String &s1, const String &s2){
    String concat;
    concat.copy(s1);
    List *current_s = s2.head;
    List *current_con = concat.head;
    while (current_con->next != nullptr){
        current_con = current_con->next;
    }
    while (current_s != nullptr){
        current_con->next = new List;
        current_con->next->value = current_s->value;
        current_con->next->next = nullptr;
        current_con = current_con->next;
        current_s = current_s->next;
    }
    return concat;
}


String operator+ (const String &s1, const char *s2){
    String s(s2);
    return (s1 + s);
}


String operator+ (const char *s1, const String &s2){
    String s(s1);
    return (s + s2);
}


bool operator== (String &s1, String &s2){
    int length = s1.length();
    if (length != s2.length()){
        return false;
    }
    int count(0);
    List *current1 = s1.head;
    List *current2 = s2.head;
    while (count < length && current1->value == current2->value){
        count++;
        current1 = current1->next;
        current2 = current2->next;
    }
    return (count == length);
}


bool operator== (String &s1, const char *s2){
    String s(s2);
    return (s1 == s);
}


bool operator== (const char *s1, String &s2){
    String s(s1);
    return (s == s2);
}


bool operator< (String &s1, String &s2){
    int length = s1.length();
    if (length < s2.length()){
        return true;
    }
    if (length > s2.length()){
        return false;
    }
    int count(0);
    List *current1 = s1.head;
    List *current2 = s2.head;
    while (count < length){
        count++;
        if (current1->value < current2->value){
            return true;
        }
        if (current1->value > current2->value){
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return (count != length);
}


bool operator!= (String &s1, String &s2){
    return !(s1 == s2);
}


bool operator!= (String &s1, const char *s2){
    String s(s2);
    return !(s1 == s);
}


bool operator!= (const char *s1, String &s2){
    String s(s1);
    return !(s == s2);
}


bool operator< (String &s1, const char *s2){
    String s(s2);
    return (s1 < s);
}


bool operator< (const char *s1, String &s2){
    String s(s1);
    return (s < s2);
}


bool operator> (String &s1, String &s2){
    return (s1 != s2 && !(s1 < s2));
}


bool operator> (String &s1, const char *s2){
    String s(s2);
    return (s1 > s);
}


bool operator> (const char *s1, String &s2){
    String s(s1);
    return (s > s2);
}


bool operator<= (String &s1, String &s2){
    return (s1 < s2 || s1 == s2);
}


bool operator<= (String &s1, const char *s2){
    String s(s2);
    return (s1 <= s);
}


bool operator<= (const char *s1, String &s2){
    String s(s1);
    return (s <= s2);
}


bool operator>= (String &s1, String &s2){
    return (s1 > s2 || s1 == s2);
}


bool operator>= (String &s1, const char *s2){
    String s(s2);
    return (s1 >= s);
}


bool operator>= (const char *s1, String &s2){
    String s(s1);
    return (s >= s2);
}

