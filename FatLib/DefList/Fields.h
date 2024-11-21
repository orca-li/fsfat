#if !defined FAT_SIGNATURE_FIELDS_H
#define FAT_SIGNATURE_FIELDS_H

#include "FatConf.h"
#include "Short/Fields.h"

/**
 * @brief Names
 */

#define _FAT_ITEM_ID_jmpBoot_NAME                   jmpBoot
#define _FAT_ITEM_ID_OEMName_NAME                   OEMName
#define _FAT_ITEM_ID_BytsPerSec_NAME                BytsPerSec
#define _FAT_ITEM_ID_SerPerClus_NAME                SerPerClus
#define _FAT_ITEM_ID_RsvdSecCnt_NAME                RsvdSecCnt
#define _FAT_ITEM_ID_NumFATs_NAME                   NumFATs
#define _FAT_ITEM_ID_RootEntCnt_NAME                RootEntCnt
#define _FAT_ITEM_ID_TotSec16_NAME                  TotSec16
#define _FAT_ITEM_ID_Media_NAME                     Media
#define _FAT_ITEM_ID_FATSz16_NAME                   FATSz16
#define _FAT_ITEM_ID_SecPerTrk_NAME                 SecPerTrk
#define _FAT_ITEM_ID_NumHeads_NAME                  NumHeads
#define _FAT_ITEM_ID_HiddSec_NAME                   HiddSec
#define _FAT_ITEM_ID_TotSec32_NAME                  TotSec32

#if __FS_FAT == __FS_FAT32

#define _FAT_ITEM_ID_FATSz32_NAME                   FATSz32
#define _FAT_ITEM_ID_ExtFlags_NAME                  ExtFlags
#define _FAT_ITEM_ID_FSVer_NAME                     FSVer
#define _FAT_ITEM_ID_RootClus_NAME                  RootClus
#define _FAT_ITEM_ID_FSInfo_NAME                    FSInfo
#define _FAT_ITEM_ID_BkBootSec_NAME                 BkBootSec
#define _FAT_ITEM_ID_Reserved0_NAME                 Reserved0
#define _FAT_ITEM_ID_DrvNum_NAME                    DrvNum

#else

#define _FAT_ITEM_ID_DrvNum_NAME                    DrvNum

#endif

#define _FAT_ITEM_ID_Reserved1_NAME                 Reserved1
#define _FAT_ITEM_ID_BootSig_NAME                   BootSig
#define _FAT_ITEM_ID_VolID_NAME                     VolID
#define _FAT_ITEM_ID_VolLab_NAME                    VolLab
#define _FAT_ITEM_ID_FilSysType_NAME                FilSysType
#define _FAT_ITEM_ID_SetToZero1_NAME                SetToZero1
#define _FAT_ITEM_ID_Signature_word_NAME            Signature_word
#define _FAT_ITEM_ID_SetToZero2_NAME                SetToZero2
#define _FAT_ITEM_ID__NULL_NAME                     _NULL

/**
 * @brief Sizes
 */

#define _FAT_ITEM_ID_jmpBoot_SZ                     (3)
#define _FAT_ITEM_ID_OEMName_SZ                     (8)
#define _FAT_ITEM_ID_BytsPerSec_SZ                  (2)
#define _FAT_ITEM_ID_SerPerClus_SZ                  (1)
#define _FAT_ITEM_ID_RsvdSecCnt_SZ                  (2)
#define _FAT_ITEM_ID_NumFATs_SZ                     (1)
#define _FAT_ITEM_ID_RootEntCnt_SZ                  (2)
#define _FAT_ITEM_ID_TotSec16_SZ                    (2)
#define _FAT_ITEM_ID_Media_SZ                       (1)
#define _FAT_ITEM_ID_FATSz16_SZ                     (2)
#define _FAT_ITEM_ID_SecPerTrk_SZ                   (2)
#define _FAT_ITEM_ID_NumHeads_SZ                    (2)
#define _FAT_ITEM_ID_HiddSec_SZ                     (4)
#define _FAT_ITEM_ID_TotSec32_SZ                    (4)

