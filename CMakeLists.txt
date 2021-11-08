cmake_minimum_required(VERSION 3.10)

project(university_db)

set(SRC 
    main.cpp
    student.cpp
    data_base_of_students.cpp)  
set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion -O3)

add_library(${PROJECT_NAME}-lib STATIC ${SRC}) 
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
set_target_properties(${PROJECT_NAME}-lib PROPERTIES 
                        CXX_STANDARD 17 
                        CXX_STANDARD_REQUIRED ON)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
set_target_properties(${PROJECT_NAME} PROPERTIES 
                        CXX_STANDARD 17 
                        CXX_STANDARD_REQUIRED ON)


