#include "Funciones.h"

int CargarCadena(char cadena[], int tamanio)
{
	int retorno;
	char bufferString[1000];
	retorno = -1;

	if(cadena != NULL && tamanio > 0)
	{

		fflush(stdin);

		if(gets(bufferString) != NULL && strlen(bufferString) > 0)
		{
				if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
				{
					bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
				}
				if(strnlen(bufferString, sizeof(bufferString)) <= tamanio-1)
				{
					strncpy(cadena, bufferString, tamanio);
					retorno = 0;
				}
				else
				{
					printf("--- Error, demasiado caracteres ---\n");
				}
		}
		else
		{
			printf("\n--- No ingreso nada ---\n");
		}
	}

return retorno;
}

int PedirNumeroConReintentosConRango(int* numero, char mensaje[], int min, int max, int reintentos)
{
	int auxNumero;
	int retorno = 0;
	do{
		if(PedirNumero(&auxNumero, mensaje) == 1 && auxNumero>=min && auxNumero<=max)
		{
			*numero = auxNumero;
			retorno = 1;
			reintentos = 0;
		}
		else
		{
			printf("\n--- Numero fuera de rango ---\n--- Le quedan %d reintento/s ---\n\n", reintentos-1);
		}

		reintentos--;
	}while(reintentos > 0);

	return retorno;
}

int esNumerica(char cadena[], int limite)
{
	int retorno = 1;

	for(int i = 0; i<limite && cadena[i] != '\0'; i++)
	{
		if((i == 0 && (cadena[i] == '+' || cadena[i] == '-')) || (i > 0 && cadena[i] == '.'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
return retorno;
}

int PedirNumero(int* pNumero, char mensaje[])
{
	int retorno = -1;
	char bufferString[50];

		printf(mensaje);
		if(pNumero != NULL && CargarCadena(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString, sizeof(bufferString)))
		{
			retorno = 1;
			*pNumero = atoi(bufferString);
		}
		else
		{
			printf("\n--- Error, eso no es un numero ---\n");
		}

return retorno;
}

int PedirNumeroConReintentos(int* pNumero, char mensaje[], int reintentos)
{
	int numero;
	int retorno = 0;

	do{
		if(PedirNumero(&numero, mensaje) == 1)
		{
			*pNumero = numero;
			retorno = 1;
			reintentos = 0;
		}
		else
		{
			printf("Le quedan %d reintento/s\n\n", reintentos-1);
		}
		reintentos--;
	}while(reintentos > 0);
return retorno;
}

float PedirFloat(float* pNumero, char mensaje[])
{

	int retorno = 0;
	char bufferString[50];

	printf(mensaje);
	if(pNumero != NULL && CargarCadena(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString, sizeof(bufferString)))
	{
		retorno = 1;
		*pNumero = atof(bufferString);
	}
	else
	{
		printf("\n--- Error, eso no es un numero ---\n");
	}

return retorno;
}

float PedirFloatConReintentos(float* pNumero, char mensaje[], int reintentos)
{
	int retorno = 0;
	float salario;

	do{
		if(PedirFloat(&salario, mensaje))
		{
			*pNumero = salario;
			retorno = 1;
			reintentos = 0;
		}
		else
		{
			printf("Le quedan %d reintento/s\n\n", reintentos-1);
		}

		reintentos--;
	}while(reintentos > 0);
return retorno;
}

int PedirCaracteres(char cadena[], int tamanio, char mensaje[])
{
	int retorno = -1;

	if(cadena != NULL && tamanio > 0)
	{
		printf(mensaje);
		if(CargarCadena(cadena, tamanio) == 0)
		{
			retorno = 1;
			for(int i = 0; i < tamanio && cadena[i] != '\0'; i++)
			{
				if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] < 'A' || cadena[i] > 'z') && (cadena[0] == ' ' || cadena[i] != ' '))
				{
					retorno = 0;
					break;
				}
			}

		}
	}
return retorno;
}

int PedirCaracteresConReintentos(char cadena[], int tamanio, char mensaje[], int reintentos)
{
	int retorno = 0;

	if(cadena != NULL && tamanio > 0)
	{
		do
		{
			if(PedirCaracteres(cadena, tamanio, mensaje) == 1)
			{
				retorno = 1;
				reintentos = 0;
			}
			else
			{
				printf("\n--- Error, caracter invalido. Le quedan %d reintento/s ---\n", reintentos-1);
			}

			reintentos--;
		}while(reintentos > 0);
	}

return retorno;
}
