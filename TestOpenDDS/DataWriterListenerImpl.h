#pragma once

#include <ace/Global_Macros.h>

#include <dds/DdsDcpsPublicationC.h>
#include <dds/DCPS/LocalObject.h>
#include <dds/DCPS/Definitions.h>

class CTestOpenDDSDlg;
class CDataWriterListenerImpl : public virtual OpenDDS::DCPS::LocalObject<DDS::DataWriterListener>
{
private:
	CTestOpenDDSDlg*		_dlg = nullptr;

public:
	void Init(CTestOpenDDSDlg* dlg);

	virtual void on_offered_deadline_missed(DDS::DataWriter_ptr writer, const DDS::OfferedDeadlineMissedStatus& status);
	virtual void on_offered_incompatible_qos(DDS::DataWriter_ptr writer, const DDS::OfferedIncompatibleQosStatus& status);
	virtual void on_liveliness_lost(DDS::DataWriter_ptr writer, const DDS::LivelinessLostStatus& status);
	virtual void on_publication_matched(DDS::DataWriter_ptr writer, const DDS::PublicationMatchedStatus& status);
};

