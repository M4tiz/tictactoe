# better way ?
INCLUDE_DIRECTORIES(.)

# Source files
# ====================================
#           (Glob is not recommended)
#   file(GLOB APL_SRC *.cc)
#   file(GLOB_RECURSE APL_SRC *.cc)

SET(PROJECT_TEST_HDS
    symbolic.h
    logger.h
    game.h
    game_runner.h
    ./gui/gui_game_handler.h
    game_handler.h
    ./stream/stream_game_handler.h
)

SET(PROJECT_TEST_SRC
    symbolic.cpp
    logger.cpp
    game.cpp
    game_runner.cpp
    ./gui/gui_game_handler.cpp
    ./stream/stream_game_handler.cpp
)

# main library (prevent recompilation when building tests)
ADD_LIBRARY(${PROJECT_NAME} ${PROJECT_TEST_SRC} ${PROJECT_TEST_HDS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} spdlog::spdlog)

LINK_DIRECTORIES(${GTKMM_LIBRARY_DIRS})
INCLUDE_DIRECTORIES(${GTKMM_INCLUDE_DIRS})

#  main executable
# ==========================

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main spdlog::spdlog project_test ${GTKMM_LIBRARIES})
