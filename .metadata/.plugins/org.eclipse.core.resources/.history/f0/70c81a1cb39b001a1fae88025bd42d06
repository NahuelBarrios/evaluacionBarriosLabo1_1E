#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"

//***********************************************************************************************************************************
int inicializarCliente(eCliente array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmptyCliente=1;
        }
        retorno=0;
    }
    return retorno;
}

void hardCodeCliente(eCliente array[],int size,int id,char nombre[],char apellido[],char cuil[])
{
	array[id].idCliente= id;
	strcpy(array[id].nombreCliente, nombre);
	strcpy(array[id].apellidoCliente, apellido);
	strcpy(array[id].cuilCliente, cuil);
	array[id].masPrestamoActivo=0;
	array[id].masPrestamoSaldo=0;
	array[id].isEmptyCliente = 0;

}

//***********************************************************************************************************************************

int altaCliente(eCliente array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(buscarEmptyCliente(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idCliente=*contadorID;
            array[posicion].isEmptyCliente=0;
            array[posicion].masPrestamoActivo=0;
            array[posicion].masPrestamoSaldo=0;
            utn_getTexto("\nIngrese el nombre del cliente: ","\nError",1,51,3,array[posicion].nombreCliente);
            utn_getTexto("\nIngrese el apellido del cliente: ","\nError",1,51,3,array[posicion].apellidoCliente);
            utn_getTexto("\nIngrese el cuil del cliente: ","\nError",1,14,3,array[posicion].cuilCliente);

            printf("\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s",
                   array[posicion].idCliente,array[posicion].nombreCliente,array[posicion].apellidoCliente,array[posicion].cuilCliente);
            retorno=0;
        }
    }
    return retorno;
}

int buscarEmptyCliente(eCliente array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyCliente==1)
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

int modificarCliente(eCliente array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(buscarIdCliente(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
            	printf("\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s",
            	                   array[posicion].idCliente,array[posicion].nombreCliente,array[posicion].apellidoCliente,array[posicion].cuilCliente);
                utn_getChar("\nModificar:\nN-Modificar nombre\nA-Modificar Apellido\nC-Modificar cuil\nS-Salir","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'N':
                    	utn_getTexto("\nIngrese el nuevo nombre: ","\nError",1,51,1,array[posicion].nombreCliente);
                    	break;
                    case 'A':
                    	utn_getTexto("\nIngrese el nuevo apellido: ","\nError",1,51,1,array[posicion].apellidoCliente);
                        break;
                    case 'C':
                    	utn_getTexto("\nIngrese el nuevo cuil: ","\nError",1,14,1,array[posicion].cuilCliente);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int buscarIdCliente(eCliente array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyCliente==1)
                continue;
            else if(array[i].idCliente==valorBuscado)
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

int listarCliente(eCliente array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyCliente==1)
                continue;
            else
            {
            	printf("\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s",
            	                   array[i].idCliente,array[i].nombreCliente,array[i].apellidoCliente,array[i].cuilCliente);
            }
        }
        retorno=0;
    }
    return retorno;
}
