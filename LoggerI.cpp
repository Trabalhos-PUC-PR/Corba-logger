// Nomes:  Enzo Ramon Campa e Leandro Ceron Durau
#include "LoggerI.h"
#include <iostream>

using namespace std;
// Implementation skeleton constructor
Logger_i::Logger_i ()
{
        verbose_ = true;
}

// Implementation skeleton destructor
Logger_i::~Logger_i ()
{
}

::CORBA::Boolean Logger_i::verbose ()
{
        return verbose_;
}

void Logger_i::verbose (
  ::CORBA::Boolean verbose)
{
        verbose_ = verbose;
}

void Logger_i::log (
  ::Severidade severidade,
  const std::string endereco,
  ::CORBA::Short pid,
  const std::string hora,
  const std::string msg)
{
        if(verbose_){
                std::string sever = "";
                if(severidade == Severidade::DEBUG)sever = "Debug";
                if(severidade == Severidade::WARNING)sever = "Warning";
                if(severidade == Severidade::ERROR)sever = "Error";
                if(severidade == Severidade::CRITICAL)sever = "Critical";
                cout << "Severidade: " << sever << endl;
                cout << "Endereco: " << endereco << endl;
                cout << "Pid: " << pid << endl;
                cout << "Hora: " << hora << endl;
                cout << "Msg: " << msg << endl;

        }
}