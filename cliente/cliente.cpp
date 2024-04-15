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
		ORB_var orb = ORB_init(argc, argv, "orb");

		Object_ptr ref;
		Logger_var logger;

		ref = orb->resolve_initial_references("NameService");
		NamingContext_var sn = NamingContext::_narrow(ref);

		Name nome(1);
		nome.length(1);
		nome[0].id = string_dup(argv[1]);

		ref = sn->resolve(nome);

		logger = Logger::_narrow(ref);

		string cmd;

		do{
			cout << "> ";
			cin >> cmd;
			if (cmd == "verbose"){
				logger->verbose(!logger->verbose());
			}else if (cmd == "log"){
				const auto now = std::chrono::system_clock::now();
				logger->log(Severidade::ERROR, "127.0.0.1:4200", 12, format("{:%d-%m-%Y %H:%M:%OS}", now), "Erro no angular!");
			}
		} while (cmd != "fim");
		// 3. Usa log
		orb->destroy();

	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION: "<<e<<endl;
	}

	return 0;

}
