#pragma once
#include <QWidget>
#include <utility>
#include <QMenu>

#include "data/flash_card.hpp"


namespace Ui
{
	class EditDeck;
}

class EditDeck : public QWidget
{
	Q_OBJECT
public:
	explicit EditDeck(QWidget*);
	explicit EditDeck(QWidget*, data::deck_data&&);
	~EditDeck();

public slots:
	void deleteSelectedCard();
	void editSelectedCard();
	void newCard();
	void updateButtons();
	void saveDeck();
	void closeDeck();

private:
	Ui::EditDeck *ui;
	data::deck_data deck;
	std::shared_ptr<QMenu> card_menu;

	void set_deckui(const data::deck_data&);

};
