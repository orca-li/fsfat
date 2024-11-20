#if !defined STM_FS_STFAT32_H
#define STM_FS_STFAT32_H

#include "FatDefs.h"

#define FAT_TESTS_API
#if defined FAT_TESTS_API

void
InitFatBuffer(unsigned char type);
void 
GetFatSignatureTable(void);
void
PrintFatBuffer(void);
void
GetManualTable(void);


#endif 

#endif /* STM_FS_STFAT32_H */