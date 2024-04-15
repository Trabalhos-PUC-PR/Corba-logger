// Enzo Ramon Campa e Leandro Ceron Durau

#include <iostream>
#include <string>
#include "LoggerC.h"
#include <orbsvcs/CosNamingC.h>
#include <time.h>


using namespace std;
using namespace CORBA;
using namespace CosNaming;

int main(int argc, char* argv[])
{
        if (argc < 2) {
                cerr << "USO: " << argv[0] << " file://<ior_file>" << endl;
                return 1;
        }

        try {
                // 1. Inicializa ORB
                ORB_var orb = ORB_init(argc,argv,"ORB");

                // 2. Obtém referência para o objeto distribuído
                Object_ptr ref;
                Logger_var log;

                // ref = orb->string_to_object(argv[1]);
        
                ref = orb->resolve_initial_references("NameService");
                NamingContext_var sn = NamingContext::_narrow(ref);

                Name nome(1);
                nome.length(1);
                nome[0].id = string_dup(argv[1]);
                ref = sn->resolve(nome);

                log = Logger::_narrow(ref);

                // 3. Usa log
                string cmd;
                string sev;
                Severidade seve;
                string porta;
                cout << "Comandos:\nlog(severidade)\nverbose\nsair" << endl;

                do{
                        cout << "> ";
                        cin >> cmd;

                        if (cmd == "log"){
                                auto Timer = chrono::system_clock::now();
                                time_t tempo = chrono::system_clock::to_time_t(Timer);
                                
                                std::tm tm = *std::localtime(&tempo);
                                int hora = tm.tm_hour;
                                int min = tm.tm_min;
                                int seg = tm.tm_sec;

                                std::stringstream ss;
                                ss << setfill('0') << setw(2) << hora << ":" << setw(2) << min << ":" << setw(2) << seg <<" de 1/1/1970";

                                string horas = ss.str();

                                cout << "Coloque a severidade:\n1 - Debug\n2 - Warning\n3 - Error\n4 - Critical" << endl;
                                cout << "> ";
                                cin >> sev;
                                if (sev == "1")seve == Severidade::DEBUG;
                                else if (sev == "2")seve == Severidade::WARNING;
                                else if (sev == "3")seve == Severidade::ERROR;
                                else if (sev == "4")seve == Severidade::CRITICAL;
                                else {
                                        cout << "Severidade Incorreta" << endl;
                                        continue;
                                }
                                cout << "Coloque a msg de Log:\n> ";
                                string msg;
                                cin >> msg;
                                log->log(seve,"127.0.0.0::1234",21, horas,msg);                 
                        }
                        else if (cmd == "verbose"){
                                bool verboser = log->verbose();
                                if(verboser) log->verbose(false);
                                else log->verbose(true);
                        }
                        else {
                                cout << "Comando Incorreto" << endl;
                        }


                }while (cmd != "sair");

                // 4. Destroi ORB
                orb->destroy();
        } catch (CORBA::Exception& e) {
                cerr << "CORBA EXCEPTION:" << e << endl;
        }

        return 0;
}