#if !defined FAT_DEFINES_STDTYPES_H
#define FAT_DEFINES_STDTYPES_H

#define fatNULL             ((void *)0UL)

#define fatFALSE            (0UL)
#define fatTRUE             (1UL)
#define fatOK               (fatTRUE)
#define fatFAIL             (fatFALSE)

typedef char   fatINT8;
typedef short  fatINT16;
typedef int    fatINT32;
typedef long   fatINT64;

typedef unsigned char   fatUINT8;
typedef unsigned short  fatUINT16;
typedef unsigned int    fatUINT32;
typedef unsigned long   fatUINT64;

typedef fatUINT8 fatBOOLEAN;

#endif /* FAT_DEFINES_STDTYPES_H */