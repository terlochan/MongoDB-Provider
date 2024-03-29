# -*- mode: Makefile; -*- 

#--------------------------------- START OF LICENSE ----------------------------
#
# MySQL cimprov ver. 1.0
#
# Copyright (c) Microsoft Corporation
#
# All rights reserved. 
#
# MIT License
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the ""Software""), to deal
# in the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
# of the Software, and to permit persons to whom the Software is furnished to do
# so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
#---------------------------------- END OF LICENSE -----------------------------

#-------------------------------------------------------------------------------
# 2014-01-17
#-------------------------------------------------------------------------------

BASE_DIR := $(subst /build,,$(PWD))
OMI_ROOT := $(shell cd ../../omi/Unix; pwd -P)
SCXPAL_DIR := $(shell cd ../../pal; pwd -P)

PF_POSIX := 1
include $(SCXPAL_DIR)/build/config.mak
include $(BASE_DIR)/build/config.mak
include $(BASE_DIR)/build/Makefile.version
include $(SCXPAL_DIR)/build/Makefile.pal

ifndef ENABLE_DEBUG
$(error "ENABLE_DEBUG is not set.  Please re-run configure")
endif

ifndef SCX_BUILDVERSION_STATUS
$(error "Is Makefile.version missing?  Please re-run configure")
endif

SOURCE_DIR := $(BASE_DIR)/source/code
TEST_DIR := $(BASE_DIR)/test/code

PROVIDER_DIR := $(SOURCE_DIR)/providers
PAL_INCLUDE_DIR := $(SCXPAL_DIR)/source/code/include
PAL_TESTUTILS_DIR := $(SCXPAL_DIR)/test/code/testutils

INTERMEDIATE_DIR=$(BASE_DIR)/intermediate/$(BUILD_CONFIGURATION)
TARGET_DIR := $(BASE_DIR)/target/$(BUILD_CONFIGURATION)
PROVIDER_LIBRARY := $(INTERMEDIATE_DIR)/libmongoProvider.so

INSTALLER_TMPDIR := $(INTERMEDIATE_DIR)/installer_tmp

# Include files

INCLUDE_VERSION := $(INTERMEDIATE_DIR)/buildversion.h
INCLUDE_DEFINES := $(INTERMEDIATE_DIR)/defines.h

# Compiler flags

OMI_INCLUDE_FLAGS := -I$(OMI_ROOT)/output/include
PROVIDER_INCLUDE_FLAGS := -I$(PROVIDER_DIR)/support -I$(PAL_INCLUDE_DIR) -I$(INTERMEDIATE_DIR)


ifeq ($(ENABLE_DEBUG),1)
PROV_DEBUG_FLAGS := -g
endif

# On newer compilers (Cent 7 / gcc v4.8.3), OMI can't tolerate -Wcast-qual
# Disable that until the OMI problem is resolved ...

COMPILE_FLAGS := $(PROV_DEBUG_FLAGS) -D_REENTRANT -fstack-protector-all -Wall -fno-nonansi-builtins  -Woverloaded-virtual -Wformat -Wformat-security -Wcast-align -Wswitch-enum -Wshadow -Wwrite-strings -Wredundant-decls -Werror  -Wno-cast-qual -fPIC
PROVIDER_COMPILE_FLAGS := $(COMPILE_FLAGS) 

LINK_LIBRARIES := -Wl,-rpath=/opt/microsoft/mysql-cimprov/lib -Wl,-rpath=/opt/omi/lib -L$(OMI_ROOT)/output/lib -lmongoclient -lboost_thread -lboost_filesystem -lboost_system -lmicxx -L$(SCXPAL_TARGET_DIR) -lscxcore -lUtil -lscxassertabort -lrt 

SHARED_FLAGS := -shared

# Support for installbuilder

STAGING_DIR := $(INTERMEDIATE_DIR)/staging
ifeq ($(ULINUX),1)

  # The MP needs architecture of i686 (for x86) and x86_64 (for x64).
  MYSQL_ARCH := $(shell echo $(PF_ARCH) | sed -e 's/x86$$/i686/' -e 's/x64$$/x86_64/')
  OUTPUT_PACKAGE_PREFIX=mysql-cimprov-$(SCX_BUILDVERSION_MAJOR).$(SCX_BUILDVERSION_MINOR).$(SCX_BUILDVERSION_PATCH)-$(SCX_BUILDVERSION_BUILDNR).universal.$(MYSQL_ARCH)

else

  PF_DISTRO_LC := $(shell echo $(PF_DISTRO) | tr A-Z a-z)
  OUTPUT_PACKAGE_PREFIX=mysql-cimprov-$(SCX_BUILDVERSION_MAJOR).$(SCX_BUILDVERSION_MINOR).$(SCX_BUILDVERSION_PATCH)-$(SCX_BUILDVERSION_BUILDNR).$(PF_DISTRO_LC).$(PF_MAJOR).$(PF_ARCH)

