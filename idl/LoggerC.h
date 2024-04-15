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
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:148

#ifndef _TAO_IDL_LOGGERC_QR7ZAE_H_
#define _TAO_IDL_LOGGERC_QR7ZAE_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include <string>
#include <vector>

#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Basic_Argument_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#if TAO_MAJOR_VERSION != 3 || TAO_MINOR_VERSION != 1 || TAO_MICRO_VERSION != 3
#error This file should be regenerated with TAO_IDL
#endif
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_root/root_ch.cpp:155


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/enum_ch.cpp:39

enum Severidade
{
  DEBUG,
  WARNING,
  ERROR,
  CRITICAL
};

typedef Severidade &Severidade_out;
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:33

extern  ::CORBA::TypeCode_ptr const _tc_Severidade;
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_interface.cpp:742



#if !defined (_LOGGER__VAR_OUT_CH_)
#define _LOGGER__VAR_OUT_CH_

class Logger;
using Logger_ptr = Logger*;
using Logger_var = TAO_Objref_Var_T<Logger>;
using Logger_out = TAO_Objref_Out_T<Logger>;

#endif /* end #if !defined */


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:39



class  Logger
  : public virtual ::CORBA::Object
{
public:
  friend class TAO::Narrow_Utils<Logger>;
  // TAO_IDL - Generated from
  // /opt/ACE_wrappers/TAO/TAO_IDL/be/be_type.cpp:297

  using _ptr_type = Logger_ptr;
  using _var_type = Logger_var;
  using _out_type = Logger_out;

  static void _tao_any_destructor (void *);

  // The static operations.
  static Logger_ptr _duplicate (Logger_ptr obj);

  static void _tao_release (Logger_ptr obj);

  static Logger_ptr _narrow (::CORBA::Object_ptr obj);
  static Logger_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
  static Logger_ptr _nil ();

  virtual ::CORBA::Boolean verbose ();

  virtual void verbose (
    ::CORBA::Boolean verbose);

  virtual void log (
    ::Severidade severidade,
    const std::string endereco,
    ::CORBA::UShort pid,
    const std::string hora,
    const std::string msg);

  
  // TAO_IDL - Generated from
  // /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:135

  

  virtual ::CORBA::Boolean _is_a (const char *type_id);
  virtual const char* _interface_repository_id () const;
  virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);

protected:
  // Concrete interface only.
  Logger ();

  // Concrete non-local interface only.
  Logger (::IOP::IOR *ior, TAO_ORB_Core *orb_core);
  
  // Non-local interface only.
  Logger (
      TAO_Stub *objref,
      ::CORBA::Boolean _tao_collocated = false,
      TAO_Abstract_ServantBase *servant = nullptr,
      TAO_ORB_Core *orb_core = nullptr);

  virtual ~Logger () = default;

private:
  // Private and unimplemented for concrete interfaces.
  Logger (const Logger &) = delete;
  Logger (Logger &&) = delete;
  Logger &operator= (const Logger &) = delete;
  Logger &operator= (Logger &&) = delete;
};
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:33

extern  ::CORBA::TypeCode_ptr const _tc_Logger;
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:64



TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
  // TAO_IDL - Generated from
  // /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:889

  

  template<>
  class Arg_Traits< ::Severidade>
    : public
        Basic_Arg_Traits_T<
            ::Severidade,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:142

  

#if !defined (_LOGGER__ARG_TRAITS_)
#define _LOGGER__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::Logger>
    : public Object_Arg_Traits_T<
        ::Logger_ptr,
        ::Logger_var,
        ::Logger_out,
        TAO::Objref_Traits<Logger>,
        TAO::Any_Insert_Policy_Stream>
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_traits.cpp:58



TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_LOGGER__TRAITS_)
#define _LOGGER__TRAITS_

  template<>
  struct  Objref_Traits< ::Logger>
  {
    static ::Logger_ptr duplicate (::Logger_ptr p);
    static void release (::Logger_ptr p);
    static ::Logger_ptr nil ();
    static ::CORBA::Boolean marshal (const ::Logger_ptr p,TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/any_op_ch.cpp:31


TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {



 void operator<<= (::CORBA::Any &, Severidade);
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Severidade &);
}
TAO_END_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/any_op_ch.cpp:40




TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {

 void operator<<= (::CORBA::Any &, Logger_ptr); // copying
 void operator<<= (::CORBA::Any &, Logger_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Logger_ptr &);
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/cdr_op_ch.cpp:33


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, Severidade _tao_enumerator);
 ::CORBA::Boolean operator>> (TAO_InputCDR &strm, Severidade &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/cdr_op_ch.cpp:40



TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Logger_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, Logger_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:1648

#if defined (__ACE_INLINE__)
#include "LoggerC.inl"
#endif /* defined INLINE */

#endif /* ifndef */

