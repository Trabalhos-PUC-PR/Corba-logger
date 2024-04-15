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
		ORB_var orb = ORB_init(argc, argv, "orb");

		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;
		// 2. Obtém referêencia para o objeto distribuido
		Object_ptr ref;
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;
		Logger_var log;
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;

		ref = orb->resolve_initial_references("NameService");
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;
		NamingContext_var sn = NamingContext::_narrow(ref);
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;

		Name nome(1);
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;
		nome.length(1);
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;
		nome[0].id = string_dup(argv[1]);
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;
		ref = sn->resolve(nome);
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;

		log = Logger::_narrow(ref);
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;

		// 3. Usa log
		log->log(Severidade::DEBUG, "endereço", 12,"data", "mensagem");
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;

		// 4. Destroi ORB
		orb->destroy();
		cerr << "USO: "<<argv[0]<<" file://<ior_file>"<<endl;

	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION: "<<e<<endl;
	}

	return 0;

}
