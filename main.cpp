#include "TurnTable.h"
#include <QtWidgets/QApplication>
#include "UiCtrl.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UiCtrl w;
	w.show();
	return a.exec();
}
