/*
Universidad De La Salle Bajío
Ingeniería de Software y Sistemas Computacionales
Metodología y Programación de Sistemas
Autor: Angel Fabricio Zacarías Guzmán && Daniel Eduardo Lozano Rodriguez
Grupo: 111   Matrícula: 67664 -- 68070
Programa: PROYECTO SEGUNDO PARCIAL
Descripción: Timbiriche
fecha 30/10/2018
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;
void todo();

void imptablero(int e);
void turnos();
int ciclo(int num);
void turnos2();

void validacion1();
void rectificacionj1(int num);
void imptablero1(int num);
void valfin1(int num);

void validacion2();
void rectificacionj2(int num);
void imptablero2(int num);
void valfin2(int num);

void ganador();
void ganador2();

void maquina();
void validacion3();
void rectificacionj3();
void imptablero3(int num);
void valfin3(int num);

int asignar(int num);
void reciclo(int num);

int numeros[2][100][100], sum[3] = {0, 0, 0}, p, numfil = 0, numcol = 0, mult = 0, maqui = 0, rec = 0;
string G[100][100];

int main()
{
	int col, fil;
	cout << "**** Timbiriche ****\n\n";
	cout << "Contra quien desea jugar 1.- Maquina  2.- Jugador 2\n";
	cin >> maqui;
	while (maqui > 2 || maqui < 1)
	{
		cout << "Valor incorrecto intentelo de nuevo: ";
		cin >> maqui;
	}
	system("cls");
	cout << "Cuantas filas desea que tenga el timbiriche: ";
	cin >> fil;
	cout << "Cuantas columas desea que tenga el timbiriche: ";
	cin >> col;
	system("cls");
	numfil = (fil * 2) + 1;
	numcol = (col * 2) + 1;
	mult = fil * col;
	if (maqui == 2)
	{
		todo();
	}
	else
	{
		maquina();
	}
	system("pause");
	return 0;
}

void maquina()
{
	int e = 1;
	imptablero(e);
	turnos2();
	ganador2();
	return;
}
void ganador2()
{
	if (sum[0] > sum[1])
	{
		cout << "\n El ganador es el jugador 1" << endl;
	}
	else
	{
		if (sum[0] == sum[1])
		{
			cout << "\n Es un rotundo empate" << endl;
		}
		else
		{
			cout << "\n El ganador es la consola" << endl;
		}
	}
	return;
}
void turnos2()
{
	int i = 0;
	do
	{

		if (i % 2 == 0)
		{
			validacion1();
		}
		else
		{
			validacion3();
		}
		i = i + 1;
	} while (sum[2] != numeros[0][numfil - 1][numcol - 2]);
	return;
}
void validacion3()
{
	sum[2] = sum[2] + 1;
	rectificacionj3();
	return;
}
void rectificacionj3()
{
	int num = 0;
	rec = 0;
	random_device rd;
	default_random_engine end(rd());
	uniform_int_distribution<> inte(1, numeros[0][numfil - 1][numcol - 2]);
	reciclo(num);
	if (rec == 1)
	{
		num = asignar(num);
	}
	else
	{
		num = inte(end);
	}

	p = ciclo(num);
	if (p == 0)
	{
		sum[2] = sum[2] - 1;
		validacion3();
	}
	else
	{
		cout << "Maquina elige: " << num << endl;
		system("pause");
		system("cls");

		for (int j = 0; j < numfil; j++)
		{
			if (j % 2 == 0)
			{
				for (int i = 0; i < numcol; i++)
				{
					if (i % 2 == 0)
					{
					}

					else
					{
						if (numeros[0][j][i] == num)
						{
							numeros[1][j][i] = 0;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < numcol; i++)
				{
					if (i % 2 == 0)
					{
						if (numeros[0][j][i] == num)
						{
							numeros[1][j][i] = 0;
						}
					}
				}
			}
		}
		for (int a = 0; a < mult; a++)
		{
			valfin3(num);
		}
		if (p == 0)
		{
		}
		else
		{
			imptablero3(num);
		}
	}
	return;
}
void imptablero3(int num)
{
	for (int j = 0; j < numfil; j++)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
					cout << " +\t";
				}
				else
				{
					if (numeros[0][j][i] == num)
					{
						numeros[1][j][i] = 0;
						G[j][i] = "Ma";
						cout << " " << G[j][i] << "\t";
					}
					else
					{
						cout << " " << G[j][i] << "\t";
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
					if (numeros[0][j][i] == num)
					{
						numeros[1][j][i] = 0;
						G[j][i] = "Ma";
						cout << " " << G[j][i] << "\t";
					}
					else
					{

						cout << " " << G[j][i] << "\t";
					}
				}
				else
				{
					cout << " " << G[j][i] << "\t";
				}
			}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
	return;
}
void valfin3(int num)
{
	int sig = 0;
	for (int i = 0; i < numfil; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j < numcol; j++)
			{
				if (j % 2 != 0)
				{
					if (numeros[1][i - 1][j] == 0 && numeros[1][i][j - 1] == 0 && numeros[1][i][j + 1] == 0 && numeros[1][i + 1][j] == 0)
					{
						if (numeros[1][i][j] == 1)
						{
							numeros[1][i][j] = 0;
							G[i][j] = "Ma";
							sum[1] = sum[1] + 1;
							sig = sig + 1;
						}
					}
				}
			}
		}
	}
	if (sig > 0)
	{
		imptablero3(num);
		if (sum[2] == numeros[0][numfil - 1][numcol - 2])
		{
			p = 0;
		}
		else
		{
			validacion3();
		}
		p = 0;
	}
	return;
}

void todo()
{
	int e = 1;
	imptablero(e);
	turnos();
	ganador();
	return;
}

void imptablero(int e)
{
	for (int j = 0; j < numfil; j++)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
					cout << " +\t";
				}
				else
				{
					numeros[1][j][i] = 1;
					numeros[0][j][i] = e;
					G[j][i] = to_string(numeros[0][j][i]);
					cout << " " << G[j][i] << "\t";
					e++;
				}
			}
		}
		else
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
					numeros[1][j][i] = 1;
					numeros[0][j][i] = e;
					G[j][i] = to_string(numeros[0][j][i]);
					cout << " " << G[j][i] << "\t";
					e++;
				}
				else
				{
					numeros[1][j][i] = 1;
					G[j][i] = " ";
					cout << " " << G[j][i] << "\t";
				}
			}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
	return;
}
void turnos()
{
	int i = 0;
	do
	{

		if (i % 2 == 0)
		{
			validacion1();
		}
		else
		{
			validacion2();
		}
		i = i + 1;
	} while (sum[2] != numeros[0][numfil - 1][numcol - 2]);
	return;
}
int ciclo(int num)
{
	p = 0;
	for (int j = 0; j < numfil; j++)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
				}
				else
				{
					if (numeros[0][j][i] == num)
					{
						p = numeros[1][j][i];
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
					if (numeros[0][j][i] == num)
					{
						p = numeros[1][j][i];
					}
				}
			}
		}
	}
	return p;
}

void validacion1()
{
	int num;
	sum[2] = sum[2] + 1;
	cout << "Que Numero Elige Jugador 1: ";
	cin >> num;
	system("cls");
	rectificacionj1(num);
	return;
}
void rectificacionj1(int num)
{
	p = ciclo(num);
	if (p == 0)
	{
		cout << "Valor incorrecto intentelo de nuevo: ";
		sum[2] = sum[2] - 1;
		validacion1();
	}
	else
	{
		for (int j = 0; j < numfil; j++)
		{
			if (j % 2 == 0)
			{
				for (int i = 0; i < numcol; i++)
				{
					if (i % 2 == 0)
					{
					}
					else
					{
						if (numeros[0][j][i] == num)
						{
							numeros[1][j][i] = 0;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < numcol; i++)
				{
					if (i % 2 == 0)
					{
						if (numeros[0][j][i] == num)
						{
							numeros[1][j][i] = 0;
						}
					}
				}
			}
		}
		for (int a = 0; a < mult; a++)
		{
			valfin1(num);
		}
		if (p == 0)
		{
		}
		else
		{
			imptablero1(num);
		}
	}
	return;
}
void imptablero1(int num)
{
	for (int j = 0; j < numfil; j++)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
					cout << " +\t";
				}
				else
				{
					if (numeros[0][j][i] == num)
					{
						numeros[1][j][i] = 0;
						G[j][i] = "J1";
						cout << " " << G[j][i] << "\t";
					}
					else
					{
						cout << " " << G[j][i] << "\t";
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
					if (numeros[0][j][i] == num)
					{
						numeros[1][j][i] = 0;
						G[j][i] = "J1";
						cout << " " << G[j][i] << "\t";
					}
					else
					{

						cout << " " << G[j][i] << "\t";
					}
				}
				else
				{
					cout << " " << G[j][i] << "\t";
				}
			}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
	return;
}
void valfin1(int num)
{
	int sig = 0;
	for (int i = 0; i < numfil; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j < numcol; j++)
			{
				if (j % 2 != 0)
				{
					if (numeros[1][i - 1][j] == 0 && numeros[1][i][j - 1] == 0 && numeros[1][i][j + 1] == 0 && numeros[1][i + 1][j] == 0)
					{
						if (numeros[1][i][j] == 1)
						{
							numeros[1][i][j] = 0;
							G[i][j] = "G1";
							sum[0] = sum[0] + 1;
							sig = sig + 1;
						}
					}
				}
			}
		}
	}
	if (sig > 0)
	{
		imptablero1(num);
		if (sum[2] == numeros[0][numfil - 1][numcol - 2])
		{
			p = 0;
		}
		else
		{
			validacion1();
		}
		p = 0;
	}
	return;
}

void validacion2()
{
	int num;
	sum[2] = sum[2] + 1;
	cout << "Que Numero Elige Jugador 2: ";
	cin >> num;
	system("cls");
	rectificacionj2(num);
	return;
}
void rectificacionj2(int num)
{
	p = ciclo(num);
	if (p == 0)
	{
		cout << "Valor incorrecto intentelo de nuevo: ";
		sum[2] = sum[2] - 1;
		validacion2();
	}
	else
	{
		for (int j = 0; j < numfil; j++)
		{
			if (j % 2 == 0)
			{
				for (int i = 0; i < numcol; i++)
				{
					if (i % 2 == 0)
					{
					}
					else
					{
						if (numeros[0][j][i] == num)
						{
							numeros[1][j][i] = 0;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < numcol; i++)
				{
					if (i % 2 == 0)
					{
						if (numeros[0][j][i] == num)
						{
							numeros[1][j][i] = 0;
						}
					}
				}
			}
		}
		for (int a = 0; a < mult; a++)
		{
			valfin2(num);
		}
		if (p == 0)
		{
		}
		else
		{
			imptablero2(num);
		}
	}
	return;
}
void imptablero2(int num)
{
	for (int j = 0; j < numfil; j++)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
					cout << " +\t";
				}
				else
				{
					if (numeros[0][j][i] == num)
					{
						numeros[1][j][i] = 0;
						G[j][i] = "J2";
						cout << " " << G[j][i] << "\t";
					}
					else
					{
						cout << " " << G[j][i] << "\t";
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i % 2 == 0)
				{
					if (numeros[0][j][i] == num)
					{
						numeros[1][j][i] = 0;
						G[j][i] = "J2";
						cout << " " << G[j][i] << "\t";
					}
					else
					{

						cout << " " << G[j][i] << "\t";
					}
				}
				else
				{
					cout << " " << G[j][i] << "\t";
				}
			}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
	return;
}
void valfin2(int num)
{
	int sig = 0;
	for (int i = 0; i < numfil; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j < numcol; j++)
			{
				if (j % 2 != 0)
				{
					if (numeros[1][i - 1][j] == 0 && numeros[1][i][j - 1] == 0 && numeros[1][i][j + 1] == 0 && numeros[1][i + 1][j] == 0)
					{
						if (numeros[1][i][j] == 1)
						{
							numeros[1][i][j] = 0;
							G[i][j] = "G2";
							sum[1] = sum[1] + 1;
							sig = sig + 1;
						}
					}
				}
			}
		}
	}
	if (sig > 0)
	{
		imptablero2(num);
		if (sum[2] == numeros[0][numfil - 1][numcol - 2])
		{
			p = 0;
		}
		else
		{
			validacion2();
		}
		p = 0;
	}
	return;
}

void ganador()
{
	if (sum[0] > sum[1])
	{
		cout << "\n El ganador es el jugador 1" << endl;
	}
	else
	{
		if (sum[0] == sum[1])
		{
			cout << "\n Es un rotundo empate" << endl;
		}
		else
		{
			cout << "\n El ganador es el jugador 2" << endl;
		}
	}
	return;
}

int asignar(int num)
{
	int sig = 0;
	rec = 0;
	for (int i = 0; i < numfil; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j < numcol; j++)
			{
				if (j % 2 != 0)
				{
					if (numeros[1][i - 1][j] == 1 && numeros[1][i][j - 1] == 0 && numeros[1][i][j + 1] == 0 && numeros[1][i + 1][j] == 0 && rec == 0)
					{
						num = numeros[0][i - 1][j];
						rec = 1;
					}
					else
					{
						if (numeros[1][i - 1][j] == 0 && numeros[1][i][j - 1] == 1 && numeros[1][i][j + 1] == 0 && numeros[1][i + 1][j] == 0 && rec == 0)
						{
							num = numeros[0][i][j - 1];
							rec = 1;
						}
						else
						{
							if (numeros[1][i - 1][j] == 0 && numeros[1][i][j - 1] == 0 && numeros[1][i][j + 1] == 1 && numeros[1][i + 1][j] == 0 && rec == 0)
							{
								num = numeros[0][i][j + 1];
								rec = 1;
							}
							else
							{
								if (numeros[1][i - 1][j] == 0 && numeros[1][i][j - 1] == 0 && numeros[1][i][j + 1] == 0 && numeros[1][i + 1][j] == 1 && rec == 0)
								{
									num = numeros[0][i + 1][j];
									rec = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	return num;
}
void reciclo(int num)
{
	int sig = 0;
	rec = 0;
	for (int i = 0; i < numfil; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j < numcol; j++)
			{
				if (j % 2 != 0)
				{
					if (numeros[1][i - 1][j] == 1 && numeros[1][i][j - 1] == 0 && numeros[1][i][j + 1] == 0 && numeros[1][i + 1][j] == 0 && rec == 0)
					{
						rec = 1;
					}
					else
					{
						if (numeros[1][i - 1][j] == 0 && numeros[1][i][j - 1] == 1 && numeros[1][i][j + 1] == 0 && numeros[1][i + 1][j] == 0 && rec == 0)
						{

							rec = 1;
						}
						else
						{
							if (numeros[1][i - 1][j] == 0 && numeros[1][i][j - 1] == 0 && numeros[1][i][j + 1] == 1 && numeros[1][i + 1][j] == 0 && rec == 0)
							{

								rec = 1;
							}
							else
							{
								if (numeros[1][i - 1][j] == 0 && numeros[1][i][j - 1] == 0 && numeros[1][i][j + 1] == 0 && numeros[1][i + 1][j] == 1 && rec == 0)
								{

									rec = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	return;
}
