#include "stdafx.h"
#include "DataWriterListenerImpl.h"
#include "TestOpenDDSDlg.h"
#include "DataATypeSupportC.h"
#include "DataATypeSupportImpl.h"

using namespace DDS;

void CDataWriterListenerImpl::Init(CTestOpenDDSDlg* dlg)
{
	_dlg = dlg;
}

void CDataWriterListenerImpl::on_offered_deadline_missed(DDS::DataWriter_ptr writer, const DDS::OfferedDeadlineMissedStatus& status)
{
	int a = 1;
}

void CDataWriterListenerImpl::on_offered_incompatible_qos(DDS::DataWriter_ptr writer, const DDS::OfferedIncompatibleQosStatus& status)
{
	int a = 1;
}

void CDataWriterListenerImpl::on_liveliness_lost(DDS::DataWriter_ptr writer, const DDS::LivelinessLostStatus& status)
{
	int a = 1;
}

void CDataWriterListenerImpl::on_publication_matched(DDS::DataWriter_ptr writer, const DDS::PublicationMatchedStatus& status)
{
	int a = 1;

}