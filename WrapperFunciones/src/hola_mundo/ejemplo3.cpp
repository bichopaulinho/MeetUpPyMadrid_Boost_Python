/*
 * ejemplo3.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: Pedro Valiente Verde
 */

#include <iostream>
#include <string>

#include <boost/python.hpp>

void HolaMundo(const std::string &texto = "Hola python madrid") {
	std::cout << texto << std::endl;
}

// Sin la macro, no detecta los argumentos por defecto
BOOST_PYTHON_FUNCTION_OVERLOADS(sobre_carga_modificar_texto, HolaMundo, 0,
		1);

BOOST_PYTHON_MODULE(ejemplo3)
{
	boost::python::def("hola_mundo", HolaMundo,
			sobre_carga_modificar_texto(
					"Muestra por la pantalla el texto introducido\nArgumentos: \n\t texto: texto a mostrar"));
}

