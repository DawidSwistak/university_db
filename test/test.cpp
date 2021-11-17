#define CATCH_CONFIG_MAIN  
#include "catch_amalgamated.hpp"
#include "../data_base_of_students.hpp"
#include "../student.hpp"
#include "../db_lib.hpp"

SCENARIO("Testing adding students to database")
{
    GIVEN("empty Data base")
    {
        DataBaseOfStudents testingDataBase;
        WHEN(".addNewStudent(\"Maciek\", \"Kowalski\", \"Lodz\", 123, 31051432274, Gender::man);")
        {
            auto resultAdd1st = testingDataBase.addNewStudent("Maciek", "Kowalski", "Lodz", 123, 31051432274, Gender::man);
            THEN("Function supposed to return true")
            {
                REQUIRE(resultAdd1st == true);
                THEN("size of vector ==1")
                {
                    auto students = testingDataBase.getStudents();
                    REQUIRE(students.size() == 1);
                }
            }
            WHEN("adding another student: .addNewStudent(\"Tomek\", \"Kozak\", \"Warszawa\", 231, 31051432274, Gender::man);")
            {
                auto resultAdd2nd = testingDataBase.addNewStudent("Tomek", "Kozak", "Warszawa", 231, 31051432274, Gender::man);
                auto students = testingDataBase.getStudents();
                THEN("Function supposed to return true")
                {
                    REQUIRE(resultAdd2nd == true);
                    THEN("size of vector ==2")
                    {
                        REQUIRE(students.size() == 2);
                    }
                }
                THEN("Name of second student ==\"Tomek\"")
                {
                    REQUIRE_FALSE(students[1].getName().compare("Tomek"));
                }
                THEN("Surname of second student ==\"Kozak\"")
                {
                    REQUIRE_FALSE(students[1].getSurname().compare("Kozak"));
                }
                THEN("Addres of second student ==\"Warszawa\"")
                {
                    REQUIRE_FALSE(students[1].getAddres().compare("Warszawa"));
                }
                THEN("Pessel of second student ==31051432274")
                {
                    REQUIRE(students[1].getPesel() == 31051432274);
                }
                THEN("Index of second student ==231")
                {
                    REQUIRE(students[1].getIndexNumber() == 231);
                }
                THEN("Gender of the second student ==Gender::man")
                {
                    REQUIRE(students[1].getGender() == Gender::man);
                }
            }
        }
    }
}
SCENARIO("Testing function validationOfPesel()")
{
    WHEN("Correct pesel and gender:")
    {
        GIVEN("Variant with woman: validationOfPesel(94072127646, Gender::woman")
        {
            auto result =  validationOfPesel(94072127646, Gender::woman);
            THEN("Supposed return true")
            {
                REQUIRE(result == true);
            }
        }
        GIVEN("Variant with man: validationOfPesel(35121538619, Gender::man)")
        {
            auto result = validationOfPesel(35121538619, Gender::man);
            THEN("Supposed return true")
            {
                REQUIRE(result == true);
            }
        }
    }
    WHEN("Correct pesel but diffrent gender:")
    {
        GIVEN("Variant with woman: validationOfPesel(94072127646, Gender::man")
        {
            auto result =  validationOfPesel(94072127646, Gender::man);
            THEN("Supposed return false")
            {
                REQUIRE(result == false);
            }
        }
        GIVEN("Variant with man: validationOfPesel(35121538619, Gender::woman)")
        {
            auto result = validationOfPesel(35121538619, Gender::woman);
            THEN("Supposed return false")
            {
                REQUIRE(result == false);
            }
        }
    }
    WHEN("Wrong PESEL:")
    {
        REQUIRE(validationOfPesel(9407212764, Gender::woman) == false);
        REQUIRE(validationOfPesel(940721276, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127, Gender::woman) == false);
        REQUIRE(validationOfPesel(9407212, Gender::woman) == false);
        REQUIRE(validationOfPesel(940721, Gender::woman) == false);
        REQUIRE(validationOfPesel(4072, Gender::woman) == false);
        REQUIRE(validationOfPesel(0, Gender::woman) == false);
        REQUIRE(validationOfPesel(10000, Gender::woman) == false);
        REQUIRE(validationOfPesel(10000000, Gender::woman) == false);
        REQUIRE(validationOfPesel(1000000000, Gender::woman) == false);
        REQUIRE(validationOfPesel(10000, Gender::man) == false);
        REQUIRE(validationOfPesel(10000000, Gender::man) == false);
        REQUIRE(validationOfPesel(1000000000, Gender::man) == false);
        REQUIRE(validationOfPesel(9407212764600, Gender::woman) == false);
        REQUIRE(validationOfPesel(940721276461, Gender::woman) == false);
        REQUIRE(validationOfPesel(9407212764610, Gender::woman) == false);
        REQUIRE(validationOfPesel(9407212764622, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127646000000, Gender::woman) == false);
        REQUIRE(validationOfPesel(940721276499999, Gender::woman) == false);
        REQUIRE(validationOfPesel(-94072127646, Gender::woman) == false);
        REQUIRE(validationOfPesel(-35121538619, Gender::man) == false);
    }
    WHEN("Wrong control value")
    {
        REQUIRE(validationOfPesel(35121538610, Gender::man) == false);
        REQUIRE(validationOfPesel(35121538611, Gender::man) == false);
        REQUIRE(validationOfPesel(35121538612, Gender::man) == false);
        REQUIRE(validationOfPesel(35121538613, Gender::man) == false);
        REQUIRE(validationOfPesel(35121538614, Gender::man) == false);
        REQUIRE(validationOfPesel(35121538615, Gender::man) == false);
        REQUIRE(validationOfPesel(35121538616, Gender::man) == false);
        REQUIRE(validationOfPesel(35121538617, Gender::man) == false);
        REQUIRE(validationOfPesel(35121538618, Gender::man) == false);

        REQUIRE(validationOfPesel(94072127640, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127641, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127642, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127643, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127644, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127645, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127647, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127648, Gender::woman) == false);
        REQUIRE(validationOfPesel(94072127649, Gender::woman) == false);
    }
}
