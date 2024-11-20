# AUTOMAKE

## 1. Setup
```bash
sudo pacman -S automake autoconf
touch configure.ac
touch Makefile.am
```

## 2. Configure
### 2.1. Autoconf
vim configure.ac
```bash
AC_INIT([orcali], [1.0], [krylov.yar.igo@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
```

### 2.2 Automake
vim Makefile.am
```bash
AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = fsfat

fsfat_SOURCES = \
	main.c \
	FatIfc/Src/FatApi.c \
	FatLibIfc/Src/LocCnt.c \
	FatTst/Src/FatTestLib.c

fsfat_CFLAGS = \
	-I$(top_srcdir)/fsfat.h \
	-I$(top_srcdir)/FatIfc/Inc \
	-I$(top_srcdir)/FatLibIfc/Inc \
	-I$(top_srcdir)/FatTst/Inc

include_HEADERS = fsfat.h
```

## 3. Build
```bash
aclocal
autoconf
automake --add-missing
./configure
```

## 4. Make
```bash
make
```