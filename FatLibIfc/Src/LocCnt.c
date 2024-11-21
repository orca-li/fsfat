#include "LocCnt.h"

static fatUINT8 HexSignatureArray[512] = {0};

static FAT_HB_BOOT_START BootStart = {
    fatFIELD_ITEM_ID_INIT(jmpBoot),
    fatFIELD_ITEM_ID_INIT(OEMName),
    // fatFIELD_ITEM_ID_INIT(_NULL),
};

static FAT_HB_BIOSPB BiosParametersBoot = {
    fatFIELD_ITEM_ID_INIT(BytsPerSec),
    fatFIELD_ITEM_ID_INIT(SerPerClus),
};

static FAT_HB_FSINFO FileSystemInfo = {

};

static FAT_HB_DIR DirectoryStructure = {

};

static FAT_HB_LONG_NAME LongFileNameImplementation = {

};

static FAT_SIGNATURE_FIELD *SignatureList[] = {
    (FAT_SIGNATURE_FIELD *)&BootStart.jmpBoot,
    (FAT_SIGNATURE_FIELD *)&BootStart.OEMName,

    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.BytsPerSec,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.SerPerClus,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.RsvdSecCnt,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.NumFATs,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.RootEntCnt,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.TotSec16,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.Media,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.FATSz16,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.SecPerTrk,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.NumHeads,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.HiddSec,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.TotSec32,

#if IS_FS_FATX == IS_FS_FAT32

    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.FATSz32,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.ExtFlags,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.FSVer,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.RootClus,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.FSInfo,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.BkBootSec,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.Reserved,

#endif

    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.DrvNum,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.Reserved1,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.BootSig,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.VolID,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.VolLab,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.FilSysType,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.SetToZero1,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.Signature_word,
    (FAT_SIGNATURE_FIELD *)&BiosParametersBoot.SetToZero2,

    (FAT_SIGNATURE_FIELD *)&FileSystemInfo.LeadSeg,
    (FAT_SIGNATURE_FIELD *)&FileSystemInfo.Reserved1,
    (FAT_SIGNATURE_FIELD *)&FileSystemInfo.StrucSig,
    (FAT_SIGNATURE_FIELD *)&FileSystemInfo.FreeCount,
    (FAT_SIGNATURE_FIELD *)&FileSystemInfo.Nxt_Free,
    (FAT_SIGNATURE_FIELD *)&FileSystemInfo.Reserved2,
    (FAT_SIGNATURE_FIELD *)&FileSystemInfo.TrailSig,

    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.Name,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.Attr,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.NTRes,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.CrtTimeTenth,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.CrtTime,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.CrtDate,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.LstAccDate,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.FstClusHI,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.WrtTime,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.WrtDate,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.FstClusLO,
    (FAT_SIGNATURE_FIELD *)&DirectoryStructure.FileSize,

    (FAT_SIGNATURE_FIELD *)&LongFileNameImplementation.Ord,
    (FAT_SIGNATURE_FIELD *)&LongFileNameImplementation.Name1,
    (FAT_SIGNATURE_FIELD *)&LongFileNameImplementation.Attr,
    (FAT_SIGNATURE_FIELD *)&LongFileNameImplementation.Type,
    (FAT_SIGNATURE_FIELD *)&LongFileNameImplementation.Chksum,
    (FAT_SIGNATURE_FIELD *)&LongFileNameImplementation.Name2,
    (FAT_SIGNATURE_FIELD *)&LongFileNameImplementation.FstClusLO,
    (FAT_SIGNATURE_FIELD *)&LongFileNameImplementation.Name3,

    (FAT_SIGNATURE_FIELD *)&LongFileNameImplementation._NULL,
};
FAT_SIGNATURE_FIELD *LocationCounter = (FAT_SIGNATURE_FIELD*)&SignatureList;

const unsigned short
fatGetSzSignatureList(void)
{
    return (sizeof(SignatureList) / sizeof(*SignatureList));
}