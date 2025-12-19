find_package(fmt CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)

#We're using the project name as the target name, but you can change it to make them different.
#With this setup, the name of the executable will be the same as the project name.
add_executable(${PROJECT_NAME} main.cpp)

target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET CXX_MODULES FILES
        utils/utilities.ixx
        board/board.ixx
        board/board_entity.ixx 
        pieces/tetromino.ixx 
        game/gamestate.ixx
        game/game.ixx 
)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt sfml-graphics)