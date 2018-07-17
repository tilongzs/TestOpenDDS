#include "stdafx.h"
#include "TestOpenDDS.h"
#include "TestOpenDDSDlg.h"
#include "afxdialogex.h"

#include "DataReaderListenerImpl.h"
#include "DataWriterListenerImpl.h"
#include "DataATypeSupportImpl.h"

#include <ppltasks.h>
using namespace concurrency;

#define WMSG_LOG		WM_USER + 1

CTestOpenDDSDlg::CTestOpenDDSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTOPENDDS_DIALOG, pParent)
{

}

void CTestOpenDDSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, _editDomainID);
	DDX_Control(pDX, IDC_EDIT_MSG, _editMsg);
	DDX_Control(pDX, IDC_BUTTON_JOIN_DOMAIN, _btnJoinDomain);
	DDX_Control(pDX, IDC_EDIT2, _editLeftTopic);
	DDX_Control(pDX, IDC_EDIT3, _editLeftData);
	DDX_Control(pDX, IDC_EDIT4, _editRightTopic);
	DDX_Control(pDX, IDC_EDIT5, _editRightData);
	DDX_Control(pDX, IDC_BUTTON_SEND_LEFT_TOPIC, _btnSendLeftTopic);
	DDX_Control(pDX, IDC_BUTTON_SEND_RIGHT_TOPIC, _btnSendRightTopic);
	DDX_Control(pDX, IDC_BUTTON_START_LEFT_TOPIC, _btnStartLeftTopic);
	DDX_Control(pDX, IDC_BUTTON_START_RIGHT_TOPIC, _btnStartRightTopic);
	DDX_Control(pDX, IDC_BUTTON_RECV_LEFT_TOPIC, _btnRecvLeftTopic);
	DDX_Control(pDX, IDC_BUTTON_RECV_RIGHT_TOPIC, _btnRecvRightTopic);
}

BEGIN_MESSAGE_MAP(CTestOpenDDSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_JOIN_DOMAIN, &CTestOpenDDSDlg::OnBtnJoinDomain)
	ON_MESSAGE(WMSG_LOG, OnLog)
	ON_BN_CLICKED(IDC_BUTTON_SEND_LEFT_TOPIC, &CTestOpenDDSDlg::OnBtnSendLeftTopic)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestOpenDDSDlg::OnBtnLeaveDomain)
	ON_BN_CLICKED(IDC_BUTTON_STOP_LEFT_TOPIC, &CTestOpenDDSDlg::OnBtnStopLeftTopic)
	ON_BN_CLICKED(IDC_BUTTON_SEND_RIGHT_TOPIC, &CTestOpenDDSDlg::OnBtnSendRightTopic)
	ON_BN_CLICKED(IDC_BUTTON_STOP_Right_TOPIC, &CTestOpenDDSDlg::OnBtnStopRightTopic)
	ON_BN_CLICKED(IDC_BUTTON_START_LEFT_TOPIC, &CTestOpenDDSDlg::OnBtnPublishLeftTopic)
	ON_BN_CLICKED(IDC_BUTTON_START_RIGHT_TOPIC, &CTestOpenDDSDlg::OnBtnPublishRightTopic)
	ON_BN_CLICKED(IDC_BUTTON_RECV_LEFT_TOPIC, &CTestOpenDDSDlg::OnBtnSubscribeLeftTopic)
	ON_BN_CLICKED(IDC_BUTTON_RECV_RIGHT_TOPIC, &CTestOpenDDSDlg::OnBtnSubscribeRightTopic)
END_MESSAGE_MAP()

BOOL CTestOpenDDSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	// ACE初始化
	ACE_Object_Manager::instance()->init();
	AppendMSG(L"ACE初始化完成");

	_editDomainID.SetWindowText(L"233");
	_editLeftTopic.SetWindowText(L"test topic Left");
	_editLeftData.SetWindowText(L"data Left");
	_editRightTopic.SetWindowText(L"test topic Right");
	_editRightData.SetWindowText(L"data Right");

	return TRUE;
}

void CTestOpenDDSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

void CTestOpenDDSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CTestOpenDDSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTestOpenDDSDlg::OnBtnJoinDomain()
{
	CString strDomainID;
	_editDomainID.GetWindowText(strDomainID);
	_domainID = _wtoi(strDomainID);
	_editDomainID.EnableWindow(FALSE);
	_btnJoinDomain.EnableWindow(FALSE);

	_editLeftData.GetWindowText(_dataA_leftTopicData);

	task<void> taskStartPublisher([&]
	{
		char* paramBuf[] = { "-DCPSConfigFile", "rtps.ini" };
		//	char* paramBuf[] = { "-DCPSInfoRepo", "file://D:\\Study\\openDDS\\bin\\simple.ior" };
		int paramCount = 2;

		JoinDomain(paramCount, paramBuf);
	});
}

