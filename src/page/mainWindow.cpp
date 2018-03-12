#include "mainWindow.h"
#include "navigation.h"
#include "mainPage.h"

#include <QLayout>

struct page::MainWindow::MainWindowData
{
	Navigation * navigation;
	MainPage * mainPage;
};

page::MainWindow::MainWindow(QWidget * _parent):
	BaseWidget(_parent),
	data(new MainWindowData)
{
	data->navigation = new Navigation;
	data->mainPage = new MainPage;

	data->navigation->loadConfig("./data/page/navigation.xml");
	data->mainPage->loadConfig("./data/page/mainPage.xml");

	QHBoxLayout * layout = new QHBoxLayout;

	layout->setMargin(2);
	layout->setSpacing(2);

	layout->addWidget(data->navigation);
	layout->addWidget(data->mainPage);

	setLayout(layout);

	setWindowFlags(Qt::FramelessWindowHint);
	setFixedWidth(1280);
	setFixedHeight(800);

	connect(data->navigation,
		SIGNAL(signalPageChanged(const QString &)),
		data->mainPage,
		SLOT(slotPageChanged(const QString &)));
}

page::MainWindow::~MainWindow()
{
	delete data;
}
