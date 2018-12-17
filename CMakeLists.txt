cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1Golubeva_AllLab) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(Exception Exception)

set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

set(Queue Queue)
set(QueueLib QueueLib)
set(QueueTest QueueTest)
#set(MyLib1 MyLib1) #Переменная с именем библиотеки

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exception)
add_subdirectory(Exception)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(Queue)
add_subdirectory(QueueLib)
add_subdirectory(QueueTest)
 #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)
#(lib1) #Собираем проект в поддиректории lib1

#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}
