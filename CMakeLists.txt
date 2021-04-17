cmake_minimum_required(VERSION 3.17)
project(K--CA)

set(CMAKE_CXX_STANDARD 14)
include_directories(.)

add_executable(K--CA
        Blockchain.cpp
        Block.cpp
        Block.h
        Blockchain.h
        main.cpp
        sha256.cpp
        sha256.h
        Message.h
   #[[     Message.cpp
        FiniteStateMachine.h
        Pbft.cpp
        Pbft.h
        Node.h Node.cpp Network.h Network.cpp FiniteStateMachine.cpp Translation.h]])
