#pragma once

#include <ace/Log_Msg.h>

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>
#include <dds/DCPS/StaticIncludes.h>
#include "DataATypeSupportImpl.h"

using namespace DDS;

class CTestOpenDDSDlg : public CDialogEx
{
public:
	CTestOpenDDSDlg(CWnd* pParent = NULL);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTOPENDDS_DIALOG };
#endif
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()

private:
	int			_domainID = 0;

	CEdit		_editMsg;
	CButton		_btnJoinDomain;
	CEdit		_editDomainID;
	CEdit		_editLeftTopic;
	CEdit		_editLeftData;
	CEdit		_editRightTopic;
	CEdit		_editRightData;
	CButton		_btnSendLeftTopic;
	CButton		_btnSendRightTopic;
	CButton		_btnStartLeftTopic;
	CButton		_btnStartRightTopic;
	CButton		_btnRecvLeftTopic;
	CButton		_btnRecvRightTopic;

	DomainParticipantFactory_var	_dpf = nullptr;
	DomainParticipant_var			_participant = nullptr;
	TestA::DataATypeSupport_var		_dataA_TS = nullptr;
	long							_dataA_leftTopicNeedStop = FALSE;
	long							_dataA_leftTopicHasNewData = FALSE;
	CString							_dataA_leftTopicData;
	long							_dataA_rightTopicNeedStop = FALSE;
	long							_dataA_rightTopicHasNewData = FALSE;
	CString							_dataA_rightTopicData;

	int JoinDomain(int argc, char* argv[]);

	LRESULT OnLog(WPARAM wParam, LPARAM lParam);

public:
	void AppendMSG(const CString& msg);

	afx_msg void OnBtnJoinDomain();
	afx_msg void OnBtnLeaveDomain();
	afx_msg void OnBtnPublishLeftTopic();
	afx_msg void OnBtnSendLeftTopic();
	afx_msg void OnBtnStopLeftTopic();
	afx_msg void OnBtnPublishRightTopic();
	afx_msg void OnBtnSendRightTopic();
	afx_msg void OnBtnStopRightTopic();
	afx_msg void OnBtnSubscribeLeftTopic();
	afx_msg void OnBtnSubscribeRightTopic();
};
