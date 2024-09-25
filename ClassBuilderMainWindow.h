#pragma once

#include "ClassBuilderMainPanel.h"
#include <QMainWindow>

namespace net::draconia::classbuilder::ui
{
    class ClassBuilderMainWindow : public QMainWindow
    {
        Q_OBJECT

        ClassBuilderMainPanel *mPnlMain;
    protected:
        ClassBuilderMainPanel *getMainPanel();
        void initControls();
        void initMenus();
        void initWindow();
    public:
        explicit ClassBuilderMainWindow(QWidget *parent = nullptr);
        ClassBuilderMainWindow(QWidget *parent = nullptr);
        ~ClassBuilderMainWindow();
    };
}
