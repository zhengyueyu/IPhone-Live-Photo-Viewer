#include "imagesmanager.h"
#include "qfileinfo.h"
#include "qstringbuilder.h"
#include "heifimage.h"

ImagesManager* ImagesManager::getInstance()
{
    static ImagesManager* im = new ImagesManager();
    return im;
}

void ImagesManager::updateImages(const QString& fileName)
{
    //TODO:cache five photos
    if (m_curImg)
        clearImages();
    QFileInfo fileinf(fileName);
    if (!fileinf.suffix().compare("heic", Qt::CaseInsensitive))
    {
        m_curImg = new HeifImage(fileName);
    }
}

QImage ImagesManager::getCurrentImage()
{
    if (m_curImg)
        return m_curImg->getImage();
    return QImage();
}

bool ImagesManager::isLivePhoto(const QString& fileName)
{
    QFileInfo fileInf(fileName);
    if ("heic" != fileInf.suffix())
        return false;

    if (QFile::exists(fileInf.baseName() % "mov"))
        return true;

    return false;
}

void ImagesManager::clearImages()
{
    delete m_curImg;
    m_curImg = nullptr;
}

ImagesManager::ImagesManager()
{

}