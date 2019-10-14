file(GLOB_RECURSE Lab_SRC
    NAMES "*.h" "*.hpp" "*.c" "*.cpp"
)

add_library(Lab STATIC ${Lab_SRC})
include_directories(${Lab_INCLUDE_DIRS})
