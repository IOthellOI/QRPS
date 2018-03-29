//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   FileTable
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef FILETABLE_H
#define FILETABLE_H

#include "baseWidget.h"

namespace table
{
	class FileTable : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit FileTable(QWidget * _parent = nullptr);
		virtual ~FileTable();

	public:
		virtual void setTitle(const QString & _text) const;

	public slots:
		void slotButtonChecked();

	private:
		struct FileTableData;
		FileTableData * data;
	};
}

#endif // !FILETABLE_H