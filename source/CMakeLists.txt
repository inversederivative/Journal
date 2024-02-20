set(SOURCES 
	main.cpp
	MainWindow.cpp
	../include/MainWindow.hpp
	JournalEntry.cpp
	../include/JournalEntry.hpp
)


add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
