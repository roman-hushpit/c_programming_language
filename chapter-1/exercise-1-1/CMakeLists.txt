add_library(exercise_1_1
        exercise_1_1.c
)

target_include_directories(exercise_1_1 PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(test_exercise_1_1
        test_exercise_1_1.c
)

target_link_libraries(test_exercise_1_1
        exercise_1_1
        unity
)

add_test(NAME test_exercise_1_1 COMMAND test_exercise_1_1)