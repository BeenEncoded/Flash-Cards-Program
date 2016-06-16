#include <QWidget>
#include <vector>
#include <utility>

#include "EditCard.hpp"
#include "ui_EditCard.h"
#include "data/global.hpp"
#include "data/flash_card.hpp"
#include "gui/main_widgets/EditDeck.hpp"

EditCard::EditCard(QWidget* parent, data::deck_data&& d) : 
	QWidget{parent},
	ui{new Ui::EditCard},
	deck(d),
	index{(std::size_t)-1}
{
	this->ui->setupUi(this);
	global::main_window->setWindowTitle("Edit Card");
	global::main_window->adjustSize();
}

EditCard::EditCard(QWidget* parent, data::deck_data&& d, const std::size_t& i) : 
	QWidget{parent},
	ui{new Ui::EditCard},
	deck(d),
	index{i}
{
	this->ui->setupUi(this);
	global::main_window->setWindowTitle("Edit Card");
	global::main_window->adjustSize();
	if(i != (std::size_t)-1) this->set_card(this->deck.cards[this->index]);
}

EditCard::~EditCard()
{
	delete this->ui;
}

void EditCard::cancel()
{
	global::main_window->setCentralWidget(new EditDeck{global::main_window, std::move(this->deck)});
}

void EditCard::set_card(const data::card_data& c)
{
	this->ui->front->setPlainText(c.front);
	this->ui->back->setPlainText(c.back);
}

void EditCard::done()
{
	if(this->index == (std::size_t)-1)
	{
		this->deck.cards.push_back(data::card_data{
			this->ui->front->toPlainText(),
			this->ui->back->toPlainText()});
		this->index = (this->deck.cards.size() - 1);
	}
	else
	{
		this->deck.cards[this->index].front = this->ui->front->toPlainText();
		this->deck.cards[this->index].back = this->ui->back->toPlainText();
	}
	global::main_window->setCentralWidget(new EditDeck{global::main_window, std::move(this->deck)});
}

