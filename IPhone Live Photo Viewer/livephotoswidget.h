#pragma once
#include "qstackedwidget.h"

class QLabel;
class MovViewer;
class BaseImage;

//加载、预缓存、随图片变换大小、视频切换效果
class LivePhotosWidget :
    public QStackedWidget
{
public:
    LivePhotosWidget() = delete;
    LivePhotosWidget(QWidget* parent);
    void show(const QString& fileName);
protected:
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
private:
    QLabel* m_photoView = nullptr;
    MovViewer* m_movView = nullptr;
    BaseImage* m_currentImage = nullptr;

    QString m_fileName;
};

