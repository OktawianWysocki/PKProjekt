#pragma once
#include <QMainWindow>
#include "Sprzezenie.h"

#ifndef GUI_H
#define GUI_H

namespace Ui {
class gui;
}

class gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit gui(QWidget* parent = nullptr);
    ~gui();

    void startSimulation();
    void stopSimulation();
    void resetSimulation();
    void updateCharts();

private:
    Ui::gui* ui;
    Sprzezenie* sprzezenie;
    bool simulationRunning = false;
};

#endif
