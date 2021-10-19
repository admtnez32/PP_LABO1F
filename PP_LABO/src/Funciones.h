#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// @fn int CargarCadena(char[], int)
/// @brief Carga de cadena
///
/// @param cadena	cadena a cargar
/// @param tamanio tamanio de la cadena
/// @return	retorna -1 si no pudo cargar la cadena; retorna 0 si pudo cargar la cadena
int CargarCadena(char cadena[], int tamanio);

/// @fn int PedirNumeroConRango(char[], char[], int, int)
/// @brief Solicitar numero con rango min y max
///
/// @param mensaje	mensaje a mostrar
/// @param mensajeError	mensaje de error a mostrar
/// @param min	numero minimo a ingresar
/// @param max	numero maximo a ingresar
/// @return	numero ingresado
int PedirNumeroConRango(char mensaje[], char mensajeError[], int min, int max);

/// @fn int esNumerica(char[], int)
/// @brief detecta si una cadena es numerica
///
/// @param cadena	cadena a evaluar
/// @param limite	tamanio del array
/// @return retorna 1 si es numerica; retorna 0 si no es numerica
int esNumerica(char cadena[], int limite);

/// @fn int PedirNumero(int*, char[])
/// @brief 	Solicitar un numero entero
///
/// @param pNumero	puntero donde devuelve el numero ingresado
/// @param mensaje	mensaje a mostrar
/// @return	retorna -1 si no pudo pedir numero; retorna 1 todo ok
int PedirNumero(int* pNumero, char mensaje[]);

/// @fn int PedirNumeroConReintentos(int*, char[], int)
/// @brief 	Solicitar numero con reintentos
///
/// @param pNumero	puntero donde devuelve el numero ingresado
/// @param mensaje	mensaje a mostrar
/// @param reintentos	cantidad de reintentos
/// @return retorna 0 si no pudo cargar el numero; retorna 1 para todo ok
int PedirNumeroConReintentos(int* pNumero, char mensaje[], int reintentos);

/// @fn int PedirNumeroConReintentosConRango(int*, char[], int, int, int)
/// @brief Solicitar numero con reintentos y rango
///
/// @param numero	puntero donde guardar el numero
/// @param mensaje	mensaje a mostrar
/// @param min	minimo
/// @param max	maximo
/// @param reintentos	cantidad de reintentos
/// @return	retorna 0 para numero invalido; 1 para todo OK
int PedirNumeroConReintentosConRango(int* numero, char mensaje[], int min, int max, int reintentos);

/// @fn float PedirFloat(float*, char[])
/// @brief Solicitar numero flotante
///
/// @param pNumero	puntero donde devuelve el numero ingresado
/// @param mensaje	mensaje a mostrar
/// @return	retorna 0 si no pudo cargar el numero; retorna 1 para todo ok
float PedirFloat(float* pNumero, char mensaje[]);

/// @fn float PedirFloatConReintentos(float*, char[], int)
/// @brief
///
/// @param pNumero	puntero donde devuelve el numero ingresado
/// @param mensaje mensaje a mostrar
/// @param reintentos	cantidad de reintentos
/// @return	retorna 0 si no pudo cargar el numero; retorna 1 para todo ok
float PedirFloatConReintentos(float* pNumero, char mensaje[], int reintentos);

/// @fn int PedirCaracteres(char[], int, char[])
/// @brief Solicita chars
///
/// @param cadena	cadena a cargar
/// @param tamanio	tamanio de cadena
/// @param mensaje	mensaje a mostrar
/// @return retorna 0 si no pudo cargar la cadena; retorna 1 para todo ok
int PedirCaracteres(char cadena[], int tamanio, char mensaje[]);

/// @fn int PedirCaracteres(char[], int, char[], int)
/// @brief	Solicitar chars con reintentos
///
/// @param cadena	cadena a cargar
/// @param tamanio	tamanio de cadena
/// @param mensaje	mensaje a mostrar
/// @param reintentos	cantidad de reintentos
/// @return retorna 0 si no pudo cargar la cadena; retorna 1 para todo ok
int PedirCaracteresConReintentos(char cadena[], int tamanio, char mensaje[], int reintentos);
#endif /* FUNCIONES_H_ */

