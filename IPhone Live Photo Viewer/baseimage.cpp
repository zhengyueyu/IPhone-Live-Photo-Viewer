#include "baseimage.h"

BaseImage* BaseImage::next()
{
    return m_next;
}

BaseImage* BaseImage::pre()
{
    return m_pre;
}