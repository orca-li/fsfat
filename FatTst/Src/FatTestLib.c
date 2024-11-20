#include "FatTestLib.h"
#include <stdio.h>
#define GET_STATUS(_status) \
    printf("status: %d\n", _status)

static fatSTATUS
fatCheckSzSignatureList(void)
{
    if (fatGetSzSignatureList() == SIGNATURE_LIST_SIZE)
    {
        return fatStatusOK;
    }

    return fatStatusWrongSz;
}

fatSTATUS
fatMainTestLib(void)
{
    unsigned long long status;

    status = fatStatusOK;
    status |= fatCheckSzSignatureList();

    return status;
}