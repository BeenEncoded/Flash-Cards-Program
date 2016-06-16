#pragma once
#include <QWidget>
#include <vector>

#include "data/flash_card.hpp"
#include "utility/file_loader.hpp"


namespace Ui
{
	class EditCard;
}

class EditCard : public QWidget
{
	Q_OBJECT
public:
	explicit EditCard(QWidget*, data::deck_data&&);
	explicit EditCard(QWidget*, data::deck_data&&, const std::size_t&);
	~EditCard();

public slots:
	void done();
	void cancel();

private:
	Ui::EditCard *ui;
	data::deck_data deck;
	std::size_t index;

	void set_card(const data::card_data&);
};
