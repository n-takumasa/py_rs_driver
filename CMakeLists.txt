cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(rs_driver_wrapper
    VERSION 0.1.0
    DESCRIPTION "RS Driver wrapper"
    LANGUAGES CXX
)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# pybind11
add_subdirectory(external/pybind11)
pybind11_add_module(rs_driver_wrapper src/rs_driver_wrapper.cpp)

# RS Driver
add_subdirectory(external/rs_driver)
find_package(rs_driver REQUIRED)
include_directories(${rs_driver_INCLUDE_DIRS})

find_package(Boost REQUIRED COMPONENTS system)
find_package(Boost REQUIRED COMPONENTS date_time)
find_package(Boost REQUIRED COMPONENTS regex)

set_target_properties(rs_driver_wrapper
    PROPERTIES
    VERSION ${PROJECT_VERSION}
)

target_compile_options(rs_driver_wrapper PUBLIC -O2 -Wall)

target_link_libraries(rs_driver_wrapper PUBLIC pthread ${rs_driver_LIBRARIES})
