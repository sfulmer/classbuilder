#include "ClassBuilderApp.h"

using namespace net::draconia::classbuilder;

void ClassBuilderApp::showMainWindow()
{
    getMainWindow().show();
}

ClassBuilderApp::ClassBuilderApp(int argc, char **argv)
    :   QApplication(argc, argv)
{ }

ClassBuilderApp::~ClassBuilderApp()
{ }

int ClassBuilderApp::exec()
{
    showMainWindow();

    return(QApplication::exec());
}

ClassBuilderMainWindow &ClassBuilderApp::getMainWindow()
{
    return(mWndMain);
}
