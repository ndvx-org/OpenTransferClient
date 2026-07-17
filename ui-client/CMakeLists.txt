cmake_minimum_required (VERSION 3.10)

# MSVC Hot Reload
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ui-client")
add_subdirectory(SDL EXCLUDE_FROM_ALL)

if(ANDROID)
    # Android: Shared Library namens "main"
    add_library(main SHARED "src/otc.cpp" "src/otc.h" "src/log.h" "src/err.h" "src/window.cpp" "src/form.h")
    target_link_libraries(main PRIVATE SDL3::SDL3)
    if (CMAKE_VERSION VERSION_GREATER 3.12)
      set_property(TARGET main PROPERTY CXX_STANDARD 23)
    endif()
    target_include_directories(main PRIVATE SDL/include)
else()
    add_executable (OpenTransferClient_ui-client "src/otc.cpp" "src/otc.h" "src/log.h" "src/err.h" "src/window.cpp" "src/form.h")
    target_link_libraries(OpenTransferClient_ui-client PRIVATE SDL3::SDL3)
    if (CMAKE_VERSION VERSION_GREATER 3.12)
      set_property(TARGET OpenTransferClient_ui-client PROPERTY CXX_STANDARD 23)
    endif()
    target_include_directories(OpenTransferClient_ui-client PRIVATE SDL/include)
endif()


if(WIN32)
    add_custom_command(
        TARGET OpenTransferClient_ui-client POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL3::SDL3> 
            $<TARGET_FILE_DIR:OpenTransferClient_ui-client>
        COMMENT "Copy SDL3.dll to output directory"
    )
endif()