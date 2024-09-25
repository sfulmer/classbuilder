QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Argument.cpp \
    Class.cpp \
    ClassBuilderApp.cpp \
    ClassBuilderMainPanel.cpp \
    ClassModel.cpp \
    Constructor.cpp \
    Controller.cpp \
    Field.cpp \
    Function.cpp \
    General.cpp \
    Getter.cpp \
    Object.cpp \
    Observable.cpp \
    Operator.cpp \
    OperatorAssignment.cpp \
    OperatorEquals.cpp \
    Parent.cpp \
    Setter.cpp \
    Value.cpp \
    ValueField.cpp \
    ValueFunction.cpp \
    ValueLiteral.cpp \
    Variable.cpp \
    main.cpp \
    ClassBuilderMainWindow.cpp

HEADERS += \
    AccessControl.h \
    Argument.h \
    Class.h \
    ClassBuilderApp.h \
    ClassBuilderMainPanel.h \
    ClassBuilderMainWindow.h \
    ClassModel.h \
    Constructor.h \
    Controller.h \
    Field.h \
    Function.h \
    General.h \
    Getter.h \
    Object.h \
    Observable.h \
    Operator.h \
    OperatorAssignment.h \
    OperatorEquals.h \
    Parent.h \
    Setter.h \
    Value.h \
    ValueField.h \
    ValueFunction.h \
    ValueLiteral.h \
    Variable.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
