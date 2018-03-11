//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataTable
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 11,2018
//////////////////////////////////////////////////
#pragma once

#include "baseWidget.h"

namespace table
{
	class DataTable : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit DataTable(QWidget * _parent = nullptr);
		virtual ~DataTable();

	private:
		struct DataTableData;
		DataTableData * data;
	};
}
