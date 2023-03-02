#pragma once

#include <QtWidgets/QWidget>
#include "ui_iphonelivephotoviewer.h"


class QStackedWidget;

class IPhoneLivePhotoViewer : public QWidget
{
    Q_OBJECT

public:
    IPhoneLivePhotoViewer(QWidget *parent = Q_NULLPTR);

private:
    Ui::IPhoneLivePhotoViewerClass ui;
};
