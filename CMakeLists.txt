cmake_minimum_required(VERSION 3.10)

project(project VERSION 1.5)

# Add your source files
set(SOURCES
    main.cpp
    functions.cpp
    student.cpp 
)

# Add your header files
set(HEADERS
    functions.h
    student.h    
    person.h  
)

# Create an executable
add_executable(myprogram ${SOURCES} ${HEADERS})

# Set C++ standard
set_target_properties(myprogram PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)


