cmake_minimum_required (VERSION 2.6)
project (CPEN391GL)

include_directories(include)
add_executable(testGL 
		${PROJECT_SOURCE_DIR}/src/Fonts.c
		${PROJECT_SOURCE_DIR}/src/FontsData.c
		${PROJECT_SOURCE_DIR}/src/HWDraw.c
		${PROJECT_SOURCE_DIR}/src/testGL.c
	)