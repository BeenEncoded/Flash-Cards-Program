#pragma once
#include <QDialog>
#include <vector>

#include "data/flash_card.hpp"


namespace Ui
{
	class StudyDeck;
}

class StudyDeck : public QDialog
{
	Q_OBJECT
public:
	explicit StudyDeck(QWidget*, data::deck_data&&);
	~StudyDeck();

public slots:
	void next_card();
	void prev_card();
	void flip_card();
	void shuffle();

private:
	Ui::StudyDeck *ui;
	data::deck_data deck;
	std::vector<data::card_data*> cards;
	std::size_t card;
	bool frontshowing;

	void set_card(const data::card_data&);

};

