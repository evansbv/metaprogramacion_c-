cmake_minimum_required(VERSION 3.10)

project(ReflexionCXX)

set(CMAKE_CXX_STANDARD 17)

# Agregar Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Archivos fuente
add_executable(main main.cpp)
add_executable(test_fabrica test_fabrica.cpp)

# Link Google Test
target_link_libraries(test_fabrica GTest::GTest GTest::Main)

# Agregar pruebas
add_test(NAME FabricaTest COMMAND test_fabrica)
