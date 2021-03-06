# New ports collection makefile for:	lazarus
# Date Created:				2006-02-09
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD: ports/editors/lazarus/Makefile,v 1.15 2007/09/18 07:12:58 acm Exp $
#

PORTNAME=	lazarus
PORTVERSION=	0.9.24
PORTREVISION=	3
CATEGORIES=	editors devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/-0/}
DIST_SUBDIR=	freepascal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A portable Delphi-like IDE for the FreePascal compiler

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils

ONLY_FOR_ARCHS=	i386

USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	#

MAKE_ENV=	OPT="-Sgic -Fu${UNITSDIR}/* -Fl${LOCALBASE}/lib -Fl${X11BASE}/lib" LCL_PLATFORM=${LCL_PLATFORM}
MAN1=		lazbuild.1
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PORTNAME}

BUILDNAME=	${ARCH}-freebsd
FPC_MINVER=	2.2.0
UNITSDIR=	${LOCALBASE}/lib/fpc/${FPC_MINVER}/units/${BUILDNAME}
BASE_UNITS=	GDBINT GRAPH IBASE LIBASYNC HASH HTTPD MYSQL NETDB ODBC ORACLE \
		PASJPEG PASZLIB PTHREADS POSTGRES REGEXPR SQLITE
ALL_UNITS=	${BASE_UNITS} BFD CAIRO FCL-BASE FCL-DB FCL-FPCUNIT FCL-IMAGE \
		FCL-NET FCL-PASSRC FCL-REGISTRY FCL-WEB FCL-XML FFTW FPMKUNIT \
		FORMS FPGTK FV GCONF GDBM GGI GNOME GTK GTK2 IMLIB LIBCURL \
		LIBGD LIBPNG NCURSES OPENGL OPENSSL PCAP SVGALIB SYSLOG TCL \
		UNZIP UTMP X11 ZLIB ZVT

# Base units
GDBINT_UNIT=	devel/fpc-gdbint
GRAPH_UNIT=	graphics/fpc-graph
IBASE_UNIT=	databases/fpc-ibase
LIBASYNC_UNIT=	net/fpc-libasync
HASH_UNIT=	security/fpc-hash
HTTPD_UNIT=	www/fpc-httpd
MYSQL_UNIT=	databases/fpc-mysql
NETDB_UNIT=	net/fpc-netdb
ODBC_UNIT=	databases/fpc-odbc
ORACLE_UNIT=	databases/fpc-oracle
PASJPEG_UNIT=	graphics/fpc-pasjpeg
PASZLIB_UNIT=	archivers/fpc-paszlib
PTHREADS_UNIT=	devel/fpc-pthreads
POSTGRES_UNIT=	databases/fpc-postgres
REGEXPR_UNIT=	devel/fpc-regexpr
SQLITE_UNIT=	databases/fpc-sqlite

# Extra units
BFD_UNIT=	devel/fpc-bfd
CAIRO_UNIT=	graphics/fpc-cairo
FCL_BASE_UNIT=	devel/fpc-fcl-base
FCL_DB_UNIT=	devel/fpc-fcl-db
FCL_FPCUNIT_UNIT=	devel/fpc-fcl-fpcunit
FCL_IMAGE_UNIT=	devel/fpc-fcl-image
FCL_NET_UNIT=	devel/fpc-fcl-net
FCL_PASSRC_UNIT=	devel/fpc-fcl-passrc
FCL_REGISTRY_UNIT=	devel/fpc-fcl-registry
FCL_WEB_UNIT=	devel/fpc-fcl-web
FCL_XML_UNIT=	devel/fpc-fcl-xml
FFTW_UNIT=	math/fpc-fftw
FPMKUNIT_UNIT=	devel/fpc-fpmkunit
FORMS_UNIT=	x11-toolkits/fpc-forms
FPGTK_UNIT=	graphics/fpc-fpgtk
FV_UNIT=	devel/fpc-fv
GCONF_UNIT=	devel/fpc-gconf
GDBM_UNIT=	databases/fpc-gdbm
GGI_UNIT=	graphics/fpc-ggi
GNOME_UNIT=	x11-toolkits/fpc-gnome
GTK_UNIT=	x11-toolkits/fpc-gtk
GTK2_UNIT=	x11-toolkits/fpc-gtk2
HTTPD_UNIT=	www/fpc-httpd
IMLIB_UNIT=	graphics/fpc-imlib
LIBCURL_UNIT=	ftp/fpc-libcurl
LIBGD_UNIT=	graphics/fpc-libgd
LIBPNG_UNIT=	graphics/fpc-libpng
NCURSES_UNIT=	graphics/fpc-ncurses
OPENGL_UNIT=	graphics/fpc-opengl
OPENSSL_UNIT=	security/fpc-openssl
PCAP_UNIT=	net/fpc-pcap
SVGALIB_UNIT=	graphics/fpc-svgalib
SYSLOG_UNIT=	sysutils/fpc-syslog
TCL_UNIT=	lang/fpc-tcl
UNZIP_UNIT=	archivers/fpc-unzip
UTMP_UNIT=	sysutils/fpc-utmp
X11_UNIT=	x11/fpc-x11
ZLIB_UNIT=	devel/fpc-zlib
ZVT_UNIT=	x11-toolkits/fpc-zvt

