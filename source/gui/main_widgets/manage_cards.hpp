#pragma once
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

