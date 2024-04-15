// Nomes: Enzo Ramon Campa e Leandro Ceron Durau
#ifndef LOGGERI_RJ7GUO_H_
#define LOGGERI_RJ7GUO_H_

#include "LoggerS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class  Logger_i
  : public virtual POA_Logger
{
public:
  // Constructor
  Logger_i ();

  // Destructor
  virtual ~Logger_i ();

  virtual
  ::CORBA::Boolean verbose ();

  virtual
  void verbose (
    ::CORBA::Boolean verbose);

  virtual
  void log (
    ::Severidade severidade,
    const std::string endereco,
    ::CORBA::Short pid,
    const std::string hora,
    const std::string msg);

private:
  bool verbose_;
};


#endif /* LOGGERI_H_  */