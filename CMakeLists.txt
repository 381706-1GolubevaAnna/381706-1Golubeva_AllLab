cmake_minimum_required(VERSION 2.8) #Ïðîâåðêà âåðñèè CMake.

set(PROJECT_NAME 381706-1Golubeva_AllLab) #Ñîçäàåì îáû÷íóþ ëîêàëüíóþ ïåðåìåííóþ ñ èìåíåì ïðîåêòà
project(${PROJECT_NAME}) # Íàçâàíèå ïðîåêòà

set(Exception Exception)

set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

set(Queue Queue)
set(QueueLib QueueLib)
set(QueueTest QueueTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Ñîçäàåòñÿ ïåðåìåííàÿ CMAKE_CONFIGURATION_TYPES ñî çíà÷åíèåì "Debug;Release" è ìåòêîé/ðàçäåëîì Configs, ïåðåìåííàÿ ñîõðàíèåòñÿ â ñïåöèàëüíîì ôàéëå äîñòóïíîì èç âñåõ ôàéëîâ,
if(NOT CMAKE_BUILD_TYPE) # ïðîâåðêà èìåþùèõñÿ ó êîìïèëÿòîðà âàðèàíòîâ ñáîðêè
  set(CMAKE_BUILD_TYPE Release) #Åñëè íåò òî óñòàíàâëèâàåì Release
endif()

file(GLOB hdrs "*.h*") #Äîáàâëÿåì â ïåðåìåííóþ hdrs âñå ôàéëû ñ ðàñøèðåíèåì .h
file(GLOB srcs "*.cpp") #Äîáàâëÿåì â ïåðåìåííóþ srcs âñå ôàéëû ñ ðàñøèðåíèåì .h


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Ñîçäàåì ïðîåêò ñ èìåíåì èç ïåðåìåííîé ${PROJECT_NAME}, â íåãî äîáàâëÿþòñÿ ôàéëû èç ïåðåìåííûõ ${srcs} è ${hdrs}

#${CMAKE_CURRENT_SOURCE_DIR}
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

#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Ïîäêëþ÷àåì ê ïðîåêòó ñ èìåíåì ${PROJECT_NAME} áèáëèîòåêó ñ èìåíåì ${MyLib1}
