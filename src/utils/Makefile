#
#  utilfct library makefile
#

TOPDIR   = ..
INCDIR   = $(TOPDIR)\include;.
TARGET   = utilfct$(LBO)

!include $(TOPDIR)\config\makerules

OBJECTS = utilfct$(CO) utilfct_listbox$(CO) utilfct_menu$(CO) utilfct_notebook$(CO)
OBJECTS = $(OBJECTS) utilfct_dlg$(CO) utilfct_pm_misc$(CO) utilfct_thread$(CO) utilfct_slider$(CO)
OBJECTS = $(OBJECTS) fileutil$(CO)
OBJECTS = $(OBJECTS) errorstr$(CO) rel2abs$(CO) abs2rel$(CO) inimacro$(CO)
OBJECTS = $(OBJECTS) charset$(CO) wildcards$(CO) queue$(CO) strlcpy$(CO) strchomp$(CO)
OBJECTS = $(OBJECTS) strlcat$(CO) snprintf$(CO) strnchr$(CO) strnlen$(CO)
OBJECTS = $(OBJECTS) strutils$(CO) strptime$(CO)
OBJECTS = $(OBJECTS) eautils$(CO) eadecode$(CO)
OBJECTS = $(OBJECTS) memcmpcpy$(CO) vdelegate$(CO) interlocked$(CO) debuglog$(CO)
STDLIBS = $(LIBS_UNI)

utilfct$(LBO): $(OBJECTS)
	if exist $@ del $@
	$(LB) $@ $(OBJECTS) $(LBENDL)

charset.exe:	charset.obj
	$(CL) $(LFLAGS) $(LFLAGS_OUT)$@ $(LOBJ_PREFX)$(OBJECTS) $(LIBS) $(STDLIBS)$(LOBJ_SUFFX) $(LDEF_PREFX)$(DEF)
	
clean: $(MDUMMY)
	-@del utilfct$(LBO) $(OBJECTS) 2> nul

abs2rel.c:	fileutil.h
fileutil.h:	..\include\config.h
..\include\config.h:	..\include\config_gcc.h ..\include\config_wcc.h ..\include\config_icc_36.h ..\include\config_icc_30.h
charset.c:	charset.h strutils.h debuglog.h utilfct.h
debuglog.h:	.\errorstr.h
utilfct.h:	..\include\config.h .\errorstr.h .\minmax.h .\strutils.h
debuglog.c:	debuglog.h snprintf.h strutils.h
eautils.c:	debuglog.h
errorstr.c:	strutils.h snprintf.h
fileutil.c:	fileutil.h strutils.h minmax.h
memcmpcpy.c:	strutils.h
pcmfloat2int.c:	pcmconvert.h utilfct.h debuglog.h
pcmconvert.h:	..\include\format.h
..\include\format.h:	..\include\plugin.h
..\include\plugin.h:	..\include\config.h .\cpp\xstring.h
.\cpp\xstring.h:	.\cpp\smartptr.h
.\cpp\smartptr.h:	..\include\config.h .\cpp\cpputil.h .\cpp\mutex.h .\debuglog.h
.\cpp\mutex.h:	..\include\config.h .\interlocked.h .\debuglog.h
.\interlocked.h:	..\include\config.h
.\debuglog.h:	.\errorstr.h
pcmfloat2int_merge.c:	pcmconvert.h utilfct.h debuglog.h
pcmint2float.c:	pcmconvert.h .\debuglog.h
pcmint2float_extract.c:	pcmconvert.h .\debuglog.h
queue.c:	queue.h
rel2abs.c:	fileutil.h
strchomp.c:	strutils.h
strnchr.c:	strutils.h
strnlen.c:	strutils.h
utilfct.c:	utilfct.h debuglog.h
utilfct_listbox.c:	utilfct.h debuglog.h
utilfct_menu.c:	utilfct.h debuglog.h
utilfct_notebook.c:	utilfct.h debuglog.h
utilfct_pm_misc.c:	utilfct.h debuglog.h
utilfct_slider.c:	utilfct.h debuglog.h
utilfct_thread.c:	utilfct.h debuglog.h
vdelegate.c:	vdelegate.h
vdelegate.h:	..\include\config.h
wildcards.c:	wildcards.h .\debuglog.h
inimacro.c:	inimacro.h fileutil.h utilfct.h debuglog.h
inimacro.h:	..\include\config.h
strutils.c:	strutils.h
utilfct_dlg.c:	utilfct.h debuglog.h
interlocked.c:	interlocked.h
interlocked.h:	..\include\config.h
eadecode.c:	strutils.h debuglog.h
strptime.c:	strutils.h
