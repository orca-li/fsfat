#if !defined FAT_DEFINES_H
#define FAT_DEFINES_H

#include "FatConfig.h"

#define IS_FS_FAT32 1
/* API */
typedef struct XFAT_FIELD
{
    unsigned char * const field;
    const unsigned char size;
    const unsigned char offset;
    unsigned char mail;
} field_ft;

#if IS_FS_FATX == IS_FS_FAT12 || IS_FS_FATX == IS_FS_FAT16 || IS_FS_FATX == IS_FS_FAT32

typedef struct XFAT_BOOT_SECTOR 
{
    field_ft jmpBoot;
    field_ft OEMName;

    field_ft _NULL_;
} boot_start_ft;

typedef struct XFAT_BIOS_PARAMETERS_BOOT
{
    field_ft BytsPerSec;
    field_ft SerPerClus;
    field_ft RsvdSecCnt;
    field_ft NumFATs;
    field_ft RootEntCnt;
    field_ft TotSec16;
    field_ft Media;
    field_ft FATSz16;
    field_ft SecPerTrk;
    field_ft NumHeads;
    field_ft HiddSec;
    field_ft TotSec32;

#if IS_FS_FATX == IS_FS_FAT32
    field_ft FATSz32;
    field_ft ExtFlags;
    field_ft FSVer;
    field_ft RootClus;
    field_ft FSInfo;
    field_ft BkBootSec;
    field_ft Reserved;
#endif

    field_ft DrvNum;
    field_ft Reserved1;
    field_ft BootSig;
    field_ft VollD;
    field_ft VolLab;
    field_ft FilSysType;
    field_ft SetToZero1;
    field_ft Signature_word;
    field_ft SetToZero2;

    field_ft _NULL_;
} biospb_ft;

#else
#error "Unknown FAT SYSTEM"
#endif

typedef struct XFAT_FILE_SYSTEM_INFO
{
    field_ft LeadSeg;
    field_ft Reserved1;
    field_ft StrucSig;
    field_ft FreeCount;
    field_ft Nxt_Free;
    field_ft Reserved2;
    field_ft TrailSig;

    field_ft _NULL_;
} fsinfo_ft;

typedef struct XFAT_DIRECTORY_STRUCTURE
{
    field_ft Name;
    field_ft Attr;
    field_ft NTRes;
    field_ft CrtTimeTenth;
    field_ft CrtTime;
    field_ft CrtDate;
    field_ft LstAccDate;
    field_ft FstClusHI;
    field_ft WrtTime;
    field_ft WrtDate;
    field_ft FstClusLO;
    field_ft FileSize;

    field_ft _NULL_;
} dir_ft;

typedef struct XFAT_LONG_FILE_NAME_IMPLEMENTATION
{
    field_ft Ord;
    field_ft Name1;
    field_ft Attr;
    field_ft Type;
    field_ft Chksum;
    field_ft Name2;
    field_ft FstClusLO;
    field_ft Name3;

    field_ft _NULL_;
} ldir_ft;

#endif /* FAT_DEFINES_H */