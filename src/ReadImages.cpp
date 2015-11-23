// -*- C++ -*-
/*!
 * @file  ReadImages.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "ReadImages.h"
using namespace std;
using namespace cv;
// Module specification
// <rtc-template block="module_spec">
static const char* readimages_spec[] =
  {
    "implementation_id", "ReadImages",
    "type_name",         "ReadImages",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "Kazuki Urabe",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.ReadData", "0:camera",
    "conf.default.filename", "image/image???.jpg",
    // Widget
    "conf.__widget__.ReadData", "radio",
    "conf.__widget__.filename", "text",
    // Constraints
    "conf.__constraints__.ReadData", "(1:picture,0:camera)",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ReadImages::ReadImages(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outputOut("output", m_output)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ReadImages::~ReadImages()
{
}



RTC::ReturnCode_t ReadImages::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("output", m_outputOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("ReadData", m_ReadData, "0:camera");
  bindParameter("filename", m_filename, "image/image???.jpg");
  // </rtc-template>

  videoCapture.open(0);
  videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, 320);
  videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
  if (!videoCapture.isOpened())
  {
    cout<<"No Camera Device"<<endl;
    return RTC::RTC_ERROR;
  }
  videoCapture>>inputFrame;
  namedWindow( "Display window", WINDOW_AUTOSIZE );
  cv::imshow( "Display window", inputFrame);
  cv::waitKey(25);
  cout<<"Initialize OK"<<endl;

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ReadImages::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadImages::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadImages::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ReadImages::onActivated(RTC::UniqueId ec_id)
{

  return RTC::RTC_OK;
}


RTC::ReturnCode_t ReadImages::onDeactivated(RTC::UniqueId ec_id)
{

  inputFrame.release();
  outputFrame.release();
  videoCapture.release();

  return RTC::RTC_OK;
}


RTC::ReturnCode_t ReadImages::onExecute(RTC::UniqueId ec_id)
{

  if (!videoCapture.isOpened())
     return RTC::RTC_OK;

  videoCapture>>inputFrame;

  cv::imshow("Display window", inputFrame);

  inputFrame>>m_output;

  cv::waitKey(3);


  m_outputOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ReadImages::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadImages::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadImages::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadImages::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadImages::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ReadImagesInit(RTC::Manager* manager)
  {
    coil::Properties profile(readimages_spec);
    manager->registerFactory(profile,
                             RTC::Create<ReadImages>,
                             RTC::Delete<ReadImages>);
  }
};  

