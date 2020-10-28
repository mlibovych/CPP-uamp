#include "mediator.h"

Mediator::Mediator() : QObject() {
    db = new MyDb(this);
    libraryManager = new LibraryManager(this);

    mainWindow = new MainWindow(this);
    loginScreen = new LoginScreen(this);
    mainWindow->layoutOuter->addWidget(loginScreen);
    registrationScreen = new RegistrationScreen(this);
    mainWindow->layoutOuter->addWidget(registrationScreen);
    generalScreen = new GeneralScreen(this);
    mainWindow->layoutOuter->addWidget(generalScreen);

    mainWindow->layoutOuter->setCurrentWidget(loginScreen);
    mainWindow->show();

    connect(this, SIGNAL(changeWidget(QWidget *, bool)), mainWindow, SLOT(setWidget(QWidget *, bool)));
    connect(this, SIGNAL(addSongsToLibrary(const QString&)), libraryManager, SLOT(addSongsToLibrary(const QString&)));
    connect(this, SIGNAL(showInLibrary(const Tags&)), generalScreen, SLOT(showInView(const Tags&)));
}


Mediator::~Mediator() {
    //
}

LibraryManager * Mediator::getLibraryManager() const {
    return libraryManager;
}

void Mediator::signIn() {
    user = new User(this);
    user->setId(0);
    user->setLogin("Test");
    emit changeWidget(generalScreen, true);
}

void Mediator::registrationOpen() {
    emit changeWidget(registrationScreen, false);
}

void Mediator::registrationTry() {
    emit registrationTry(registrationScreen->getLogin(),
                         registrationScreen->getPassword(),
                         registrationScreen->getPasswordRepeat()
                        );
}

void Mediator::backToSignIn() {
    emit changeWidget(loginScreen, false);
}

void Mediator::initImport(const QString& path) {
    emit addSongsToLibrary(path);
}

void Mediator::slotAddSong(const Tags& tags) {
    emit showInLibrary(tags);
}