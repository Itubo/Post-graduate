cmake_minimum_required(VERSION 3.25)
project(2_3_ C)

set(CMAKE_C_STANDARD 11)

add_executable(2_3_ Single_linkList/MyNode.c Single_linkList/MyNode.h main.c Double_linkedlist/MyDNode.c Double_linkedlist/MyDNode.h)
