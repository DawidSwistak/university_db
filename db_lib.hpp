#pragma once
#include <iomanip>
#include <array>
#include <fstream>
#include "data_base_of_students.hpp"

bool validationOfPesel(long long pesel, Gender gender);

bool addStudentsToFile(std::string nameOfFile, DataBaseOfStudents & dbOfStudents);
bool takeStudentsFromFile(std::string nameOfFile, DataBaseOfStudents & dbOfStudents);

void showStudent(const Student& student);
void showStudents(const std::vector<Student>& listOfStudents);
