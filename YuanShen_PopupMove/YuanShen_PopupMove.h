#pragma once
#include <Windows.h>

#include <QtWidgets/QMainWindow>
#include "ui_YuanShen_PopupMove.h"

class YuanShen_PopupMove : public QMainWindow
{
    Q_OBJECT

public:
    YuanShen_PopupMove(QWidget *parent = Q_NULLPTR);

private:
    Ui::YuanShen_PopupMoveClass ui;
private:
	QPoint m_Press;
	QPoint m_Move;
	bool leftBtnClk = false;

	HWND ysHandle;
	RECT ysRect;
private:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void paintEvent(QPaintEvent *);

	void syncToYuanShen();
	void syncToThis();

private slots:
	void StartMove();




};