int CTestOpenDDSDlg::JoinDomain(int argc, char* argv[])
{
	try
	{
		// 创建域参与者工厂
		_dpf = TheParticipantFactoryWithArgs(argc, argv);
		if (!_dpf)
		{
			AppendMSG(L"启动发布服务失败");
			return 0;
		}

		// 创建域参与者
		_participant = _dpf->create_participant(_domainID, // 域ID
			PARTICIPANT_QOS_DEFAULT,
			0,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!_participant)
		{
			AppendMSG(L"创建域参与者失败");
			return 0;
		}

		// 注册类型
		_dataA_TS = new TestA::DataATypeSupportImpl;
		if (_dataA_TS->register_type(_participant, "") != DDS::RETCODE_OK)
		{
			AppendMSG(L"注册类型失败");
			return 0;
		}

		_btnJoinDomain.EnableWindow(FALSE);
		_btnJoinDomain.SetWindowText(L"已加入");
		AppendMSG(L"加入域成功");
	}
	catch (const CORBA::Exception& e)
	{
		e._tao_print_exception("Exception caught in main():");
		return -1;
	}

	return 0;
}


void CTestOpenDDSDlg::AppendMSG(const CString& msg)
{
	CString* pMsg = new CString(msg);
	PostMessage(WMSG_LOG, (WPARAM)pMsg);
}

LRESULT CTestOpenDDSDlg::OnLog(WPARAM wParam, LPARAM lParam)
{
	CString* pMsg = (CString*)wParam;

	if (_editMsg.GetLineCount() > 30)
	{
		_editMsg.SetSel(0, -1);
		_editMsg.Clear();
	}

	CString curMsg;
	_editMsg.GetWindowTextW(curMsg);
	curMsg += "\r\n";
	curMsg += CTime::GetCurrentTime().Format(L"[%H:%M:%S] ");
	curMsg += *pMsg;
	_editMsg.SetWindowTextW(curMsg);
	_editMsg.LineScroll(_editMsg.GetLineCount());

	delete pMsg;
	return TRUE;
}

