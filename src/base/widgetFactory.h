//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   ClickButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "baseWidget.h"

namespace base
{
	class WidgetFactory : public QObject
	{
	public:
		explicit WidgetFactory() = delete;

	public:
		static base::BaseWidget * create(const QString & _type);
	};
}

#endif // !COMPONENTFACTORY_H
