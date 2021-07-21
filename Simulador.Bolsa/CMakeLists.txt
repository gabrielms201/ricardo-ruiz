cmake_minimum_required(VERSION "3.21.0")

project("Simulador.Bolsa")

add_executable("${PROJECT_NAME}" "Main.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #/bin
install(FILES "Main.cpp" DESTINATION src)		#/src
