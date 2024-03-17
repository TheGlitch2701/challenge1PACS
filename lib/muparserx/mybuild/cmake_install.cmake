# Install script for directory: /home/theglitch/challenge1PACS/lib/muparserx_mia

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/u/sw/toolchains/gcc-glibc/11.2.0/prefix/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/theglitch/challenge1PACS/lib/muparserx_mia/mybuild/libmuparserx.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/theglitch/challenge1PACS/lib/muparserx_mia/mybuild/muparserx.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/muparserx" TYPE FILE FILES
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/cmake/muparserxConfig.cmake"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/mybuild/muparserxConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muparserx" TYPE FILE FILES
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpDefines.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpError.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpFuncCmplx.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpFuncCommon.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpFuncMatrix.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpFuncNonCmplx.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpFuncStr.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpFwdDecl.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpICallback.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpIOprt.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpIOprtBinShortcut.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpIPackage.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpIPrecedence.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpIToken.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpIValReader.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpIValue.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpIfThenElse.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpMatrix.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpMatrixError.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpOprtBinAssign.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpOprtBinCommon.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpOprtBinShortcut.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpOprtCmplx.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpOprtIndex.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpOprtMatrix.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpOprtNonCmplx.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpOprtPostfixCommon.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpPackageCmplx.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpPackageCommon.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpPackageMatrix.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpPackageNonCmplx.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpPackageStr.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpPackageUnit.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpParser.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpParserBase.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpParserMessageProvider.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpRPN.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpScriptTokens.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpStack.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpStringConversionHelper.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpTest.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpTokenReader.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpTypes.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpValReader.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpValue.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpValueCache.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/mpVariable.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/suSortPred.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/suStringTokens.h"
    "/home/theglitch/challenge1PACS/lib/muparserx_mia/parser/utGeneric.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/theglitch/challenge1PACS/lib/muparserx_mia/mybuild/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
