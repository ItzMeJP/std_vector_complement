cmake_minimum_required(VERSION 3.16)

project(std_vector_complement
        VERSION 26.05.2022
        DESCRIPTION
        "Std Vector complementary C++ API. Easy deployment of several heuristics using std::vector<>")

# Set if it will have export lib capabilities
# If the lib is placed inside the project folder, it nos needed to install it.

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set (INSTALL_IN_ROOT Yes)


#External packages
#find_package(Eigen3 REQUIRED)
#find_package(Boost COMPONENTS date_time system REQUIRED)
#find_package(Threads REQUIRED)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
        include/std_vector_complement
        #${BOOST_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(${PROJECT_NAME} SHARED
        src/std_vector_complement/std_vector_operations.cpp
        src/examples/example_node.cpp)

## Set dependencies of the library
target_link_libraries(${PROJECT_NAME}
        #Eigen3::Eigen
        #${BOOST_LIBRARIES}
        #${CMAKE_THREAD_LIBS_INIT}
        )


# To export the lib and install it
set_target_properties(${PROJECT_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        PUBLIC_HEADER "include/std_vector_complement/std_vector_operations.h"

        )

target_include_directories(${PROJECT_NAME} PRIVATE .)

configure_file(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)


if(${INSTALL_IN_ROOT})
    MESSAGE(">>>>> The std_vector_complement is set to be installed in root. Use sudo to install." )
    install(TARGETS ${PROJECT_NAME}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}
            PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
            PRIVATE_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

    install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
            DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

else()
    MESSAGE(">>>>> The std_vector_complement is set to be installed locally." )
    install(TARGETS ${PROJECT_NAME}
            LIBRARY DESTINATION ${CMAKE_BINARY_DIR}
            PUBLIC_HEADER DESTINATION ${CMAKE_BINARY_DIR}/public_headers)

    install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
            DESTINATION ${CMAKE_BINARY_DIR}/pkgconfig)
endif()



add_executable(example_node
       src/examples/example_node.cpp)

target_link_libraries(example_node
        ${PROJECT_NAME}
        )
