#pragma once


// Диалоговое окно CModDlg

class CModDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModDlg)

public:
	CModDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CModDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	INT m_a;
	INT m_b;
	INT m_k;
	INT m_len;
	INT m_method;
	afx_msg void OnBnClickedOk();
};
