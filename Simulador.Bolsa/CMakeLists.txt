cmake_minimum_required(VERSION "3.21.0")

project("Simulador.Bolsa")

add_executable("${PROJECT_NAME}"
			"Application.cpp" 
			"Application.h"
			"Ui.cpp"
			"Ui.h")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin) # <-> /bin
install(FILES 
			"Application.cpp"
			"Application.h" 
			"Ui.cpp"
			"Ui.h"
		DESTINATION src)   # <-> /src

target_link_directories("${PROJECT_NAME}" PRIVATE "lib" "${PROJECT_NAME}")
target_link_libraries("${PROJECT_NAME}" PRIVATE "quickfix")
target_include_directories("${PROJECT_NAME}" PRIVATE "quickfix")