#if __FS_FAT == __FS_FAT32

#define _FAT_ITEM_ID_FATSz32_SZ                     (4)
#define _FAT_ITEM_ID_ExtFlags_SZ                    (2)
#define _FAT_ITEM_ID_FSVer_SZ                       (2)
#define _FAT_ITEM_ID_RootClus_SZ                    (4)
#define _FAT_ITEM_ID_FSInfo_SZ                      (2)
#define _FAT_ITEM_ID_BkBootSec_SZ                   (2)
#define _FAT_ITEM_ID_Reserved0_SZ                   (12)
#define _FAT_ITEM_ID_DrvNum_SZ                      (1)

#else

#define _FAT_ITEM_ID_DrvNum_SZ                      (1)

#endif

#define _FAT_ITEM_ID_Reserved1_SZ                   (1)
#define _FAT_ITEM_ID_BootSig_SZ                     (1)
#define _FAT_ITEM_ID_VolID_SZ                       (4)
#define _FAT_ITEM_ID_VolLab_SZ                      (11)
#define _FAT_ITEM_ID_FilSysType_SZ                  (8)
#define _FAT_ITEM_ID_SetToZero1_SZ                  (420)
#define _FAT_ITEM_ID_Signature_word_SZ              (2)
#define _FAT_ITEM_ID_SetToZero2_SZ                  (0)
#define _FAT_ITEM_ID__NULL_SZ                       (0)

/**
 * @brief Index
 */

#define _FAT_ITEM_ID_jmpBoot_IDX                    0
#define _FAT_ITEM_ID_OEMName_IDX                    3
#define _FAT_ITEM_ID_BytsPerSec_IDX                 11
#define _FAT_ITEM_ID_SerPerClus_IDX                 13
#define _FAT_ITEM_ID_RsvdSecCnt_IDX                 14
#define _FAT_ITEM_ID_NumFATs_IDX                    16
#define _FAT_ITEM_ID_RootEntCnt_IDX                 17
#define _FAT_ITEM_ID_TotSec16_IDX                   19
#define _FAT_ITEM_ID_Media_IDX                      21
#define _FAT_ITEM_ID_FATSz16_IDX                    22
#define _FAT_ITEM_ID_SecPerTrk_IDX                  24
#define _FAT_ITEM_ID_NumHeads_IDX                   26
#define _FAT_ITEM_ID_HiddSec_IDX                    28
#define _FAT_ITEM_ID_TotSec32_IDX                   32

#if __FS_FAT == __FS_FAT32

#define _FAT_ITEM_ID_FATSz32_IDX                    36
#define _FAT_ITEM_ID_ExtFlags_IDX                   40
#define _FAT_ITEM_ID_FSVer_IDX                      42
#define _FAT_ITEM_ID_RootClus_IDX                   44
#define _FAT_ITEM_ID_FSInfo_IDX                     48
#define _FAT_ITEM_ID_BkBootSec_IDX                  50
#define _FAT_ITEM_ID_Reserved0_IDX                  52

#define _FAT_ITEM_ID_DrvNum_IDX                     64

#define _FAT_ITEM_ID_Reserved1_IDX                  65
#define _FAT_ITEM_ID_BootSig_IDX                    66
#define _FAT_ITEM_ID_VolID_IDX                      67
#define _FAT_ITEM_ID_VolLab_IDX                     71
#define _FAT_ITEM_ID_FilSysType_IDX                 82
#define _FAT_ITEM_ID_SetToZero1_IDX                 90
#define _FAT_ITEM_ID_Signature_word_IDX             510
#define _FAT_ITEM_ID_SetToZero2_IDX                 512
#define _FAT_ITEM_ID__NULL_IDX                      512

#else

#define _FAT_ITEM_ID_DrvNum_IDX                     36

