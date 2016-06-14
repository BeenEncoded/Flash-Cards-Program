

#include "manage_cards.hpp"
#include "ui_managecards.h"

ManageCards::ManageCards(QWidget* parent) : 
	QWidget{parent},
	ui{new Ui::ManageCards}
{
	this->ui->setupUi(this); 
}

ManageCards::~ManageCards()
{
	delete this->ui;
}

