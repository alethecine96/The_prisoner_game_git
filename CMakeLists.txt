cmake_minimum_required(VERSION 3.4)

# Define sources and executable
add_subdirectory(test)
add_executable(menu main.cpp)
add_library(menu2 menu.cpp menu.h Mappa.cpp Mappa.h Player.cpp Player.h Projectile.cpp Projectile.h Enemy.cpp Enemy.h Entity.cpp Entity.h Update.cpp Update.h Coin.cpp Coin.h Powerup.cpp Powerup.h GameCharacter.cpp GameCharacter.h Strategy.cpp Strategy.h Observer.h Subject.h Client.cpp Client.h Achievement.cpp Achievement.h)
# Detect and add SFML

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(menu ${SFML_LIBRARIES})
    target_link_libraries(menu2 ${SFML_LIBRARIES})
endif()

target_link_libraries(menu menu2)