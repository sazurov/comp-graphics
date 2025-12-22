#include "../include/InitialsWidget.h"
#include <QPainter>
#include <QPainterPath>
#include <QTimer>
#include <cmath>

InitialsWidget::InitialsWidget(QWidget *parent) : QWidget(parent), time(0) {
  setMinimumSize(800, 600);
  setWindowTitle("Прыгающие инициалы");

  letters[0] = {GROUND, 0, 0.0, QColor(255, 50, 50), GROUND};
  letters[1] = {GROUND, 0, M_PI / 3, QColor(50, 255, 50), GROUND};
  letters[2] = {GROUND, 0, 2 * M_PI / 3, QColor(50, 50, 255), GROUND};

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &InitialsWidget::updateAnimation);
  timer->start(16);
}

void InitialsWidget::updateAnimation() {
  const double dt = 0.016;
  time += dt;

  for (int i = 0; i < 3; i++) {
    Letter &letter = letters[i];

    letter.velocity += GRAVITY * dt;
    letter.y += letter.velocity * dt;

    if (letter.y >= GROUND) {
      letter.y = GROUND;
      letter.velocity = JUMP_VELOCITY;
      letter.velocity += (i - 1) * 30;
    }
  }

  update();
}

void InitialsWidget::drawLetterC(QPainter &p, double x, double y,
                                 const QColor &color) {
  p.setPen(QPen(color, 3));
  p.setBrush(QBrush(color));

  p.drawRect(QRectF(x + 10, y, 15, 100));
  p.drawRect(QRectF(x + 10, y, 70, 15));
  p.drawRect(QRectF(x + 10, y + 85, 70, 15));
}

void InitialsWidget::drawLetterGhe(QPainter &p, double x, double y,
                                   const QColor &color) {
  p.setPen(QPen(color, 3));
  p.setBrush(QBrush(color));

  p.drawRect(QRectF(x + 10, y, 70, 15));
  p.drawRect(QRectF(x + 10, y, 15, 100));
}

void InitialsWidget::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  painter.fillRect(rect(), Qt::white);

  painter.setPen(QPen(Qt::gray, 2, Qt::DashLine));
  painter.drawLine(0, GROUND + 100, width(), GROUND + 100);

  drawLetterC(painter, 150, letters[0].y, letters[0].color);
  drawLetterGhe(painter, 350, letters[1].y, letters[1].color);
  drawLetterC(painter, 550, letters[2].y, letters[2].color);
}