endif

ifeq ("$(wildcard /usr/bin/dpkg-deb)","")
DPKG_LOCATION="--DPKG_LOCATION=$(SCXPAL_DIR)/installer/InstallBuilder/tools/bin/dpkg-deb-$(PF_ARCH)"
else
DPKG_LOCATION=
endif

# Support for src_to_obj handling

INCLUDES = $(OMI_INCLUDE_FLAGS) $(PROVIDER_INCLUDE_FLAGS)
CFLAGS = $(COMPILE_FLAGS)
CXXFLAGS = $(COMPILE_FLAGS)

#--------------------------------------------------------------------------------
# Build targets

ifeq ($(ULINUX),1)
#all : $(OMI_ROOT)/output $(SCXPAL_INTERMEDIATE_DIR) PROVIDER_STATUS $(PROVIDER_LIBRARY) MYAUTH_STATUS $(MYAUTH_PROG) OMI_PREEXEC_STATUS $(OMI_PREEXEC) KIT_STATUS kit
all : $(OMI_ROOT)/output $(SCXPAL_INTERMEDIATE_DIR) PROVIDER_STATUS $(PROVIDER_LIBRARY)
else
#all : $(OMI_ROOT)/output $(SCXPAL_INTERMEDIATE_DIR) PROVIDER_STATUS $(PROVIDER_LIBRARY) MYAUTH_STATUS $(MYAUTH_PROG) OMI_PREEXEC_STATUS $(OMI_PREEXEC)
all : $(OMI_ROOT)/output $(SCXPAL_INTERMEDIATE_DIR) PROVIDER_STATUS $(PROVIDER_LIBRARY)
endif

clean :
	$(RMDIR) $(BASE_DIR)/build/cppunit_result.* $(BASE_DIR)/build/scxtestrunner.log $(BASE_DIR)/installer/intermediate $(BASE_DIR)/intermediate $(BASE_DIR)/target $(PROVIDER_TEST_DIR)/providertestutils.cpp
	-find $(BASE_DIR) -name \*~ -exec rm {} \;

distclean : clean
	-$(RM) $(BASE_DIR)/build/config.mak
	-$(RM) $(BASE_DIR)/build/Makefile.version
	-$(MAKE) -C $(OMI_ROOT) distclean
	-$(MAKE) -C $(SCXPAL_DIR)/build distclean
	-$(RMDIR) $(OMI_ROOT)/output*
	-$(RM) $(SCXPAL_DIR)/build/config.mak
	-$(RM) $(SCXPAL_DIR)/build/Makefile.config_cache

ifeq ($(OPENSOURCE_DISTRO),0)

# Install the OMI provider for test purposes
# This assumes that:
#   1) OMI already has registration files for libmysqlProvider.so

install : /opt/omi/lib/libmongoProvider.so
	@[ -e $(INTERMEDIATE_DIR)/tmp_start_omi  ] && rm $(INTERMEDIATE_DIR)/tmp_start_omi  && sudo /etc/init.d/omiserverd start || exit 0

/opt/omi/lib/libmongoProvider.so : $(PROVIDER_LIBRARY)
	@echo "========================= Performing Installing OMI provider"
	-sudo /etc/init.d/omiserverd stop
	touch $(INTERMEDIATE_DIR)/tmp_start_omi
	sudo $(COPY) -v $(PROVIDER_LIBRARY) /opt/omi/lib/

restart :
	@-sudo /etc/init.d/omiserverd stop
	@sudo /etc/init.d/omiserverd start

else

install : all
	$(MKPATH) /etc/opt/microsoft/mysql-cimprov/conf
	$(MKPATH) /opt/microsoft/mysql-cimprov/bin
	$(MKPATH) /opt/microsoft/mysql-cimprov/lib
	$(MKPATH) /var/opt/microsoft/mysql-cimprov/auth
	$(MKPATH) /var/opt/microsoft/mysql-cimprov/log
	$(MKPATH) /var/opt/microsoft/mysql-cimprov/run

	$(COPY) $(INTERMEDIATE_DIR)/mycimprovauth /opt/microsoft/mysql-cimprov/bin
	$(COPY) $(INTERMEDIATE_DIR)/omi_preexec /opt/microsoft/mysql-cimprov/bin
	$(COPY) $(INTERMEDIATE_DIR)/libmysqlProvider.so /opt/microsoft/mysql-cimprov/lib 

	chmod 755 /opt/microsoft/mysql-cimprov/bin/mycimprovauth
	chmod 755 /opt/microsoft/mysql-cimprov/bin/omi_preexec
	chmod 755 /opt/microsoft/mysql-cimprov/lib/libmysqlProvider.so

	$(SOFTLINK) /opt/microsoft/mysql-cimprov/lib/libmysqlProvider.so /opt/omi/lib

