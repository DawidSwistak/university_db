#include "data_base_of_students.hpp"
#include <algorithm>
    void DataBaseOfStudents::showStudent(const Student& student)
    {
         std::cout <<   "Name: "    << student.getName() << 
                        " Surname: "<< student.getSurname() <<
                        " Addres: " << student.getAddres() <<
                        " Index: "  << student.getIndexNumber() <<
                        " Pesel: "  << student.getPesel() <<
                        " Sex: "    << student.getGenderAsString() << "\n";
    }
    void DataBaseOfStudents::showStudents(const std::vector<Student>& listOfStudents)
    {
        for(auto it : listOfStudents){
            showStudent(it);
        }
    }

    void DataBaseOfStudents::showAllStudents()
    {
        showStudents(students_);
    }
    
    void DataBaseOfStudents::addNewStudent(std::string name, std::string surname, std::string addres, 
                        int indexNumber, int pesel, Gender gender)
    {
        Student student(name, surname, addres, indexNumber, pesel, gender);
        students_.push_back(student);
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

    int DataBaseOfStudents::findStudentByPesel(int pesel, Student * matchingStudent)
    {
        for(auto it : students_){
            if(it.getPesel() == pesel){
                *matchingStudent = it;
                return 1;
            }
        }
        return 0;
    }

    void DataBaseOfStudents::sortByPesel()
    {
        std::sort(students_.begin(), students_.end(), [](const Student& lhs, const Student& rhs) {
            return lhs.getPesel() < rhs.getPesel();
        });
    }

    void DataBaseOfStudents::sortBySurname()
    {
        std::sort(students_.begin(), students_.end(), [](Student& lhs, Student& rhs) {
            return lhs.getSurname() < rhs.getSurname();
        });
    }



/*
std::vector<Student> DataBaseOfStudents::findStudentBySurname(std::string surname)
    {
        std::vector<Student> matchingSurnameList;
        for(auto it : students_){
            if(surname == it.getSurname()){
                matchingSurnameList.push_back(it);
            }
        }
        if(matchingSurnameList.size() == 0){
                std::cout << "There is no students with Surname: \"" << surname << "\"!\n";
            }
            else if (matchingSurnameList.size() == 1){
                std::cout<<"There is one student with Surname: \"" << surname << "\"\n"; 
                showStudent(matchingSurnameList[0]);
            }
            else{ 
                std::cout << "There is more than one student with Surname: \"" << surname << "\"\n";
                showStudents(matchingSurnameList);
            }
    }
*/
