#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;

class Estudiante : Persona{

private: string carnet;

public: 
	Estudiante() {
	}
	Estudiante(string ca, string nom, string ape, string dir, int tel, int gen, string em, string fn) : Persona(nom, ape, dir, tel, gen, em, fn) {
		carnet = ca;
	}
	 
	void setCarnet(string ca) { carnet = ca; }
	void setNombre(string nom) { nombres = nom; }
	void setApellido(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setGenero(int gen) { genero = gen; }
	void setEmail(string em) { email = em; }
	void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }

	string getCarnet() { return carnet; }
	string getNombre() { return nombres; }
	string getApellido() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	int getGenero() { return genero; }
	string getEmail() { return email; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }

	//metodos
	~Estudiante() {} 

	void crear() {
		int q_estado;
		ConexionBD conectar = ConexionBD();
		conectar.abrirConexion();
		if (conectar.getconexion()) {
			string query = "INSERT INTO estudiantes (carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento) VALUES  ('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + to_string(telefono) + "," + to_string(genero) + ",'" + email + "','" + fecha_nacimiento + "');";
			const char* i = query.c_str();
			q_estado = mysql_query(conectar.getconexion(), i);
			if (!q_estado) {
				cout << "El ingreso de datos ha sido exitoso" << endl;
			}
			else
			{
				cout << "Error al ingresar la informacion" << endl;
			}
		}
		else
		{
			cout << "La conexión en la base de datos no ha podido completarse, intente más tarde " << endl;
		}
		conectar.cerrarConexion();
	}
	void leer() {
		int q_estado;
		ConexionBD conectar = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		conectar.abrirConexion();

		if (conectar.getconexion()) {

			cout << "---------- Datos de Estudiantes ----------" << endl;
			string query = "Select * from estudiantes";
			const char* c = query.c_str();
			q_estado = mysql_query(conectar.getconexion(), c);
			if (!q_estado) {
				resultado = mysql_store_result(conectar.getconexion());
				cout << "ID ESTUDIANTE  |   CARNET   |  NOMBRES  |   APELLIDOS   |   DIRECCION   |   TELEFONO   |   GENERO   |   EMAIL   | FECHA DE NACIMIENTO   " << endl;
				while (fila = mysql_fetch_row(resultado))
				{
					cout << fila[0] << " - " << fila[1] << " - " << fila[2] << " - " << fila[3] << " - " << fila[4] << " - " << fila[5] << " - " << fila[6] << " - " << fila[7] << " - " << fila[8] << endl;
				}
			}
			else
			{
				cout << "Error al consultar la informacion" << endl;
			}
		}
		else
		{
			cout << "Error en la conexion, intenta de nuevo :)" << endl;
		}
		conectar.cerrarConexion();

	}
	void actualizar(int _id) {
		int q_estado;
		ConexionBD conectar = ConexionBD();
		conectar.abrirConexion();

		if (conectar.getconexion()) {
			string query = "UPDATE estudiantes SET carnet ='" + carnet + "' , nombres = '" + nombres + "' , apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = " + to_string(telefono) + ", genero = " + to_string(genero) + ", email = '" + email + "', fecha_nacimiento = '" + fecha_nacimiento + "' WHERE id_estudiante = " + to_string(_id) + " ;";
			const char* i = query.c_str();
			q_estado = mysql_query(conectar.getconexion(), i);
			if (!q_estado) {
				cout << "El ingreso de datos ha sido exitoso" << endl;
			}
			else
			{
				cout << "Error al actualizar la informacion" << endl;
			}
		}
		else
		{
			cout << "Error en la conexion, intenta de nuevo :)" << endl;
		}
		conectar.cerrarConexion();

	}
	void borrar(int _id) {
		int q_estado;
		ConexionBD conectar = ConexionBD();
		conectar.abrirConexion();
		if (conectar.getconexion()) {
			string idE = to_string(_id);
			string query = "DELETE FROM estudiantes WHERE " + idE + ";";

			const char* c = query.c_str();
			q_estado = mysql_query(conectar.getconexion(), c);
			if (!q_estado) {
				cout << "El usuario a sido eliminado exitosamente" << endl;
			}
			else
			{
				cout << "Error al eliminar la informacion" << endl;
			}

		}
		else
		{
			cout << "Error en la conexion, intenta de nuevo :)" << endl;
		}
		conectar.cerrarConexion();

	}

};