endif # ifeq ($(OPENSOURCE_DISTRO),0)

PROVIDER_STATUS:
	@echo "========================= Performing Building provider"

MYAUTH_STATUS:
	@echo "========================= Performing Building mycimprovauth executable"

OMI_PREEXEC_STATUS:
	@echo "========================= Performing Building OMI preexec executable"

KIT_STATUS:
	@echo "========================= Performing Building provider tests"

#--------------------------------------------------------------------------------
# OMI build
#
# Build the OMI distribution
#
# Technically, we should go to build OMI all the time. But I'd rather not spend
# the time doing it here EVERY TIME, when we never normally change OMI. This is
# a good tradeoff (build if not built, otherwise assume all is well).
#
# Doing a 'make clean' in OMI directory will force us to rebuild.

$(OMI_ROOT)/output : $(OMI_ROOT)/output/lib/libmicxx.so

$(OMI_ROOT)/output/lib/libmicxx.so :
	@echo "========================= Performing Building OMI"
	$(MAKE) -C $(OMI_ROOT)
ifeq ($(PERFORM_OMI_MAKEINSTALL),1)
	$(MAKE) -C $(OMI_ROOT) install
endif

#--------------------------------------------------------------------------------
# PAL build
#
# Build the PAL (Platform Abstraction Layer)
#
# Doing a 'make clean' in PAL directory will force us to rebuild.

$(SCXPAL_INTERMEDIATE_DIR) :
	@echo "========================= Performing Building PAL"
	$(MAKE) -C $(SCXPAL_DIR)/build

#--------------------------------------------------------------------------------
# Version information header file
#
# Build the version header file

$(INCLUDE_VERSION) : $(BASE_DIR)/build/Makefile.version
	-$(MKPATH) $(@D)
	@$(ECHO) "Creating $@" 
	@$(call pf_fwrite,"/*------------------------------------------------------------------------------",  $@)
	@$(call pf_fappend,"    Copyright (C) 2007-2014 Microsoft Corp.                                     ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"*/                                                                              ", $@)
	@$(call pf_fappend,"/**                                                                             ", $@)
	@$(call pf_fappend,"    \file                                                                       ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"    \brief       Auto generated file containing build version information       ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"    \author      Automated Build System                                         ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"    DO NOT EDIT THIS FILE!                                                      ", $@)
	@$(call pf_fappend,"    DO NOT CHECK IN THIS FILE!                                                  ", $@)
	@$(call pf_fappend,"*/                                                                              ", $@)
	@$(call pf_fappend,"/*----------------------------------------------------------------------------*/", $@)
	@$(call pf_fappend,"#ifndef BUILDVERSION_H                                                          ", $@)
	@$(call pf_fappend,"#define BUILDVERSION_H                                                          ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"#include <string>                                                               ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"/** Major version number */                                                     ", $@)
	@$(call pf_fappend,"const int CIMPROV_BUILDVERSION_MAJOR = $(SCX_BUILDVERSION_MAJOR);               ", $@)
	@$(call pf_fappend,"/** Minor version number */                                                     ", $@)
	@$(call pf_fappend,"const int CIMPROV_BUILDVERSION_MINOR = $(SCX_BUILDVERSION_MINOR);               ", $@)
	@$(call pf_fappend,"/** Patch version number */                                                     ", $@)
	@$(call pf_fappend,"const int CIMPROV_BUILDVERSION_PATCH = $(SCX_BUILDVERSION_PATCH);               ", $@)
	@$(call pf_fappend,"/** Build number */                                                             ", $@)
	@$(call pf_fappend,"const int CIMPROV_BUILDVERSION_BUILDNR = $(SCX_BUILDVERSION_BUILDNR);           ", $@)
	@$(call pf_fappend,"/** Build date */                                                               ", $@)
	@$(call pf_fappend,"const std::wstring CIMPROV_BUILDVERSION_DATE(L\"$(SCX_BUILDVERSION_DATE)\");    ", $@)
	@$(call pf_fappend,"/** Build status */                                                             ", $@)
	@$(call pf_fappend,"const std::wstring CIMPROV_BUILDVERSION_STATUS(L\"$(SCX_BUILDVERSION_STATUS)\");  ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"#endif /* BUILDVERSION_H */                                                     ", $@)
	@$(call pf_fappend,"/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/", $@)

#================================================================================
# File depends.h (compiler dependencies)
#================================================================================

$(INCLUDE_DEFINES) : $(BASE_DIR)/build/config.mak
	-$(MKPATH) $(@D)
	@$(ECHO) "Creating $@" 
	@$(call pf_fwrite,"/*------------------------------------------------------------------------------",  $@)
	@$(call pf_fappend,"    Copyright (C) 2007 Microsoft Corp.                                          ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"*/                                                                              ", $@)
	@$(call pf_fappend,"/**                                                                             ", $@)
	@$(call pf_fappend,"    \file                                                                       ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"    \brief       Auto generated file containing build definitions               ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"    \author      Automated Build System                                         ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"    DO NOT EDIT THIS FILE!                                                      ", $@)
	@$(call pf_fappend,"    DO NOT CHECK IN THIS FILE!                                                  ", $@)
	@$(call pf_fappend,"*/                                                                              ", $@)
	@$(call pf_fappend,"/*----------------------------------------------------------------------------*/", $@)
	@$(call pf_fappend,"#ifndef DEFINES_H                                                               ", $@)
	@$(call pf_fappend,"#define DEFINES_H                                                               ", $@)
	@$(call pf_fappend,"                                                                                ", $@)
ifneq ($(PF_DISTRO),)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"#ifndef PF_DISTRO_$(PF_DISTRO)                                                  ", $@)
	@$(call pf_fappend,"#define PF_DISTRO_$(PF_DISTRO)                                                  ", $@)
	@$(call pf_fappend,"#endif                                                                          ", $@)
endif
ifneq ($(PF_MAJOR),)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"#ifndef PF_MAJOR                                                                 ", $@)
	@$(call pf_fappend,"#define PF_MAJOR $(PF_MAJOR)                                                    ", $@)
	@$(call pf_fappend,"#endif                                                                          ", $@)
endif
ifneq ($(PF_MINOR),)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"#ifndef PF_MINOR                                                                 ", $@)
	@$(call pf_fappend,"#define PF_MINOR $(PF_MINOR)                                                    ", $@)
	@$(call pf_fappend,"#endif                                                                          ", $@)
endif
ifneq ($(ARCH),)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"#ifndef $(ARCH)                                                                 ", $@)
	@$(call pf_fappend,"#define $(ARCH)                                                                 ", $@)
	@$(call pf_fappend,"#endif                                                                          ", $@)
endif
ifeq ($(BUILD_TYPE),Debug)
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"#ifndef _DEBUG                                                                  ", $@)
	@$(call pf_fappend,"#define _DEBUG                                                                  ", $@)
	@$(call pf_fappend,"#endif                                                                          ", $@)
else
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"#ifndef NDEBUG                                                                  ", $@)
	@$(call pf_fappend,"#define NDEBUG                                                                  ", $@)
	@$(call pf_fappend,"#endif                                                                          ", $@)
