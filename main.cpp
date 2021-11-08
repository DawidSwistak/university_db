#include "data_base_of_students.hpp"

    void showStudent(const Student& student)
    {
         std::cout <<   "Name: "    << student.getName() << 
                        " Surname: "<< student.getSurname() <<
                        " Addres: " << student.getAddres() <<
                        " Index: "  << student.getIndexNumber() <<
                        " Pesel: "  << student.getPesel() <<
                        " Sex: "    << student.getGenderAsString() << "\n";
    }
    void showStudents(const std::vector<Student>& listOfStudents)
    {
        for(auto it : listOfStudents){
            showStudent(it);
        }
    }

    int main()
{
    DataBaseOfStudents studenty;
    studenty.addNewStudent("Maciek", "backo", "miasto", 43256, 321, Gender::man);
    studenty.showAllStudents();
    std::cout<<std::endl;
    studenty.addNewStudent("Baciek2", "cacko2", "miasto2", 124562, 123, Gender::woman);
    studenty.addNewStudent("Adam", "acko", "miasto2", 123322, 213, Gender::man);
    studenty.showAllStudents();

    std::cout<<"\nStudents with the same surname:\n";
    auto foundStudents = studenty.findStudentBySurname("macko4");
    showStudents(foundStudents);
    std::cout<<"\nStudents with the same pesel:\n";

    Student foundStudent;
    if(studenty.findStudentByPesel(213, &foundStudent))
    {
    showStudent(foundStudent);
    }
    std::cout<<"After sort by pesel: \n";
    studenty.sortByPesel();
    std::cout<<std::endl;
    studenty.showAllStudents();

    std::cout<<"\nAfter sort by pesel: \n";
    studenty.sortBySurname();
    std::cout<<std::endl;
    studenty.showAllStudents();
}
