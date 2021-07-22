cmake_minimum_required(VERSION "3.21.0")

project("Simulador.Bolsa")

add_executable("${PROJECT_NAME}" "Application.cpp" "Application.h")


install(TARGETS "${PROJECT_NAME}" DESTINATION bin) # <-> /bin
install(FILES "Application.cpp" "Application.h" DESTINATION src)   # <-> /src

target_link_directories("${PROJECT_NAME}" PUBLIC "lib" "${PROJECT_NAME}" PUBLIC "quickfix")
target_link_libraries("${PROJECT_NAME}" PUBLIC "quickfix")
target_include_directories("${PROJECT_NAME}" PUBLIC "quickfix")
