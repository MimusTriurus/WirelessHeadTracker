#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Converter.h>
#include <DataTransmitter.h>
#include <RtimuSensorsGetter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow( QWidget *parent = nullptr );
    ~MainWindow( );
private:
    Ui::MainWindow *ui;
    RtimuSensorsGetter _getter;
    DataTransmitter _transmitter;
private slots:
    void onGetSensorsData( float xG, float yG, float zG, float xA, float yA, float zA );
};

#endif // MAINWINDOW_H
