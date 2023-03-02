#include "iphonelivephotoviewer.h"
#include "stdafx.h"
#include "QtSvg/qsvgrenderer.h"
#include "livephotoswidget.h"

IPhoneLivePhotoViewer::IPhoneLivePhotoViewer(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.left->setFixedWidth(width() * 0.1);
	ui.right->setFixedWidth(width() * 0.1);

	LivePhotosWidget* lpw = new LivePhotosWidget(this);
	ui.horizontalLayout->insertWidget(1, lpw, 8);
	lpw->setFixedSize(width() * 0.8, height());

	auto setIcon = [](QLabel* label, const QString& iconFile, const QSize& sz)
	{
		QPixmap pixmap(sz);
		pixmap.fill(Qt::transparent);

		QPainter painter(&pixmap);
		QSvgRenderer renderer;
		renderer.load(iconFile);
		renderer.render(&painter);
		label->setPixmap(pixmap);
	};

	QSize iconSz(width() * 0.1, width() * 0.1);
	setIcon(ui.left, ":/res/icon/slide_left.svg", iconSz);
	setIcon(ui.right, ":/res/icon/slide_right.svg", iconSz);

	lpw->show("d:/IMG_3241.HEIC");
}