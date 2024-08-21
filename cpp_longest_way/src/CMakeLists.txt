set(SOURCE_FILES
        longest_way.cpp
        main.cpp)

# 実行ファイルを追加
add_executable(find_longest_way ${SOURCE_FILES})

# longest_way.cppをライブラリとしても追加
add_library(longest_way longest_way.cpp)
