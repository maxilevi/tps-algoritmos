#include "conversion.h"
#include <stdlib.h>

const int MAX_CONDUCTAS = 3;
const char CONDUCTAS[] =
{
	CONDUCTA_BUENA_LETRA,
	CONDUCTA_REGULAR_LETRA,
	CONDUCTA_MALA_LETRA
};

int calcular_tope(char* string)
{
	int tope = 0;
	while(string[tope] != '\0')
	{
		tope++;
	}
	return tope;
}

void slice(char* array, char resultado[], int empieza, int termina)
{
	for(int i = empieza; i < termina; ++i)
	{
		resultado[i - empieza] = array[i];
	}
}

fecha_t parsear_fecha(char* string)
{
	fecha_t fecha = {.es_valida = false};
	int tope = calcular_tope(string);
	if(tope != 6) return fecha;

	char anio_str[4];
	slice(string, anio_str, 0, 4);
	fecha.anio = atoi(anio_str);

	char mes_str[2];
	slice(string, mes_str, 4, 6);
	fecha.mes = atoi(mes_str);

	fecha.es_valida = fecha.mes > 0 && fecha.mes < 13;
	return fecha;
}

int parsear_conducta(char* conducta)
{
	int tope = calcular_tope(conducta);
	if(tope != 1) return -1;
	for(int i = 0; i < MAX_CONDUCTAS; ++i)
	{
		if(conducta[0] == CONDUCTAS[i])
			return i;
	}
	return -1;
}

bool fecha_valida(char* fecha)
{
	return (parsear_fecha(fecha)).es_valida;
}

bool conducta_valida(char* string)
{
	return parsear_conducta(string) != -1;
}