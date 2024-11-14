#include <fsfat.h>
#include "NameSpaces.h"

STATIC UINT8
FatBuffer[VOLUME_SIGNATURE_SZ];

STATIC FAT_BOOT_START 
BootStart = {
    STRUCT_ID_FIELD(JMPBOOT),
    STRUCT_ID_FIELD(OEMNAME),
    STRUCT_ID_FIELD_NULL
};

STATIC FAT_BPB
BiosParametersBoot = {
    STRUCT_ID_FIELD(BYTSPERSEC),
    STRUCT_ID_FIELD(SERPERCLUS),
    STRUCT_ID_FIELD_NULL
};

STATIC FAT_FILE 
INTERNAL FatInit32(VOID)
{
    

    return RETURN(FILE, VPZ);
}

STATIC FAT_FILE 
INTERNAL FatInit12(VOID)
{
    return RETURN(FILE, VPZ);
}

STATIC FAT_FILE 
INTERNAL FatInit16(VOID)
{
    return RETURN(FILE, VPZ);
}


FAT_FILE 
FATAPI FatInit(
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
            return RETURN(FILE, VPZ);
    }
}

#if defined FAT_TESTS_API

#include <stdio.h>

#define DEBUG_LOG(...) printf(__VA_ARGS__)
#define DEBUG_FIELD_INTERNAL(_field) \
    DEBUG_LOG("%016s : %03s : %03s : %03s\n", \
        "Address", \
        "Sz", \
        "<<", \
        "M" \
    ); \
    DEBUG_LOG("%016p : %03d : %03d : %03d\n", \
        &BiosParametersBoot._field.field, \
        BiosParametersBoot._field.size, \
        BiosParametersBoot._field.offset, \
        BiosParametersBoot._field.mail \
    )

UINT16
TEST INTERNAL GetSectionLength(
        CONST FAT_FIELD *Section
    )
{
    UINT16 c;

    c = 0;
    while(Section->mail == MAIL_FIELD)
    {
        Section++;
        c++;
    }

    if (Section->mail != MAIL_NULL)
    {
        DEBUG_LOG("GetSectionLength(): broken field!\n");
    }

    return c;
}

VOID
TEST BrutforceFatBuffer(VOID)
{
    UINT16 i;

    for(i = 0; i < ARR_SIZEOF(FatBuffer); i++)
    {
        FatBuffer[i] = i;
    }
}

STATIC VOID
TEST INTERNAL PrintSection(
        OUT FAT_FIELD **point,
        OUT UINT16 *align,
        IN CONST UINT16 limit
    )
{
    UINT16 i;

    for (i = 0; i < limit; i++)
    {
        DEBUG_LOG("%02hhd", *(*point)->field);

        putchar((SKIP_INDEX_OFFSET(i) % (32 - *align) == 0) ? 
            '\n' : ' ');

        (*point)++;
        *align++;
    }
}

VOID 
TEST GetFatSignatureTable(VOID)
{
    UINT16 lim, align;
    FAT_FIELD *pfield;

    align = 0;
    
    // pfield = (FAT_FIELD*)&BootStart;
    // lim = GetSectionLength(pfield);
    // PrintSection(&pfield, &align, lim);
    DEBUG_FIELD_INTERNAL(STRUCT_ID_SERPERCLUS_NAME);
    DEBUG_FIELD_INTERNAL(STRUCT_ID_BYTSPERSEC_NAME);


    pfield = (FAT_FIELD*)&BiosParametersBoot;
    lim = GetSectionLength(pfield);
    PrintSection(&pfield, &align, lim);

    putchar('\n');
}

VOID
TEST PrintFatBuffer(VOID)
{
    UINT16 i;

    for(i = 0; i < VOLUME_SIGNATURE_SZ; i++)
    {
        DEBUG_LOG("%02hhx", FatBuffer[i]);

        putchar((SKIP_INDEX_OFFSET(i) % 32 == 0) ? '\n' : ' ');
    }

    putchar('\n');
}

#endif