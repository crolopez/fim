SET(LIB_CJSON "cjson")
SET(LIB_CJSON_PATH "${LIBS_F}/lib${LIB_CJSON}.a")
list(APPEND LIBRARIES ${LIB_CJSON})


# cJSON library unpacking
SET(LIB_CJSON_SRC "${EXTERNAL_F}/${LIB_CJSON}/cJSON.c")
add_custom_command(OUTPUT ${LIB_CJSON_SRC}
    COMMENT "Creating ${LIB_CJSON} library."
    COMMAND cd ${EXTERNAL_F} &&
            tar zxvf ${LIB_CJSON}.tar.gz
    VERBATIM
)
add_custom_target(UNCOMPRESSED_CJSON DEPENDS ${LIB_CJSON_SRC})


# cJSON library generation
add_library(_${LIB_CJSON} STATIC ${LIB_CJSON_SRC})
add_dependencies(_${LIB_CJSON} UNCOMPRESSED_CJSON)


# Move cJSON library to its final path
add_custom_command(OUTPUT ${LIB_CJSON_PATH}
    COMMAND pwd && mv lib_${LIB_CJSON}.a ${LIB_CJSON_PATH}
    DEPENDS _${LIB_CJSON}
    VERBATIM
)
