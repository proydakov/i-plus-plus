#==============================================================================
# Copyright (c) 2021 Evgeny Proydakov <lord.tiran@gmail.com>
#==============================================================================

SET(SOURCE_FILES main.cpp)

CONFIGURE_FILE(resource.h.tmpl ${CMAKE_CURRENT_SOURCE_DIR}/resource.h)
I_ADD_EXECUTABLE(opengles2_gradient ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(opengles2_gradient opengles2_sdk)
