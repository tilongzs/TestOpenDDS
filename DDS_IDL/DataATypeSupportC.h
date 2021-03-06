// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.5.0
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
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
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be\be_codegen.cpp:149

#ifndef _TAO_IDL_DATAATYPESUPPORTC_IFVURN_H_
#define _TAO_IDL_DATAATYPESUPPORTC_IFVURN_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "dds/DCPS/ZeroCopyInfoSeq_T.h"
#include "dds/DCPS/ZeroCopySeq_T.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "DataAC.h"
#include "dds/DdsDcpsInfrastructureC.h"
#include "dds/DdsDcpsPublicationC.h"
#include "dds/DdsDcpsSubscriptionExtC.h"
#include "dds/DdsDcpsTopicC.h"
#include "dds/DdsDcpsTypeSupportExtC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 5 || TAO_MICRO_VERSION != 0
#error This file should be regenerated with TAO_IDL
#endif

// TAO_IDL - Generated from
// be\be_visitor_module\module_ch.cpp:35

namespace TestA
{

  // TAO_IDL - Generated from
  // be\be_visitor_sequence\sequence_ch.cpp:99

  typedef ::TAO::DCPS::ZeroCopyDataSeq< TestA::DataA, DCPS_ZERO_COPY_SEQ_DEFAULT_SIZE> DataASeq;
  

  // TAO_IDL - Generated from
  // be\be_interface.cpp:748

#if !defined (_TESTA_DATAATYPESUPPORT__VAR_OUT_CH_)
#define _TESTA_DATAATYPESUPPORT__VAR_OUT_CH_

  class DataATypeSupport;
  typedef DataATypeSupport *DataATypeSupport_ptr;
  typedef TAO_Objref_Var_T<DataATypeSupport> DataATypeSupport_var;
  typedef TAO_Objref_Out_T<DataATypeSupport> DataATypeSupport_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface\interface_ch.cpp:40

  class  DataATypeSupport
    : public virtual ::OpenDDS::DCPS::TypeSupport
  
