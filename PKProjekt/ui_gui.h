/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QWidget *centralwidget;
    QGridLayout *mainGridLayout;
    QChartView *chartSetpointOutput;
    QChartView *chartError;
    QChartView *chartControl;
    QVBoxLayout *pidLayout;
    QLabel *pidLabel;
    QLineEdit *kpInput;
    QLineEdit *kiInput;
    QLineEdit *kdInput;
    QPushButton *resetButton;
    QVBoxLayout *arxLayout;
    QLabel *arxLabel;
    QLineEdit *arxAInput;
    QLineEdit *arxBInput;
    QLineEdit *arxDelayInput;
    QLCDNumber *simulationTimeDisplay;
    QPushButton *startStopButton;
    QTextBrowser *logOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName("gui");
        gui->resize(1200, 800);
        gui->setWindowState(Qt::WindowMaximized);
        centralwidget = new QWidget(gui);
        centralwidget->setObjectName("centralwidget");
        mainGridLayout = new QGridLayout(centralwidget);
        mainGridLayout->setObjectName("mainGridLayout");
        chartSetpointOutput = new QChartView(centralwidget);
        chartSetpointOutput->setObjectName("chartSetpointOutput");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chartSetpointOutput->sizePolicy().hasHeightForWidth());
        chartSetpointOutput->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(chartSetpointOutput, 0, 0, 1, 2);

        chartError = new QChartView(centralwidget);
        chartError->setObjectName("chartError");
        sizePolicy.setHeightForWidth(chartError->sizePolicy().hasHeightForWidth());
        chartError->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(chartError, 1, 0, 1, 1);

        chartControl = new QChartView(centralwidget);
        chartControl->setObjectName("chartControl");
        sizePolicy.setHeightForWidth(chartControl->sizePolicy().hasHeightForWidth());
        chartControl->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(chartControl, 1, 1, 1, 1);

        pidLayout = new QVBoxLayout();
        pidLayout->setObjectName("pidLayout");
        pidLabel = new QLabel(centralwidget);
        pidLabel->setObjectName("pidLabel");

        pidLayout->addWidget(pidLabel);

        kpInput = new QLineEdit(centralwidget);
        kpInput->setObjectName("kpInput");

        pidLayout->addWidget(kpInput);

        kiInput = new QLineEdit(centralwidget);
        kiInput->setObjectName("kiInput");

        pidLayout->addWidget(kiInput);

        kdInput = new QLineEdit(centralwidget);
        kdInput->setObjectName("kdInput");

        pidLayout->addWidget(kdInput);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");

        pidLayout->addWidget(resetButton);


        mainGridLayout->addLayout(pidLayout, 2, 0, 1, 1);

        arxLayout = new QVBoxLayout();
        arxLayout->setObjectName("arxLayout");
        arxLabel = new QLabel(centralwidget);
        arxLabel->setObjectName("arxLabel");

        arxLayout->addWidget(arxLabel);

        arxAInput = new QLineEdit(centralwidget);
        arxAInput->setObjectName("arxAInput");

        arxLayout->addWidget(arxAInput);

        arxBInput = new QLineEdit(centralwidget);
        arxBInput->setObjectName("arxBInput");

        arxLayout->addWidget(arxBInput);

        arxDelayInput = new QLineEdit(centralwidget);
        arxDelayInput->setObjectName("arxDelayInput");

        arxLayout->addWidget(arxDelayInput);


        mainGridLayout->addLayout(arxLayout, 2, 1, 1, 1);

        simulationTimeDisplay = new QLCDNumber(centralwidget);
        simulationTimeDisplay->setObjectName("simulationTimeDisplay");
        simulationTimeDisplay->setSegmentStyle(QLCDNumber::Flat);

        mainGridLayout->addWidget(simulationTimeDisplay, 3, 0, 1, 1);

        startStopButton = new QPushButton(centralwidget);
        startStopButton->setObjectName("startStopButton");

        mainGridLayout->addWidget(startStopButton, 3, 1, 1, 1);

        logOutput = new QTextBrowser(centralwidget);
        logOutput->setObjectName("logOutput");
        logOutput->setHtml(QString::fromUtf8("\n"
"        <!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"        <html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"        p, li { white-space: pre-wrap; }\n"
"        </style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"        <p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Log symulacji pojawi si\304\231 tutaj.</p>\n"
"        </body></html>\n"
"        "));
        logOutput->setMaximumHeight(100);

        mainGridLayout->addWidget(logOutput, 4, 0, 1, 2);

        gui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gui);
        menubar->setObjectName("menubar");
        gui->setMenuBar(menubar);
        statusbar = new QStatusBar(gui);
        statusbar->setObjectName("statusbar");
        gui->setStatusBar(statusbar);

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QMainWindow *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "Symulator UAR", nullptr));
        pidLabel->setText(QCoreApplication::translate("gui", "PID", nullptr));
        kpInput->setPlaceholderText(QCoreApplication::translate("gui", "Kp", nullptr));
        kiInput->setPlaceholderText(QCoreApplication::translate("gui", "Ki", nullptr));
        kdInput->setPlaceholderText(QCoreApplication::translate("gui", "Kd", nullptr));
        resetButton->setText(QCoreApplication::translate("gui", "Reset", nullptr));
        arxLabel->setText(QCoreApplication::translate("gui", "ARX", nullptr));
        arxAInput->setPlaceholderText(QCoreApplication::translate("gui", "A", nullptr));
        arxBInput->setPlaceholderText(QCoreApplication::translate("gui", "B", nullptr));
        arxDelayInput->setPlaceholderText(QCoreApplication::translate("gui", "Op\303\263\305\272nienie", nullptr));
        startStopButton->setText(QCoreApplication::translate("gui", "Start / Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