OPTIONS=	GTK2	"Use gtk20 interface instead of gtk12"	off \
		BIGIDE	"Compile additional components"	off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2)
USE_GNOME=	gtk20
LCL_PLATFORM=	gtk2
.else
USE_GNOME=	gtk12 gdkpixbuf
LCL_PLATFORM=	gtk
.endif

.if defined(WITH_BIGIDE)
LAZARUS_TARGET=	bigide lazbuild
.endif

.for OPT in ${ALL_UNITS}
BUILD_DEPENDS+=	${UNITSDIR}/${OPT:L:S/httpd/httpd-1.3/}/Package.fpc:${PORTSDIR}/${${OPT:S/-/_/}_UNIT}
.endfor

post-depends:
.if exists(${LOCALBASE}/bin/fpc)
FPC_VER!=	${LOCALBASE}/bin/fpc -i -v | ${SED} -n -e 's/^Free Pascal Compiler version //' -e '1p'
FPC_DIR=	${LOCALBASE}/lib/fpc/${FPC_VER}
FPC_REQVER!=	${ECHO_CMD} $$(expr ${FPC_VER:C/^[^\.]*\.//} \>= ${FPC_MINVER:C/^[^\.]*\.//})

.if (${FPC_REQVER} != 1)
IGNORE=	requires fpc ${FPC_MINVER} or above. Please upgrade
.endif
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/man1
	@${MV} ${WRKSRC}/install/man/man1/lazbuild.1 ${WRKDIR}/man1
	@${MV} ${WRKSRC}/examples ${WRKDIR}/examples
	@${MV} ${WRKSRC}/docs ${WRKDIR}/docs

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/${MAKEFILE}

do-build:
	@cd ${WRKSRC} && \
		${GMAKE} ${MAKE_ENV} ${LAZARUS_TARGET}

post-build:
	@cd ${WRKSRC} && \
		${RM} -Rf COPYING* README* debian localize.bat test *.orig *.bak

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/lazarus-wrapper
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/lazarus-wrapper
	@${ECHO} "exec ./startlazarus" >> ${WRKDIR}/lazarus-wrapper

	@${RM} -f ${PLIST}

.	for FILE in bin/lazarus bin/lazbuild
		@${ECHO_CMD} ${FILE} >> ${PLIST}
.	endfor

.if !defined(NOPORTDOCS)
	@${ECHO_CMD} "%%DATADIR%%/docs" >> ${PLIST}
	@cd ${WRKDIR}/docs && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DOCSDIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DOCSDIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DOCSDIR%%" >> ${PLIST}
.endif

.if !defined(NOPORTEXAMPLES)
	@${ECHO_CMD} "%%DATADIR%%/examples" >> ${PLIST}
	@cd ${WRKDIR}/examples && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%EXAMPLESDIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%EXAMPLESDIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%EXAMPLESDIR%%" >> ${PLIST}
.endif

	@cd ${WRKSRC} && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
.for DIRE in components converter debugger designer doceditor ide images install languages lcl lazarus.app \
	packager tools units
		@${MKDIR} ${DATADIR}/${DIRE}
		@cd ${WRKSRC}/${DIRE} && \
			${FIND} * -type d -exec ${MKDIR} "${DATADIR}/${DIRE}/{}" \; && \
				${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/${DIRE}/{}" \;
.endfor

.for FILE in lazarus startlazarus lazbuild
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${DATADIR}
.endfor

.if !defined(NOPORTDOCS)
	@cd ${WRKDIR}/docs && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	@${LN} -s ${DOCSDIR} ${DATADIR}/docs
.endif

.if !defined(NOPORTEXAMPLES)
	@cd ${WRKDIR}/examples && \
		${FIND} * -type d -exec ${MKDIR} "${EXAMPLESDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;
	@${LN} -s ${EXAMPLESDIR} ${DATADIR}/examples
.endif

	${INSTALL_SCRIPT} ${WRKSRC}/localize.sh ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/lazarus-wrapper ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA}	${WRKSRC}/Makefile* ${DATADIR}
	${INSTALL_MAN} ${WRKDIR}/man1/${MAN1} ${MAN1PREFIX}/man/man1
	${LN} -s ${DATADIR}/lazbuild ${PREFIX}/bin/lazbuild

.include <bsd.port.post.mk>
