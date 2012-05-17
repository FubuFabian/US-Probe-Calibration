#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

#include "QVTKImageWidget.h"
#include <vtkEventQtSlotConnect.h>


class QAction;

namespace Ui
{
  class MainWindow;
}

//!Main Window for user Interaction
/*!
  This class is the main window of  ht US Probe Calibration. Here the user can
  open the calibration images and open the calibration widget
*/
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  /// Writes at the logger
  void addLogText(QString str);

  /**
   * \brief return this display widget
   * \param[out] this display widget 
   */
  QVTKImageWidget* getDisplayWidget();



private:


  Ui::MainWindow *ui;///<main window object

  /** \brief The filename of each selected image */
  QStringList imagesFilenames;

  QString textOnTextArea;///<Text on the logger

  /**
   * Central widget for display image purposes
   */
  QVTKImageWidget *displayWidget;


  vtkSmartPointer<vtkEventQtSlotConnect> Connections;///<Connects with the probe calibration widget

private slots:

  /**
   * \brief Add image folder to application
   */
  void addImages();

  /** 
   * \brief Display selected image with the image slider
   */
  void displaySelectedImage(int idx);

  /**
   * \brief Implements a ultrasound 3D probe calibration, for navigate with the 
   * probe
   */
  void probeCalibration();
  
  /**
    * \brief Print the text on logger
    */
  void print();


};




#endif // MAINWINDOW_H
