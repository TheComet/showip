set (SHOWIP_RUNTIME_DESTINATION "bin" CACHE STRING "Destination prefix of showip")

message (STATUS ${SHOWIP_RUNTIME_DESTINATION})

add_executable (showip
        "src/showip.c"
        "src/main.c"
        "include/showip/showip.h"
)

include_directories ("include")

install (TARGETS showip
    RUNTIME DESTINATION "${SHOWIP_RUNTIME_DESTINATION}")
