add_executable(oop_exercise_03 main.cpp)
target_include_directories(oop_exercise_03 PRIVATE ${Lab_INCLUDE_DIRS})
target_link_libraries(oop_exercise_03 PRIVATE Lab)
