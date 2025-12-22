#include "../include/InitialsWidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  InitialsWidget widget;
  widget.show();

  return app.exec();
}
