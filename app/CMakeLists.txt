cmake_minimum_required(VERSION 3.4.1)

#查找系统库 liblog.so
find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

#变量
set(distribution_DIR ../../../../libs)

add_library( fmod
             SHARED
             IMPORTED)
set_target_properties( fmod
                       PROPERTIES IMPORTED_LOCATION
                       #ANDROID_ABI 预编译的变量，使用对应的编译工具链编译
                       ${distribution_DIR}/${ANDROID_ABI}/libfmod.so)

 add_library( fmodL
              SHARED
              IMPORTED)
 set_target_properties( fmodL
                        PROPERTIES IMPORTED_LOCATION
                        ${distribution_DIR}/${ANDROID_ABI}/libfmodL.so)

#设置编译C的标准
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_library(native-lib
            SHARED
            src/main/cpp/native-lib.cpp)

 include_directories(src/main/cpp/inc)



# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.



# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.
#指定链接的target
target_link_libraries( # Specifies the target library.
                       native-lib
                       fmod
                       fmodL
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
