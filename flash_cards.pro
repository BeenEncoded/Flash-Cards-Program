QT += core gui widgets
CONFIG += C++14

QMAKE_CXXFLAGS += /IC:\Users\include #additional includes
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = flash_cards
TEMPLATE = app

include(files.pri)
include(test_files.pri)

#release libs
CONFIG(release, debug|release) {
	message(BUILDING RELEASE...)
    DESTDIR = build/release
	LIBS += "C:\Users\lib\x64\libboost_system-vc140-mt-1_60.lib" \
			"C:\Users\lib\x64\libboost_filesystem-vc140-mt-1_60.lib" \
			"C:\Users\lib\x64\libboost_regex-vc140-mt-1_60.lib"
}

#debug libs
CONFIG(debug, debug|release) {
	message(BUILDING DEBUG...)
    DESTDIR = build/debug
	LIBS += "C:\Users\lib\x64\libboost_system-vc140-mt-gd-1_60.lib" \
			"C:\Users\lib\x64\libboost_filesystem-vc140-mt-gd-1_60.lib" \
			"C:\Users\lib\x64\libboost_regex-vc140-mt-gd-1_60.lib"
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui
