
#include "LightScheme.h"
#include <memory>
#include <unordered_map>

std::unique_ptr<QPalette> LightScheme::getPalette() const {
  auto lightPalette = std::make_unique<QPalette>();

  lightPalette->setColor(QPalette::Window, QColor(0xF0, 0xF0, 0xF0));
  lightPalette->setColor(QPalette::WindowText, QColor(0x30, 0x30, 0x30));
  lightPalette->setColor(QPalette::Disabled, QPalette::WindowText, QColor(0x90, 0x90, 0x90));
  lightPalette->setColor(QPalette::Base, QColor(0xFC, 0xFC, 0xFC));
  lightPalette->setColor(QPalette::Disabled, QPalette::Base, QColor(0xFA, 0xFA, 0xFA));
  lightPalette->setColor(QPalette::AlternateBase, lightPalette->color(QPalette::Window));
  lightPalette->setColor(QPalette::Disabled, QPalette::AlternateBase,
                         lightPalette->color(QPalette::Disabled, QPalette::Window));
  lightPalette->setColor(QPalette::ToolTipBase, QColor(0xFF, 0xFF, 0xCD));
  lightPalette->setColor(QPalette::ToolTipText, Qt::black);
  lightPalette->setColor(QPalette::Text, lightPalette->color(QPalette::WindowText));
  lightPalette->setColor(QPalette::Disabled, QPalette::Text,
                         lightPalette->color(QPalette::Disabled, QPalette::WindowText));
  lightPalette->setColor(QPalette::Light, Qt::white);
  lightPalette->setColor(QPalette::Midlight, QColor(0xF0, 0xF0, 0xF0));
  lightPalette->setColor(QPalette::Dark, QColor(0xDA, 0xDA, 0xDA));
  lightPalette->setColor(QPalette::Mid, QColor(0xCC, 0xCC, 0xCC));
  lightPalette->setColor(QPalette::Shadow, QColor(0xBE, 0xBE, 0xBE));
  lightPalette->setColor(QPalette::Button, lightPalette->color(QPalette::Base));
  lightPalette->setColor(QPalette::Disabled, QPalette::Button, lightPalette->color(QPalette::Disabled, QPalette::Base));
  lightPalette->setColor(QPalette::ButtonText, lightPalette->color(QPalette::WindowText));
  lightPalette->setColor(QPalette::Disabled, QPalette::ButtonText,
                         lightPalette->color(QPalette::Disabled, QPalette::WindowText));
  lightPalette->setColor(QPalette::BrightText, QColor(0xF4, 0x00, 0x00));
  lightPalette->setColor(QPalette::Link, QColor(0x00, 0x00, 0xFF));
  lightPalette->setColor(QPalette::Highlight, QColor(0xB5, 0xB5, 0xB5));
  lightPalette->setColor(QPalette::Disabled, QPalette::Highlight, QColor(0xDF, 0xDF, 0xDF));
  lightPalette->setColor(QPalette::HighlightedText, lightPalette->color(QPalette::WindowText));
  lightPalette->setColor(QPalette::Disabled, QPalette::HighlightedText,
                         lightPalette->color(QPalette::Disabled, QPalette::WindowText));

  return lightPalette;
}

std::unique_ptr<QString> LightScheme::getStyleSheet() const {
  std::unique_ptr<QString> qsStylesheet = nullptr;

  QFile qfDarkStyle(QString(":/light_scheme/stylesheet.qss"));
  if (qfDarkStyle.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qsStylesheet = std::make_unique<QString>(qfDarkStyle.readAll());

    qfDarkStyle.close();
  }

  return qsStylesheet;
}

std::unique_ptr<ColorScheme::ColorParams> LightScheme::getColorParams() const {
  auto customColors = std::make_unique<ColorParams>();

  customColors->insert(ColorParams::value_type(ThumbnailSequenceSelectedItemBackground, QColor(0x72, 0x72, 0x72)));
  customColors->insert(ColorParams::value_type(ThumbnailSequenceSelectedItemText, Qt::white));
  customColors->insert(ColorParams::value_type(ThumbnailSequenceItemText, Qt::black));
  customColors->insert(ColorParams::value_type(ThumbnailSequenceSelectionLeaderBackground, QColor(0x69, 0x69, 0x69)));
  customColors->insert(ColorParams::value_type(OpenNewProjectBorder, QColor(0xCC, 0xCC, 0xCC)));
  customColors->insert(ColorParams::value_type(ProcessingIndicationFade, QColor(0x93, 0x93, 0x93)));
  customColors->insert(ColorParams::value_type(ProcessingIndicationHeadColor, QColor(0x30, 0x30, 0x30)));
  customColors->insert(ColorParams::value_type(ProcessingIndicationTail, QColor(0xB5, 0xB5, 0xB5)));
  customColors->insert(ColorParams::value_type(StageListHead, customColors->at(ProcessingIndicationHeadColor)));
  customColors->insert(ColorParams::value_type(StageListTail, customColors->at(ProcessingIndicationTail)));
  customColors->insert(ColorParams::value_type(FixDpiDialogErrorText, QColor(0xFB, 0x00, 0x00)));

  return customColors;
}
