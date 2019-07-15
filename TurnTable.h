#pragma once

#include <QtWidgets/QWidget>
#include "ui_TurnTable.h"

class TurnTable : public QWidget
{
	Q_OBJECT

public:
	TurnTable(QWidget *parent = Q_NULLPTR);

private:
	Ui::TurnTableClass ui;
};
