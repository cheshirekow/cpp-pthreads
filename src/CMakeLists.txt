#find_package(GTKmm REQUIRED)
#find_package(Boost COMPONENTS iostreams REQUIRED)
                                                                    
#include_directories( 
#   ${Boost_INCLUDE_DIRS}
#    ${GTKmm_INCLUDE_DIRS} 
#    )


#set(LIBS ${LIBS} 
#   ${Boost_LIBRARIES}
#    ${GTKmm_LIBRARIES} 
#    )
 
#add_executable( ${CMAKE_PROJECT_NAME} main.cpp Application.cpp)

#target_link_libraries( ${CMAKE_PROJECT_NAME} ${LIBS})

#configure_file( 
#    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.glade 
#    ${CMAKE_CURRENT_BINARY_DIR}/mainwindow.glade COPYONLY )
    
#configure_file( 
#    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.xml 
#    ${CMAKE_CURRENT_BINARY_DIR}/mainwindow.xml COPYONLY )
 
