//
// CLIENTE DE CONTA BANCÁRIA SIMPLES
//
// Sistemas Distribuídos
// Escola Politécnica -- PUCPR
// (C) Prof. Luiz Lima Jr. (luiz.lima@pucpr.br)
//

#include <iostream>
#include "LoggerC.h"  // stub

using namespace std;
using namespace CORBA;

int main(int argc, char* argv[])
{
    try {
	    // 1. Inicializa ORB
        ORB_var orb = ORB_init(argc, argv, "ORB");

	    // 2. Obtém referência para objeto distirbuído (da IOR)
				Object_ptr ref = orb->string_to_object(argv[1]);
        auto logger = Logger::_narrow(ref);

			// 3. Usa objeto (chama métodos)
			logger->log(Severidade::DEBUG, "sim", 12, "horario", "log");
			

	    // 4. Finalizações
        orb->destroy();
    } catch (const Exception& e) {
        cerr << "ERRO CORBA: " << e << endl;
    }

	return 0;
}
