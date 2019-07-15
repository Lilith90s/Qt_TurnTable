#include "UiCtrl.h"

UiCtrl::UiCtrl(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	start_button = new QPushButton(this);
	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(start_button->sizePolicy().hasHeightForWidth());
	start_button->setSizePolicy(sizePolicy);
	start_button->setText("启动");
	ui.v_mainLayout->addWidget(start_button, 0, Qt::AlignHCenter);

	table = new TurnTable();
	QWidget *window = QWidget::createWindowContainer(table);
	//window->resize(500, 500);
	QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	sizePolicy1.setHeightForWidth(window->sizePolicy().hasHeightForWidth());
	ui.v_mainLayout->addWidget(window);
	
	result_label = new QLabel(this);
	result_label->setObjectName("result");
	result_label->setText("未开始");
	result_label->setSizePolicy(sizePolicy);
	ui.v_mainLayout->addWidget(result_label, 0, Qt::AlignCenter);
	ui.v_mainLayout->setStretch(0, 1);
	ui.v_mainLayout->setStretch(1, 8);
	ui.v_mainLayout->setStretch(2, 1);
	
	auto ret = connect(start_button, SIGNAL(clicked()), table, SLOT(set_RandTimer()));
	table->set_resultLabel(result_label);
}

UiCtrl::~UiCtrl()
{
}
