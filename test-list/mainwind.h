#ifndef MAINWIND_H
#define MAINWIND_H

#include <QMainWindow>

namespace Ui {
class MainWind;
}

class MainWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWind(QWidget *parent = nullptr);
    ~MainWind();

private:
    Ui::MainWind *ui;
};

#endif // MAINWIND_H
