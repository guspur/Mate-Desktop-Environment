orbcoreincludedir =$(includedir)/matecorba-2.0/matecorba/orb-core

orbcoreinclude_HEADERS =		\
	corba-environment-type.h	\
	corba-nvlist.h			\
	corba-object-type.h		\
	corba-orb-type.h		\
	corba-orb.h			\
	corba-pobj.h			\
	corba-typecode-type.h		\
	orb-core.h			\
	orb-types.h			\
	matecorba-object.h			\
	matecorba-small.h			\
	corba-defs.h			\
	corba-context.h			\
	corba-context-type.h		\
	iop-defs.h			\
	corba-object.h			\
	corba-policy-type.h		\
	corba-string.h			\
	corba-environment.h		\
	corba-any.h			\
	orb-core-types.h		\
	corba-typecode.h		\
	allocators.h			\
	corba-any-type.h		\
	matecorba-interface.h

BUILT_SOURCES = corba-defs.h iop-defs.h matecorba-interface.h

IDL_FLAGS_NO_DEFS = -I$(top_srcdir)/src/idl/CORBA_PIDL	\
	-I$(top_srcdir)/src/idl/CORBA			\
	-I$(top_srcdir)/src/idl/interop			\
	-I$(top_srcdir)/src/orb/orb-core		\
	--noskels --nodefskels --nostubs --noidata	\
	--nocommon					\
        --showcpperrors
IDL_FLAGS = $(IDL_FLAGS_NO_DEFS)		\
	 --define=Object=OObject		\
	--define=TypeCode=TTypeCode
IDL_FILES=corba-defs.idl iop-defs.idl matecorba-interface.idl
IDL_DIR=$(top_srcdir)/src/orb/orb-core/

include $(top_srcdir)/Makefile.shared

matecorba-interface.h: $(top_srcdir)/src/orb/orb-core/matecorba-interface.idl $(IDL_COMPILER)
	-(rm -f matecorba-interface.h || true ) > /dev/null
	$(IDL_COMPILER) $(IDL_FLAGS_NO_DEFS) --deps .deps/matecorba-interface.idl.P $<


CLEANFILES=$(BUILT_SOURCES)
