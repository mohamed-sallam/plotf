#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_plot_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void fplot(const QString &function, const double &Xstart, const double &Xend, const int &samples = 1001, const double &Ystart=-10, const double &Yend=10);
};
#endif // MAINWINDOW_H
