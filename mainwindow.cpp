#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mathutil.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::fplot("x^2", -1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fplot(const QString &function, const double &Xstart, const double &Xend, const int &samples, const double &Ystart, const double &Yend)
{
    // generate some data:
    QVector<double> x(samples), y(samples); // initialize with entries 0 -> `samples`
    const int numberOfSpacesInRange {samples - 1};
    const double step {(Xend - Xstart) / (numberOfSpacesInRange)};
    int nanCounter {0};
    for (int i {0}; i<samples; ++i)
    {
      x[i] = Xstart + i * step; // x goes from start to end
      y[i] = MathUtil::substituteIntoFunc(function, "x", x[i]); // plot the function
      if (std::isnan(y[i]))
          ++nanCounter;
    }
    if (nanCounter == samples)
        QMessageBox::warning(this, "Error", "Follow the function syntax instructions!\n"
                                            "Use ONLY these operators +-*/^ and "
                                            "small letter x as a mathematical variable!\n"
                                            "ex: 5*x^2+10*x-1.1/2");
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(Xstart, Xend);
    ui->customPlot->yAxis->setRange(Ystart, Yend);
    ui->customPlot->replot();
}

void MainWindow::on_plot_pushButton_clicked()
{
    // deleting white spaces from input fields
    QString function {ui->function_lineEdit->text().remove(" ")},
            x1 {ui->x1_lineEdit->text().remove(" ")},
            x2 {ui->x2_lineEdit->text().remove(" ")};

    // check if the input fields are empty or not
    if (function.isEmpty() || x1.isEmpty() || x2.isEmpty())
        QMessageBox::warning(this, "Error", "Please, fill all fields!");
    else
        MainWindow::fplot(function, x1.toDouble(), x2.toDouble());
}

