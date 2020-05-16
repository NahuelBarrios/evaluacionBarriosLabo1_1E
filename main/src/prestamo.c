#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "prestamo.h"

//***********************************************************************************************************************************
int inicializarPrestamo(ePrestamo array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmptyPrestamo=1;
        }
        retorno=0;
    }
    return retorno;
}
//***********************************************************************************************************************************
int buscarEmptyPrestamo(ePrestamo array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyPrestamo==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int buscarIdPrestamo(ePrestamo array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyPrestamo==1)
                continue;
            else if(array[i].idPrestamo==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//***********************************************************************************************************************************
