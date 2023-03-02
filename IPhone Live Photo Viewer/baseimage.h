#pragma once
#include "qstring.h"
#include "qimage.h"

class BaseImage
{
public:
	virtual BaseImage* next();
	virtual BaseImage* pre();
	virtual QImage getImage() = 0;
protected:
	BaseImage* m_next = nullptr;
	BaseImage* m_pre = nullptr;
	QString m_fileName;
};
