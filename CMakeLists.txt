# CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.17)

# プロジェクト名と使用する言語を設定
project(BootCamp2024_cpp)
set(CMAKE_CXX_STANDARD 14)

# 実行ファイルの作成（1つ目は実行ファイルの名前，2つ目以降はソースファイルやヘッダファイルなど）
add_executable(
        Hello_world #実行ファイル名
        Hello_world/HelloWorld.cpp #ソースファイルのパス
)
add_executable(
        LPF
        LPF/LPF.cpp
        LPF/LPF.h
        LPF/LPF_func.cpp
)

add_executable(
        csv_Input
        csv_Input/csv_Input.cpp
)
add_executable(
        csv_Output
        csv_Output/crlserial.hpp
        csv_Output/csv_Output.cpp
)