#define _FAT_ITEM_ID_Reserved1_IDX                  37
#define _FAT_ITEM_ID_BootSig_IDX                    38
#define _FAT_ITEM_ID_VolID_IDX                      39
#define _FAT_ITEM_ID_VolLab_IDX                     43
#define _FAT_ITEM_ID_FilSysType_IDX                 54
#define _FAT_ITEM_ID_SetToZero1_IDX                 62
#define _FAT_ITEM_ID_Signature_word_IDX             510
#define _FAT_ITEM_ID_SetToZero2_IDX                 512
#define _FAT_ITEM_ID__NULL_IDX                      512

#endif                  

/**
 * @brief Public
 */

#define FAT_ITEM_ID_jmpBoot_NAME                    _FAT_ITEM_ID_jmpBoot_NAME
#define FAT_ITEM_ID_jmpBoot_SZ                      _FAT_ITEM_ID_jmpBoot_SZ
#define FAT_ITEM_ID_jmpBoot_IDX                     _FAT_ITEM_ID_jmpBoot_IDX

#define FAT_ITEM_ID_OEMName_NAME                    _FAT_ITEM_ID_OEMName_NAME
#define FAT_ITEM_ID_OEMName_SZ                      _FAT_ITEM_ID_OEMName_SZ
#define FAT_ITEM_ID_OEMName_IDX                     _FAT_ITEM_ID_OEMName_IDX

#define FAT_ITEM_ID_BytsPerSec_NAME                 _FAT_ITEM_ID_BytsPerSec_NAME
#define FAT_ITEM_ID_BytsPerSec_SZ                   _FAT_ITEM_ID_BytsPerSec_SZ
#define FAT_ITEM_ID_BytsPerSec_IDX                  _FAT_ITEM_ID_BytsPerSec_IDX

#define FAT_ITEM_ID_SerPerClus_NAME                 _FAT_ITEM_ID_SerPerClus_NAME
#define FAT_ITEM_ID_SerPerClus_SZ                   _FAT_ITEM_ID_SerPerClus_SZ
#define FAT_ITEM_ID_SerPerClus_IDX                  _FAT_ITEM_ID_SerPerClus_IDX

#define FAT_ITEM_ID_RsvdSecCnt_NAME                 _FAT_ITEM_ID_RsvdSecCnt_NAME
#define FAT_ITEM_ID_RsvdSecCnt_SZ                   _FAT_ITEM_ID_RsvdSecCnt_SZ
#define FAT_ITEM_ID_RsvdSecCnt_IDX                  _FAT_ITEM_ID_RsvdSecCnt_IDX

#define FAT_ITEM_ID_NumFATs_NAME                    _FAT_ITEM_ID_NumFATs_NAME
#define FAT_ITEM_ID_NumFATs_SZ                      _FAT_ITEM_ID_NumFATs_SZ
#define FAT_ITEM_ID_NumFATs_IDX                     _FAT_ITEM_ID_NumFATs_IDX

#define FAT_ITEM_ID_RootEntCnt_NAME                 _FAT_ITEM_ID_RootEntCnt_NAME
#define FAT_ITEM_ID_RootEntCnt_SZ                   _FAT_ITEM_ID_RootEntCnt_SZ
#define FAT_ITEM_ID_RootEntCnt_IDX                  _FAT_ITEM_ID_RootEntCnt_IDX

#define FAT_ITEM_ID_TotSec16_NAME                   _FAT_ITEM_ID_TotSec16_NAME
#define FAT_ITEM_ID_TotSec16_SZ                     _FAT_ITEM_ID_TotSec16_SZ
#define FAT_ITEM_ID_TotSec16_IDX                    _FAT_ITEM_ID_TotSec16_IDX

#define FAT_ITEM_ID_Media_NAME                      _FAT_ITEM_ID_Media_NAME
#define FAT_ITEM_ID_Media_SZ                        _FAT_ITEM_ID_Media_SZ
#define FAT_ITEM_ID_Media_IDX                       _FAT_ITEM_ID_Media_IDX

