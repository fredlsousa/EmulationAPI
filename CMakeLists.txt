cmake_minimum_required(VERSION 3.12)
project(API_Singleton)

set(CMAKE_CXX_STANDARD 17)

add_executable(API_Singleton main.cpp ModelImpl.cpp ModelImpl.h SystemImpl.cpp SystemImpl.h FlowImpl.cpp FlowImpl.h Model.h System.h Flow.h Singleton.h Tests/unit_Flow.h Tests/unit_System.h Tests/unit_Model.h Tests/func_Tests.h ExponentialFlow.cpp ExponentialFlow.h LogisticFlow.cpp LogisticFlow.h)