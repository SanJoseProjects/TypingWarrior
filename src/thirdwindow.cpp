#include "thirdwindow.h"
#include "ui_thirdwindow.h"
ThirdWindow::ThirdWindow(QWidget *parent)
    : QMainWindow(parent), thirdwindow(new Ui::ThirdWindow) {
  thirdwindow->setupUi(this);
  thirdwindow->textEdit->setReadOnly(true);
  QRegExp exp("[a-zA-Z ]{600}");
  thirdwindow->lineEdit->setValidator(new QRegExpValidator(exp, this));
  thirdwindow->pushButton_check->setEnabled(false);
}
ThirdWindow::~ThirdWindow() { delete thirdwindow; }

void ThirdWindow::on_pushButton_check_clicked() {
  disconnect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
  thirdwindow->timertext->setText("00:00");
  mis = text_verification(thirdwindow->textEdit->toPlainText(),
                          thirdwindow->lineEdit->text());
  speed = speed_measurement(ti, thirdwindow->lineEdit->text());
  timetext = "Затраченое время: " + QString::number(ti) + " секунды\n" +
             "Cкрость набора: " + QString::number(speed) + " с/м\n" +
             "Допущено ошибок: " + QString::number(mis);
  QMessageBox::information(this, "Время", timetext);
  thirdwindow->lineEdit->clear();
  thirdwindow->pushButton_start->setEnabled(true);
  thirdwindow->pushButton_check->setEnabled(false);
  thirdwindow->textEdit->setEnabled(true);
}

void ThirdWindow::on_pushButton_start_clicked() {
  ti = 0;
  t.setHMS(0, 0, 0);
  thirdwindow->textEdit->setEnabled(false);
  timer = new QTimer(this);
  if (rand() % 7 + 1 == 1) {
    lvl1 = ":/res/levels/letters/fjdk.txt";
  } else if (rand() % 7 + 1 == 2) {
    lvl1 = ":/res/levels/letters/rtuy.txt";
  } else if (rand() % 7 + 1 == 3) {
    lvl1 = ":/res/levels/letters/cvnb.txt";
  } else if (rand() % 7 + 1 == 4) {
    lvl1 = ":/res/levels/letters/asl.txt";
  } else if (rand() % 7 + 1 == 5) {
    lvl1 = ":/res/levels/letters/zxm.txt";
  } else if (rand() % 7 + 1 == 6) {
    lvl1 = ":/res/levels/letters/ghei.txt";
  } else {
    lvl1 = ":/res/levels/letters/qwop.txt";
  }

  if (rand() % 5 + 1 == 1) {
    lvl2 = ":/res/levels/words/firstLevel.txt";
  } else if (rand() % 5 + 1 == 2) {
    lvl2 = ":/res/levels/words/secondLevel.txt";
  } else if (rand() % 5 + 1 == 3) {
    lvl2 = ":/res/levels/words/thirdLevel.txt";
  } else if (rand() % 5 + 1 == 4) {
    lvl2 = ":/res/levels/words/fourthLevel.txt";
  } else {
    lvl2 = ":/res/levels/words/fifthLevel.txt";
  }

  if (rand() % 3 + 1 == 1) {
    lvl3 = ":/res/levels/sentences/firstLevel.txt";
  } else if (rand() % 3 + 1 == 2) {
    lvl3 = ":/res/levels/sentences/secondLevel.txt";
  } else {
    lvl3 = ":/res/levels/sentences/thirdLevel.txt";
  }
  if (thirdwindow->radioButton_easy->isChecked()) {
    path = lvl1;
    timer->start(1000);
  }
  if (thirdwindow->radioButton_normal->isChecked()) {
    path = lvl2;
    timer->start(1000);
  }
  if (thirdwindow->radioButton_hard->isChecked()) {
    path = lvl3;
    timer->start(1000);
  }
  connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
  thirdwindow->pushButton_start->setEnabled(false);
  buffer = open_file(path);
  thirdwindow->textEdit->setText(buffer);
  thirdwindow->lineEdit->clear();
}

void ThirdWindow::onTimeout() {
  thirdwindow->pushButton_check->setCheckable(true);
  ;
  t = t.addSecs(1);
  ti += 1;
  if (ti == 1) {
    thirdwindow->pushButton_check->setEnabled(true);
  }
  time_show = t.toString("mm:ss");
  thirdwindow->timertext->setText(time_show);
}
void ThirdWindow::closeEvent(QCloseEvent *event) {
  event->ignore();
  if (QMessageBox::Yes ==
      QMessageBox::question(this, "Закрыть?", "Уверены?",
                            QMessageBox::Yes | QMessageBox::No)) {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    event->accept();
  }
}

int ThirdWindow::text_verification(QString str, QString text) {
  mis = 0;
  dop = 0;
  for (i = 0; i < str.length(); i++) {
    if ((text[i] != str[i]) && (i < text.length()) && (i < str.length())) {
      mis = mis + 1;
    }
  }
  if (text.length() == 0) {
    mis = str.length();
  } else if (str.length() != text.length()) {
    if (text.length() < str.length()) {
      dop = str.length() - text.length();
    }
    if (text.length() > str.length()) {
      dop = text.length() - str.length();
    }
  }
  mis += dop;
  return mis;
}

int ThirdWindow::speed_measurement(int time, QString text) {
  speed = 60 * text.length() / time;
  return speed;
}

QString ThirdWindow::open_file(QString path) {
  QFile level(path);
  if (!level.open(QFile::ReadOnly | QFile::Text)) {
    thirdwindow->pushButton_start->setEnabled(true);
    return "ERROR FILE IS NOT CHOSEN";
  } else {
    buffer = level.readAll();
    level.close();
  }
  return buffer;
}
