

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "data/global.hpp"
#include "gui/main_widgets/ManageDecks.hpp"

MainWindow::MainWindow(QWidget* parent) : 
	QMainWindow{parent},
	ui{new Ui::MainWindow}
{
	this->ui->setupUi(this);
	global::main_window = this;
	this->setCentralWidget(new ManageDecks{this});
}

MainWindow::~MainWindow()
{
	delete this->ui;
}

