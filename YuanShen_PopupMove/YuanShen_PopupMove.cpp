#include "YuanShen_PopupMove.h"

#include <QString>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include "YuanShen_Fun.h"

YuanShen_PopupMove::YuanShen_PopupMove(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	//this->setAttribute(Qt::WA_TransparentForMouseEvents, true);

	connect(ui.pB_StartMove, &QPushButton::clicked, this, &YuanShen_PopupMove::StartMove);

		//setCurrentIndex;
}

void YuanShen_PopupMove::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		syncToYuanShen();

		m_Press = event->globalPos();
		leftBtnClk = true;
	}
	event->ignore();
}

void YuanShen_PopupMove::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		leftBtnClk = false;
	}
	if (event->button() == Qt::RightButton)
	{
		this->close();
	}
	event->ignore();
}

void YuanShen_PopupMove::mouseMoveEvent(QMouseEvent *event)
{
	if (leftBtnClk)
	{
		m_Move = event->globalPos();
		this->move(this->pos() + m_Move - m_Press);
		m_Press = m_Move;

		syncToThis();
	}
	event->ignore();
	update();
}

void YuanShen_PopupMove::paintEvent(QPaintEvent *)
{
}

void YuanShen_PopupMove::syncToYuanShen()
{
	ysHandle = getYuanShenHandle();
	if (IsWindow(ysHandle))
	{
		SetForegroundWindow(ysHandle);/* 对原神窗口的操作 */
		if (getYuanShenRect(ysHandle, ysRect))
		{
			this->setGeometry(ysRect.left, ysRect.top, ysRect.right - ysRect.left, ysRect.bottom - ysRect.top);
			
			this->resize(ysRect.right - ysRect.left, ysRect.bottom - ysRect.top);
			//ui.label->setGeometry(ysRect.left, ysRect.top, ysRect.right - ysRect.left, ysRect.bottom - ysRect.top);
			setThisTop((HWND)this->winId());

		}

	}
}
void YuanShen_PopupMove::syncToThis()
{
	if (IsWindow(ysHandle))
	{
		bool res=false;
		res=SetWindowPos(ysHandle, HWND_TOPMOST, this->x(), this->y(), 0, 0, SWP_NOZORDER | SWP_NOSIZE);

		if (!res)
		{
			int errorcode = 0;
			errorcode = GetLastError();
			switch (errorcode)
			{
			case 5:
			{
				//need admin
				break;
			}
			}
		}
	}
}
void YuanShen_PopupMove::StartMove()
{
	ui.stackedWidget->setCurrentIndex(1);
}

