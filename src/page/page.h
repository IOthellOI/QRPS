//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   Page
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef PAGE_H
#define PAGE_H

#include "baseWidget.h"

namespace page
{
	class Page : public base::BaseWidget
	{
	public:
		explicit Page(QWidget * _parent = nullptr);
		virtual ~Page();

	public:
		virtual void loadConfig(const QString & _path) const;

	private:
		struct PageData;
		PageData * data;
	};
}

#endif // !PAGE_H
