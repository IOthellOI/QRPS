//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   MainPage
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 13,2018
//////////////////////////////////////////////////
#pragma once
#ifndef TREETABLE_H
#define TREETABLE_H

#include "baseWidget.h"

namespace group
{
	class TreeTable : public base::BaseWidget
	{
	public:
		explicit TreeTable(QWidget * _parent = nullptr);
		virtual ~TreeTable();

	public:
		virtual void loadConfig(const QString & _path) const;

	private:
		struct TreeTableData;
		TreeTableData * data;
	};
}

#endif // !TREETABLE_H


