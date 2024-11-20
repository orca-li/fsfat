#if !defined FAT_DEFINES_STATUS_H
#define FAT_DEFINES_STATUS_H

#define fatStatusOK                     (0UL)
/**
 * @brief the wrong size of the SignatureList[]
 * @details the sum of the fields of the structures does not match the array of fields
 * @todo fulfill the conditions of this function
 *          @fn fatCheckSzSignatureList(void) 
 *          @file FatTestLib.c
 */
#define fatStatusWrongSz                (1UL << 0)

#endif /* FAT_DEFINES_STATUS_H */