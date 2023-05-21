// pch.cpp: el archivo de código fuente correspondiente al encabezado precompilado

#include "pch.h"
#pragma region
// Cuando se utilizan encabezados precompilados, se requiere este archivo de código fuente para que la compilación se realice correctamente.
int __stdcall suma(int a, int b) {
	//data
	int resultado;

	_asm {	//ensamblador inline
		
		mov eax, a
		add eax, b

		mov resultado, eax

	}

	return resultado;

}
int __stdcall largo_cadena(const char* str) {
	int len = strlen(str);
	return len;
}

//Reescribir el contenido de una cadena que se obtuvo desde c#
int __stdcall escribir_cadena(char* str, int len_buffer) {
	const char* aux = "a"; //debe ser menor que len_buffer
	int len = strlen(aux);
	for (int i = 0; i < len; i++) {
		str[i] = aux[i];
	}
	return len;
}

#pragma endregion

#pragma region PROGRAMAS 2023 1

int __stdcall promedioDeUsuario(char* cadRes, char* nombre, int cal1, int cal2, int cal3) {
	// a nombre no se le hace cambio en este programa...

	int prom;
	int pDecimal;

	_asm {
		mov eax, 0
		add eax, cal1
		add eax, cal2
		add eax, cal3

		mov edx, 0
		mov ecx, 3
		div ecx

		mov pDecimal, edx
		mov prom, eax
	}
	prom += pDecimal / 3;
	
	int c = 0;
	const char* aux = " tienes un promedio de: "; //debe ser menor que len_buffer
	
	//agregar a cadRes el nombre del alumno
	int len = strlen(nombre);

	for (int i = 0; i < len; i++) 
	{
		cadRes[c] = nombre[i];
		c++;
	}
	
	//cadRes = cadRes + aux
	//agregar el contenido de aux a cadRes...
	len = strlen(aux);
	
	for (int i = 0; i < len; i++)
	{
		cadRes[c] = aux[i];
		c++;
	}

	//cadRes = cadRes + prom
	if (prom == 10) {
		cadRes[c] = 49;
		c++;
		cadRes[c] = 48;
	}
	else {
		cadRes[c] = prom + 48;
	}

	c++; //retorna la cant de caracteres en la palabra ...

	return c;

}
#pragma endregion

#pragma region
int __stdcall infoTrabajador(char* cadRes, char* nombre, int horasTrabajadas, int salarioPorHora, int bon)
{
	int TotalSueldo = 0;

	_asm{ //Assembly inline
				
		mov eax, horasTrabajadas
		mov ebx, salarioPorHora

		mul ebx
		mov TotalSueldo, eax

	}
	


	return 0;
}

#pragma endregion

#pragma region

int __stdcall velocidad(char* cadRes, char* nombre, int distancia, int tiempo) {
	//a nombre no se le hara ningun cambio en este programa ... 
   //velocidad = distancia / tiempo 
	int velocidad;
	int pDecimal;
	_asm {
		mov eax, distancia
		mov ebx, tiempo
		mov edx, 0
		div ebx // eax / ebx => distancia / tiempo 
		mov pDecimal, edx
		mov velocidad, eax
	}
	//velocidad += pDecimal / tiempo; 
	int c = 0; //inicio de la cadena resultado c += addCadena2Cadena(cadRes, c, nombre); const char* aux = “ tiene una velociad de: “; //debe ser menor que len_buffer c += addCadena2Cadena(cadRes, c, aux); //Params: cadena en la que se concatenara, posicion de inicio del numero, numero a concatenar c += addNum2Cadena(cadRes, c, velocidad); //retorna la cantidad de caracteres en la palabra ... return c; } 
	c += addCadena2Cadena(cadRes, c, nombre);
	const char* aux = "tiene una velocidad de: ";
	c += addCadena2Cadena(cadRes, c, aux);
	c += addNum2Cadena(cadRes, c, velocidad);
	return c;
}

int __stdcall addCadena2Cadena(char* cadRes, int indice, const char* cadena) {
		int len = strlen(cadena);
		for (int i = 0; i < len; i++) //recorre cada caracter del nombre del carrito 
		{
			cadRes[indice] = cadena[i];
		indice++;
	}
	return len;
}
int __stdcall addNum2Cadena(char* cadRes, int indice, int numero) {
	//buscar cuantos digitos tiene la variables 
	int tempNumero = numero;
	int cont = 0; //almacena el total de digitos-1 
	while (tempNumero >= 10) {
		tempNumero /= 10; cont++;
	}
	//X = 1 //XX = 10 //XXX = 100 //XXXX = 1000 
	if (cont >= 1) {
		//se entra solo cuando son dos o mas digitos los que componen al numero 
		int div = 10;
		for (int i = 0; i < cont - 1; i++) {
			//busca encontrar al divisor 
			div = div * 10;
		} while (numero > 10) {
			//obtener el digito mas a la izquierda ... 
			int t = numero / div;
			cadRes[indice] = t + 48;
			indice++;
			numero = numero % div;
			div = div / 10;
		}
		cadRes[indice] = numero + 48;
		indice++;
	}
	else {
		//con = 0
		cadRes[indice] = numero + 48;
		indice++;
	}
	return cont + 1;
}

#pragma endregion

#pragma region
int* __stdcall sumaNumerosVector(char* cadRes, char* nombre, int* vector) {

	//int c = 0;

	_asm {
		mov esi, vector // almacena la ubicacion de memoria del vector inicio
		mov edi, esi	// respaldo de la posición de inicio del vector, 
		
		//como en nuestro vector la primera posicion es cuantos elementos tenemos,
		// entonces, se mueve a ecx, la primera posición para obtener la
		mov ecx, dword ptr[esi]	//cantidad de elementos que tiene el arreglo

		//la primera posicion "activa" / util para el vector, es la tercera posicion
		//como empiza en cero, la tercera posicion es igual a sumarle 8 a la pos inicial
		// 0 = 1era		4 = 2da		8 = 3era	....
		add esi, 8	// apartir de aqui operar con arreglo...

		//se usara eax como acumulador, se inicializa en cero
		mov eax, 0

		ciclo:
			
			add eax, dword ptr[esi] //obtiene el valor de la pos actual del apuntador..
			add esi , 4	//cambias a la sig pos, sumas 4 por 4 bytes por cada elemento del vector
			loop ciclo //repite el acceso al vector para realizar la suma la cant de elementos "activos"

		//a la posición de origen respaldada (edi) se le suma 4 para acceder a la 2da pos del vector
		//esta asociada al acumulador... 
		//una vez en esta pos se almacena en ella la suma de los digitos del vector
		mov dword ptr[edi+4], eax 
	}
	return vector;
}
#pragma endregion