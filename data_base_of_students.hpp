#pragma once
#include "student.hpp"
#include <vector>

class DataBaseOfStudents
{
    std::vector<Student> students_;

public:
    void showStudent(const Student& student);
    void showStudents(const std::vector<Student>& listOfStudents);
    void showAllStudents();
    void addNewStudent(std::string name, std::string surname, std::string addres, 
                        int indexNumber, int pesel, Gender gender);
    std::vector<Student> findStudentBySurname(std::string surname);
    int findStudentByPesel(int pesel, Student * matchingStudent);
    void sortByPesel();
    void sortBySurname();
};
