cmake_minimum_required(VERSION 3.10)

project(university_db)

set(SRC 
    student.cpp
    data_base_of_students.cpp
    db_lib.cpp)  
set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion -O3)
########################################################################
add_library(${PROJECT_NAME}-lib STATIC ${SRC}) 
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
set_target_properties(${PROJECT_NAME}-lib PROPERTIES 
                        CXX_STANDARD 17 
                        CXX_STANDARD_REQUIRED ON)
########################################################################
#add_library(${PROJECT_NAME}-libTests STATIC ${SRC} test/catch_amalgamated.cpp) 
#target_compile_options(${PROJECT_NAME}-libTests PRIVATE ${FLAGS})
#set_target_properties(${PROJECT_NAME}-libTests PROPERTIES 
#                        CXX_STANDARD 17 
#                        CXX_STANDARD_REQUIRED ON)
########################################################################
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
set_target_properties(${PROJECT_NAME} PROPERTIES 
                        CXX_STANDARD 17 
                        CXX_STANDARD_REQUIRED ON)
########################################################################
#add_executable(${PROJECT_NAME}-ut test/test.cpp)
#target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-Tests)
#target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
#set_target_properties(${PROJECT_NAME}-ut PROPERTIES 
#                        CXX_STANDARD 17 
#                        CXX_STANDARD_REQUIRED ON)
########################################################################
enable_testing()
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-ut)
