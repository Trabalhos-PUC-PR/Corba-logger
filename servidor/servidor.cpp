//
// SERVIDOR DE CONTA SIMPLES
// Arquitetura de Sistemas Distribuídos, Paralelos e Concorrentes
// Escola Politécnica -- PUCPR
// Prof. Luiz Lima Jr. (laplima@ppgia.pucpr.br)
//

#include <iostream>
#include <fstream>
#include <string>
#include "LoggerI.h"
#include "tao/String_Alloc.h"
#include <orbsvcs/CosNamingC.h>

using namespace std;
using namespace CORBA;
using namespace PortableServer;
using namespace CosNaming;

ORB_var orb = ORB::_nil();

int main(int argc, char* argv[])
{
    // Verifica parametros da linha de comando
    if (argc < 2) {
		cerr << "USO: " << argv[0] << " <arq_ior>" << endl;
		return 1;
    }

    try {

		// 1. Inicia ORB
		cout << "Inciando ORB" << endl;
		orb = ORB_init(argc,argv,"orb");

		// 2. Ativa RootPOA
	    cout <<  "Ativando RootPOA" << endl;
		POA_var root_poa;
		Object_ptr tmp_ref;
		tmp_ref = orb->resolve_initial_references("RootPOA");
		root_poa = POA::_narrow(tmp_ref); // safe casting
		POAManager_var poa_manager = root_poa->the_POAManager();
		poa_manager->activate();

		// 3. Instancia "servants"
		cout << "Instanciando servant" << endl;
		Logger_i logger_i; // account name = ior file name

		// 4. Registra servos no POA, criando objetos distribuídos
		cout << "Registrando servos no POA (criando objetos CORBA)" << endl;
		Logger_var logger = logger_i._this(); // returns reference to the object

		tmp_ref = orb->resolve_initial_references("NameService");
		NamingContext_var sn = NamingContext::_narrow(tmp_ref);

		Name nome(1);
		nome.length(1);
		nome[0].id = string_dup(argv[1]);
		sn->rebind(nome, logger.in());
		cout << argv[1] << " publicado\n";
		// 5. Publica IOR
		cout <<  "Publicando IOR (arquivo \"" << argv[1] << "\")" << endl;
		String_var ior = orb->object_to_string(logger.in());
		ofstream arq_ior(argv[1]);
		arq_ior << ior << endl;
		arq_ior.close();

		// 6. Aguarda requisições
		cout << "Aguardando requisicoes...\n" << endl;
		orb->run();

		// 7. Finaliza
		root_poa->destroy(true,true);
		orb->destroy();

    } catch (Exception& e) {
		cerr << "CORBA exception: " << e << endl;
    }

    return 0;
}