void CTestOpenDDSDlg::OnBtnPublishLeftTopic()
{
	_dataA_leftTopicNeedStop = FALSE;
	CString topicName;
	_editLeftTopic.GetWindowText(topicName);
	_editLeftTopic.EnableWindow(FALSE);
	_btnStartLeftTopic.EnableWindow(FALSE);

	task<void>([&, topicName]
	{
		CString log;
		// 创建主题
		CORBA::String_var type_name = _dataA_TS->get_type_name();
		Topic_var dataA_leftTopic = _participant->create_topic(CStringA(topicName),
			type_name,
			TOPIC_QOS_DEFAULT,
			0,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!dataA_leftTopic)
		{
			AppendMSG(L"创建主题失败");
			return;
		}

		// 创建发布者
		Publisher_var dataA_leftTopicPublisher = _participant->create_publisher(PUBLISHER_QOS_DEFAULT,
			0,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!dataA_leftTopicPublisher)
		{
			AppendMSG(L"创建发布者失败");
			return;
		}

		DataWriterQos dataWriterQos;
		dataA_leftTopicPublisher->get_default_datawriter_qos(dataWriterQos);
		dataWriterQos.liveliness.kind = AUTOMATIC_LIVELINESS_QOS;
		DDS::Duration_t livelinessTime = { 1, 0 };
		dataWriterQos.liveliness.lease_duration = livelinessTime;
		dataWriterQos.history.kind = KEEP_LAST_HISTORY_QOS;
		dataWriterQos.durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS;

		// 创建写数据工具
		CDataWriterListenerImpl* dataWriterListener = new CDataWriterListenerImpl();
		dataWriterListener->Init(this);

		DDS::DataWriter_var writer =
			dataA_leftTopicPublisher->create_datawriter(dataA_leftTopic,
				dataWriterQos, // DATAWRITER_QOS_DEFAULT
				dataWriterListener,
				OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!writer)
		{
			AppendMSG(L"创建写数据工具失败");
			return;
		}

		TestA::DataADataWriter_var message_writer = TestA::DataADataWriter::_narrow(writer);
		if (!message_writer)
		{
			ASSERT(0);
		}

		// 阻塞直至订阅者出现
		DDS::StatusCondition_var condition = writer->get_statuscondition();
		condition->set_enabled_statuses(DDS::PUBLICATION_MATCHED_STATUS);

		DDS::WaitSet_var ws = new DDS::WaitSet; // 不能使用delete ws
		ws->attach_condition(condition);

		DDS::PublicationMatchedStatus matches;
		while (!_dataA_leftTopicNeedStop)
		{
			if (writer->get_publication_matched_status(matches) != DDS::RETCODE_OK)
			{
				ASSERT(0);
			}

			DDS::ConditionSeq conditions;
			DDS::Duration_t timeout = { 1, 0 };
			ReturnCode_t ret = ws->wait(conditions, timeout);
			if (DDS::RETCODE_OK != ret)
			{
				if (DDS::RETCODE_TIMEOUT == ret)
				{
					continue;
				}
				else
				{
					ASSERT(0);
					return;
				}
			}


			while (!_dataA_leftTopicNeedStop)
			{
				if (!_dataA_leftTopicHasNewData)
				{
					Sleep(100);
					continue;
				}

				if (writer->get_publication_matched_status(matches) != DDS::RETCODE_OK)
				{
					ASSERT(0);
				}

				// 写数据
				static int length = 10;
				TestA::DataA dataA;
				dataA.pos = 1;
				dataA.length = length;
				dataA.name = CStringA(_dataA_leftTopicData);

				DDS::InstanceHandle_t handle = message_writer->register_instance(dataA);


				for (int i = 0; i < 2; ++i)
				{
					//	ReturnCode_t error = message_writer->write(dataA, DDS::HANDLE_NIL);
					ReturnCode_t error = message_writer->write(dataA, handle);
					dataA.pos += 10;
					dataA.length += 100;

					if (error != DDS::RETCODE_OK)
					{
						ACE_ERROR((LM_ERROR,
							ACE_TEXT("ERROR: %N:%l: main() -")
							ACE_TEXT(" write returned %d!\n"), error));
					}
				}

				_dataA_leftTopicHasNewData = FALSE;

				// 等待订阅者接收完毕
				timeout = { 30, 0 };
				if (message_writer->wait_for_acknowledgments(timeout) != DDS::RETCODE_OK)
				{
					ASSERT(0);
				}
			}
		}

		// 清理资源
		ws->detach_condition(condition);
		dataA_leftTopicPublisher->delete_datawriter(writer);
		_participant->delete_publisher(dataA_leftTopicPublisher);
		_participant->delete_topic(dataA_leftTopic);

		log.Format(L"主题：%s已停止", topicName);
		AppendMSG(log);
	});
}

void CTestOpenDDSDlg::OnBtnSendLeftTopic()
{
	_editLeftData.GetWindowText(_dataA_leftTopicData);
	_dataA_leftTopicHasNewData = TRUE;
}

void CTestOpenDDSDlg::OnBtnStopLeftTopic()
{
	_dataA_leftTopicNeedStop = TRUE;
	_editLeftTopic.EnableWindow(TRUE);
	_btnStartLeftTopic.EnableWindow(TRUE);
}

void CTestOpenDDSDlg::OnBtnLeaveDomain()
{
	_participant->delete_contained_entities();
	_dpf->delete_participant(_participant);
	TheServiceParticipant->shutdown();
	_dpf = nullptr;
	_participant = nullptr;
}

