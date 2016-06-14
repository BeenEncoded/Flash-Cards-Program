#pragma once
#ifndef MANAGECARDS_H
#define MANAGECARDS_H
#include <QWidget>

namespace Ui
{
	class ManageCards;
}

class ManageCards : public QWidget
{
	Q_OBJECT

public:
	explicit ManageCards(QWidget* = nullptr);
	~ManageCards();

private:
	Ui::ManageCards *ui;
};

#endif // MANAGECARDS_H
