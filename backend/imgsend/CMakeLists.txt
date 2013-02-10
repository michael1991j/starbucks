project( MatConverter )
find_package( OpenCV REQUIRED )
add_executable( MatConverter MatConverter )
target_link_libraries( MatConverter ${OpenCV_LIBS} )