#define FAT_ITEM_ID_FATSz16_NAME                    _FAT_ITEM_ID_FATSz16_NAME
#define FAT_ITEM_ID_FATSz16_SZ                      _FAT_ITEM_ID_FATSz16_SZ
#define FAT_ITEM_ID_FATSz16_IDX                     _FAT_ITEM_ID_FATSz16_IDX

#define FAT_ITEM_ID_SecPerTrk_NAME                  _FAT_ITEM_ID_SecPerTrk_NAME
#define FAT_ITEM_ID_SecPerTrk_SZ                    _FAT_ITEM_ID_SecPerTrk_SZ
#define FAT_ITEM_ID_SecPerTrk_IDX                   _FAT_ITEM_ID_SecPerTrk_IDX

#define FAT_ITEM_ID_NumHeads_NAME                   _FAT_ITEM_ID_NumHeads_NAME
#define FAT_ITEM_ID_NumHeads_SZ                     _FAT_ITEM_ID_NumHeads_SZ
#define FAT_ITEM_ID_NumHeads_IDX                    _FAT_ITEM_ID_NumHeads_IDX

#define FAT_ITEM_ID_HiddSec_NAME                    _FAT_ITEM_ID_HiddSec_NAME
#define FAT_ITEM_ID_HiddSec_SZ                      _FAT_ITEM_ID_HiddSec_SZ
#define FAT_ITEM_ID_HiddSec_IDX                     _FAT_ITEM_ID_HiddSec_IDX

#define FAT_ITEM_ID_TotSec32_NAME                   _FAT_ITEM_ID_TotSec32_NAME
#define FAT_ITEM_ID_TotSec32_SZ                     _FAT_ITEM_ID_TotSec32_SZ
#define FAT_ITEM_ID_TotSec32_IDX                    _FAT_ITEM_ID_TotSec32_IDX

#if __FS_FAT == __FS_FAT32

#define FAT_ITEM_ID_FATSz32_NAME                    _FAT_ITEM_ID_FATSz32_NAME
#define FAT_ITEM_ID_FATSz32_SZ                      _FAT_ITEM_ID_FATSz32_SZ
#define FAT_ITEM_ID_FATSz32_IDX                     _FAT_ITEM_ID_FATSz32_IDX

#define FAT_ITEM_ID_ExtFlags_NAME                   _FAT_ITEM_ID_ExtFlags_NAME
#define FAT_ITEM_ID_ExtFlags_SZ                     _FAT_ITEM_ID_ExtFlags_SZ
#define FAT_ITEM_ID_ExtFlags_IDX                    _FAT_ITEM_ID_ExtFlags_IDX

#define FAT_ITEM_ID_FSVer_NAME                      _FAT_ITEM_ID_FSVer_NAME
#define FAT_ITEM_ID_FSVer_SZ                        _FAT_ITEM_ID_FSVer_SZ
#define FAT_ITEM_ID_FSVer_IDX                       _FAT_ITEM_ID_FSVer_IDX

#define FAT_ITEM_ID_RootClus_NAME                   _FAT_ITEM_ID_RootClus_NAME
#define FAT_ITEM_ID_RootClus_SZ                     _FAT_ITEM_ID_RootClus_SZ
#define FAT_ITEM_ID_RootClus_IDX                    _FAT_ITEM_ID_RootClus_IDX

#define FAT_ITEM_ID_FSInfo_NAME                     _FAT_ITEM_ID_FSInfo_NAME
#define FAT_ITEM_ID_FSInfo_SZ                       _FAT_ITEM_ID_FSInfo_SZ
#define FAT_ITEM_ID_FSInfo_IDX                      _FAT_ITEM_ID_FSInfo_IDX

#define FAT_ITEM_ID_BkBootSec_NAME                  _FAT_ITEM_ID_BkBootSec_NAME
#define FAT_ITEM_ID_BkBootSec_SZ                    _FAT_ITEM_ID_BkBootSec_SZ
#define FAT_ITEM_ID_BkBootSec_IDX                   _FAT_ITEM_ID_BkBootSec_IDX

