#include "TurnTable.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TurnTable w;
	w.show();
	return a.exec();
}
