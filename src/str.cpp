#include "str.h"
#include <iostream>


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


String::~String() {
    List *current = head;
    List *next = current->next;
    while (current != nullptr){
        delete current;
        current = next;
        next = next->next;
    }
    head = nullptr;
}


