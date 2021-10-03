#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_YuanShen_PopupMove.h"

class YuanShen_PopupMove : public QMainWindow
{
    Q_OBJECT

public:
    YuanShen_PopupMove(QWidget *parent = Q_NULLPTR);

private:
    Ui::YuanShen_PopupMoveClass ui;
};
