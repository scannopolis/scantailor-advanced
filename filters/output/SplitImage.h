
#ifndef SCANTAILOR_SPLITIMAGE_H
#define SCANTAILOR_SPLITIMAGE_H


#include <imageproc/BinaryImage.h>
#include <QtGui/QImage>
#include <functional>
#include <memory>

namespace output {

/**
 * The class to store and manage output images split to foreground and background layers.
 * It works in two modes:
 *  1.  Storing foreground and background images directly.
 *      Then use SplitImage::toImage() method to get the image from layers.
 *  2.  Storing only an image and mask.
 *      Then use SplitImage::getForegroundImage() and
 *      SplitImage::getBackgroundImage() to get the image layers.
 */
class SplitImage {
 public:
  enum ForegroundType {
    COLOR_FOREGROUND,
    BINARY_FOREGROUND,
    INDEXED_FOREGROUND
  };

  SplitImage();

  SplitImage(const QImage& foreground, const QImage& background);

  SplitImage(const QImage& foreground, const QImage& background, const QImage& originalBackground);

  QImage toImage() const;

  QImage getForegroundImage() const;

  void setForegroundImage(const QImage& foregroundImage);

  QImage getBackgroundImage() const;

  void setBackgroundImage(const QImage& backgroundImage);

  void setMask(const imageproc::BinaryImage& mask, ForegroundType foregroundType);

  void applyToLayerImages(const std::function<void(QImage&)>& consumer);

  bool isNull() const;

  const QImage& getOriginalBackgroundImage() const;

  void setOriginalBackgroundImage(const QImage& originalBackgroundImage);

 private:
  imageproc::BinaryImage m_mask;
  QImage m_foregroundImage;
  QImage m_backgroundImage;
  QImage m_originalBackgroundImage;
  ForegroundType m_foregroundType = COLOR_FOREGROUND;
};
}  // namespace output


#endif  // SCANTAILOR_SPLITIMAGE_H
