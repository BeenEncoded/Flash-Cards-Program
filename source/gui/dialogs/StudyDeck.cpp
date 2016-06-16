#include <QWidget>
#include <vector>
#include <QDialog>
#include <algorithm>
#include <QStatusBar>
#include <QMessageBox>

#include "StudyDeck.hpp"
#include "ui_StudyDeck.h"
#include "data/flash_card.hpp"
#include "data/global.hpp"

StudyDeck::StudyDeck(QWidget* parent, data::deck_data&& d) : 
	QDialog{parent},
	ui{new Ui::StudyDeck},
	deck(d),
	cards{},
	card{0},
	frontshowing{true}
{
	this->ui->setupUi(this);
	for(unsigned int x{0}; x < this->deck.cards.size(); ++x) this->cards.emplace_back(&this->deck.cards[x]);
	this->card = 0;
	if(!this->cards.empty()) this->set_card(*(this->cards[this->card]));
}

StudyDeck::~StudyDeck()
{
	delete this->ui;
}

void StudyDeck::next_card()
{
	if(this->deck.cards.empty()) return;
	if(this->card < (this->cards.size() - 1)) this->set_card(*(this->cards[++this->card]));
}

void StudyDeck::prev_card()
{
	if(this->deck.cards.empty()) return;
	if(this->card > 0) this->set_card(*(this->cards[--this->card]));
}

void StudyDeck::flip_card()
{
	if(this->cards.empty()) return;
	if(this->frontshowing)
	{
		this->ui->text->setText(this->cards[this->card]->back);
		this->ui->card_box->setTitle("Back");
		this->frontshowing = false;
	}
	else
	{
		this->ui->text->setText(this->cards[this->card]->front);
		this->ui->card_box->setTitle("Front");
		this->frontshowing = true;
	}
}

void StudyDeck::shuffle()
{
	if(!this->cards.empty())
	{
		std::random_shuffle(this->cards.begin(), this->cards.end());
		this->card = 0;
		this->set_card(*(this->cards[this->card]));
		global::main_window->statusBar()->showMessage("Deck Shuffled", 2000);
	}
	else global::main_window->statusBar()->showMessage("The deck is empty!", 2000);
}

void StudyDeck::set_card(const data::card_data& card)
{
	this->ui->text->setText(card.front);
	this->ui->card_box->setTitle("Front");
	this->frontshowing = true;
}

