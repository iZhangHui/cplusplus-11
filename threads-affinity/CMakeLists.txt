add_executable(launch-thread-per-cpu launch-thread-per-cpu.cpp)
target_link_libraries(launch-thread-per-cpu pthread)

add_executable(launch-threads-report-cpu launch-threads-report-cpu.cpp)
target_link_libraries(launch-threads-report-cpu pthread)

add_executable(set-affinity set-affinity.cpp)
target_link_libraries(set-affinity pthread)

add_executable(thread-workload-benchmark thread-workload-benchmark.cpp)
target_link_libraries(thread-workload-benchmark pthread)
