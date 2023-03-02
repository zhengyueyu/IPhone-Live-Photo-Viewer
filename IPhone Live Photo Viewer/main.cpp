#include "iphonelivephotoviewer.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QTranslator tsor;
	tsor.load(QApplication::applicationDirPath() % QDir::separator() % "iphone live photo viewer_zh.qm");
	a.installTranslator(&tsor);

	IPhoneLivePhotoViewer w;
	w.show();
	return a.exec();
}
