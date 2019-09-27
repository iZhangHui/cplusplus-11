cmake_minimum_required(VERSION 3.5)
project(cpp11_test CXX)

set(CMAKE_CXX_STANDARD 17)
# use clang++ default
set(CMAKE_CXX_COMPILER clang++)

find_package(Boost)

add_subdirectory(CAS)
add_subdirectory(List)
add_subdirectory(algrithm)
add_subdirectory(bstree)
add_subdirectory(enable_shared_from_this)
add_subdirectory(lambda)
add_subdirectory(move)
add_subdirectory(smartptr)
add_subdirectory(static)
add_subdirectory(stl)
add_subdirectory(string)
add_subdirectory(template)
add_subdirectory(thread)
# add_subdirectory(threadpool)
add_subdirectory(threads-affinity)
add_subdirectory(boost)

###############################################################
###############################################################
add_executable(access_control access_control.cpp)
add_executable(auto auto.cpp)

add_executable(cast cast.cpp)
add_executable(division_zero division_zero.cpp)
add_executable(enum_class enum_class.cpp)
add_executable(explicit explicit.cpp)
add_executable(float_division float_division.cpp)
add_executable(functional1 functional1.cpp)

# add_library(lru_cache lru_cache.hpp)

add_executable(max_sub_array max_sub_array.cpp)
add_executable(noexcept noexcept.cpp)
add_executable(nullptr nullptr.cpp)
add_executable(overload_new_delete overload_new_delete.cpp)
add_executable(override_final override_final.cpp)
add_executable(override_overload_overwrite override_overload_overwrite.cpp)
add_executable(prime_number prime_number.cpp)
add_executable(return_reference return_reference.cpp)

add_executable(scope scope.cpp)
add_executable(singleton singleton.cpp)
target_link_libraries(singleton pthread)

add_executable(sizeof sizeof.cpp)
add_executable(sqrtx sqrtx.cpp)
add_executable(static_assert static_assert.cpp)
add_executable(static_var static_var.cpp)
add_executable(test_nullprt test_nullprt.cpp)

add_executable(type_traits type_traits.cpp)
add_executable(uninitialized_copy uninitialized_copy.cpp)
add_executable(virtaul_destructor virtaul_destructor.cpp)

add_executable(pragma_pack pragma_pack.cpp)
add_executable(vector_reserve vector_reserve.cpp)
add_executable(data_member_init data_member_init.cpp)
add_executable(array_ptr array_ptr.cpp)
