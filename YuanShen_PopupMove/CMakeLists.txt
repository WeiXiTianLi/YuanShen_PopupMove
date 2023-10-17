
project(YuanShen.PopupMove VERSION 1.0.0)

# 该项目为静态链接Qt5的动态链接库
# Qt5
set(Qt5VER "qt-5.15.2-lite-release-static")
set(Qt5_DIR "${ThridPatryDir}/${Qt5VER}/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Gui Widgets FbSupport FontDatabaseSupport  REQUIRED)
#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


if(MSVC)
    set(VERSION_RC "${CMAKE_BINARY_DIR}/version.rc")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
                   "${VERSION_RC}")
endif()

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /level='requireAdministrator' /uiAccess='false'")

# vcpkg
# 将源代码添加到此项目的可执行文件。
add_executable(${PROJECT_NAME}  ${VERSION_RC}  YuanShen_PopupMove.rc
    main.cpp
    YuanShen_Fun.cpp
    YuanShen_Fun.h
    YuanShen_PopupMove.cpp
    YuanShen_PopupMove.h
)


set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded")

# link 3rdparty lib
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets libcmt)

# used utf-8 encoding
target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8")
