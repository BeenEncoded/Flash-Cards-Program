#Files releavant to full builds (aka: release and debug builds)

#additionally, add the source diretcory to the list of includes:
QMAKE_CXXFLAGS += /Isource

SOURCES += source/main.cpp \
		   source/utility/file_loader.cpp \
		   source/utility/filesystem.cpp \
		   source/utility/stream_operations.cpp \
		   source/gui/mainwindow.cpp \
		   source/data/global.cpp \
		   source/gui/main_widgets/manage_cards.cpp \
		   source/data/flash_card.cpp

HEADERS += source/utility/file_loader.hpp \
		   source/utility/filesystem.hpp \
		   source/utility/stream_operations.hpp \
		   source/gui/mainwindow.hpp \
		   source/data/global.hpp \
		   source/gui/main_widgets/manage_cards.hpp \
		   source/data/flash_card.hpp

FORMS += source/gui/mainwindow.ui \
		 source/gui/main_widgets/managecards.ui

#RESOURCES += 