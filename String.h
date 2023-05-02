//
//  String.hpp
//  PROJECT-CSS-v2
//
//  Created by Tymon Muszynski on 31/03/2023.
//
#pragma once
#include <iostream>

class String {
public:
    String();  // konstruktor domyślny
    String(const char* str);  // konstruktor z parametrem
    ~String();  // destruktor
    
    char* c_str() const;  // metoda zwracająca wskaźnik do tablicy znaków
    int length() const;  // metoda zwracająca długość ciągu znaków
    void addChars(const char* str);
    void addChar(const char str);
    // przeciążanie operatorów
    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend bool operator==(const String& lhs, const String& rhs); // operator wypisywania
    void reverseString();
    int getKeyOfCity();
    void removeSpaces();
    
private:
    char* m_data;  // wskaźnik do tablicy znaków przechowującej ciąg
    int m_length;  // długość ciągu
};
