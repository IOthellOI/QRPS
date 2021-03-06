//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataTable
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef DATATABLE_H
#define DATATABLE_H

#include "baseWidget.h"

namespace table
{
	class DataTable : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit DataTable(QWidget * _parent = nullptr);
		virtual ~DataTable();

	public:
		virtual void setTitle(const QString & _text) const;
		virtual void loadConfig(const QString & _path) const;

	private:
		struct DataTableData;
		DataTableData * data;
	};
}

#endif // !DATATABLE_H