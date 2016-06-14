#pragma once
#include <QString>
#include <vector>
#include <iostream>

#include "utility/file_loader.hpp"
#include "global.hpp"

namespace data
{
	struct deck_data;
	struct card_data;
	
	std::ostream& operator<<(std::ostream&, const deck_data&);
	std::istream& operator>>(std::istream&, deck_data&);

	std::ostream& operator<<(std::ostream&, const card_data&);
	std::istream& operator>>(std::istream&, card_data&);

	//I know a simple std::pair might do, but I want to make it more readable
	struct card_data
	{
		QString front, back;
	};

	struct deck_data
	{
		QString name, description;
		std::vector<card_data> cards;
		utility::ID_T id;

		static constexpr const char* const EXTENSION{".deck"};

		static boost::filesystem::path& folder()
		{
			static boost::filesystem::path f{global::root};
			return f;
		}

		static utility::ID_T load_id(std::istream&);
		static deck_data     basic(std::istream&);
	};


}

