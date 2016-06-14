#ifndef UNIT_TEST_PROG
#include <QApplication>

#include "gui/mainwindow.hpp"

int main(int c, char** v)
{
	QApplication app{c, v};
	MainWindow window;
	window.show();
	return app.exec();
}

#endif