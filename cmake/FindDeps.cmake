find_package(cJSON REQUIRED)


# Create the targets
list(LENGTH LIBRARIES COUNT)
foreach(LIBRARY ${LIBRARIES})
    SET(LIB_FILE "${LIBS_F}/lib${LIBRARY}.a")
    add_custom_target(${LIBRARY} DEPENDS ${LIB_FILE})
    add_dependencies(${LIBRARY} create_folders)
endforeach()


# Link the dependencies with the FIM library
add_dependencies(${FIM_LIB} ${LIBRARIES})
