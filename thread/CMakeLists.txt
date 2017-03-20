add_executable(thread1 thread1.cpp)
target_link_libraries(thread1 pthread)

add_executable(thread2 thread2.cpp)
target_link_libraries(thread2 pthread)

add_executable(get_future get_future.cpp)
target_link_libraries(get_future pthread)

add_executable(mutex_atomic mutex_atomic.cpp)
target_link_libraries(mutex_atomic pthread)

add_executable(thread_wrap thread_wrap.cpp)
target_link_libraries(thread_wrap pthread)