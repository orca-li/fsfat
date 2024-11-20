#if !defined FAT_LOCATION_COUNTER_H
#define FAT_LOCATION_COUNTER_H

/**
 * 
 * @brief SignatureBuffer
 * @brief HumanizingBuffer
 * @brief LocationCounter
 * 
 * A signature buffer has been developed to process FAT filesystem signatures. 
 * For improved human readability and analysis, a “humanizing” buffer is employed. 
 * This buffer consists of a list of structures, each describing a single byte 
 * within the signature. Each structure contains not only the byte’s value but also 
 * additional metadata to enhance the interpretation of the signature. This approach 
 * facilitates treating the signature as a set of named objects, improving readability 
 * and debugging, rather than a raw byte array. The location counter serves as the array 
 * index for accessing elements in the humanizing buffer.
 */

typedef struct _FAT_SIGNATURE_FIELD_FLAGS
{
    /**
     * @brief move to the next structure until the buffer runs out
     */
    unsigned char StructEnd:1; 
    unsigned char BufferEnd:1;
} FAT_SIGNATURE_FIELD_FLAGS;

typedef struct _FAT_SIGNATURE_FIELD
{
    unsigned char * const field;
    const unsigned short size;
    const unsigned short offset;
    unsigned char * const name;

    /**
     * @internal data needed for the library API 
     */
    /**
     * @brief mail - array end flag
     * 0x00 - NULL
     * Other - Not Null
     */
    FAT_SIGNATURE_FIELD_FLAGS flags;
} FAT_SIGNATURE_FIELD;

/**
 * @brief HumanizingBuffer
 */
typedef struct _FAT_HB_BOOT_START
{
    FAT_SIGNATURE_FIELD jmpBoot;
    FAT_SIGNATURE_FIELD OEMName;

#define PLUS_SIZE_SIGNATURE_1 2
    FAT_SIGNATURE_FIELD _NULL;
} FAT_HB_BOOT_START;

typedef struct _FAT_HB_BIOS_PARAMETERS_BOOT
{
    FAT_SIGNATURE_FIELD BytsPerSec;
    FAT_SIGNATURE_FIELD SerPerClus;
    FAT_SIGNATURE_FIELD RsvdSecCnt;
    FAT_SIGNATURE_FIELD NumFATs;
    FAT_SIGNATURE_FIELD RootEntCnt;
    FAT_SIGNATURE_FIELD TotSec16;
    FAT_SIGNATURE_FIELD Media;
    FAT_SIGNATURE_FIELD FATSz16;
    FAT_SIGNATURE_FIELD SecPerTrk;
    FAT_SIGNATURE_FIELD NumHeads;
    FAT_SIGNATURE_FIELD HiddSec;
    FAT_SIGNATURE_FIELD TotSec32;

#define PLUS_SIZE_SIGNATURE_2_1 12

#if IS_FS_FATX == IS_FS_FAT32
    FAT_SIGNATURE_FIELD FATSz32;
    FAT_SIGNATURE_FIELD ExtFlags;
    FAT_SIGNATURE_FIELD FSVer;
    FAT_SIGNATURE_FIELD RootClus;
    FAT_SIGNATURE_FIELD FSInfo;
    FAT_SIGNATURE_FIELD BkBootSec;
    FAT_SIGNATURE_FIELD Reserved;
#define PLUS_SIZE_SIGNATURE_2_2 7

#else
#define PLUS_SIZE_SIGNATURE_2_2 0
#endif

    FAT_SIGNATURE_FIELD DrvNum;
    FAT_SIGNATURE_FIELD Reserved1;
    FAT_SIGNATURE_FIELD BootSig;
    FAT_SIGNATURE_FIELD VolID;
    FAT_SIGNATURE_FIELD VolLab;
    FAT_SIGNATURE_FIELD FilSysType;
    FAT_SIGNATURE_FIELD SetToZero1;
    FAT_SIGNATURE_FIELD Signature_word;
    FAT_SIGNATURE_FIELD SetToZero2;

#define PLUS_SIZE_SIGNATURE_2_3 9
#define PLUS_SIZE_SIGNATURE_2  \
    (PLUS_SIZE_SIGNATURE_2_1 + PLUS_SIZE_SIGNATURE_2_2 + PLUS_SIZE_SIGNATURE_2_3)

    FAT_SIGNATURE_FIELD _NULL;
} FAT_HB_BIOSPB;

typedef struct _FAT_FILE_SYSTEM_INFO
{
    FAT_SIGNATURE_FIELD LeadSeg;
    FAT_SIGNATURE_FIELD Reserved1;
    FAT_SIGNATURE_FIELD StrucSig;
    FAT_SIGNATURE_FIELD FreeCount;
    FAT_SIGNATURE_FIELD Nxt_Free;
    FAT_SIGNATURE_FIELD Reserved2;
    FAT_SIGNATURE_FIELD TrailSig;

#define PLUS_SIZE_SIGNATURE_3 7

    FAT_SIGNATURE_FIELD _NULL;
} FAT_HB_FSINFO;

typedef struct _FAT_DIRECTORY_STRUCTURE
{
    FAT_SIGNATURE_FIELD Name;
    FAT_SIGNATURE_FIELD Attr;
    FAT_SIGNATURE_FIELD NTRes;
    FAT_SIGNATURE_FIELD CrtTimeTenth;
    FAT_SIGNATURE_FIELD CrtTime;
    FAT_SIGNATURE_FIELD CrtDate;
    FAT_SIGNATURE_FIELD LstAccDate;
    FAT_SIGNATURE_FIELD FstClusHI;
    FAT_SIGNATURE_FIELD WrtTime;
    FAT_SIGNATURE_FIELD WrtDate;
    FAT_SIGNATURE_FIELD FstClusLO;
    FAT_SIGNATURE_FIELD FileSize;    

#define PLUS_SIZE_SIGNATURE_4 12

    FAT_SIGNATURE_FIELD _NULL;
} FAT_HB_DIR;

typedef struct _FAT_LONG_FILE_NAME_IMPLEMENTATION
{
    FAT_SIGNATURE_FIELD Ord;
    FAT_SIGNATURE_FIELD Name1;
    FAT_SIGNATURE_FIELD Attr;
    FAT_SIGNATURE_FIELD Type;
    FAT_SIGNATURE_FIELD Chksum;
    FAT_SIGNATURE_FIELD Name2;
    FAT_SIGNATURE_FIELD FstClusLO;
    FAT_SIGNATURE_FIELD Name3;

#define PLUS_SIZE_SIGNATURE_5 8

    FAT_SIGNATURE_FIELD _NULL;
#define PLUS_SIZE_SIGNATURE_6_NULL 1
} FAT_HB_LONG_NAME;

#define SIGNATURE_LIST_SIZE \
    ( \
        PLUS_SIZE_SIGNATURE_1 + \
        PLUS_SIZE_SIGNATURE_2 + \
        PLUS_SIZE_SIGNATURE_3 + \
        PLUS_SIZE_SIGNATURE_4 + \
        PLUS_SIZE_SIGNATURE_5 + \
        PLUS_SIZE_SIGNATURE_6_NULL \
    )

const unsigned short fatGetSzSignatureList(void);

#endif /* FAT_LOCATION_COUNTER_H */