endif
	@$(call pf_fappend,"                                                                                ", $@)
	@$(call pf_fappend,"#endif /* DEFINES_H */                                                          ", $@)
	@$(call pf_fappend,"/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/", $@)

#================================================================================
# Internal functions
#================================================================================

# Convert a list of src files with absolute paths under BASE_DIR to corresponding
# object files under intermediate directory 
# src_to_obj(list_of_cppfiles)
src_to_obj = $(patsubst $(BASE_DIR)%, $(INTERMEDIATE_DIR)%, $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(1))))

# No default rules, please
.SUFFIX: 

# Rule for compiling cpp files in source tree, ouptut in mirrored intermediate dir
$(INTERMEDIATE_DIR)/%.o : $(BASE_DIR)/%.cpp  $(INCLUDE_DEFINES) $(INCLUDE_VERSION)
	$(MKPATH) $(@D)
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -I$(<D) -o $@ $<

$(INTERMEDIATE_DIR)/%.o : $(BASE_DIR)/%.c $(INCLUDE_DEFINES) $(INCLUDE_VERSION)
	$(MKPATH) $(@D)
	$(CXX) -c $(CFLAGS) $(INCLUDES) -I$(<D) -o $@ $<

#--------------------------------------------------------------------------------
# MongoDB Provider
#
# Build the Provider Library 

STATIC_PROVIDERLIB_SRCFILES = \
	$(PROVIDER_DIR)/MongoDB_Server_Class_Provider.cpp \
	$(PROVIDER_DIR)/MongoDB_Server_Database_Class_Provider.cpp \
	$(PROVIDER_DIR)/MongoDB_Server_Statistics_Class_Provider.cpp

STATIC_PROVIDERLIB_SRCFILES += \
	$(PROVIDER_DIR)/module.cpp \
	$(PROVIDER_DIR)/schema.c \
	$(PROVIDER_DIR)/stubs.cpp

STATIC_PROVIDERLIB_SRCFILES += \
	$(PROVIDER_DIR)/support/MongoAuth.cpp \
	$(PROVIDER_DIR)/support/MongoUtils.cpp \
	$(PROVIDER_DIR)/support/productdependencies.cpp

