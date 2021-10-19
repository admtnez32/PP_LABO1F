#include "MenuClientes.h"

int MenuPrincipal(void)
{
	printf("*  --- MENU PRINCIPAL ---			*\n*						*\n"
		"*      1- Alta de Cliente			*\n"
	    "*      2- Modificar datos de cliente		*\n"
	    "*      3- Baja de cliente			*\n"
	    "*      4- Crear pedido de recoleccion		*\n"
	    "*      5- Procesar residuos			*\n"
	    "*      6- Imprimir Clientes			*\n"
	    "*      7- Imprimir Pedidos pendientes		*\n"
	    "*      8- Imprimir Pedidos procesados		*\n"
	    "*      9- Imprimir Pedidos pendientes espec.	*\n"
	    "*      10- Imprimir Promedio de kg de PP	*\n*						*"
	    "\n*      0-SALIR					*\n*						*\n");

return 0;
}

int MenuModificar(void)
{
	printf("* --- Que desea modificar? ---  			*\n*							*\n"
		"*	1- Direccion					*\n"
	    "*	2- Localidad					*\n*							*"
	    "\n*	0- MENU PRINCIPAL				*\n*							*\n");
return 0;
}

int PrintMenu(int numberMenu)
{
	int retorno;
	retorno = -1;

	printf("*************************************************\n*						*\n");
	if(numberMenu == PRINCIPAL)
	{
		MenuPrincipal();
		retorno = 0;
	}
	else if(numberMenu == MODIFICAR)
		{
			MenuModificar();
			retorno = 0;
		}
		else
		{
			//MenuInformes();
			retorno = 0;
		}
	printf("*************************************************\n\n");

return retorno;
}
