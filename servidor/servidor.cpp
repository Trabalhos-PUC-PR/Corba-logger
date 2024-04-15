#include <iostream>
#include <fstream>
#include "LoggerI.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/String_Alloc.h"
#include <orbsvcs/CosNamingC.h>

using namespace std;
using namespace CORBA;
using namespace PortableServer;
using namespace CosNaming;

int main(int argc, char* argv[])
{
	try {
		// 1. Inicia ORB
		ORB_var orb = ORB_init(argc, argv, "ORB");
		
		// 2. Ativa RootPOA
		POA_var root_poa;
		Object_ptr tmp_ref;
		tmp_ref = orb->resolve_initial_references("RootPOA");
		root_poa = POA::_narrow(tmp_ref);
		auto poa_manager = root_poa->the_POAManager();
		poa_manager->activate();

		// 3. Instancia "servants"
		Logger_i log_i;

		// 4. Registra servos no POA, criando objetos distribuídos
		auto account = log_i._this();

		// 5. Publica iostream

		// 5.2. Conectar com servidor de nomes
		tmp_ref = orb->resolve_initial_references("NameService");
		auto sn = NamingContext::_narrow(tmp_ref);

		Name nome(1);
		nome.length(1);
		nome[0].id = string_dup(argv[1]);

		// 6. Aguarda reqs
		orb->run();

		// 7. Finaliza
		root_poa->destroy(true, true);
		orb->destroy();

		
	} catch (const Exception& e) {
		cerr << "erro corba: " << e << endl;
	}

    return 0;
}
