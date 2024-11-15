#include <fsfat.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    BrutforceFatBuffer();
    GetManualTable();
    GetFatSignatureTable();

    printf("\nFatBuffer[]:\n");
    PrintFatBuffer();

    return 0;
}

/**
    @todo заполнение сигнатуры не через i++, а через PrintSec++,
    т.е. если длина заголовка 8 байт, то печатать 0xNN 0xNN ..., а не 
    перебор 0x01 0x02 и т.д.
*/