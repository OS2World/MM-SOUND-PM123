#
#  skinutil.exe makefile
#

TOPDIR   = ..
INCDIR   = $(TOPDIR)\include;$(TOPDIR)\utils;$(TOPDIR)\gbm123;$(TOPDIR)\pm123
TARGET   = skinutil.exe

!include $(TOPDIR)\config\makerules

OBJECTS  = skinutil$(CO)
DEF      = skinutil$(LDEF_SUFFX)
LIBS     = $(TOPDIR)\gbm123\libgbm$(LBO) $(TOPDIR)\utils\utilfct$(LBO)

skinutil.exe: $(OBJECTS) $(DEF) $(LIBS)
	$(CL) $(LFLAGS) $(LFLAGS_IO) $(LFLAGS_OUT)$@ $(LOBJ_PREFX)$(OBJECTS)$(LOBJ_SUFFX) $(LLIB_PREFX)$(LIBS)$(LLIB_SUFFX) $(LDEF_PREFX)$(DEF)
	$(POSTLINKCMD)

clean:  $(MDUMMY)
	-@del skinutil.exe $(OBJECTS) 2> nul

skinutil.c:	..\gbm123\gbm.h ..\gbm123\gbmrect.h ..\utils\utilfct.h ..\pm123\gui\skin.h ..\pm123\copyright.h
..\gbm123\gbm.h:	..\include\config.h
..\include\config.h:	..\include\config_gcc.h ..\include\config_wcc.h ..\include\config_icc_36.h ..\include\config_icc_30.h
..\utils\utilfct.h:	..\include\config.h ..\utils\errorstr.h ..\utils\minmax.h ..\utils\strutils.h
