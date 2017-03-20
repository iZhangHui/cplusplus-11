add_executable(lambda1 lambda1.cpp)

add_executable(lambda2 lambda2.cpp)
target_link_libraries(lambda2 pthread)

add_executable(lambda3 lambda3.cpp)
target_link_libraries(lambda3 pthread)

add_executable(lambda4 lambda4.cpp)
add_executable(lambda5 lambda5.cpp)
