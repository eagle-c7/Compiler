cmake_minimum_required(VERSION 3.13.4)

###############################################
# Set project_name as the directory name
###############################################

# set(LLVM_DIR "/Users/wangzijun/llvm-project/build/lib/cmake/llvm")

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

file(RELATIVE_PATH project_name ${CMAKE_CURRENT_LIST_DIR}/.. ${CMAKE_CURRENT_LIST_DIR})

project(${project_name})

###############################################
# Generate lexer and parser codes
###############################################

message("-- Generating lexer and parser codes")
execute_process(WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                COMMAND flex lexer.l
                COMMAND bison -d parser.y)

###############################################
# Set dependencies
###############################################

# Set project compile flags.
set(CMAKE_CXX_STANDARD 14)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
# message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})

add_definitions(${LLVM_DEFINITIONS})

include_directories(${CMAKE_SOURCE_DIR}/include)

###############################################
# Set project files
###############################################

file(GLOB SOURCES ./*.hpp ./*.cpp)

add_executable(${project_name} ${SOURCES})

###############################################
# Link
###############################################

if(WIN32)
    target_link_libraries(${project_name} ${LLVM_AVAILABLE_LIBS})
else()
    # llvm_map_components_to_libnames(llvm_libs support core irreader)
    execute_process(COMMAND llvm-config-14 --libs all
					OUTPUT_VARIABLE llvm_libs)
	string(STRIP ${llvm_libs} llvm_libs)
	string(REPLACE " " ";" llvm_libs ${llvm_libs})
    target_link_libraries(${project_name} PRIVATE ${llvm_libs})
endif()
