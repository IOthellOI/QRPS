//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   NavigationButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef NAVIGATIONBUTTON_H
#define NAVIGATIONBUTTON_H

#include "baseWidget.h"

namespace button
{
	class NavigationButton : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit NavigationButton(QWidget * _parent = nullptr);
		virtual ~NavigationButton();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setIcon(const QIcon & _icon) const;
		virtual void setChecked(bool _checked) const;
		virtual void setBindPage(const QString & _page) const;

	signals:
		void signalClicked(const QString & _page);

	public slots:
		void slotClicked(bool _clicked);

	private:
		struct NavigationButtonData;
		NavigationButtonData * data;
	};
}

#endif // !NAVIGATIONBUTTON_H