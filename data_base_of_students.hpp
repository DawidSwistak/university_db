#pragma once
#include "student.hpp"
#include <vector>
#include <algorithm>
#include <iomanip>

class DataBaseOfStudents
{
    std::vector<Student> students_;
    void showStudent(const Student& student);
    void showStudents(const std::vector<Student>& listOfStudents);
public:
    std::vector<Student> getStudents() const;
    DataBaseOfStudents& operator+=(Student student);
    void showAllStudents();
    bool addNewStudent(std::string name, std::string surname, std::string addres, 
                        int indexNumber, long pesel, Gender gender);
    std::vector<Student> findStudentBySurname(std::string surname);
    Student* findStudentByPesel(long pesel);
    void sortByPesel();
    void sortBySurname();
    void remoweStudet(int index);
};
