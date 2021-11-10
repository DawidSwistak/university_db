#pragma once
#include <iostream>

enum class Gender
{
    man,
    woman
};

class Student
{
private:
    std::string name_;
    std::string surname_;
    std::string addres_;
    int indexNumber_;
    long pesel_;
    Gender gender_;  
public:
    std::string getName() const;
    std::string getSurname() const;
    std::string getAddres() const;
    int getIndexNumber() const;
    long getPesel() const;
    Gender getGender() const;
    std::string getGenderAsString() const;

    Student(std::string name = "name", std::string surname = "surname", std::string addres = "addres", 
            int indexNumber = 0, long pesel = 0,  Gender gender = Gender::man);
};
