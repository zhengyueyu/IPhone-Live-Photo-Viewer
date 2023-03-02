#pragma once
#include <qstring.h>
#include <qimage.h>
class BaseImage;

class ImagesManager
{
public:
	static ImagesManager* getInstance();
	void updateImages(const QString& fileName);
	QImage getCurrentImage();
private:
	ImagesManager();
	bool isLivePhoto(const QString& fileName);
	void clearImages();
private:
	BaseImage* m_curImg = nullptr;
};