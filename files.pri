#Files releavant to full builds (aka: release and debug builds)

#additionally, add the source diretcory to the list of includes:
QMAKE_CXXFLAGS += /Isource

SOURCES += source/main.cpp \
		   source/utility/file_loader.cpp \
		   source/utility/filesystem.cpp \
		   source/utility/stream_operations.cpp \
		   source/gui/mainwindow.cpp \
		   source/data/global.cpp \
		   source/data/flash_card.cpp \
		   source/gui/main_widgets/ManageDecks.cpp \
		   source/gui/main_widgets/EditDeck.cpp \
		   source/gui/main_widgets/EditCard.cpp \
		   source/gui/dialogs/StudyDeck.cpp

HEADERS += source/utility/file_loader.hpp \
		   source/utility/filesystem.hpp \
		   source/utility/stream_operations.hpp \
		   source/gui/mainwindow.hpp \
		   source/data/global.hpp \
		   source/data/flash_card.hpp \
		   source/gui/main_widgets/ManageDecks.hpp \
		   source/gui/main_widgets/EditDeck.hpp \
		   source/gui/main_widgets/EditCard.hpp \
		   source/gui/dialogs/StudyDeck.hpp

FORMS += source/gui/mainwindow.ui \
		 source/gui/main_widgets/ManageDecks.ui \
		 source/gui/main_widgets/EditDeck.ui \
		 source/gui/main_widgets/EditCard.ui \
		 source/gui/dialogs/StudyDeck.ui

RESOURCES += source/resources/resources.qrc