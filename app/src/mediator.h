#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

#include "mainwindow.h"
#include "login.h"
#include "registration.h"
#include "general.h"

class MainWindow;
class LoginScreen;
class RegistrationScreen;
class GeneralScreen;

class Mediator : public QObject
{
    Q_OBJECT

private:
    MainWindow *mainWindow;
    LoginScreen *loginScreen;
    RegistrationScreen *registrationScreen;
    GeneralScreen *generalScreen;

public:
    Mediator();
    ~Mediator();

public slots:
    void signIn();
    void registrationOpen();
    void backToSignIn();

signals:
    void changeWidget(QWidget *widget, bool tool);
};
