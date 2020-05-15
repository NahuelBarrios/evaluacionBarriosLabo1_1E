/*
 * cliente.h
 *
 *  Created on: 14 may. 2020
 *      Author: Nahu_
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int idCliente;
	char nombreCliente[51];
	char apellidoCliente[51];
	char cuilCliente[15];
	int masPrestamoActivo;
	int masPrestamoSaldo;
	int isEmptyCliente;

}eCliente;

//***********************************************************************************************************************************
int inicializarCliente(eCliente array[], int size);

void hardCodeCliente(eCliente array[],int size,int id,char nombre[],char apellido[],char cuil[]);
//***********************************************************************************************************************************
int altaCliente(eCliente array[], int size, int* contadorID);

int buscarEmptyCliente(eCliente array[], int size, int* posicion);
//***********************************************************************************************************************************
int modificarCliente(eCliente array[], int sizeArray);

int buscarIdCliente(eCliente array[], int size, int valorBuscado, int* posicion);
//***********************************************************************************************************************************
int listarCliente(eCliente array[], int size);
#endif /* CLIENTE_H_ */
