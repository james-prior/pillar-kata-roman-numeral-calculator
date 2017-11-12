set(
    LIB_SOURCES
    roman.c
)

set(
    MAIN_SOURCES
    main.c
)

set(
    HEADERS 
    ${CONFIG_HEADER}
    roman.h
)

add_library(roman STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main roman)

install(
    TARGETS roman
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/roman.h DESTINATION include)
