//stdafx.h: archivo de inclusión de los archivos estándar del sistema 
//o archivos de inclusión escpecíficos de un proyecto utilizados frecuentemente
// en 
#pragma once

#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows
// Archivos de encabezado de Windows
#include <windows.h>
extern "C" __declspec(dllexport) int __stdcall suma(int a, int b);
extern "C" __declspec(dllexport) int __stdcall largo_cadena(const char* str);
extern "C" __declspec(dllexport) int __stdcall escribir_cadena(const char* str, int len_buffer);

//unidad 4 . 2023-1 PromUsuario
extern "C" __declspec(dllexport) int __stdcall promedioDeUsuario(char* cadRes, char* nombre, int cal1, int cal2, int cal3);

//Unidad 4 . 2023-1 Mayo InfoTrabajador
extern "C" __declspec(dllexport) int __stdcall infoTrabajador(char* cadRes, char* nombre, int horasTrabajadas, int salarioPorHora, int bonificaciones);

//Unidad 4 . 2023-1 VarianteVelocidad
extern "C" __declspec(dllexport) int __stdcall velocidad(char* cadRes, char* nombre, int distancia, int tiempo);
extern "C" __declspec(dllexport) int __stdcall addNum2Cadena(char* cadRes, int indice, int numero);
extern "C" __declspec(dllexport) int __stdcall addCadena2Cadena(char* cadRes, int indice, const char* cadena);
extern "C" __declspec(dllexport) int* __stdcall sumaNumerosVector(char* cadRes, char* nombre, int* vector);