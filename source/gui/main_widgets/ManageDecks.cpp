#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <vector>
#include <utility>

#include "ManageDecks.hpp"
#include "ui_ManageDecks.h"
#include "utility/file_loader.hpp"
#include "data/flash_card.hpp"
#include "gui/main_widgets/EditDeck.hpp"
#include "gui/dialogs/StudyDeck.hpp"

namespace
{
	QString deck_display(const data::deck_data&);


	inline QString deck_display(const data::deck_data& deck)
	{
		return deck.name; // for now this is all it will be...  we may make it more complicated
	}


}

ManageDecks::ManageDecks(QWidget* parent) : 
	QWidget{parent},
	ui{new Ui::ManageDecks}
{
	this->ui->setupUi(this);
	global::main_window->setWindowTitle("Manage Decks");
	global::main_window->adjustSize();
	this->deck_menu = std::make_shared<QMenu>("Deck");
	this->connect(this->deck_menu->addAction("Edit Deck"), &QAction::triggered, this, &ManageDecks::editSelectedDeck);
	this->connect(this->deck_menu->addAction("Delete Deck"), &QAction::triggered, this, &ManageDecks::deleteSelectedDeck);
	this->ui->deck_button->setMenu(this->deck_menu.get());

	this->decks = utility::load_basic<data::deck_data>();
	this->refresh_list();
	this->updateButtons();
}

ManageDecks::~ManageDecks()
{
	delete this->ui;
}

void ManageDecks::deleteSelectedDeck()
{
	if(!this->ui->list->selectedItems().empty())
	{
		if(this->ui->list->currentRow() >= 0)
		{
			auto answer = QMessageBox::question(this, "WARNING!", (QString{"Do you really want to delete \""} + 
				this->decks[this->ui->list->currentRow()].name + QString{"\"??  This is permanent!"}));

			if(answer == QMessageBox::Yes)
			{
				utility::remove<data::deck_data>(this->decks[this->ui->list->currentRow()].id);
				this->decks.erase((this->decks.begin() + this->ui->list->currentRow()));

				this->refresh_list();
				this->updateButtons();
			}
		}
	}
}

void ManageDecks::newDeck()
{
	global::main_window->setCentralWidget(new EditDeck{global::main_window});
}

void ManageDecks::studyDeck()
{
	if(!this->ui->list->selectedItems().empty())
	{
		if(this->ui->list->currentRow() >= 0)
		{
			StudyDeck d{this, std::move(utility::load<data::deck_data>(this->decks[this->ui->list->currentRow()].id))};
			d.exec();
		}
	}
}

void ManageDecks::updateButtons()
{
	this->ui->deck_button->setEnabled(!this->ui->list->selectedItems().empty());
}

void ManageDecks::editSelectedDeck()
{
	if(!this->ui->list->selectedItems().empty())
	{
		if(this->ui->list->currentRow() >= 0)
		{
			global::main_window->setCentralWidget(
				new EditDeck{
					global::main_window, 
					std::move(utility::load<data::deck_data>(this->decks[this->ui->list->currentRow()].id))});
		}
	}
}

void ManageDecks::refresh_list()
{
	this->ui->list->clear();
	for(std::size_t x{0}; x < this->decks.size(); ++x)
	{
		this->ui->list->addItem(deck_display(this->decks[x]));
	}
}

