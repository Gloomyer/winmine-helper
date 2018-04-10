
// winmineFZDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "winmineFZ.h"
#include "winmineFZDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CwinmineFZDlg �Ի���



CwinmineFZDlg::CwinmineFZDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WINMINEFZ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CwinmineFZDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CwinmineFZDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CwinmineFZDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CwinmineFZDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CwinmineFZDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CwinmineFZDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CwinmineFZDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CwinmineFZDlg ��Ϣ�������

BOOL CwinmineFZDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CwinmineFZDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CwinmineFZDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CwinmineFZDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CwinmineFZDlg::OnBnClickedButton1() {
	HWND h = ::FindWindow(NULL, _T("ɨ��"));
	if (h == NULL) {
		MessageBox(_T("��Ϸδ��"));
		return;
	}
	::SendMessage(h, WM_COMMAND, 0x209, 0);
}


void CwinmineFZDlg::OnBnClickedButton2() {
	HWND h = ::FindWindow(NULL, _T("ɨ��"));
	if (h == NULL) {
		MessageBox(_T("��Ϸδ��"));
		return;
	}
	::SendMessage(h, WM_COMMAND, 0x20A, 0);
}


void CwinmineFZDlg::OnBnClickedButton3() {
	HWND h = ::FindWindow(NULL, _T("ɨ��"));
	if (h == NULL) {
		MessageBox(_T("��Ϸδ��"));
		return;
	}
	::SendMessage(h, WM_COMMAND, 0x20B, 0);
}


void CwinmineFZDlg::OnBnClickedButton4() {
	HWND h = ::FindWindow(NULL, _T("ɨ��"));
	if (h == NULL) {
		MessageBox(_T("��Ϸδ��"));
		return;
	}
	DWORD pid;
	if (GetWindowThreadProcessId(h, &pid) == NULL) {
		MessageBox(_T("��Ϸ����ID��ѯʧ��"));
		return;
	}

	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	int count;
	ReadProcessMemory(pHandle,(LPCVOID)0x01005194, &count, 4, NULL);
	CString str;
	str.Format(_T("ʣ������:%d"), count);
	SetDlgItemText(IDC_STATIC_COUNT, str);
}

#define gamex 14+6
#define gamey 56+6
void CwinmineFZDlg::OnBnClickedButton5() {
	HWND h = ::FindWindow(NULL, _T("ɨ��"));
	if (h == NULL) {
		MessageBox(_T("��Ϸδ��"));
		return;
	}
	DWORD pid;
	if (GetWindowThreadProcessId(h, &pid) == NULL) {
		MessageBox(_T("��Ϸ����ID��ѯʧ��"));
		return;
	}

	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);


	int row, colum;
	ReadProcessMemory(pHandle, (LPCVOID)0x01005338, &row, 4, NULL);
	ReadProcessMemory(pHandle, (LPCVOID)0x01005334, &colum, 4, NULL);

	//��ȡ����
	//���̴���24*32�� �㶨��
	char chessboard[24][32];
	DWORD readSize;
	ReadProcessMemory(pHandle, (LPCVOID)0x01005361, &chessboard, 32 * 24, &readSize);
	if (readSize != 24 * 32) {
		MessageBox(_T("�������ݶ�ȡʧ��"));
		return;
	}

	CString chessboardStr;
	WORD xy[2];
	for (size_t y = 0; y < row; y++) {
		for (size_t x = 0; x < colum; x++) {
			chessboardStr.AppendFormat(_T("%d\t"), chessboard[y][x]);
			if (chessboard[y][x] == 0x10) {
				break;
			} else if (chessboard[y][x] != -113) {
				xy[0] = gamex + x * 16;
				xy[1] = gamey + y * 16;
				::SendMessage(h, WM_LBUTTONDOWN, 1, *(int*)xy);
				::SendMessage(h, WM_LBUTTONUP, 0, *(int*)xy);
			}
		}
		chessboardStr.AppendFormat(_T("\n"));
	}
	SetDlgItemText(IDC_STATIC_CHESSBORAD, chessboardStr);
}
