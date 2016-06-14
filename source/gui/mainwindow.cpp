

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "data/global.hpp"

MainWindow::MainWindow(QWidget* parent) : 
	QMainWindow{parent},
	ui{new Ui::MainWindow}
{
	this->ui->setupUi(this);
	global::main_window = this;
}

MainWindow::~MainWindow()
{
	delete this->ui;
}

