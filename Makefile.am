AUTOMAKE_OPTIONS = foreign subdir-objects

bin_PROGRAMS = fsfat

fsfat_SOURCES = \
	main.c \
	FatIfc/Src/FatApi.c \
	FatLibIfc/Src/LocCnt.c \
	FatTst/Src/FatTestLib.c

fsfat_CFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/FatIfc/Inc \
	-I$(top_srcdir)/FatLibIfc/Inc \
	-I$(top_srcdir)/FatTst/Inc \
    -I$(top_srcdir)/FatLib

include_HEADERS = fsfat.h