void CTestOpenDDSDlg::OnBtnPublishRightTopic()
{
	_dataA_rightTopicNeedStop = FALSE;
	CString topicName;
	_editRightTopic.GetWindowText(topicName);
	_editRightTopic.EnableWindow(FALSE);
	_btnStartRightTopic.EnableWindow(FALSE);

	task<void>([&, topicName]
	{
		CString log;
		// 创建主题
		CORBA::String_var type_name = _dataA_TS->get_type_name();
		Topic_var dataA_rightTopic = _participant->create_topic(CStringA(topicName),
			type_name,
			TOPIC_QOS_DEFAULT,
			0,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!dataA_rightTopic)
		{
			AppendMSG(L"创建主题失败");
			return;
		}

		// 创建发布者
		Publisher_var dataA_rightTopicPublisher = _participant->create_publisher(PUBLISHER_QOS_DEFAULT,
			0,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!dataA_rightTopicPublisher)
		{
			AppendMSG(L"创建发布者失败");
			return;
		}

		// 创建写数据工具
		CDataWriterListenerImpl* dataWriterListener = new CDataWriterListenerImpl();
		dataWriterListener->Init(this);

		DDS::DataWriter_var writer =
			dataA_rightTopicPublisher->create_datawriter(dataA_rightTopic,
				DATAWRITER_QOS_DEFAULT,
				dataWriterListener,
				OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!writer)
		{
			AppendMSG(L"创建写数据工具失败");
			return;
		}

		TestA::DataADataWriter_var message_writer = TestA::DataADataWriter::_narrow(writer);
		if (!message_writer)
		{
			ASSERT(0);
		}



		// 阻塞直至订阅者出现
		DDS::StatusCondition_var condition = writer->get_statuscondition();
		condition->set_enabled_statuses(DDS::PUBLICATION_MATCHED_STATUS);

		DDS::WaitSet_var ws = new DDS::WaitSet; // 不能使用delete ws
		ws->attach_condition(condition);

		DDS::PublicationMatchedStatus matches;
		while (!_dataA_rightTopicNeedStop)
		{
			DDS::ConditionSeq conditions;
			DDS::Duration_t timeout = { 1, 0 };
			ReturnCode_t ret = ws->wait(conditions, timeout);
			if (DDS::RETCODE_OK != ret)
			{
				if (DDS::RETCODE_TIMEOUT == ret)
				{
					continue;
				}
				else
				{
					ASSERT(0);
					return;
				}
			}

			while (!_dataA_rightTopicNeedStop)
			{
				if (!_dataA_rightTopicHasNewData)
				{
					Sleep(100);
					continue;
				}

				if (writer->get_publication_matched_status(matches) != DDS::RETCODE_OK)
				{
					ASSERT(0);
				}

				// 写数据
				TestA::DataA dataA;
				dataA.pos = 1;
				dataA.length = 10;
				dataA.name = CStringA(_dataA_rightTopicData);

				for (int i = 0; i < 2; ++i)
				{
					DDS::ReturnCode_t error = message_writer->write(dataA, DDS::HANDLE_NIL);
					++dataA.pos;
					++dataA.length;

					if (error != DDS::RETCODE_OK)
					{
						ACE_ERROR((LM_ERROR,
							ACE_TEXT("ERROR: %N:%l: main() -")
							ACE_TEXT(" write returned %d!\n"), error));
					}
				}

				_dataA_rightTopicHasNewData = FALSE;

				// 等待订阅者接收完毕
				timeout = { 30, 0 };
				if (message_writer->wait_for_acknowledgments(timeout) != DDS::RETCODE_OK)
				{
					ASSERT(0);
				}
			}
		}

		// 清理资源
		ws->detach_condition(condition);
		dataA_rightTopicPublisher->delete_datawriter(writer);
		_participant->delete_publisher(dataA_rightTopicPublisher);
		_participant->delete_topic(dataA_rightTopic);

		log.Format(L"主题：%s已停止", topicName);
		AppendMSG(log);
	});
}

void CTestOpenDDSDlg::OnBtnSendRightTopic()
{
	_editRightData.GetWindowText(_dataA_rightTopicData);
	_dataA_rightTopicHasNewData = TRUE;
}

void CTestOpenDDSDlg::OnBtnStopRightTopic()
{
	_dataA_rightTopicNeedStop = TRUE;
	_editRightTopic.EnableWindow(TRUE);
	_btnStartRightTopic.EnableWindow(TRUE);
}

