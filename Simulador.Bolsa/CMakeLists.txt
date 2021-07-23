cmake_minimum_required(VERSION "3.21.0")

project("Simulador.Bolsa")

add_executable("${PROJECT_NAME}"
			"Simulador.Bolsa.cpp"
			"Application.cpp" 
			"Application.h"
			"Ui.cpp"
			"Ui.h"
			"Order.h")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin) # <-> /bin
install(FILES 
			"Simulador.Bolsa.cpp"
			"Application.cpp"
			"Application.h" 
			"Ui.cpp"
			"Ui.h"
			"Order.h"
		DESTINATION src)   # <-> /src


target_link_directories("${PROJECT_NAME}" PRIVATE "lib")
target_link_libraries("${PROJECT_NAME}" PRIVATE "quickfix")
target_include_directories("${PROJECT_NAME}" PRIVATE "quickfix")
if(WIN32)
	target_link_libraries("${PROJECT_NAME}" PRIVATE ws2_32.lib)
endif()