STATIC_PROVIDERLIB_LOGPOLICY += \
	$(PROVIDER_DIR)/support/logpolicy.cpp

PROVIDER_HEADERS = \
	$(PROVIDER_DIR)/support/MongoAuth.h \
	$(PROVIDER_DIR)/support/MongoUtils.h

STATIC_PROVIDERLIB_OBJFILES = $(call src_to_obj,$(STATIC_PROVIDERLIB_SRCFILES))

$(PROVIDER_LIBRARY): INCLUDES += $(PROVIDER_INCLUDE_FLAGS)
$(PROVIDER_LIBRARY): CFLAGS += $(PROVIDER_COMPILE_FLAGS)
$(PROVIDER_LIBRARY): CXXFLAGS += $(PROVIDER_COMPILE_FLAGS)
$(PROVIDER_LIBRARY): $(STATIC_PROVIDERLIB_OBJFILES) $(STATIC_PROVIDERLIB_LOGPOLICY) $(INCLUDE_DEFINES) $(INCLUDE_VERSION) $(PROVIDER_HEADERS)
	$(MKPATH) $(INTERMEDIATE_DIR)
	$(MKPATH) $(INTERMEDIATE_DIR)
	g++ $(PROVIDER_COMPILE_FLAGS) $(SHARED_FLAGS) $(PROVIDER_INCLUDE_FLAGS) -o $@ $(STATIC_PROVIDERLIB_OBJFILES) $(STATIC_PROVIDERLIB_LOGPOLICY) $(LINK_LIBRARIES)

#--------------------------------------------------------------------------------
# MySQL mycimprovauth executable
#
# Build the mycimprovauth executable (authentication file maintenance)

#STATIC_MYAUTH_SRCFILES = \
#	$(PROVIDER_DIR)/support/logstartup.cpp \
#	$(PROVIDER_DIR)/support/mycnf-paths.cpp \
#	$(PROVIDER_DIR)/support/productdependencies.cpp \
#	$(PROVIDER_DIR)/support/sqlauth.cpp \
#	$(PROVIDER_DIR)/support/sqlbinding.cpp \
#	$(SOURCE_DIR)/myauth/myauth.cpp
#
#STATIC_MYAUTH_HEADERS = \
#	$(PROVIDER_DIR)/support/sqlauth.h
#
#STATIC_MYAUTH_OBJFILES = $(call src_to_obj,$(STATIC_MYAUTH_SRCFILES))
#
#$(MYAUTH_PROG): CFLAGS += $(MYAUTH_COMPILE_FLAGS)
#$(MYAUTH_PROG): CXXFLAGS += $(MYAUTH_COMPILE_FLAGS)
#$(MYAUTH_PROG): $(STATIC_MYAUTH_OBJFILES) $(STATIC_MYAUTH_HEADERS) $(INCLUDE_DEFINES) $(INCLUDE_VERSION)
#	$(MKPATH) $(INTERMEDIATE_DIR)
#	$(MKPATH) $(INTERMEDIATE_DIR)
#	g++ $(MYAUTH_COMPILE_FLAGS) -o $@ $(STATIC_MYAUTH_OBJFILES) $(STATIC_PROVIDERLIB_LOGPOLICY) $(MYAUTH_LINK_LIBRARIES)

#--------------------------------------------------------------------------------
# MySQL OMI_PREEXEC
#
# Build the omi_preexec executable (for PAL logging and state information)

#STATIC_OMI_PREEXEC_SRCFILES = \
#	$(PROVIDER_DIR)/support/logstartup.cpp \
#	$(PROVIDER_DIR)/support/mycnf-paths.cpp \
#	$(PROVIDER_DIR)/support/productdependencies.cpp \
#	$(PROVIDER_DIR)/support/sqlauth.cpp \
#	$(SOURCE_DIR)/omi_preexec/mycnf-scanner.cpp \
#	$(SOURCE_DIR)/omi_preexec/omi-mysql.cpp \
#	$(SOURCE_DIR)/omi_preexec/omi-preexec.cpp
#
#STATIC_OMI_PREEXEC_HEADERS = \
#	$(PROVIDER_DIR)/support/mycnf-paths.h \
#	$(SOURCE_DIR)/omi_preexec/mycnf-scanner.h \
#	$(SOURCE_DIR)/omi_preexec/omi-preexec.h
#
#STATIC_OMI_PREEXEC_OBJFILES = $(call src_to_obj,$(STATIC_OMI_PREEXEC_SRCFILES))
#
#$(OMI_PREEXEC): CFLAGS += $(PREEXEC_COMPILE_FLAGS)
#$(OMI_PREEXEC): CXXFLAGS += $(PREEXEC_COMPILE_FLAGS)
#$(OMI_PREEXEC): $(STATIC_OMI_PREEXEC_OBJFILES) $(STATIC_OMI_PREEXEC_HEADERS) $(INCLUDE_DEFINES) $(INCLUDE_VERSION)
#	$(MKPATH) $(INTERMEDIATE_DIR)
#	$(MKPATH) $(INTERMEDIATE_DIR)
#	g++ $(PREEXEC_COMPILE_FLAGS) -o $@ $(STATIC_OMI_PREEXEC_OBJFILES) $(STATIC_PROVIDERLIB_LOGPOLICY) $(PREEXEC_LINK_LIBRARIES)

