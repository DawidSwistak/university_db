#include "data_base_of_students.hpp"
#include "db_lib.hpp"
    
    int main()
{
    DataBaseOfStudents DB;
    std::cout << "\nAFTER CREATING NEW DATA BASE:\n"; DB.showAllStudents();
    DB.addNewStudent("Maciek", "Kowalski", "Grudziadz", 234954, 93101420091, Gender::man);
    std::cout << "\nAFTER: .addNewStudent(\"Maciek\", \"Kowalski\", \"Grudziadz\", 234954, 92071314764, Gender::man);:\n"; DB.showAllStudents();
    
    takeStudentsFromFile("../testingData.txt", DB);
    std::cout << "\nAFTER ADDING 10-RECORDS FROM .TXT FILE:\n"; DB.showAllStudents();

    DB.sortByPesel();
    std::cout << "\nAFTER sortByPesel():\n"; DB.showAllStudents();

    DB.sortBySurname();
    std::cout << "\nAFTER .sortBySurname():\n"; DB.showAllStudents();

    std::cout << "\nAFTER .findStudentBySurname(\"Kozak\"):\nRESULT:\n"; 
    auto resultSearchingBySurname = DB.findStudentBySurname("Kozak");
    showStudents(resultSearchingBySurname);

    std::cout << "\nAFTER .findStudentByPesel(93101420091):\nRESULT:\n";
    auto ptrStudentFoundByPesel = DB.findStudentByPesel(93101420091);
    showStudent(*ptrStudentFoundByPesel);

    DB.remoweStudet(234954);
    std::cout << "\nAFTER .remoweStudet(234954):\n"; DB.showAllStudents();

    std::cout << "\nAFTER trying add too short PESEL:\nRESEULT:" << 
    DB.addNewStudent("Alfreda", "Nowak", "Czestochowa", 123456, 903044006, Gender::woman) << "\n"; 
    DB.showAllStudents();

    std::cout << "\nAFTER trying add PESEL and wrong gender:\nRESEULT:" << 
    DB.addNewStudent("Alfreda", "Nowak", "Czestochowa", 123456, 70032550684, Gender::man) << "\n"; 
    DB.showAllStudents();

    std::cout << "\nAFTER trying add too long PESEL:\nRESEULT:" << 
    DB.addNewStudent("Alfreda", "Nowak", "Czestochowa", 123456, 700325506848, Gender::man) << "\n"; 
    DB.showAllStudents();

    std::cout << "\nAFTER trying add PESEL with wrong last control value :\nRESEULT:" << 
    DB.addNewStudent("Alfreda", "Nowak", "Czestochowa", 123456, 70032550685, Gender::man) << "\n"; 
    DB.showAllStudents();

    addStudentsToFile("../savedData.txt", DB);
    takeStudentsFromFile("../savedData.txt", DB);
    std::cout << "\nAFTER ADDING DATA TO NEW FILE..\nAND AFTER THAT, READING THAT FILE AND ADDING TO EXISTING DATA:\n";
    DB.showAllStudents();
}
