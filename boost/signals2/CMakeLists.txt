#==============================================================================
# Copyright (c) 2014 Evgeny Proydakov <lord.tiran@gmail.com>
#==============================================================================

FIND_PACKAGE(Boost)
INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIRS})

SET(SOURCE_FILES main.cpp)

I_ADD_EXECUTABLE(boost_signals2 ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(boost_signals2 ${Boost_SYSTEM_LIBRARY})
TARGET_LINK_LIBRARIES(boost_signals2 ${Boost_THREAD_LIBRARY})
TARGET_LINK_LIBRARIES(boost_signals2 ${Boost_DATE_TIME_LIBRARY})
TARGET_LINK_LIBRARIES(boost_signals2 ${Boost_REGEX_LIBRARY})
TARGET_LINK_LIBRARIES(boost_signals2 ${Boost_CHRONO_LIBRARY})

if(MSVC)
    target_compile_options(boost_signals2 PRIVATE "/wd4244")
endif()
