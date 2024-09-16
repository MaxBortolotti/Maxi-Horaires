cmake_minimum_required(VERSION 3.24)
project(DecalageHoraireC C)

set(CMAKE_C_STANDARD 11)

add_executable(DecalageHoraireC main.c maillon.c maillon.h LLC.c LLC.h horlogeMax.c horlogeMax.h menu.c menu.h)
