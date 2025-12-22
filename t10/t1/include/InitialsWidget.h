#ifndef INITIALS_WIDGET_H
#define INITIALS_WIDGET_H

#include <QColor>
#include <QWidget>

class QTimer;
class QPainter;

class InitialsWidget : public QWidget {
  Q_OBJECT

private:
  struct Letter {
    double y;
    double velocity;
    double phase;
    QColor color;
    double baseY;
  };

  static constexpr double GRAVITY = 980.0;
  static constexpr double JUMP_VELOCITY = -400.0;
  static constexpr double GROUND = 400.0;

  Letter letters[3];
  QTimer *timer;
  double time;

  void drawLetterC(QPainter &p, double x, double y, const QColor &color);
  void drawLetterGhe(QPainter &p, double x, double y, const QColor &color);

private slots:
  void updateAnimation();

protected:
  void paintEvent(QPaintEvent *event) override;

public:
  explicit InitialsWidget(QWidget *parent = nullptr);
  ~InitialsWidget() override = default;
};

#endif // INITIALS_WIDGET_H
