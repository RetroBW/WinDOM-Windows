# Microsoft Visual C++ generated build script - Do not modify

PROJ = WINDOM
DEBUG = 0
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = /d_DEBUG
R_RCDEFINES = /dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = D:\C_WORK\WINDOM\
USEMFC = 1
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = /YcSTDAFX.H
CUSEPCHFLAG = 
CPPUSEPCHFLAG = /YuSTDAFX.H
FIRSTC =             
FIRSTCPP = STDAFX.CPP  
RC = rc
CFLAGS_D_WEXE = /nologo /G2 /W3 /Zi /AM /Od /D "_DEBUG" /FR /GA /Fd"WINDOM.PDB"
CFLAGS_R_WEXE = /nologo /Gs /G2 /W3 /AM /O1 /D "NDEBUG" /FR /GA
LFLAGS_D_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE /CO  
LFLAGS_R_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE  
LIBS_D_WEXE = mafxcwd oldnames libw mlibcew ctl3d commdlg.lib mmsystem.lib shell.lib 
LIBS_R_WEXE = mafxcw oldnames libw mlibcew ctl3d commdlg.lib mmsystem.lib shell.lib 
RCFLAGS = /nologo /z
RESFLAGS = /nologo /t
RUNFLAGS = 
DEFFILE = WINDOM.DEF
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WEXE)
LFLAGS = $(LFLAGS_D_WEXE)
LIBS = $(LIBS_D_WEXE)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WEXE)
LFLAGS = $(LFLAGS_R_WEXE)
LIBS = $(LIBS_R_WEXE)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = STDAFX.SBR \
		WINDOM.SBR \
		MAINFRM.SBR \
		WINDODOC.SBR \
		WINDOVW.SBR \
		DOM.SBR \
		MATRIX.SBR \
		BORDER.SBR \
		NAME.SBR \
		SCORESDL.SBR


WINDOM_RCDEP = d:\c_work\windom\res\windom.ico \
	d:\c_work\windom\res\windom.rc2


STDAFX_DEP = d:\c_work\windom\stdafx.h


WINDOM_DEP = d:\c_work\windom\stdafx.h \
	d:\c_work\windom\windom.h \
	c:\msvc\mfc\include\ctl3d.h \
	d:\c_work\windom\mainfrm.h \
	d:\c_work\windom\windodoc.h \
	d:\c_work\windom\windovw.h \
	d:\c_work\windom\dom.h \
	d:\c_work\windom\matrix.h \
	d:\c_work\windom\border.h \
	d:\c_work\windom\register.h \
	d:\c_work\windom\name.h \
	d:\c_work\windom\scoresdl.h


MAINFRM_DEP = d:\c_work\windom\stdafx.h \
	d:\c_work\windom\windom.h \
	c:\msvc\mfc\include\ctl3d.h \
	d:\c_work\windom\mainfrm.h


WINDODOC_DEP = d:\c_work\windom\stdafx.h \
	d:\c_work\windom\windom.h \
	d:\c_work\windom\windodoc.h


WINDOVW_DEP = d:\c_work\windom\stdafx.h \
	d:\c_work\windom\windom.h \
	d:\c_work\windom\windodoc.h \
	d:\c_work\windom\windovw.h \
	d:\c_work\windom\dom.h \
	d:\c_work\windom\matrix.h \
	d:\c_work\windom\border.h \
	d:\c_work\windom\register.h \
	d:\c_work\windom\name.h \
	d:\c_work\windom\scoresdl.h


DOM_DEP = d:\c_work\windom\stdafx.h \
	d:\c_work\windom\offset.h \
	d:\c_work\windom\dom.h


MATRIX_DEP = d:\c_work\windom\stdafx.h \
	d:\c_work\windom\matrix.h \
	d:\c_work\windom\offset.h


BORDER_DEP = d:\c_work\windom\stdafx.h \
	d:\c_work\windom\border.h \
	d:\c_work\windom\register.h \
	d:\c_work\windom\offset.h


NAME_DEP = d:\c_work\windom\stdafx.h \
	d:\c_work\windom\windom.h \
	c:\msvc\mfc\include\ctl3d.h \
	d:\c_work\windom\name.h


SCORESDL_DEP = d:\c_work\windom\stdafx.h \
	d:\c_work\windom\windom.h \
	c:\msvc\mfc\include\ctl3d.h \
	d:\c_work\windom\scoresdl.h


all:	$(PROJ).EXE $(PROJ).BSC

WINDOM.RES:	WINDOM.RC $(WINDOM_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r WINDOM.RC

STDAFX.OBJ:	STDAFX.CPP $(STDAFX_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c STDAFX.CPP

WINDOM.OBJ:	WINDOM.CPP $(WINDOM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c WINDOM.CPP

MAINFRM.OBJ:	MAINFRM.CPP $(MAINFRM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c MAINFRM.CPP

WINDODOC.OBJ:	WINDODOC.CPP $(WINDODOC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c WINDODOC.CPP

WINDOVW.OBJ:	WINDOVW.CPP $(WINDOVW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c WINDOVW.CPP

DOM.OBJ:	DOM.CPP $(DOM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DOM.CPP

MATRIX.OBJ:	MATRIX.CPP $(MATRIX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c MATRIX.CPP

BORDER.OBJ:	BORDER.CPP $(BORDER_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c BORDER.CPP

NAME.OBJ:	NAME.CPP $(NAME_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c NAME.CPP

SCORESDL.OBJ:	SCORESDL.CPP $(SCORESDL_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c SCORESDL.CPP


$(PROJ).EXE::	WINDOM.RES

$(PROJ).EXE::	STDAFX.OBJ WINDOM.OBJ MAINFRM.OBJ WINDODOC.OBJ WINDOVW.OBJ DOM.OBJ \
	MATRIX.OBJ BORDER.OBJ NAME.OBJ SCORESDL.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
STDAFX.OBJ +
WINDOM.OBJ +
MAINFRM.OBJ +
WINDODOC.OBJ +
WINDOVW.OBJ +
DOM.OBJ +
MATRIX.OBJ +
BORDER.OBJ +
NAME.OBJ +
SCORESDL.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
c:\msvc\lib\+
c:\msvc\mfc\lib\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) WINDOM.RES $@
	@copy $(PROJ).CRF MSVC.BND

$(PROJ).EXE::	WINDOM.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) WINDOM.RES $@

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
