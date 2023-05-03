//
//  String.cpp
//
//  Created by Tymon Muszynski on 31/03/2023.
//
#include "String.h"

// konstruktor domyślny
String::String() : m_data(nullptr), m_length(0) {}

// konstruktor z parametrem
String::String(const char* str) : m_data(nullptr), m_length(0) {
    if (str) {
        m_length = int(strlen(str));
        m_data = new char[m_length + 1];
        strcpy(m_data, str);
    }
}

// destruktor
String::~String() {
//    delete [] m_data;
//  std::cout<<"--> String destruktor "<<m_data<<std::endl;
    if (m_data) {
        delete [] m_data;
        m_data = nullptr;
    }
    m_length = 0;
}
void String::removeSpaces() {
    int len = m_length;
    int i = 0, j = len - 1;
//    std::cout<<"->"<<m_data<<"<-"<<std::endl;
//    std::cout<<"->"<<int(m_data[i])<<"<->"<<len<<std::endl;
    // usuwanie spacji z początku
    while (i < len &&( m_data[i] == 32 || m_data[i] == 9)) {
//        std::cout<<"spacja"<<std::endl;
        i++;
    }
    // usuwanie spacji z końca
    while (j >= 0 && m_data[j] == ' ') {

        j--;
    }
    // alokowanie pamięci dla nowego łańcucha znakowego
    char* newStr = new char[j - i + 2];
    // przepisanie łańcucha znakowego bez początkowych i końcowych spacji
    int k = 0;
    for (int l = i; l <= j; l++) {
        newStr[k] = m_data[l];
        k++;
    }
//    std::cout<<"->"<<newStr<<"<-"<<std::endl;
    delete [] m_data;
    newStr[k] = '\0';
    m_data = newStr;
    m_length = j-i+2;

}

char* String::c_str() const {
    return m_data;
}

int String::length() const {
    return m_length;
}

void String::reverseString(){
    for(int i=0; i<m_length/2; i++){
        char tmp = m_data[i];
        m_data[i] = m_data[m_length-i-1];
        m_data[m_length-i-1] = tmp;
    }
}

void String::addChars(const char* str) {
    if (str) {
        int newLength = m_length + int(strlen(str));
        char* newData = new char[newLength + 1];
        strcpy(newData, m_data);
        strcat(newData, str);
            delete[] m_data;
        m_data = newData;
        m_length = newLength;
    }
    
}

int String::getKeyOfCity(){
//    if(m_data == nullptr) {
//        std::cout << "Brak danych" << std::endl;
//    }
//    else {
        int key = 0;
        for (int i = 0; i < m_length; i++) {
            key += m_data[i];
        }
        return key;
//    }
}

bool operator==(const String& lhs, const String &rhs) {
//    if (lhs.m_length != rhs.m_length) {
//        return false;
//    }
    for (size_t i = 0; i < lhs.m_length; ++i) {
        if (lhs.m_data[i] != rhs.m_data[i]) {
            return false;
        }
    }
    return true;
}

void String::addChar(const char str){
        if(str){
            int newLength = m_length + 1;
            char* newData = new char[newLength + 1];
            strcpy(newData, m_data);
            newData[m_length] = str;
            newData[newLength] = '\0';
            delete [] m_data;
            m_data = newData;
            m_length = newLength;
        }
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    if (str.m_data)
        os <<str.m_data;
    return os;
}


