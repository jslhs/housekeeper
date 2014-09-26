#include "housekeeper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	housekeeper w;
	w.show();
	return a.exec();
}
