#include "str.h"
#include <iostream>

#define FAIL -1


String::String() {} //???


String::String(const char *s) {
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

String::String(const String &s) {
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


String::~String() {                             // А он нужен?
    List *next = head;
    while (head != nullptr){
        if (next != nullptr) {
            next = next->next;
        }
        delete head;
        head = next;
    }
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


std::ostream& operator<< (std::ostream &out, const String &s){
    List *current = s.head;
    while (current != nullptr){
        out << current->value;
        current = current->next;
    }
    return out;
}