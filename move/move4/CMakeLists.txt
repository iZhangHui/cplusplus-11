add_library(strvec StrVec.cpp String.cpp)
add_executable(useStrVec useStrVec.cpp)
target_link_libraries(useStrVec strvec)
