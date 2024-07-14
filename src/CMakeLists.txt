cmake_minimum_required(VERSION 3.8)

project(sphio)

#set(VTK_DIR "/home/zzp/workspace/app/vtk/lib/cmake/vtk-9.3")
#find_package(VTK REQUIRED)
file(GLOB files *.cpp)

add_library(sphio SHARED ${files})
