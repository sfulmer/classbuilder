#pragma once

#include "ClassBuilderMainWindow.h"
#include <QApplication>

using net::draconia::classbuilder::ui::ClassBuilderMainWindow;

namespace net::draconia::classbuilder
{
    class ClassBuilderApp : public QApplication
    {
        Q_OBJECT

        ClassBuilderMainWindow mWndMain;
    protected:
        void showMainWindow();
    public:
        ClassBuilderApp(int argc,char **argv);
        ~ClassBuilderApp();

        int exec();
        ClassBuilderMainWindow &getMainWindow();
    };
}
