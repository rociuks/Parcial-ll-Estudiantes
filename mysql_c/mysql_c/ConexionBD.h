#pragma once
#include <iostream>
#include <mysql.h>
using namespace std;
class ConexionBD
{
private:
	MYSQL* conexion;
public:
	ConexionBD() {};
	void abrirConexion() {
		conexion = mysql_init(0);
		conexion = mysql_real_connect(conexion, "localhost", "usr_escuela", "Escuel@123", "db_escuela", 3306, NULL, 0);
	}
	MYSQL* getconexion() {
		return conexion;
	}
	void cerrarConexion() {
		mysql_close(conexion);
	}
};