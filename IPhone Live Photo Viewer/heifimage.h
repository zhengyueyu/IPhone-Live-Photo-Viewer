#pragma once
#include "baseimage.h"
#include "qimage.h"

class HeifImage :
    public BaseImage
{
public:
    HeifImage(const QString& fileName);
    virtual QImage getImage() override;
private:
    void decode2Qimage();
private:
    QImage m_img;
    QVector<QImage> m_vImage;
};

