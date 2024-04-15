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


	  cerr << "0";		// 2. Obtém referêencia para o objeto distribuido
	try {
	  cerr << "1";		// 2. Obtém referêencia para o objeto distribuido
		// 1. Inicializa ORB
		ORB_var orb = ORB_init(argc, argv, "orb");

	  cerr << "2";		// 2. Obtém referêencia para o objeto distribuido
		Object_ptr ref;
	  cerr << "3";		// 2. Obtém referêencia para o objeto distribuido
		Logger_var logger;

	  cerr << "4";		// 2. Obtém referêencia para o objeto distribuido
		ref = orb->resolve_initial_references("NameService");
	  cerr << "5";		// 2. Obtém referêencia para o objeto distribuido
		NamingContext_var sn = NamingContext::_narrow(ref);

//	  cerr << "6";		// 2. Obtém referêencia para o objeto distribuido
//		Name nome(1);
//	  cerr << "7";		// 2. Obtém referêencia para o objeto distribuido
//		nome.length(1);
//	  cerr << "8";		// 2. Obtém referêencia para o objeto distribuido
//		nome[0].id = string_dup(argv[1]);
//	  cerr << "9";		// 2. Obtém referêencia para o objeto distribuido
//		ref = sn->resolve(nome);

	  cerr << "10";		// 2. Obtém referêencia para o objeto distribuido
		logger = Logger::_narrow(ref);

		string cmd;

	  cerr << "11";		// 2. Obtém referêencia para o objeto distribuido
		do{
		cout << "> ";
		cin >> cmd;
		if (cmd == "verbose"){
			bool alteracao = !logger->verbose();
			logger->verbose(alteracao);
		}else if (cmd == "log"){
			srand((unsigned) time(NULL));
			const auto now = std::chrono::system_clock::now();
			logger->log(Severidade::DEBUG, "endereco", 12, format("{:%d-%m-%Y %H:%M:%OS}", now), "Mensagem de erro!");
		}
		}while (cmd != "fim");
		// 3. Usa log

		// 4. Destroi ORB
	  cerr << "12";		// 2. Obtém referêencia para o objeto distribuido
		orb->destroy();

	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION: "<<e<<endl;
	}

	return 0;

}
