#include <vector>
#include <QWidget>
#include <QMenu>
#include <utility>
#include <QAction>
#include <QMessageBox>
#include <QStatusBar>

#include "EditDeck.hpp"
#include "ui_EditDeck.h"
#include "data/global.hpp"
#include "data/flash_card.hpp"
#include "gui/main_widgets/ManageDecks.hpp"
#include "gui/mainwindow.hpp"
#include "gui/main_widgets/EditCard.hpp"

namespace
{
	QString card_display(const data::card_data&);



	inline QString card_display(const data::card_data& card)
	{
		return card.front;  //this may become more complicated in the future
	}


}

/**
Create a new deck.
*/
EditDeck::EditDeck(QWidget* parent) : 
	QWidget{parent},
	ui{new Ui::EditDeck},
	deck{"", "", std::vector<data::card_data>{}, 0},
	card_menu{}
{
	this->ui->setupUi(this);
	global::main_window->setWindowTitle("Edit Deck");
	global::main_window->adjustSize();

	//create the card menu:
	this->card_menu = std::make_shared<QMenu>("Card Menu");
	this->connect(this->card_menu->addAction("Edit Card"), &QAction::triggered, this, &EditDeck::editSelectedCard);
	this->connect(this->card_menu->addAction("Delete Card"), &QAction::triggered, this, &EditDeck::deleteSelectedCard);
	this->ui->card_button->setMenu(this->card_menu.get());
	this->updateButtons();
}

/**
Edit an existing deck.
*/
EditDeck::EditDeck(QWidget* parent, data::deck_data&& d) : 
	QWidget{parent},
	ui{new Ui::EditDeck},
	deck(d),
	card_menu{}
{
	this->ui->setupUi(this);
	global::main_window->setWindowTitle("Edit Deck");
	global::main_window->adjustSize();
	this->set_deckui(this->deck);

	//create the card menu:
	this->card_menu = std::make_shared<QMenu>("Card Menu");
	this->connect(this->card_menu->addAction("Edit Card"), &QAction::triggered, this, &EditDeck::editSelectedCard);
	this->connect(this->card_menu->addAction("Delete Card"),  &QAction::triggered, this, &EditDeck::deleteSelectedCard);
	this->ui->card_button->setMenu(this->card_menu.get());
	this->updateButtons();
}

EditDeck::~EditDeck()
{
	delete this->ui;
}

void EditDeck::editSelectedCard()
{
	if(!this->ui->list->selectedItems().empty())
	{
		if(this->ui->list->currentRow() >= 0)
		{
			global::main_window->setCentralWidget(
				new EditCard{
					global::main_window, 
					std::move(this->deck), 
					(std::size_t)this->ui->list->currentRow()
			});
		}
	}
}

void EditDeck::newCard()
{
	this->deck.name = this->ui->deck_name->text();
	this->deck.description = this->ui->deck_description->toPlainText();
	global::main_window->setCentralWidget(new EditCard{global::main_window, std::move(this->deck)});
}

void EditDeck::deleteSelectedCard()
{
	if(!this->ui->list->selectedItems().empty())
	{
		if(this->ui->list->currentRow() >= 0)
		{
			auto answer = QMessageBox::question(this, "WARNING!", (QString{"Are you sure you want to delete \""} + 
				this->deck.cards[this->ui->list->currentRow()].front + QString{"\"?"}));

			if(answer == QMessageBox::Yes)
			{
				this->deck.cards.erase(this->deck.cards.begin() + this->ui->list->currentRow());
				this->ui->list->clear();
				for(std::size_t x{0}; x < this->deck.cards.size(); ++x)
				{
					this->ui->list->addItem(card_display(this->deck.cards[x]));
				}
				this->updateButtons();
			}
		}
	}
}

void EditDeck::set_deckui(const data::deck_data& d)
{
	this->ui->deck_name->setText(d.name);
	this->ui->deck_description->setPlainText(d.description);

	this->ui->list->clear();
	for(std::size_t x{0}; x < d.cards.size(); ++x)
	{
		this->ui->list->addItem(card_display(d.cards[x]));
	}
}

void EditDeck::updateButtons()
{
	this->ui->card_button->setEnabled(!this->ui->list->selectedItems().empty());
}

void EditDeck::saveDeck()
{
	this->deck.name = this->ui->deck_name->text();
	this->deck.description = this->ui->deck_description->toPlainText();
	utility::save<data::deck_data>(this->deck);
	global::main_window->statusBar()->showMessage("SAVED!", 3000);
}

void EditDeck::closeDeck()
{
	global::main_window->setCentralWidget(new ManageDecks{global::main_window});
}

