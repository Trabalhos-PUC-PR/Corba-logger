// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v3.1.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       https://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     https://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:1567

#ifndef LOGGERI_NGWPAI_H_
#define LOGGERI_NGWPAI_H_

#include "LoggerS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

extern bool verbose_state;

class  Logger_i
  : public virtual POA_Logger
{
public:
	bool isVerbose;
	short counter;
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
    ::CORBA::UShort pid,
    const std::string hora,
    const std::string msg);
  
	virtual
  ::CORBA::UShort count ();
};


#endif /* LOGGERI_H_  */
