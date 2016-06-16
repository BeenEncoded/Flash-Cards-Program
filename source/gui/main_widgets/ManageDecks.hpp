#pragma once
#include <QWidget>
#include <vector>
#include <utility>
#include <QMenu>

#include "data/flash_card.hpp"

namespace Ui
{
	class ManageDecks;
}

class ManageDecks : public QWidget
{
	Q_OBJECT
public:
	explicit ManageDecks(QWidget* = nullptr);
	~ManageDecks();

public slots:
	void editSelectedDeck();
	void deleteSelectedDeck();
	void newDeck();
	void studyDeck();
	
	void updateButtons();

private:
	Ui::ManageDecks *ui;
	std::vector<data::deck_data> decks;
	std::shared_ptr<QMenu> deck_menu;

	void refresh_list();

};
