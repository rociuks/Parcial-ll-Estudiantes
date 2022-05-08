#pragma once
#include <iostream>
using namespace std;
class Persona
{
protected:
	string nombres, apellidos, direccion, email, fecha_nacimiento;
	int telefono, genero;
protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, int tel, int gen, string em, string fn) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		email = em;
		fecha_nacimiento = fn;
		telefono = tel;
		genero = gen;
	}
};

