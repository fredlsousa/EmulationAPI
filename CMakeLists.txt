cmake_minimum_required(VERSION 3.12)

project(EmulationApi)

set(CMAKE_CXX_STANDARD 17)

add_executable(EmulationApi main.cpp Flow.cpp Flow.h System.cpp System.h Model.cpp Model.h ExponentialFlow.cpp ExponentialFlow.h LogisticFlow.cpp LogisticFlow.h Tests/func_Tests.h Tests/unit_System.h Tests/unit_Flow.h Tests/unit_Model.h)