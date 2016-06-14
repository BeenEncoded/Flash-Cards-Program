#include <iostream>
#include <QString>

#include "flash_card.hpp"
#include "utility/stream_operations.hpp"
#include "utility/file_loader.hpp"

using utility::write;
using utility::read;

namespace data
{
	std::ostream& operator<<(std::ostream& out, const card_data& card)
	{
		if(out.good())
		{
			write(out, card.front.toStdString());
			write(out, card.back.toStdString());
		}
		return out;
	}

	std::istream& operator>>(std::istream& in, card_data& card)
	{
		card = card_data{QString{""}, QString{""}};
		
		in.peek();
		if(in.good())
		{
			std::string temps;

			read(in, temps);
			card.front = QString::fromStdString(temps);

			read(in, temps);
			card.back = QString::fromStdString(temps);
			temps.erase();
		}
		return in;
	}

	std::ostream& operator<<(std::ostream& out, const deck_data& deck)
	{
		if(out.good())
		{
			write(out, deck.id);
			write(out, deck.name);
			write(out, deck.description);
			write(out, deck.cards);
		}
		return out;
	}

	std::istream& operator>>(std::istream& in, deck_data& deck)
	{
		deck = deck_data{
			QString{""},
			QString{""},
			std::vector<card_data>{},
			(utility::ID_T)0
		};
		std::string temps[2];

		in.peek();
		if(in.good())
		{
			read(in, deck.id);
			read(in, temps[0]);
			read(in, temps[1]);
			read(in, deck.cards);

			deck.name = QString::fromStdString(temps[0]);
			deck.description = QString::fromStdString(temps[1]);
			temps[0].erase();
			temps[1].erase();
		}
		return in;
	}


}

namespace data
{
	utility::ID_T deck_data::load_id(std::istream& in)
	{
		utility::ID_T id{0};

		in.peek();
		if(in.good()) read(in, id);
		return id;
	}

	deck_data deck_data::basic(std::istream& in)
	{
		deck_data deck{
			QString{""},
			QString{""},
			std::vector<card_data>{},
			(utility::ID_T)0
		};

		std::string temps[2];

		in.peek();
		if (in.good())
		{
			read(in, deck.id);
			read(in, temps[0]);
			read(in, temps[1]);

			deck.name = QString::fromStdString(temps[0]);
			temps[0].erase();
			deck.description = QString::fromStdString(temps[1]);
			temps[1].erase();
		}
		return deck;
	}


}

