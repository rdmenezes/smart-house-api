#pragma once
class cWindow
{
public:
	cWindow();
	~cWindow();

	void Open();
	void Close();

	bool m_bOpened;
};

