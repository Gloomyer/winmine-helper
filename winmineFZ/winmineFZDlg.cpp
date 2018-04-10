
// winmineFZDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "winmineFZ.h"
#include "winmineFZDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CwinmineFZDlg 对话框



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


// CwinmineFZDlg 消息处理程序

BOOL CwinmineFZDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CwinmineFZDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CwinmineFZDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CwinmineFZDlg::OnBnClickedButton1() {
	HWND h = ::FindWindow(NULL, _T("扫雷"));
	if (h == NULL) {
		MessageBox(_T("游戏未打开"));
		return;
	}
	::SendMessage(h, WM_COMMAND, 0x209, 0);
}


void CwinmineFZDlg::OnBnClickedButton2() {
	HWND h = ::FindWindow(NULL, _T("扫雷"));
	if (h == NULL) {
		MessageBox(_T("游戏未打开"));
		return;
	}
	::SendMessage(h, WM_COMMAND, 0x20A, 0);
}


void CwinmineFZDlg::OnBnClickedButton3() {
	HWND h = ::FindWindow(NULL, _T("扫雷"));
	if (h == NULL) {
		MessageBox(_T("游戏未打开"));
		return;
	}
	::SendMessage(h, WM_COMMAND, 0x20B, 0);
}


void CwinmineFZDlg::OnBnClickedButton4() {
	HWND h = ::FindWindow(NULL, _T("扫雷"));
	if (h == NULL) {
		MessageBox(_T("游戏未打开"));
		return;
	}
	DWORD pid;
	if (GetWindowThreadProcessId(h, &pid) == NULL) {
		MessageBox(_T("游戏进程ID查询失败"));
		return;
	}

	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	int count;
	ReadProcessMemory(pHandle,(LPCVOID)0x01005194, &count, 4, NULL);
	CString str;
	str.Format(_T("剩余数量:%d"), count);
	SetDlgItemText(IDC_STATIC_COUNT, str);
}

#define gamex 14+6
#define gamey 56+6
void CwinmineFZDlg::OnBnClickedButton5() {
	HWND h = ::FindWindow(NULL, _T("扫雷"));
	if (h == NULL) {
		MessageBox(_T("游戏未打开"));
		return;
	}
	DWORD pid;
	if (GetWindowThreadProcessId(h, &pid) == NULL) {
		MessageBox(_T("游戏进程ID查询失败"));
		return;
	}

	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);


	int row, colum;
	ReadProcessMemory(pHandle, (LPCVOID)0x01005338, &row, 4, NULL);
	ReadProcessMemory(pHandle, (LPCVOID)0x01005334, &colum, 4, NULL);

	//读取棋盘
	//棋盘存在24*32个 恒定的
	char chessboard[24][32];
	DWORD readSize;
	ReadProcessMemory(pHandle, (LPCVOID)0x01005361, &chessboard, 32 * 24, &readSize);
	if (readSize != 24 * 32) {
		MessageBox(_T("棋盘数据读取失败"));
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