void CTestOpenDDSDlg::OnBtnSubscribeLeftTopic()
{
	CString topicName;
	_editLeftTopic.GetWindowText(topicName);
	_editLeftTopic.EnableWindow(FALSE);
	_btnRecvLeftTopic.EnableWindow(FALSE);

	task<void>([&, topicName]
	{
		// 创建主题
		CORBA::String_var type_name = _dataA_TS->get_type_name();
		DDS::Topic_var topic =
			_participant->create_topic(CStringA(topicName),
				type_name,
				TOPIC_QOS_DEFAULT,
				0,
				OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!topic)
		{
			AppendMSG(L"创建主题失败");
			return;
		}

		// 创建订阅者
		DDS::Subscriber_var subscriber =
			_participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT,
				0,
				OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!subscriber)
		{
			AppendMSG(L"创建订阅者失败");
			return;
		}

		DataReaderQos dataReaderQos;
		subscriber->get_default_datareader_qos(dataReaderQos);
		dataReaderQos.liveliness.kind = AUTOMATIC_LIVELINESS_QOS;
		DDS::Duration_t livelinessTime = { 1, 0 };
		dataReaderQos.liveliness.lease_duration = livelinessTime;
		dataReaderQos.history.kind = KEEP_LAST_HISTORY_QOS;
		dataReaderQos.durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS;

		// 创建读监听器
		CDataReaderListenerImpl* dataReaderListener = new CDataReaderListenerImpl();
		dataReaderListener->Init(this);

		static int filterIndex = 1;
		CStringA filterName;
		filterName.Format("filter%d", filterIndex++);
		DDS::ContentFilteredTopic_var cft =
			_participant->create_contentfilteredtopic(filterName, // filterName不能相同
				topic,
				//"name='aaa' and pos<1000", // 字符串对比需要加单引号
				"pos>0 and pos<1000",
				StringSeq());

		//DDS::DataReader_var reader = subscriber->create_datareader(topic, // 不带过滤条件的订阅
		DDS::DataReader_var reader = subscriber->create_datareader(cft,
			dataReaderQos,// DATAREADER_QOS_DEFAULT
			dataReaderListener,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!reader)
		{
			AppendMSG(L"创建读监听器失败");
			return;
		}

		TestA::DataADataReader_var reader_i = TestA::DataADataReader::_narrow(reader);
		if (!reader_i)
		{
			ASSERT(0);
		}

		// 阻塞直至有主题发布
		DDS::StatusCondition_var condition = reader->get_statuscondition();
		condition->set_enabled_statuses(DDS::SUBSCRIPTION_MATCHED_STATUS);

		DDS::WaitSet_var ws = new DDS::WaitSet;
		ws->attach_condition(condition);

		while (!_dataA_leftTopicNeedStop)
		{
			DDS::SubscriptionMatchedStatus matches;
			if (reader->get_subscription_matched_status(matches) != DDS::RETCODE_OK)
			{
				ASSERT(0);
			}

			DDS::ConditionSeq conditions;
			DDS::Duration_t timeout = { 1, 0 };
			ReturnCode_t ret = ws->wait(conditions, timeout);
			if (DDS::RETCODE_OK != ret)
			{
				if (DDS::RETCODE_TIMEOUT == ret)
				{
					continue;
				}
				else
				{
					ASSERT(0);
					return;
				}
			}
		}

		ws->detach_condition(condition);
	});
}


void CTestOpenDDSDlg::OnBtnSubscribeRightTopic()
{
	CString topicName;
	_editRightTopic.GetWindowText(topicName);
	_editRightTopic.EnableWindow(FALSE);
	_btnRecvRightTopic.EnableWindow(FALSE);

	task<void>([&, topicName]
	{
		// 创建主题
		CORBA::String_var type_name = _dataA_TS->get_type_name();
		DDS::Topic_var topic =
			_participant->create_topic(CStringA(topicName),
				type_name,
				TOPIC_QOS_DEFAULT,
				0,
				OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!topic)
		{
			AppendMSG(L"创建主题失败");
			return;
		}

		// 创建订阅者
		DDS::Subscriber_var subscriber =
			_participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT,
				0,
				OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!subscriber)
		{
			AppendMSG(L"创建订阅者失败");
			return;
		}

		// 创建读监听器
		CDataReaderListenerImpl* dataReader = new CDataReaderListenerImpl();
		dataReader->Init(this);
		DDS::DataReaderListener_var listener(dataReader);

		DDS::DataReader_var reader = subscriber->create_datareader(topic,
			DATAREADER_QOS_DEFAULT,
			listener,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

		if (!reader)
		{
			AppendMSG(L"创建读监听器失败");
			return;
		}

		TestA::DataADataReader_var reader_i = TestA::DataADataReader::_narrow(reader);
		if (!reader_i)
		{
			ASSERT(0);
		}

		// 阻塞直至有主题发布
		DDS::StatusCondition_var condition = reader->get_statuscondition();
		condition->set_enabled_statuses(DDS::SUBSCRIPTION_MATCHED_STATUS);

		DDS::WaitSet_var ws = new DDS::WaitSet;
		ws->attach_condition(condition);

		while (!_dataA_rightTopicNeedStop)
		{
			DDS::SubscriptionMatchedStatus matches;
			if (reader->get_subscription_matched_status(matches) != DDS::RETCODE_OK)
			{
				ASSERT(0);
			}

			DDS::ConditionSeq conditions;
			DDS::Duration_t timeout = { 1, 0 };
			ReturnCode_t ret = ws->wait(conditions, timeout);
			if (DDS::RETCODE_OK != ret)
			{
				if (DDS::RETCODE_TIMEOUT == ret)
				{
					continue;
				}
				else
				{
					ASSERT(0);
					return;
				}
			}
		}

		ws->detach_condition(condition);
	});
}

