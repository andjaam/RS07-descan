#include "headers/displayarea.h"

DisplayArea::DisplayArea(QWidget *parent) : QWidget(parent)
{
    m_label = new QLabel();
}

QLabel *DisplayArea::getLabel()
{
    return m_label;
}

Image *DisplayArea::getElement()
{
    return *m_current;
}

void DisplayArea::setElements(const QStringList &filePaths)
{
    for (auto i=filePaths.cbegin(); i != filePaths.cend(); i++) {
        m_elements.push_back(new Image(*i));
    }
    for (auto i=m_elements.begin(); i != m_elements.end(); i++) {
        (*i)->setScaleFactor(1.0);
    }
    m_current = m_elements.begin();
}

void DisplayArea::getNextElement()
{
    if (std::next(m_current) != m_elements.cend()) {
        m_current++;
    }
}

void DisplayArea::getPreviousElement()
{
    if (m_current != m_elements.begin()) {
        m_current--;
    }
}

void DisplayArea::setImageInLabel(QImage img)
{
    (*m_current)->setImage(img);
    m_label->setPixmap(QPixmap::fromImage((*m_current)->getImage()));
    scaleImage(1.0);
}

void DisplayArea::setImageInLabel()
{
    m_label->setPixmap(QPixmap::fromImage((*m_current)->getImage()));
    scaleImage(1.0);
}

void DisplayArea::scaleImage(double factor)
{
    double newScaleFactor = (*m_current)->getScaleFactor() * factor;
    (*m_current)->setScaleFactor(newScaleFactor);
    QPixmap pixmap = QPixmap::fromImage((*m_current)->getImage());
    pixmap = pixmap.scaled(newScaleFactor*pixmap.size());
    m_label->setPixmap(pixmap);
    m_label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_label->resize(pixmap.size().width(), pixmap.size().height());
    qDebug() << pixmap.size().width() << " " << pixmap.size().height();
}
