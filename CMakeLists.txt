cmake_minimum_required(VERSION 3.0)
project(Figures)

file(GLOB_RECURSE sources      src/main/*.cpp src/main/*.h)
file(GLOB_RECURSE app      src/app/*.cpp src/main/*.h)
file(GLOB_RECURSE sources_test src/test/*.cpp)

file(GLOB_RECURSE data resources/*)
add_executable(Figures ${sources} ${app} ${data})

target_compile_options(Figures PUBLIC -fsanitize=leak -g -std=c++14 -Wall -Wfloat-conversion)
target_include_directories(Figures PUBLIC src/main)

file(COPY ${data} DESTINATION resources)
#find_package(Boost 1.36.0 COMPONENTS filesystem system REQUIRED)
#target_link_libraries(figures PUBLIC
#   ${Boost_LIBRARIES}
#)

find_package(Threads)
target_link_libraries(Figures ${CMAKE_THREAD_LIBS_INIT} pthread)

enable_testing()
find_package(GTest)

if(GTEST_FOUND)
  add_executable(UnitTests ${sources} ${sources_test})
  target_compile_definitions(UnitTests PUBLIC unit_tests)
  set_target_properties(Figures PROPERTIES ENABLE_EXPORTS on)
  target_link_libraries(UnitTests PUBLIC
    Figures
    ${GTEST_BOTH_LIBRARIES}
  )

  target_include_directories(UnitTests PUBLIC
    ${GTEST_INCLUDE_DIRS} 
  )
  add_test(NAME AllTests COMMAND UnitTests)

endif()

install(TARGETS Figures DESTINATION build)
install(DIRECTORY resources DESTINATION build/data)

set(CPACK_PACKAGE_NAME "Figures")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_MONOLITHIC_INSTALL 1)

include(CPack)