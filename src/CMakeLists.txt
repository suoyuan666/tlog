set (TLOG_SRC
    tlog.cpp
)

set (
    TLOG_OUT
    tlog
)

set (
    TLOG_INCLUDE
    ${PROJECT_SOURCE_DIR}/include/tlog
)
set (
    TLOG_INCLUDE_THIRD_PARTY
    ${PROJECT_SOURCE_DIR}/third_party/fmt/include
)

set (
    TLOG_LIBS
    fmt
)
include_directories(${TLOG_INCLUDE} ${TLOG_INCLUDE_THIRD_PARTY})

add_library(${TLOG_OUT} OBJECT ${TLOG_SRC})

target_link_libraries(tlog fmt)