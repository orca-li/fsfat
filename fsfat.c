#include <fsfat.h>

#include "NameSpaces.h"

STATIC UINT8
FatBuffer[VOLUME_SIGNATURE_SZ];

STATIC FAT_BOOT_START 
BootStart = {
    STRUCT_ID_FIELD(JMPBOOT),
    STRUCT_ID_FIELD(OEMNAME),
};

STATIC FAT_BPB
BiosParametersBoot = {
};

STATIC FAT_FILE 
FSFAT_INTERNAL FatInit32(VOID)
{
    

    return RETURN_STATUS(NOT_IMPLEMENTED);
}

STATIC FAT_FILE 
FSFAT_INTERNAL FatInit12(VOID)
{
    return RETURN_STATUS(NOT_IMPLEMENTED);
}

STATIC FAT_FILE 
FSFAT_INTERNAL FatInit16(VOID)
{
    return RETURN_STATUS(NOT_IMPLEMENTED);
}


FAT_FILE 
FSFAT_API FatInit(
    IN UINT8 base
    )
{
    switch (base)
    {
        case BASE_FAT12:
            return FatInit12();

        case BASE_FAT16:
            return FatInit16();

        case BASE_FAT32:
            return FatInit32();

        default:
            return RETURN(FILE, NULL);
    }
}

#if defined FAT_TESTS_API

#include <stdio.h>

#define DEBUG_LOG(...) printf(__VA_ARGS__)

VOID 
FSFAT_TEST GetFatSignatureTable(VOID)
{
    UINT16 i;
    CONST UINT8 TestLimit = 3;

    FAT_BOOT_START *pboot = &BootStart;
    for (i = 0; i < UNI_SIZEOF(BootStart, FAT_BOOT_START); i++)
    {
        DEBUG_LOG("%hhd", pboot->jmpBoot);
    }
}

#endif