  {
  public:

    // TAO_IDL - Generated from
    // be\be_type.cpp:304

    typedef DataATypeSupport_ptr _ptr_type;
    typedef DataATypeSupport_var _var_type;
    typedef DataATypeSupport_out _out_type;

    // The static operations.
    static DataATypeSupport_ptr _duplicate (DataATypeSupport_ptr obj);

    static void _tao_release (DataATypeSupport_ptr obj);

    static DataATypeSupport_ptr _narrow (::CORBA::Object_ptr obj);
    static DataATypeSupport_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static DataATypeSupport_ptr _nil (void);

    // TAO_IDL - Generated from
    // be\be_visitor_interface\interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DataATypeSupport (void);

    

    virtual ~DataATypeSupport (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DataATypeSupport (const DataATypeSupport &);

    void operator= (const DataATypeSupport &);
  };

  // TAO_IDL - Generated from
  // be\be_interface.cpp:748

#if !defined (_TESTA_DATAADATAWRITER__VAR_OUT_CH_)
#define _TESTA_DATAADATAWRITER__VAR_OUT_CH_

  class DataADataWriter;
  typedef DataADataWriter *DataADataWriter_ptr;
  typedef TAO_Objref_Var_T<DataADataWriter> DataADataWriter_var;
  typedef TAO_Objref_Out_T<DataADataWriter> DataADataWriter_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface\interface_ch.cpp:40

  class  DataADataWriter
    : public virtual ::DDS::DataWriter
  
  {
  public:

    // TAO_IDL - Generated from
    // be\be_type.cpp:304

    typedef DataADataWriter_ptr _ptr_type;
    typedef DataADataWriter_var _var_type;
    typedef DataADataWriter_out _out_type;

    // The static operations.
    static DataADataWriter_ptr _duplicate (DataADataWriter_ptr obj);

    static void _tao_release (DataADataWriter_ptr obj);

    static DataADataWriter_ptr _narrow (::CORBA::Object_ptr obj);
    static DataADataWriter_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static DataADataWriter_ptr _nil (void);

    virtual ::DDS::InstanceHandle_t register_instance (
      const ::TestA::DataA & instance) = 0;

    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
      const ::TestA::DataA & instance,
      const ::DDS::Time_t & timestamp) = 0;

    virtual ::DDS::ReturnCode_t unregister_instance (
      const ::TestA::DataA & instance,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
      const ::TestA::DataA & instance,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & timestamp) = 0;

    virtual ::DDS::ReturnCode_t write (
      const ::TestA::DataA & instance_data,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::ReturnCode_t write_w_timestamp (
      const ::TestA::DataA & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp) = 0;

    virtual ::DDS::ReturnCode_t dispose (
      const ::TestA::DataA & instance_data,
      ::DDS::InstanceHandle_t instance_handle) = 0;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp (
      const ::TestA::DataA & instance_data,
      ::DDS::InstanceHandle_t instance_handle,
      const ::DDS::Time_t & source_timestamp) = 0;

    virtual ::DDS::ReturnCode_t get_key_value (
      ::TestA::DataA & key_holder,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::InstanceHandle_t lookup_instance (
      const ::TestA::DataA & instance_data) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_interface\interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DataADataWriter (void);

    

    virtual ~DataADataWriter (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DataADataWriter (const DataADataWriter &);

    void operator= (const DataADataWriter &);
  };

  // TAO_IDL - Generated from
  // be\be_interface.cpp:748

#if !defined (_TESTA_DATAADATAREADER__VAR_OUT_CH_)
#define _TESTA_DATAADATAREADER__VAR_OUT_CH_

  class DataADataReader;
  typedef DataADataReader *DataADataReader_ptr;
  typedef TAO_Objref_Var_T<DataADataReader> DataADataReader_var;
  typedef TAO_Objref_Out_T<DataADataReader> DataADataReader_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface\interface_ch.cpp:40

  class  DataADataReader
    : public virtual ::OpenDDS::DCPS::DataReaderEx
  
  {
  public:

    // TAO_IDL - Generated from
    // be\be_type.cpp:304

    typedef DataADataReader_ptr _ptr_type;
    typedef DataADataReader_var _var_type;
    typedef DataADataReader_out _out_type;

    // The static operations.
    static DataADataReader_ptr _duplicate (DataADataReader_ptr obj);

    static void _tao_release (DataADataReader_ptr obj);

    static DataADataReader_ptr _narrow (::CORBA::Object_ptr obj);
    static DataADataReader_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static DataADataReader_ptr _nil (void);

    virtual ::DDS::ReturnCode_t read (
      ::TestA::DataASeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t take (
      ::TestA::DataASeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t read_w_condition (
      ::TestA::DataASeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t take_w_condition (
      ::TestA::DataASeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t read_next_sample (
      ::TestA::DataA & received_data,
      ::DDS::SampleInfo & sample_info) = 0;

    virtual ::DDS::ReturnCode_t take_next_sample (
      ::TestA::DataA & received_data,
      ::DDS::SampleInfo & sample_info) = 0;

    virtual ::DDS::ReturnCode_t read_instance (
      ::TestA::DataASeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t take_instance (
      ::TestA::DataASeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t read_instance_w_condition (
      ::TestA::DataASeq & received_data,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t take_instance_w_condition (
      ::TestA::DataASeq & received_data,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t read_next_instance (
      ::TestA::DataASeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t take_next_instance (
      ::TestA::DataASeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
      ::TestA::DataASeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t previous_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
      ::TestA::DataASeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t previous_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t return_loan (
      ::TestA::DataASeq & received_data,
      ::DDS::SampleInfoSeq & info_seq) = 0;

    virtual ::DDS::ReturnCode_t get_key_value (
      ::TestA::DataA & key_holder,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::InstanceHandle_t lookup_instance (
      const ::TestA::DataA & instance_data) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_interface\interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DataADataReader (void);

    

    virtual ~DataADataReader (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DataADataReader (const DataADataReader &);

    void operator= (const DataADataReader &);
  };

// TAO_IDL - Generated from
// be\be_visitor_module\module_ch.cpp:64

} // module TestA

// TAO_IDL - Generated from
// be\be_visitor_module\module_ch.cpp:35

namespace TestA
{

  // TAO_IDL - Generated from
  // be\be_visitor_sequence\sequence_ch.cpp:99

  typedef ::TAO::DCPS::ZeroCopyDataSeq< TestA::DataB, DCPS_ZERO_COPY_SEQ_DEFAULT_SIZE> DataBSeq;
  

  // TAO_IDL - Generated from
  // be\be_interface.cpp:748

#if !defined (_TESTA_DATABTYPESUPPORT__VAR_OUT_CH_)
#define _TESTA_DATABTYPESUPPORT__VAR_OUT_CH_

  class DataBTypeSupport;
  typedef DataBTypeSupport *DataBTypeSupport_ptr;
  typedef TAO_Objref_Var_T<DataBTypeSupport> DataBTypeSupport_var;
  typedef TAO_Objref_Out_T<DataBTypeSupport> DataBTypeSupport_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface\interface_ch.cpp:40

  class  DataBTypeSupport
    : public virtual ::OpenDDS::DCPS::TypeSupport
  
  {
  public:

    // TAO_IDL - Generated from
    // be\be_type.cpp:304

    typedef DataBTypeSupport_ptr _ptr_type;
    typedef DataBTypeSupport_var _var_type;
    typedef DataBTypeSupport_out _out_type;

    // The static operations.
    static DataBTypeSupport_ptr _duplicate (DataBTypeSupport_ptr obj);

    static void _tao_release (DataBTypeSupport_ptr obj);

    static DataBTypeSupport_ptr _narrow (::CORBA::Object_ptr obj);
    static DataBTypeSupport_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static DataBTypeSupport_ptr _nil (void);

    // TAO_IDL - Generated from
    // be\be_visitor_interface\interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DataBTypeSupport (void);

    

    virtual ~DataBTypeSupport (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DataBTypeSupport (const DataBTypeSupport &);

    void operator= (const DataBTypeSupport &);
  };

  // TAO_IDL - Generated from
  // be\be_interface.cpp:748

#if !defined (_TESTA_DATABDATAWRITER__VAR_OUT_CH_)
#define _TESTA_DATABDATAWRITER__VAR_OUT_CH_

  class DataBDataWriter;
  typedef DataBDataWriter *DataBDataWriter_ptr;
  typedef TAO_Objref_Var_T<DataBDataWriter> DataBDataWriter_var;
  typedef TAO_Objref_Out_T<DataBDataWriter> DataBDataWriter_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface\interface_ch.cpp:40

  class  DataBDataWriter
    : public virtual ::DDS::DataWriter
  
  {
  public:

    // TAO_IDL - Generated from
    // be\be_type.cpp:304

    typedef DataBDataWriter_ptr _ptr_type;
    typedef DataBDataWriter_var _var_type;
    typedef DataBDataWriter_out _out_type;

    // The static operations.
    static DataBDataWriter_ptr _duplicate (DataBDataWriter_ptr obj);

    static void _tao_release (DataBDataWriter_ptr obj);

    static DataBDataWriter_ptr _narrow (::CORBA::Object_ptr obj);
    static DataBDataWriter_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static DataBDataWriter_ptr _nil (void);

    virtual ::DDS::InstanceHandle_t register_instance (
      const ::TestA::DataB & instance) = 0;

    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
      const ::TestA::DataB & instance,
      const ::DDS::Time_t & timestamp) = 0;

    virtual ::DDS::ReturnCode_t unregister_instance (
      const ::TestA::DataB & instance,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
      const ::TestA::DataB & instance,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & timestamp) = 0;

    virtual ::DDS::ReturnCode_t write (
      const ::TestA::DataB & instance_data,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::ReturnCode_t write_w_timestamp (
      const ::TestA::DataB & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp) = 0;

    virtual ::DDS::ReturnCode_t dispose (
      const ::TestA::DataB & instance_data,
      ::DDS::InstanceHandle_t instance_handle) = 0;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp (
      const ::TestA::DataB & instance_data,
      ::DDS::InstanceHandle_t instance_handle,
      const ::DDS::Time_t & source_timestamp) = 0;

    virtual ::DDS::ReturnCode_t get_key_value (
      ::TestA::DataB & key_holder,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::InstanceHandle_t lookup_instance (
      const ::TestA::DataB & instance_data) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_interface\interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DataBDataWriter (void);

    

    virtual ~DataBDataWriter (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DataBDataWriter (const DataBDataWriter &);

    void operator= (const DataBDataWriter &);
  };

  // TAO_IDL - Generated from
  // be\be_interface.cpp:748

#if !defined (_TESTA_DATABDATAREADER__VAR_OUT_CH_)
#define _TESTA_DATABDATAREADER__VAR_OUT_CH_

  class DataBDataReader;
  typedef DataBDataReader *DataBDataReader_ptr;
  typedef TAO_Objref_Var_T<DataBDataReader> DataBDataReader_var;
  typedef TAO_Objref_Out_T<DataBDataReader> DataBDataReader_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface\interface_ch.cpp:40

  class  DataBDataReader
    : public virtual ::OpenDDS::DCPS::DataReaderEx
  
  {
  public:

    // TAO_IDL - Generated from
    // be\be_type.cpp:304

    typedef DataBDataReader_ptr _ptr_type;
    typedef DataBDataReader_var _var_type;
    typedef DataBDataReader_out _out_type;

    // The static operations.
    static DataBDataReader_ptr _duplicate (DataBDataReader_ptr obj);

    static void _tao_release (DataBDataReader_ptr obj);

    static DataBDataReader_ptr _narrow (::CORBA::Object_ptr obj);
    static DataBDataReader_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static DataBDataReader_ptr _nil (void);

    virtual ::DDS::ReturnCode_t read (
      ::TestA::DataBSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t take (
      ::TestA::DataBSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t read_w_condition (
      ::TestA::DataBSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t take_w_condition (
      ::TestA::DataBSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t read_next_sample (
      ::TestA::DataB & received_data,
      ::DDS::SampleInfo & sample_info) = 0;

    virtual ::DDS::ReturnCode_t take_next_sample (
      ::TestA::DataB & received_data,
      ::DDS::SampleInfo & sample_info) = 0;

    virtual ::DDS::ReturnCode_t read_instance (
      ::TestA::DataBSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t take_instance (
      ::TestA::DataBSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t read_instance_w_condition (
      ::TestA::DataBSeq & received_data,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t take_instance_w_condition (
      ::TestA::DataBSeq & received_data,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t read_next_instance (
      ::TestA::DataBSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t take_next_instance (
      ::TestA::DataBSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
      ::TestA::DataBSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t previous_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
      ::TestA::DataBSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t previous_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t return_loan (
      ::TestA::DataBSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq) = 0;

    virtual ::DDS::ReturnCode_t get_key_value (
      ::TestA::DataB & key_holder,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::InstanceHandle_t lookup_instance (
      const ::TestA::DataB & instance_data) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_interface\interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DataBDataReader (void);

    

    virtual ~DataBDataReader (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DataBDataReader (const DataBDataReader &);

    void operator= (const DataBDataReader &);
  };

// TAO_IDL - Generated from
// be\be_visitor_module\module_ch.cpp:64

} // module TestA

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:66

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:60

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_TESTA_DATAATYPESUPPORT__TRAITS_)
#define _TESTA_DATAATYPESUPPORT__TRAITS_

  template<>
  struct  Objref_Traits< ::TestA::DataATypeSupport>
  {
    static ::TestA::DataATypeSupport_ptr duplicate (
        ::TestA::DataATypeSupport_ptr p);
    static void release (
        ::TestA::DataATypeSupport_ptr p);
    static ::TestA::DataATypeSupport_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::TestA::DataATypeSupport_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_TESTA_DATAADATAWRITER__TRAITS_)
#define _TESTA_DATAADATAWRITER__TRAITS_

  template<>
  struct  Objref_Traits< ::TestA::DataADataWriter>
  {
    static ::TestA::DataADataWriter_ptr duplicate (
        ::TestA::DataADataWriter_ptr p);
    static void release (
        ::TestA::DataADataWriter_ptr p);
    static ::TestA::DataADataWriter_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::TestA::DataADataWriter_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_TESTA_DATAADATAREADER__TRAITS_)
#define _TESTA_DATAADATAREADER__TRAITS_

  template<>
  struct  Objref_Traits< ::TestA::DataADataReader>
  {
    static ::TestA::DataADataReader_ptr duplicate (
        ::TestA::DataADataReader_ptr p);
    static void release (
        ::TestA::DataADataReader_ptr p);
    static ::TestA::DataADataReader_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::TestA::DataADataReader_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_TESTA_DATABTYPESUPPORT__TRAITS_)
#define _TESTA_DATABTYPESUPPORT__TRAITS_

  template<>
  struct  Objref_Traits< ::TestA::DataBTypeSupport>
  {
    static ::TestA::DataBTypeSupport_ptr duplicate (
        ::TestA::DataBTypeSupport_ptr p);
    static void release (
        ::TestA::DataBTypeSupport_ptr p);
    static ::TestA::DataBTypeSupport_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::TestA::DataBTypeSupport_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_TESTA_DATABDATAWRITER__TRAITS_)
#define _TESTA_DATABDATAWRITER__TRAITS_

  template<>
  struct  Objref_Traits< ::TestA::DataBDataWriter>
  {
    static ::TestA::DataBDataWriter_ptr duplicate (
        ::TestA::DataBDataWriter_ptr p);
    static void release (
        ::TestA::DataBDataWriter_ptr p);
    static ::TestA::DataBDataWriter_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::TestA::DataBDataWriter_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_TESTA_DATABDATAREADER__TRAITS_)
#define _TESTA_DATABDATAREADER__TRAITS_

  template<>
  struct  Objref_Traits< ::TestA::DataBDataReader>
  {
    static ::TestA::DataBDataReader_ptr duplicate (
        ::TestA::DataBDataReader_ptr p);
    static void release (
        ::TestA::DataBDataReader_ptr p);
    static ::TestA::DataBDataReader_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::TestA::DataBDataReader_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be\be_codegen.cpp:1686
#if defined (__ACE_INLINE__)
#include "DataATypeSupportC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */

