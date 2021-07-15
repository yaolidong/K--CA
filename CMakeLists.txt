cmake_minimum_required(VERSION 3.17)
project(K--CA)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

include_directories(.)

add_executable(K--CA
        Blockchain.cpp
        Block.cpp
        Block.h
        Blockchain.h
        Cache.h
        Cache.cpp
        Sealer.h
        Sealer.cpp
        sha256.cpp
        sha256.h
        ViewState.h
        ViewState.cpp
        Message.h
        Message.cpp
        Network.h
        Network.cpp
        Node.h
        Node.cpp
        Pbft.h
        Pbft.cpp
)