#--------------------------------------------------------------------------------
# MySQL Provider Unit Tests
#
# Build and run the Provider Unit Tests

# For now, providertestutils.cpp lives in PAL, but is built in OM.  This creates
# some build issues.  To resolve, create a link to the real file.

$(PROVIDER_TEST_DIR)/providertestutils.cpp: $(PAL_TESTUTILS_DIR)/providertestutils.cpp
# We need to recreate the symlink if the link is older than what it points to.
	$(RM) $(PROVIDER_TEST_DIR)/providers/providertestutils.cpp
	ln -s $(PAL_TESTUTILS_DIR)/providertestutils.cpp $(PROVIDER_TEST_DIR)/providertestutils.cpp

STATIC_PROVIDER_UNITFILES_INCLUDE = \
	$(PROVIDER_TEST_SUPPORT_DIR)/sqlcredentials.h

STATIC_PROVIDER_UNITFILES = \
	$(PROVIDER_TEST_DIR)/auth_test.cpp \
	$(PROVIDER_TEST_DIR)/binding_test.cpp \
	$(PROVIDER_TEST_DIR)/sqlserver_test.cpp \
	$(PROVIDER_TEST_DIR)/sqlstats_test.cpp \
	$(PROVIDER_TEST_DIR)/sqldatabase_test.cpp \
	$(PROVIDER_TEST_DIR)/sqlstoredproc_test.cpp \
	$(PROVIDER_TEST_DIR)/support/testrunnerlogpolicy.cpp \
	$(TEST_DIR)/myauth/myauth_test.cpp \
	$(TEST_DIR)/omi_preexec/config_scanner_test.cpp \
	$(PROVIDER_TEST_DIR)/providertestutils.cpp \
	$(SOURCE_DIR)/omi_preexec/mycnf-scanner.cpp

STATIC_PROVIDER_PAL_UNITFILES = \
	$(PAL_TESTUTILS_DIR)/scxassert_cppunit.cpp \
	$(PAL_TESTUTILS_DIR)/testrunner.cpp

STATIC_PROVIDER_TEST_OBJFILES = $(call src_to_obj,$(STATIC_PROVIDER_UNITFILES))

$(INTERMEDIATE_DIR)/testrunner: INCLUDES += $(PROVIDER_TEST_INCLUDE_FLAGS) -I$(PAL_INCLUDE_DIR) -I$(PAL_TESTUTILS_DIR) -I$(SOURCE_DIR)/omi_preexec
$(INTERMEDIATE_DIR)/testrunner: CFLAGS += $(PROVIDER_COMPILE_FLAGS)
$(INTERMEDIATE_DIR)/testrunner: CXXFLAGS += $(PROVIDER_COMPILE_FLAGS)
$(INTERMEDIATE_DIR)/testrunner : $(STATIC_PROVIDER_UNITFILES_INCLUDE) $(STATIC_PROVIDER_TEST_OBJFILES) $(STATIC_PROVIDERLIB_OBJFILES) $(INCLUDE_DEFINES) $(INCLUDE_VERSION) $(PROVIDER_HEADERS) $(MYAUTH_PROG)
	$(MKPATH) $(INTERMEDIATE_DIR)
	$(MKPATH) $(INTERMEDIATE_DIR)
	g++ $(PROVIDER_COMPILE_FLAGS) $(PROVIDER_TEST_INCLUDE_FLAGS) -o $@ $(STATIC_PROVIDER_PAL_UNITFILES) $(STATIC_PROVIDER_TEST_OBJFILES) $(STATIC_PROVIDERLIB_OBJFILES) $(LINK_LIBRARIES) $(PROVIDER_TEST_LINK_LIBRARIES)

testrun : test

TEST_STATUS:
	@echo "========================= Performing Building provider tests"

TEST_DATA_PREP:
	@echo "========================= Performing Test data preparation"
	cp -R $(TEST_DIR)/omi_preexec/testdata/cnfs $(INTERMEDIATE_DIR)/.

