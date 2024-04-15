// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v3.1.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       https://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     https://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:1621

#include "LoggerI.h"
#include "LoggerC.h"
#include <cstdio>
#include <string>
#include <iostream>

// Implementation skeleton constructor
Logger_i::Logger_i ()
{
	isVerbose = false;
}

// Implementation skeleton destructor
Logger_i::~Logger_i ()
{
}

::CORBA::Boolean Logger_i::verbose ()
{
	return isVerbose;
}

void Logger_i::verbose (
  ::CORBA::Boolean verbose)
{
	isVerbose = verbose;
}

void Logger_i::log (
  ::Severidade severidade,
  const std::string endereco,
  ::CORBA::UShort pid,
  const std::string hora,
  const std::string msg)
{
	
	if(verbose()){
		std::string severidade_str;
		switch (severidade) {
			case(DEBUG):
				severidade_str = "DEBUG";
				break;
			case(WARNING):
				severidade_str = "WARNING";
				break;
			case(ERROR):
				severidade_str = "ERROR";
				break;
			case(CRITICAL):
				severidade_str = "CRITICAL";
				break;
		}
		std::cout << severidade_str;
		std::cout << " > pid:";
		std::cout << pid;
		std::cout << " @" ;
		std::cout << endereco;
		std::cout << " - [";
		std::cout << hora;
		std::cout << "] - ";
		std::cout << msg << std::endl;
	}

}

