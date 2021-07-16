cmake_minimum_required(VERSION 3.17)
set(GOOGLETEST_VERSION 1.11.0)
project(Martina_Bicchi_7049270)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES Note.h Note.cpp NotesCollectionSpecific.h NotesCollectionSpecific.cpp NotesCollectionImportant.h NotesCollectionImportant.cpp NotesCollection.h NotesCollection.cpp ConcreteObserver.h ConcreteObserver.cpp Subject.h Observer.h )
add_executable(Martina_Bicchi_7049270 main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(Martina_Bicchi_7049270 core)
