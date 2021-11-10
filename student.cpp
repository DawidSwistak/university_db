#include "student.hpp"

    std::string Student::getName() const {return name_;}
    std::string Student::getSurname() const {return surname_;}
    std::string Student::getAddres() const {return addres_;}
    int Student::getIndexNumber() const {return indexNumber_;}
    long Student::getPesel() const {return pesel_;}
    Gender Student::getGender() const {return gender_;}
    std::string Student::getGenderAsString() const
    {
        if(gender_ == Gender::man)
        {
            return "man";
        }
        else
        {
            return "woman";
        }
    }
    Student::Student(std::string name, std::string surname, std::string addres, 
            int indexNumber, long pesel,  Gender gender)
        :name_(name),
        surname_(surname),
        addres_(addres),
        indexNumber_(indexNumber),
        pesel_(pesel),
        gender_(gender)
    {}
