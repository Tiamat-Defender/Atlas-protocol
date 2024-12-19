# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

FILE(GLOB FreeRTOS_src FreeRTOS-Kernel/*.c)

# Add the FreeRTOS library
add_library(FreeRTOS STATIC
    ${FreeRTOS_src}
    FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/include
    FreeRTOS-Kernel/portable/MemMang/heap_4.c
    FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040
)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

#pull in freeRTOS
include(FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(AtlasPhoneOS C CXX ASM)


# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(AtlasPhoneOS AtlasPhoneOS.c)

pico_set_program_name(AtlasPhoneOS "AtlasPhoneOS")
pico_set_program_version(AtlasPhoneOS "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(AtlasPhoneOS 0)
pico_enable_stdio_usb(AtlasPhoneOS 0)

set(BOARDS_INCLUDE_PATH "/home/preston/.pico-sdk/sdk/2.1.0/src/boards/include/boards")
include_directories(${BOARDS_INCLUDE_PATH})

# Add the standard library to the build
target_link_libraries(AtlasPhoneOS
    pico_stdlib
    FreeRTOS
    FreeRTOS-kernel-Heap_4
)

# Add the standard include files to the build
target_include_directories(AtlasPhoneOS PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_include_directories(FreeRTOS PUBLIC
    FreeRTOS-Kernel/include
    include/
    FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040
    FreeRTOS-Kernel/
    FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/include
    ${PICO_SDK_PATH}/include
)

target_include_directories(FreeRTOS PUBLIC ${PICO_SDK_PATH}/include)


# Add any user requested libraries
pico_add_extra_outputs(AtlasPhoneOS)
