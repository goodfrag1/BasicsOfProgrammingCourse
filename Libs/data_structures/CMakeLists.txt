add_library(data_structures
        vector/vector.c
        vectorVoid/vectorVoid.c
        matrix/matrix.c)

target_link_libraries(data_structures algorithms)
