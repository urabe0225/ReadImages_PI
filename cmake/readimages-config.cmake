# ReadImages CMake config file
#
# This file sets the following variables:
# ReadImages_FOUND - Always TRUE.
# ReadImages_INCLUDE_DIRS - Directories containing the ReadImages include files.
# ReadImages_IDL_DIRS - Directories containing the ReadImages IDL files.
# ReadImages_LIBRARIES - Libraries needed to use ReadImages.
# ReadImages_DEFINITIONS - Compiler flags for ReadImages.
# ReadImages_VERSION - The version of ReadImages found.
# ReadImages_VERSION_MAJOR - The major version of ReadImages found.
# ReadImages_VERSION_MINOR - The minor version of ReadImages found.
# ReadImages_VERSION_REVISION - The revision version of ReadImages found.
# ReadImages_VERSION_CANDIDATE - The candidate version of ReadImages found.

message(STATUS "Found ReadImages-1.0.0")
set(ReadImages_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(ReadImages_INCLUDE_DIRS
#    "/usr/local/include/readimages-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(ReadImages_IDL_DIRS
#    "/usr/local/include/readimages-1/idl")
set(ReadImages_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(ReadImages_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(ReadImages_LIBRARIES
        "/usr/local/components/lib/libreadimages.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(ReadImages_LIBRARIES
        "/usr/local/components/lib/libreadimages.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(ReadImages_DEFINITIONS ${<dependency>_DEFINITIONS})

set(ReadImages_VERSION 1.0.0)
set(ReadImages_VERSION_MAJOR 1)
set(ReadImages_VERSION_MINOR 0)
set(ReadImages_VERSION_REVISION 0)
set(ReadImages_VERSION_CANDIDATE )

