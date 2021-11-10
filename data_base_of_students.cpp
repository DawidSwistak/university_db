#include "data_base_of_students.hpp"
#include "db_lib.hpp"
#include <algorithm>
#include <iomanip>
    std::vector<Student> DataBaseOfStudents::getStudents() const
    {
        return students_;
    }

    void DataBaseOfStudents::showStudent(const Student& student)
    {
        std::cout << std::setw(14) << student.getName() << " | " <<
                    std::setw(16) << student.getSurname() << " | " <<
                    std::setw(24) << student.getAddres() << " | " <<
                    std::setw(12) << student.getIndexNumber() << " | " <<
                    std::setw(12) << student.getPesel() << " | " <<
                    std::setw(8)  << student.getGenderAsString() << " | " << "\n";
    }
    void DataBaseOfStudents::showStudents(const std::vector<Student>& listOfStudents)
    {
        std::cout << "-----NAME----- | ----SURNAME----- | ---------ADDRES--------- | INDEX_NUMBER | ----PESEL--- | -GENDER- | \n";
        for(auto it : listOfStudents){
            showStudent(it);
        }
    }
    
    void DataBaseOfStudents::showAllStudents()
    {
        showStudents(students_);
    }
    
    bool DataBaseOfStudents::addNewStudent(std::string name, std::string surname, std::string addres, 
                        int indexNumber, long pesel, Gender gender)
    {
        if(validationOfPesel(pesel, gender))
        {
            Student student(name, surname, addres, indexNumber, pesel, gender);
            students_.push_back(student);
            return true;
        }
        return false;
        
    }

    DataBaseOfStudents& DataBaseOfStudents::operator+=(Student student)
    {
        students_.push_back(student);
        return *this;
    }

    std::vector<Student> DataBaseOfStudents::findStudentBySurname(std::string surname)
    {
        std::vector<Student> matchingSurnameList;
        for(auto it : students_){
            if(surname == it.getSurname()){
                matchingSurnameList.push_back(it);
            }
        }
        return matchingSurnameList;
    }

    Student* DataBaseOfStudents::findStudentByPesel(long pesel)
    {
        for(auto & it : students_){
            if(it.getPesel() == pesel)
            {
                return &it;
            }
        }
        return nullptr;
    }

    void DataBaseOfStudents::sortByPesel()
    {
        std::sort(students_.begin(), students_.end(), [](const Student& lhs, const Student& rhs) 
        {
            return lhs.getPesel() < rhs.getPesel();
        });
    }

    void DataBaseOfStudents::sortBySurname()
    {
        std::sort(students_.begin(), students_.end(), [](Student& lhs, Student& rhs) {
            return lhs.getSurname() < rhs.getSurname();
        });
    }

    void DataBaseOfStudents::remoweStudet(int index)
    {
        for(auto it = students_.begin(); it != students_.end(); it++)
        {
            if(it->getIndexNumber() == index)
            {
                students_.erase(it);
                return;
            }
        }
    }
