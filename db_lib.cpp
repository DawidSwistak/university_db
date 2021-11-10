#include "db_lib.hpp"

bool validationOfPesel(const long pesel, Gender gender)
{
    long controlValue = 0;
    long peselCopy = pesel;
    std::array<int, 11> digitsWeight = {1,3,1,9,7,3,1,9,7,3,1}; //from last to first
    for(int i = 0; i < 11; i++)
    {
        controlValue += peselCopy%10 * digitsWeight[i];
        peselCopy /= 10;
    }
    bool genderInPeselSayMan = (pesel/10) % 2;
    Gender peselGender = (genderInPeselSayMan) ? Gender::man : Gender::woman;

    if((controlValue%10 == 0) && (peselGender == gender))
    {
        return true;
    }
    return false;
}

void showStudentNH(const Student& student)
{
    std::cout << std::setw(14) << student.getName() << " | " <<
                std::setw(16) << student.getSurname() << " | " <<
                std::setw(24) << student.getAddres() << " | " <<
                std::setw(12) << student.getIndexNumber() << " | " <<
                std::setw(12) << student.getPesel() << " | " <<
                std::setw(8)  << student.getGenderAsString() << " | " << "\n";
}

void showStudent(const Student& student)
{
    std::cout << std::setw(14) << "-----NAME---------SURNAME--------------ADDRES---------INDEX_NUMBER----PESEL-----SEX---\n";
    showStudentNH(student);
}

void showStudents(const std::vector<Student>& listOfStudents)
{
    std::cout << "-----NAME----- | ----SURNAME----- | ---------ADDRES--------- | INDEX_NUMBER | ----PESEL--- | -GENDER- | \n";
    for(auto it : listOfStudents){
        showStudentNH(it);
    }
}

std::vector<std::string> parseText(std::string inText, char delimiter)
{
    std::vector<std::string> parsedText;
    size_t pos = 0;
    std::string subString;
    while ((pos = inText.find(delimiter)) != std::string::npos) 
    {
    subString = inText.substr(0, pos);
    inText.erase(0, pos + 1);
    parsedText.push_back(subString);
    }
    return parsedText;
}

bool studentCanBeMade(std::vector<std::string> parsedText)

{   
    if( !(parsedText.size() == 6) ){
        return 0;
    }
    if( parsedText[3].find_first_not_of("0123456789") != std::string::npos){
        return 0;
    }
    if( parsedText[4].find_first_not_of("0123456789") != std::string::npos){
        return 0;
    }
    if( parsedText[5]=="man" || parsedText[5]=="woman" ){
        return 1;
    }
    else{
        return 0;
    }
}

Student makeStudent(std::vector<std::string> parsedText)
{
    int index = std::stoi(parsedText[3]);
    long pesel = std::stol(parsedText[4]);
    Gender gender = (!parsedText[5].compare("man")) ? Gender::man : Gender::woman;
    Student student(parsedText[0], parsedText[1], parsedText[2], index, pesel, gender);
    return student;
}

bool addStudentsFromFile(std::string nameOfFile, DataBaseOfStudents & dbOfStudents)
{
    std::fstream file;
    std::string oneLine;
    file.open(nameOfFile, std::ios::in);
    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, oneLine);
            auto parsedText = parseText(oneLine,'$');
            if(studentCanBeMade(parsedText))
            {
                dbOfStudents += makeStudent(parsedText);   
            }
            else
            {
                std::cout << "\nCouldn't add Student, file might be damaged!\n";
            }
        }
        file.close();
        return true;
    }
    std::cout<< "\nFILE COULDN'T BE OPENED\n";
    return false;
}

std::string getStudentAsTxt(Student student)
{
    std::array<std::string, 6> studentAsTxt;
    studentAsTxt[0] = student.getName();
    studentAsTxt[1] = student.getSurname();
    studentAsTxt[2] = student.getAddres();
    studentAsTxt[3] = std::to_string(student.getIndexNumber());
    studentAsTxt[4] = std::to_string(student.getPesel());
    studentAsTxt[5] = (student.getGender() == Gender::man) ? "man" : "woman";
    std::string retTxt;
    for(auto it : studentAsTxt)
    {
        retTxt+=it;
        retTxt+='$';
    }
    return retTxt;
}

bool addStudentsToFile(std::string nameOfFile, DataBaseOfStudents & dbOfStudents)
{
    std::fstream file;
    std::string oneLine;
    file.open(nameOfFile, std::ios::out);
    if(file.is_open())
    {
        auto copyDB = dbOfStudents.getStudents();
        for(auto it : copyDB)
        {
            file << getStudentAsTxt(it) << "\n";
        }
        return true;
    }
        return false;
    
}