/*
 * prestamo.h
 *
 *  Created on: 15 may. 2020
 *      Author: Nahu_
 */

#ifndef PRESTAMO_H_
#define PRESTAMO_H_

typedef struct
{
	int idPrestamo;
	int idCliente;
	float importePrestamo;
	int cuotasPrestamo;
	char estadoPrestamo[51]; //En prestamo || Saldado || activo
	int isEmptyPrestamo;

}ePrestamo;

int inicializarPrestamo(ePrestamo array[], int size);

int buscarEmptyPrestamo(ePrestamo array[], int size, int* posicion);

int buscarIdPrestamo(ePrestamo array[], int size, int valorBuscado, int* posicion);

#endif /* PRESTAMO_H_ */