#define FAT_ITEM_ID_Reserved0_NAME                  _FAT_ITEM_ID_Reserved0_NAME
#define FAT_ITEM_ID_Reserved0_SZ                    _FAT_ITEM_ID_Reserved0_SZ
#define FAT_ITEM_ID_Reserved0_IDX                   _FAT_ITEM_ID_Reserved0_IDX

#endif

#define FAT_ITEM_ID_DrvNum_NAME                     _FAT_ITEM_ID_DrvNum_NAME
#define FAT_ITEM_ID_DrvNum_SZ                       _FAT_ITEM_ID_DrvNum_SZ
#define FAT_ITEM_ID_DrvNum_IDX                      _FAT_ITEM_ID_DrvNum_IDX

#define FAT_ITEM_ID_Reserved1_NAME                  _FAT_ITEM_ID_Reserved1_NAME
#define FAT_ITEM_ID_Reserved1_SZ                    _FAT_ITEM_ID_Reserved1_SZ
#define FAT_ITEM_ID_Reserved1_IDX                   _FAT_ITEM_ID_Reserved1_IDX

#define FAT_ITEM_ID_BootSig_NAME                    _FAT_ITEM_ID_BootSig_NAME
#define FAT_ITEM_ID_BootSig_SZ                      _FAT_ITEM_ID_BootSig_SZ
#define FAT_ITEM_ID_BootSig_IDX                     _FAT_ITEM_ID_BootSig_IDX

#define FAT_ITEM_ID_VolID_NAME                      _FAT_ITEM_ID_VolID_NAME
#define FAT_ITEM_ID_VolID_SZ                        _FAT_ITEM_ID_VolID_SZ
#define FAT_ITEM_ID_VolID_IDX                       _FAT_ITEM_ID_VolID_IDX

#define FAT_ITEM_ID_VolLab_NAME                     _FAT_ITEM_ID_VolLab_NAME
#define FAT_ITEM_ID_VolLab_SZ                       _FAT_ITEM_ID_VolLab_SZ
#define FAT_ITEM_ID_VolLab_IDX                      _FAT_ITEM_ID_VolLab_IDX

#define FAT_ITEM_ID_FilSysType_NAME                 _FAT_ITEM_ID_FilSysType_NAME
#define FAT_ITEM_ID_FilSysType_SZ                   _FAT_ITEM_ID_FilSysType_SZ
#define FAT_ITEM_ID_FilSysType_IDX                  _FAT_ITEM_ID_FilSysType_IDX

#define FAT_ITEM_ID_SetToZero1_NAME                 _FAT_ITEM_ID_SetToZero1_NAME
#define FAT_ITEM_ID_SetToZero1_SZ                   _FAT_ITEM_ID_SetToZero1_SZ
#define FAT_ITEM_ID_SetToZero1_IDX                  _FAT_ITEM_ID_SetToZero1_IDX

#define FAT_ITEM_ID_Signature_word_NAME             _FAT_ITEM_ID_Signature_word_NAME
#define FAT_ITEM_ID_Signature_word_SZ               _FAT_ITEM_ID_Signature_word_SZ
#define FAT_ITEM_ID_Signature_word_IDX              _FAT_ITEM_ID_Signature_word_IDX

#define FAT_ITEM_ID_SetToZero2_NAME                 _FAT_ITEM_ID_SetToZero2_NAME
#define FAT_ITEM_ID_SetToZero2_SZ                   _FAT_ITEM_ID_SetToZero2_SZ
#define FAT_ITEM_ID_SetToZero2_IDX                  _FAT_ITEM_ID_SetToZero2_IDX

#define FAT_ITEM_ID__NULL_NAME                      _FAT_ITEM_ID__NULL_NAME
#define FAT_ITEM_ID__NULL_SZ                        _FAT_ITEM_ID__NULL_SZ
#define FAT_ITEM_ID__NULL_IDX                       _FAT_ITEM_ID__NULL_IDX

#endif /* FAT_SIGNATURE_FIELDS_H */