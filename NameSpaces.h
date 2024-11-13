#if !defined FAT_NAMESPACE_H
#define FAT_NAMESPACE_H

/**
 * @brief API tag
 */
#define FSFAT_API
#define FSFAT_TEST

#define IN
#define OUT
#define FSFAT_INTERNAL

#define UNI_SIZEOF(_uni, _type) (sizeof(_uni) / sizeof(_type))

#define VOID void
#define UINT8 unsigned char
#define UINT16 unsigned short
#define UINT32 unsigned int

#define CONST const
#define STATIC static

#define FAT_FIELD field_ft
#define FAT_BOOT_START boot_start_ft
#define FAT_BPB biospb_ft
#define FAT_FS_INFO fsinfo_ft
#define FAT_STATUS UINT8
#define FAT_FILE UINT8 *

#define BASE_FAT12 12
#define BASE_FAT16 16
#define BASE_FAT32 32

#define VOLUME_SIGNATURE_SZ 512

#define RETURN(_what, ...) RETURN_ ## _what (__VA_ARGS__)
#define RETURN_STATUS(_status) RETURN_STATUS_ ## _status
#define RETURN_STATUS_OK                0x00
#define RETURN_STATUS_UNK_FAT_BASE      0x01
#define RETURN_STATUS_NOT_IMPLEMENTED   0x02
#define RETURN_FILE(_file) RETURN_FILE_ ## _file
#define RETURN_FILE_NULL

#define INTERNAL_FAT_SIGNATURE_NAME FatBuffer

#define INTERNAL_STRUCT_ID_FIELD(_name, _index, _size, _offset) \
    ._name = { \
        .field = &INTERNAL_FAT_SIGNATURE_NAME[_index], \
        .size = _size, \
        .offset = _offset, \
    }

#define STRUCT_ID_FIELD(_field) \
    INTERNAL_STRUCT_ID_FIELD( \
        STRUCT_ID_ ## _field ## _NAME, \
        STRUCT_ID_ ## _field ## _IDX, \
        STRUCT_ID_ ## _field ## _SZ, \
        STRUCT_ID_ ## _field ## _OFFSET \
    )

#define STRUCT_ID_FATX_BEGIN        (0)
#define STRUCT_ID_FATX_SZ           (0)
#define STRUCT_ID_FATX_OFFSET       (0)

#define STRUCT_ID_JMPBOOT_NAME      jmpBoot
#define STRUCT_ID_JMPBOOT_IDX       (STRUCT_ID_FATX_BEGIN)
#define STRUCT_ID_JMPBOOT_SZ        (3)
#define STRUCT_ID_JMPBOOT_OFFSET    (STRUCT_ID_JMPBOOT_IDX + STRUCT_ID_JMPBOOT_SZ)

#define STRUCT_ID_OEMNAME_NAME      OEMName
#define STRUCT_ID_OEMNAME_IDX       (STRUCT_ID_JMPBOOT_OFFSET)
#define STRUCT_ID_OEMNAME_SZ        (8)
#define STRUCT_ID_OEMNAME_OFFSET    (STRUCT_ID_JMPBOOT_IDX + STRUCT_ID_OEMNAME_SZ)

#define STRUCT_ID_BYTSPERSEC_NAME   BytsPerSec
#define STRUCT_ID_BYTSPERSEC_IDX    (STRUCT_ID_OEMNAME_OFFSET)
#define STRUCT_ID_BYTSPERSEC_SZ     (2)
#define STRUCT_ID_BYTSPERSEC_OFFSET (STRUCT_ID_OEMNAME_IDX + STRUCT_ID_BYTSPERSEC_SZ)

#define STRUCT_ID_SERPERCLUS_NAME   SerPerClus
#define STRUCT_ID_SERPERCLUS_IDX    (STRUCT_ID_BYTSPERSEC_OFFSET)
#define STRUCT_ID_SERPERCLUS_SZ     (1)
#define STRUCT_ID_SERPERCLUS_OFFSET (STRUCT_ID_BYTSPERSEC_IDX + STRUCT_ID_SERPERCLUS_SZ)

#else
#error "This file cannot be reused"
#error "You can create the same namespace in another file"

#endif /* FAT_NAMESPACE_H */