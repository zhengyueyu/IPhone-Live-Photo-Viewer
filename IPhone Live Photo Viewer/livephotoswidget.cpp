#include "livephotoswidget.h"
#include "qstackedwidget.h"
#include "qlabel.h"

#include "movviewer.h"
#include "imagesmanager.h"

LivePhotosWidget::LivePhotosWidget(QWidget* parent)
	: QStackedWidget(parent)
{
	m_photoView = new QLabel(this);
	addWidget(m_photoView);
	
	m_movView = new MovViewer(this);
	addWidget(m_movView);

	setCurrentIndex(0);
}

void LivePhotosWidget::show(const QString& fileName)
{
	m_fileName = fileName;
	ImagesManager::getInstance()->updateImages(m_fileName);
	QImage img = ImagesManager::getInstance()->getCurrentImage();
	
	QPixmap pm = QPixmap::fromImage(img.scaled(width(), height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	m_photoView->setPixmap(pm);
}

void LivePhotosWidget::mousePressEvent(QMouseEvent* event)
{
	m_movView->setMovFile(m_fileName);
	setCurrentIndex(1);
}

void LivePhotosWidget::mouseReleaseEvent(QMouseEvent* event)
{
	setCurrentIndex(0);
}
