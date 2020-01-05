# https://cmake.org/cmake/help/latest/command/add_custom_command.html
# https://gist.github.com/socantre/7ee63133a0a3a08f3990

cmake_minimum_required(VERSION 3.0.0)
project(fim_poc
    VERSION 0.0.1
)


# Directory variables
SET(EXTERNAL_F "${PROJECT_SOURCE_DIR}/external")
SET(LIBS_F "${EXTERNAL_F}/libs")
SET(TEST_F "${PROJECT_SOURCE_DIR}/test")
SET(SRC_F "${PROJECT_SOURCE_DIR}/src")
SET(INCLUDE_F "${PROJECT_SOURCE_DIR}/include")
SET(CREATE_F ${LIBS_F})


# Header files
include_directories(${INCLUDE_F})


# Source files
file(GLOB TEST_SRC "${TEST_F}/*.cpp")


# Generated files
SET(TEST_BIN "fim_test")
SET(FIM_LIB "${PROJECT_SOURCE_DIR}/external/libs/fim")


# Create folders
add_custom_command(OUTPUT ${CREATE_F}
    COMMAND mkdir -p ${CREATE_F}
    COMMENT "Creating folders"
    VERBATIM
)
add_custom_target(CREATE_FOLDERS DEPENDS ${FOLDERS})


# Create FIM library
SET(FIM_LIB "fim")
file(GLOB LIBRARY_SRC "${SRC_F}/*.cpp")
add_library(${FIM_LIB} STATIC ${LIBRARY_SRC})


# Create test binary
add_executable(${TEST_BIN} ${TEST_SRC})
TARGET_LINK_LIBRARIES(${TEST_BIN} ${FIM_LIB})




#add_custom_target(TEST_BIN DEPENDS ${FOLDERS})




