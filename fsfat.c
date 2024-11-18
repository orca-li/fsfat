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
    STRUCT_ID_FIELD(RSVDSECCNT),
    STRUCT_ID_FIELD(NUMFATS),
    STRUCT_ID_FIELD(ROOTENTCNT),
    STRUCT_ID_FIELD(TOTSEC16),
    STRUCT_ID_FIELD(MEDIA),
    STRUCT_ID_FIELD(FATSZ16),
    STRUCT_ID_FIELD(SECPERTRK),
    STRUCT_ID_FIELD(NUMHEADS),
    STRUCT_ID_FIELD(HIDDSEC),
    STRUCT_ID_FIELD(TOTSEC32),

#if IS_FS_FATX == IS_FS_FAT32
    STRUCT_ID_FIELD(FATSZ32),
    STRUCT_ID_FIELD(EXTFLAGS),
    STRUCT_ID_FIELD(FSVER),
    STRUCT_ID_FIELD(ROOTCLUS),
    STRUCT_ID_FIELD(FSINFO),
    STRUCT_ID_FIELD(BKBOOTSEC),
    STRUCT_ID_FIELD(RESERVED0),
#endif

    STRUCT_ID_FIELD(DRVNUM),
    STRUCT_ID_FIELD(RESERVED1),
    STRUCT_ID_FIELD(BOOTSIG),
    STRUCT_ID_FIELD(VOLID),
    STRUCT_ID_FIELD(VOLLAB),
    STRUCT_ID_FIELD(FILSYSTYPE),
    STRUCT_ID_FIELD(SETTOZERO1),
    STRUCT_ID_FIELD(SIGNATUREWORD),
    STRUCT_ID_FIELD(SETTOZERO2),

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

struct CORRECT_SECTION_VALUES {
    unsigned short index;
    unsigned short size;
    unsigned short offset;
};

struct CORRECT_SECTION_VALUES CorSecVals[] = {
    {
        .index = 0,
        .size = 3,
        .offset = 3,
    },
};

#define DEBUG_LOG(...) printf(__VA_ARGS__)
#define GET_FIELD_NAME_STR(_field) \
    #_field
#define FIELD_PARSE_TOKEN(_field, _param) \
    STRUCT_ID_ ## _field ## _param
#define DEBUG_FIELD_INTERNAL_TITLE() \
    DEBUG_LOG("%16s   %05s   %03s   %03s   %03s   %016s   %05s\n", \
        "Name", \
        "Index", \
        "<<<", \
        "Sz", \
        "M", \
        "Address", \
        "Value" \
    )
#define DEBUG_FIELD_INTERNAL(_sect, _field) \
    DEBUG_LOG("%16s : %05d : %03d : %03d : %03d : %016p : %02hhx\n", \
        GET_FIELD_NAME_STR(_field), \
        FIELD_PARSE_TOKEN(_field, _IDX), \
        _sect.FIELD_PARSE_TOKEN(_field, _NAME).offset, \
        _sect.FIELD_PARSE_TOKEN(_field, _NAME).size, \
        _sect.FIELD_PARSE_TOKEN(_field, _NAME).mail, \
        _sect.FIELD_PARSE_TOKEN(_field, _NAME).field, \
        *_sect.FIELD_PARSE_TOKEN(_field, _NAME).field \
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
TEST GetManualTable(VOID)
{
    DEBUG_FIELD_INTERNAL_TITLE();
    DEBUG_FIELD_INTERNAL(BootStart, JMPBOOT);
    DEBUG_FIELD_INTERNAL(BootStart, OEMNAME);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, BYTSPERSEC);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, SERPERCLUS);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, RSVDSECCNT);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, NUMFATS);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, ROOTENTCNT);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, TOTSEC16);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, MEDIA);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, FATSZ16);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, SECPERTRK);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, NUMHEADS);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, HIDDSEC);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, TOTSEC32);

#if IS_FS_FATX == IS_FS_FAT32
    putchar('\n');
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, FATSZ32);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, EXTFLAGS);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, FSVER);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, ROOTCLUS);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, FSINFO);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, BKBOOTSEC);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, RESERVED0);
    putchar('\n');
#endif

    DEBUG_FIELD_INTERNAL(BiosParametersBoot, DRVNUM);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, RESERVED1);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, BOOTSIG);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, VOLID);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, VOLLAB);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, FILSYSTYPE);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, SETTOZERO1);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, SIGNATUREWORD);
    DEBUG_FIELD_INTERNAL(BiosParametersBoot, SETTOZERO2);
}

VOID 
TEST GetFatSignatureTable(VOID)
{
    UINT16 lim, align;
    FAT_FIELD *pfield;

    align = 0;
    
    pfield = (FAT_FIELD*)&BootStart;
    lim = GetSectionLength(pfield);
    PrintSection(&pfield, &align, lim);

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

        putchar((SKIP_INDEX_OFFSET(i) % 32 == 0) ? 
            '\n' : ' ');
    }

    putchar('\n');
}

#endif