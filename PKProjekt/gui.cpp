#include "gui.h"
#include "ui_gui.h"
#include "Sprzezenie.h"
#include <QThread>
#include <QTime>

gui::gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gui),
    simulationRunning(false)
{
    ui->setupUi(this);

    sprzezenie = new Sprzezenie(new Arx({0.1, -0.4}, {0.6}, 1), new PID(1.0, 1.0, 1.0), 1.0);

    connect(ui->startStopButton, &QPushButton::clicked, [this]() {
        if (simulationRunning) {
            stopSimulation();
        } else {
            startSimulation();
        }
    });

    connect(ui->resetButton, &QPushButton::clicked, this, &gui::resetSimulation);
}

void gui::startSimulation() {
    simulationRunning = true;
    ui->logOutput->append("Symulacja się zaczęła.");

    while (simulationRunning) {
        updateCharts();
        QThread::msleep(100);
    }
}

void gui::stopSimulation() {
    simulationRunning = false;
    ui->logOutput->append("Symulacja zatrzymana.");
    qDebug() << "Symulacja zatrzymana.";
}

void gui::resetSimulation() {
    simulationRunning = false;
    sprzezenie->reset();
    ui->logOutput->append("Simulation reset.");
    qDebug() << "Reset symulacji.";
}

void gui::updateCharts() {
    ui->logOutput->append("Czas uaktualnienia wykresów: " + QString::number(QTime::currentTime().msecsSinceStartOfDay()));
    qDebug() <<"Wykresy uaktualnione o aktualne dane.";
}

gui::~gui() {
    delete sprzezenie;
    delete ui;
}
