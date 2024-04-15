//
// CLIENTE DE CONTA BANCÁRIA SIMPLES
//
// Sistemas Distribuídos
// Escola Politécnica -- PUCPR
// (C) Prof. Luiz Lima Jr. (luiz.lima@pucpr.br)
//

#include <iostream>
#include "LoggerC.h"
#include "tao/String_Alloc.h"
#include <orbsvcs/CosNamingC.h>

using namespace std;
using namespace CORBA;
using namespace CosNaming;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;
	}

	try {
		// 1. Inicializa ORB
		ORB_var orb = ORB_init(argc, argv, "ORB");

		// 2. Obtém referêencia para o objeto distribuido
		Object_ptr ref;
		Logger_var log;

		ref = orb->string_to_object(argv[1]);
		NamingContext_var sn = NamingContext::_narrow(ref);

		Name nome(1);
		nome.length(1);
		nome[0].id = string_dup(argv[1]);

		ref = sn->resolve(nome);

		log = Logger::_narrow(ref);

		// 3. Usa log


	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION: "<<e<<endl;
	}

}
