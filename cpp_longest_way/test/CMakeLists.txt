set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking

# search for unit_test_framework
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})

# create a clion_boost target from tests.cpp
add_executable(exe_test tests.cpp)

# link Boost libraries to the new target
target_link_libraries(exe_test ${Boost_LIBRARIES})

# link Boost with code library
target_link_libraries(exe_test test_library)