#include "FatApi.h"
#include "FatTestLib.h"

#include <stdio.h>
#define GET_STATUS(_status) \
    printf("status: %d\n", _status)

static fatSTATUS CallStatus = fatOK;

fatSTATUS
fatGetCallStatus(void)
{
    return CallStatus;
}

fatBOOLEAN fatLibInit(void)
{
    if (fatStatusOK != (CallStatus = fatMainTestLib()))
    {
        goto EXIT_FAIL;
    }

    return fatOK;

EXIT_FAIL:
    return fatFAIL;
}