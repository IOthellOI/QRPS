//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   Status
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef Status_H
#define Status_H

#include "baseWidget.h"

namespace page
{
	class Status : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit Status(QWidget * _parent = nullptr);
		virtual ~Status();

	public:
		struct StatusData;
		StatusData * data;
	};
}

#endif // !Status_H

