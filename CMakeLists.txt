cmake_minimum_required(VERSION 3.2)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.106.tar.gz"
    SHA1 "88b201594fab3054f7a22efa3d21d2e8981efc32"
)

project(icu-le-hb VERSION 1.0.3)

add_library(
    icu-le-hb
    src/LEFontInstance.cpp
    src/LEFontInstance.h
    src/LEGlyphFilter.h
    src/LEGlyphStorage.cpp
    src/LEGlyphStorage.h
    src/LEInsertionList.cpp
    src/LEInsertionList.h
    src/LELanguages.h
    src/LEScripts.h
    src/LESwaps.h
    src/LETypes.h
    src/LayoutEngine.cpp
    src/LayoutEngine.h
    src/OpenTypeLayoutEngine.h
    src/ScriptAndLanguageTags.cpp
    src/ScriptAndLanguageTags.h
    src/loengine.cpp
    src/loengine.h
)

hunter_add_package(harfbuzz)
find_package(harfbuzz CONFIG REQUIRED)
target_link_libraries(icu-le-hb PUBLIC harfbuzz::harfbuzz)

### Installation (https://github.com/forexample/package-example) {

# Introduce variables:
# * CMAKE_INSTALL_LIBDIR
# * CMAKE_INSTALL_BINDIR
# * CMAKE_INSTALL_INCLUDEDIR
include(GNUInstallDirs)

set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(NAMESPACE "${PROJECT_NAME}::")

include(CMakePackageConfigHelpers)

# Use:
# * PROJECT_VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Use:
# * TARGETS_EXPORT_NAME
# * PROJECT_NAME
configure_package_config_file(
    "cmake/template/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

install(
    DIRECTORY "src/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/layout"
    FILES_MATCHING
    PATTERN "*.h"
)

install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${NAMESPACE}"
    DESTINATION "${config_install_dir}"
)

### }

install(
    TARGETS icu-le-hb
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)