test : TEST_STATUS $(SCXPAL_INTERMEDIATE_DIR) $(INTERMEDIATE_DIR)/testrunner TEST_DATA_PREP
	@echo "========================= Performing MySQL testrun execution"
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(OMI_ROOT)/output/lib; cd $(INTERMEDIATE_DIR); ./testrunner

ifeq ($(OPENSOURCE_DISTRO),0)

#--------------------------------------------------------------------------------
# Build the distribution kit
#
# Build the packages via installbuilder
#
# While the "formal build" only builds ULINUX, we may build something else for DEV purposes.
# Assume we ALWAYS build RPM, but only build DPKG if --enable-ulinux is speified in configure.

ifeq ($(ULINUX),1)

kit : $(TARGET_DIR)/$(OUTPUT_PACKAGE_PREFIX).sh

$(TARGET_DIR)/$(OUTPUT_PACKAGE_PREFIX).sh : $(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).tar
	@echo "========================= Performing Building shell bundle"
	../installer/bundle/create_bundle.sh $(PF)_$(PF_DISTRO) $(INTERMEDIATE_DIR) $(OUTPUT_PACKAGE_PREFIX)
	$(MKPATH) $(TARGET_DIR)
	$(COPY) $(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).sh $(TARGET_DIR)

$(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).tar : \
		$(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).rpm \
		$(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).deb

	# Build the tar file containing both .rpm and .deb packages
	@echo "========================= Performing Building .tar file"
	cd $(INTERMEDIATE_DIR); tar cvf $(OUTPUT_PACKAGE_PREFIX).tar $(OUTPUT_PACKAGE_PREFIX).rpm $(OUTPUT_PACKAGE_PREFIX).deb

$(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).rpm : MYSQLLIB_FULLFILENAME = $(shell ldd $(PROVIDER_LIBRARY) | grep libmysqlclient.so | awk '{print $$3}')
$(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).rpm : MYSQLLIB_FILENAME = $(shell basename $(MYSQLLIB_FULLFILENAME))
$(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).rpm : $(OMI_ROOT)/output $(PROVIDER_LIBRARY) $(MYAUTH_PROG) $(OMI_PREEXEC)
	@echo "========================= Performing Building RPM package"
	$(MKPATH) $(INSTALLER_TMPDIR)
	sudo $(RMDIR) $(STAGING_DIR)
	$(MKPATH) $(INTERMEDIATE_DIR)
	python $(SCXPAL_DIR)/installer/InstallBuilder/installbuilder.py \
		--BASE_DIR=$(BASE_DIR) \
		--TARGET_DIR=$(INTERMEDIATE_DIR) \
		--INTERMEDIATE_DIR=$(INSTALLER_TMPDIR) \
		--STAGING_DIR=$(STAGING_DIR) \
		--BUILD_TYPE=$(BUILD_TYPE) \
		--BUILD_CONFIGURATION=$(BUILD_CONFIGURATION) \
		--PFARCH=$(PF_ARCH) \
		--PFDISTRO=$(PF_DISTRO) \
		--PFMAJOR=$(PF_MAJOR) \
		--PFMINOR=$(PF_MINOR) \
		--VERSION=$(SCX_BUILDVERSION_MAJOR).$(SCX_BUILDVERSION_MINOR).$(SCX_BUILDVERSION_PATCH) \
		--RELEASE=$(SCX_BUILDVERSION_BUILDNR) \
		--MYSQL_BUILD_LIBRARY=$(MYSQLLIB_FILENAME) \
		--DATAFILE_PATH=$(BASE_DIR)/installer/datafiles \
		--OUTPUTFILE=$(OUTPUT_PACKAGE_PREFIX) \
		base_mysql.data linux.data linux_rpm.data

$(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).deb : MYSQLLIB_FULLFILENAME = $(shell ldd $(PROVIDER_LIBRARY) | grep libmysqlclient.so | awk '{print $$3}')
$(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).deb : MYSQLLIB_FILENAME = $(shell basename $(MYSQLLIB_FULLFILENAME))
$(INTERMEDIATE_DIR)/$(OUTPUT_PACKAGE_PREFIX).deb : $(OMI_ROOT)/output $(PROVIDER_LIBRARY) $(MYAUTH_PROG) $(OMI_PREEXEC)
	@echo "========================= Performing Building DPKG package"
	$(MKPATH) $(INSTALLER_TMPDIR)
	sudo $(RMDIR) $(STAGING_DIR)
	$(MKPATH) $(INTERMEDIATE_DIR)
	python $(SCXPAL_DIR)/installer/InstallBuilder/installbuilder.py \
		--BASE_DIR=$(BASE_DIR) \
		--TARGET_DIR=$(INTERMEDIATE_DIR) \
		--INTERMEDIATE_DIR=$(INSTALLER_TMPDIR) \
		--STAGING_DIR=$(STAGING_DIR) \
		--BUILD_TYPE=$(BUILD_TYPE) \
		--BUILD_CONFIGURATION=$(BUILD_CONFIGURATION) \
		--PFARCH=$(PF_ARCH) \
		--PFDISTRO=$(PF_DISTRO) \
		--PFMAJOR=$(PF_MAJOR) \
		--PFMINOR=$(PF_MINOR) \
		--VERSION=$(SCX_BUILDVERSION_MAJOR).$(SCX_BUILDVERSION_MINOR).$(SCX_BUILDVERSION_PATCH) \
		--RELEASE=$(SCX_BUILDVERSION_BUILDNR) \
		--MYSQL_BUILD_LIBRARY=$(MYSQLLIB_FILENAME) \
		$(DPKG_LOCATION) \
		--DATAFILE_PATH=$(BASE_DIR)/installer/datafiles \
		--OUTPUTFILE=$(OUTPUT_PACKAGE_PREFIX) \
		base_mysql.data linux.data linux_dpkg.data

