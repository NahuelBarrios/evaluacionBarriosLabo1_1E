/*
 * informes.h
 *
 *  Created on: 15 may. 2020
 *      Author: Nahu_
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int realizarPrestamo(ePrestamo arrayPrestamo[], int sizePrestamo, int* contadorID,eCliente arrayCliente[],int sizeCliente);

int saldarPrestamo(ePrestamo arrayPrestamo[], int sizePrestamo,eCliente arrayCliente[],int sizeCliente);

int reanudarPrestamo(ePrestamo arrayPrestamo[], int sizePrestamo,eCliente arrayCliente[],int sizeCliente);

#endif /* INFORMES_H_ */
