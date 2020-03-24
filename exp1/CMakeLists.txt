cmake_minimum_required (VERSION 3.4)
project (exp1 C CXX)
set(default_build_type "Release")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17 -fPIC -lgomp -lrt -fopenmp -W -Wall -pedantic -O3 -Ofast -march=native")

# ----------------------------------------------------------------------------
# kProcessor Setup
# ----------------------------------------------------------------------------

add_subdirectory(./kProcessor)
set(kProcessor_INCLUDE_PATH "kProcessor/include")

# Add include directories.
include_directories("kProcessor/ThirdParty/MQF/include")
include_directories (${kProcessor_INCLUDE_PATH})


# ----------------------------------------------------------------------------
# END kProcessor Setup
# ----------------------------------------------------------------------------


add_executable (phmap_index use_phmap_index.cpp)
target_link_libraries (phmap_index kProcessor pthread z)
target_include_directories(phmap_index INTERFACE ${kProcessor_INCLUDE_PATH})

add_executable (phmap_indexPriorityQueue use_phmap_indexPriorityQueue.cpp)
target_link_libraries (phmap_indexPriorityQueue kProcessor pthread z)
target_include_directories(phmap_indexPriorityQueue INTERFACE ${kProcessor_INCLUDE_PATH})

add_executable (phmap_indexPriorityQueue2 use_phmap_indexPriorityQueue2.cpp)
target_link_libraries (phmap_indexPriorityQueue2 kProcessor pthread z)
target_include_directories(phmap_indexPriorityQueue2 INTERFACE ${kProcessor_INCLUDE_PATH})