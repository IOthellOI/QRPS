//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   MainWindow
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "baseWidget.h"

namespace page
{
	class MainWindow : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit MainWindow(QWidget * parent = nullptr);
		virtual ~MainWindow();

		struct MainWindowData;
		MainWindowData * data;
	};
}
#endif // !MAINWINDOW_H
