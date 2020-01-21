find_package(cJSON REQUIRED)


# Create the targets
list(LENGTH LIBRARIES COUNT)
foreach(LIBRARY ${LIBRARIES})
    SET(LIB_FILE "${LIBS_F}/lib${LIBRARY}.a")
    add_custom_target(${LIBRARY} DEPENDS ${LIB_FILE})
    add_dependencies(${LIBRARY} create_folders)
    # Link the dependencies with the FIM library
    target_link_libraries(${FIM_LIB} PRIVATE "lib${LIBRARY}.a")
endforeach()


# Link the dependencies with the FIM library
target_link_libraries(${FIM_LIB} PRIVATE -L${LIBS_F})
add_dependencies(${FIM_LIB} ${LIBRARIES})
