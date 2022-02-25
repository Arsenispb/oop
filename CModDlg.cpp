// CModDlg.cpp: файл реализации
//

#include "pch.h"
#include "hyperdist.h"
#include "CModDlg.h"
#include "afxdialogex.h"


// Диалоговое окно CModDlg

IMPLEMENT_DYNAMIC(CModDlg, CDialogEx)

CModDlg::CModDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_a(3)
	, m_b(3)
	, m_k(2)
	, m_len(500)
	, m_method(0)
{

}

CModDlg::~CModDlg()
{
}

void CModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_a);
	DDX_Text(pDX, IDC_EDIT1, m_b);
	DDX_Text(pDX, IDC_EDIT3, m_k);
	DDX_Text(pDX, IDC_EDIT4, m_len);
	DDX_Radio(pDX, IDC_RADIO1, m_method);
}


BEGIN_MESSAGE_MAP(CModDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CModDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений CModDlg


void CModDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(1);
	if (m_a < 2 || m_a>10) {
		AfxMessageBox(L"Wrong parameter a; corrected to [2, 10]");
		m_a = 2;
		UpdateData(0);
	}
	else if (m_b < 2 || m_b>10) {
		AfxMessageBox(L"Wrong parameter b; corrected to [2, 10]");
		m_b = 2;
		UpdateData(0);
	}
	else if (m_k < 1 || m_k>m_a || m_k>m_b) {
		AfxMessageBox(L"Wrong parameter k; corrected to [1, min(a,b)]");
		m_k = 1;
		UpdateData(0);
	}
	else if (m_len < 10 || m_len>50000) {
		AfxMessageBox(L"Wrong sample len; corrected to [10, 50000]");
		m_len = 500;
		UpdateData(0);
	}
	else CDialogEx::OnOK();
}
