cmake_minimum_required(VERSION 3.6)
project(lab2)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ggdb -Wpedantic")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(SOURCE_FILES_CLIENT client.c client.h Queue.c Queue.h)
set(SOURCE_FILES_BARBER barber.c barber.h Queue.c Queue.h)

add_executable(client ${SOURCE_FILES_CLIENT})
add_executable(barber ${SOURCE_FILES_BARBER})

target_link_libraries(barber pthread)
target_link_libraries(client pthread)
target_link_libraries(barber rt)
target_link_libraries(client rt)
target_link_libraries(barber m)
target_link_libraries(client m)

