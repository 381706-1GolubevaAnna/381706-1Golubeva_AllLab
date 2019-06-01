file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${TableTest} ${srcs} ${hdrs})
target_link_libraries(${TableTest} ${TableLib} gtest)
