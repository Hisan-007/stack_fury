# cmake_minimum_required(VERSION <specify CMake version here>)
project(CLion_C__files)

set(CMAKE_CXX_STANDARD 14)

add_executable(CLion_C__files main.cpp C.cpp C.h B.cpp A.cpp A.h BB.cpp BB.h BankAccount.cpp BankAccount.h Saving.h Batsman.cpp Batsman.h Current.h)