else # ifeq ($(ULINUX),1)

kit : $(OMI_ROOT)/output $(PROVIDER_LIBRARY) $(MYAUTH_PROG) $(OMI_PREEXEC)
	@echo "========================= Performing building package"
	$(MKPATH) $(INSTALLER_TMPDIR)
	sudo $(RMDIR) $(STAGING_DIR)
	python $(SCXPAL_DIR)/installer/InstallBuilder/installbuilder.py \
		--BASE_DIR=$(BASE_DIR) \
		--TARGET_DIR=$(INTERMEDIATE_DIR) \
		--INTERMEDIATE_DIR=$(INSTALLER_TMPDIR) \
		--STAGING_DIR=$(STAGING_DIR) \
		--BUILD_TYPE=$(BUILD_TYPE) \
		--BUILD_CONFIGURATION=$(BUILD_CONFIGURATION) \
		--PFARCH=$(PF_ARCH) \
		--PFDISTRO=$(PF_DISTRO) \
		--PFMAJOR=$(PF_MAJOR) \
		--PFMINOR=$(PF_MINOR) \
		--VERSION=$(SCX_BUILDVERSION_MAJOR).$(SCX_BUILDVERSION_MINOR).$(SCX_BUILDVERSION_PATCH) \
		--RELEASE=$(SCX_BUILDVERSION_BUILDNR) \
		--MYSQL_BUILD_LIBRARY=$(MYSQLLIB_FILENAME) \
		--DATAFILE_PATH=$(BASE_DIR)/installer/datafiles \
		--OUTPUTFILE=$(OUTPUT_PACKAGE_PREFIX) \
		base_mysql.data linux.data linux_rpm.data

endif # ifeq ($(ULINUX),1)

else # ifeq ($(OPENSOURCE_DISTRO),0)

endif # ifeq ($(OPENSOURCE_DISTRO),0)

#
# The following is all for OMI "bootstrap" stuff (allowing omigen and omireg to run)
#

ifeq ($(PERFORM_OMI_MAKEINSTALL),1)

CLASSES = \
	MongoDB_Server \
	MongoDB_Server_Database \
	MongoDB_Server_Statistics

OMI_DIR = $(OMI_ROOT)/output/install_local
OMI_BINDIR = $(OMI_DIR)/bin
OMI_LIBDIR = $(OMI_DIR)/lib
OMIGEN = $(OMI_BINDIR)/omigen

MOF_DIR = $(SOURCE_DIR)/mof

# For these targets to run, configure MUST be run with the --enable-omi-tools qualifier, like this:
#   ./configure --enable-debug --enable-omi-tools

schema_gen :
	# The omigen facility is unhappy if no ~/.omigenrc file exists, so create one for this run
	touch ~/.omigenrc
	$(MKPATH) $(INTERMEDIATE_DIR)/omi
	cd $(INTERMEDIATE_DIR)/omi; $(OMIGEN) $(MOF_DIR)/mongo.mof -d $(PROVIDER_DIR) $(CLASSES) --cpp -I $(OMI_DIR)/share/omischema
	$(RM) ~/.omigenrc

omi_reg :
	$(MKPATH) $(INTERMEDIATE_DIR)/omi
	$(MKPATH) $(OMI_DIR)/etc/omiregister/root-mongo
	export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(OMI_LIBDIR); cd $(INTERMEDIATE_DIR)/omi; $(OMI_BINDIR)/omireg -n root/mongo -o @requestor@ $(PROVIDER_LIBRARY)
	$(COPY) -r $(OMI_DIR)/etc/omiregister/root-mongo $(INTERMEDIATE_DIR)/omi

endif # $(PERFORM_OMI_MAKEINSTALL),1
