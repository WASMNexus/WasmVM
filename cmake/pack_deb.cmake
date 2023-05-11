if(DEV_BUILD)
    set(CPACK_PACKAGE_NAME ${PROJECT_NAME}-dev)
else(DEV_BUILD)
    set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
endif(DEV_BUILD)

set(CPACK_PACKAGE_VENDOR "WasmVM")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A WebAssembly virtual machine implementation")
set(CPACK_VERBATIM_VARIABLES True)
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
SET(CPACK_OUTPUT_FILE_PREFIX ${PROJECT_ROOT}/packages)
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA
    ${CMAKE_CURRENT_LIST_DIR}/triggers
)

set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 1)
set(CPACK_PACKAGE_VERSION_PATCH 0)

set(CPACK_GENERATOR "DEB")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Luis Hsu")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")

set(CPACK_DEB_COMPONENT_INSTALL YES)

include(CPack)