#pragma once
#include <QWidget>
#include "ui_TurnTable.h"
#include "TurnTable.h"
#include <qpushbutton.h>
class UiCtrl : public QWidget
{
	Q_OBJECT

public:
	UiCtrl(QWidget *parent = Q_NULLPTR);
	~UiCtrl();

private:
	Ui::TurnTableClass ui;
	TurnTable* table;
	QPushButton* start_button;
	QLabel* result_label;

};
