#include <QMainWindow>
#include <boost/filesystem.hpp>
#include <QDir>

#include "global.hpp"

using boost::filesystem::path;

namespace global
{
	QMainWindow* main_window{nullptr};
	path root{path{QDir::homePath().toStdWString()} / path{".Flash Cards Program Data"}};

}