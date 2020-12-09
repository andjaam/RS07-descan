#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>
#include <QImage>
#include <QString>
#include <QDebug>
#include <QPixmap>
#include <stack>

class Image
{

public:
    Image(const QString& filePath);
    void loadImage(QString filePath);

    QImage getImage();
    void setImage(QImage img);
    QString getFilePath();
    void setFilePath(QString filePath);
    QSize size();
    bool isNull();

    QImage resizeImage(double factor, char option);
    QImage changeBrightness(double brightnessFactor);
    QImage changeContrast(double contrastFactor);
    QImage gammaCorrection(double gamma);
    QImage greyScale();
    QImage changeSaturation(double saturationChange);

    int width();
    int height();

    std::stack<QImage> undoStack;
    std::stack<QImage> redoStack;

    void saveAction();
    void undoAction();
    void redoAction();

    void cropImage(QPoint startPoint, QPoint endPoint);
    void rotateImage(int angle);

    double getScaleFactor();
    void setScaleFactor(double factor);

private:
    QImage m_image;
    QString m_filePath ;
    double scaleFactor;

//signals:

};

double truncate(double x);

#endif // IMAGE_H
