////
//// Created by John on 2/18/2024.
////
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QListWidget>
#include <QLabel>
#include <QTextEdit>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create main window
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Simple Journal App");
    mainWindow.resize(800, 600);

    // Create central widget and layout for main window
    QWidget *centralWidget = new QWidget(&mainWindow);
    mainWindow.setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *journalLayout = new QHBoxLayout();

    // Sidebar with journal entries
    QListWidget *journalEntries = new QListWidget();
    journalEntries->setFixedWidth(200);
    journalEntries->addItem("Entry 1");
    journalEntries->addItem("Entry 2");
    journalEntries->addItem("Entry 3");
    journalLayout->addWidget(journalEntries);

    // Journal page area
    QWidget *journalPageWidget = new QWidget();
    QVBoxLayout *journalPageLayout = new QVBoxLayout(journalPageWidget);
    QLabel *titleLabel = new QLabel("Journal Entry Title");
    QTextEdit *contentTextEdit = new QTextEdit();
    journalPageLayout->addWidget(titleLabel);
    journalPageLayout->addWidget(contentTextEdit);

    // Add journal page area to main layout
    journalLayout->addWidget(journalPageWidget);

    // Set the main layout for the central widget
    mainLayout->addLayout(journalLayout);

    // Create and add menu bar
    QMenuBar *menuBar = mainWindow.menuBar();
    QMenu *fileMenu = menuBar->addMenu("&File");
    fileMenu->addAction("&New Entry");
    fileMenu->addAction("&Save Entry");
    fileMenu->addAction("&Exit");

    QMenu *editMenu = menuBar->addMenu("&Edit");
    // Add edit actions as needed...

    // Cut, Copy, Duplicate, Paste
    editMenu->addAction("&Cut");
    editMenu->addAction("&Copy");
    editMenu->addAction("&Duplicate");
    editMenu->addAction("&Paste");


    QMenu *viewMenu = menuBar->addMenu("&View");
    // Add view actions as needed...

    QMenu *settingsMenu = menuBar->addMenu("&Settings");
    // Add settings actions as needed...

    // Show the main window
    mainWindow.show();

    return app.exec();
}


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create main window
    setWindowTitle("Simple Journal App");
    resize(800, 600);

    QIcon appIcon("./images/icon.png");
    setWindowIcon(appIcon);

    // Create central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create a QHBoxLayout to hold the main layout
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // Sidebar with journal entries
    QWidget* sidebar = new QWidget(this);
    QVBoxLayout* sidebarVLayout = new QVBoxLayout(sidebar);
    QPushButton *collapseButton = new QPushButton( this);
    collapseButton->setFixedWidth(5); // Set a fixed width for the button
    sidebarVLayout->addWidget(collapseButton);

    journalEntries = new QListWidget();
    journalEntries->setFixedWidth(200);
    sidebarVLayout->addWidget(journalEntries);
    //sidebarVLayout->addStretch(); // Add stretch to push the button to the bottom


    // Journal page area
    QWidget* journalPageWidget = new QWidget(this);
    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
    contentTextEdit = new QTextEdit();
    journalPageLayout->addWidget(titleLabel);
    journalPageLayout->addWidget(contentTextEdit);

    // Add sidebar and journalPageWidget to the main layout
    mainLayout->addWidget(sidebar);
    mainLayout->addWidget(journalPageWidget);

    // Create and add menu bar
    QMenuBar *menuBar = this->menuBar();
    QMenu *fileMenu = menuBar->addMenu("&File");

    // Create the File Menu actions
    QAction *newEntryAction = fileMenu->addAction("&New Entry");
    QAction* saveAction = fileMenu->addAction("&Save Entry");
    QAction* exitAction = fileMenu->addAction("&Exit");

    // Connect them to their handler functions
    QObject::connect(newEntryAction, &QAction::triggered, this, &MainWindow::createNewEntry);
    QObject::connect(saveAction, &QAction::triggered, this, &MainWindow::saveEntry);
    QObject::connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);

    // Connect the collapseButton to its handler function
    QObject::connect(collapseButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);

    // Change the behavior of the journal entries, when clicked on
    QObject::connect(journalEntries, &QListWidget::itemClicked, this, &MainWindow::loadEntryContent);

    QMenu *editMenu = menuBar->addMenu("&Edit");
    // Add edit actions as needed...

    // Cut, Copy, Duplicate, Paste
    editMenu->addAction("&Cut");
    editMenu->addAction("&Copy");
    editMenu->addAction("&Duplicate");
    editMenu->addAction("&Paste");

    // Populate entries from folder
    populateEntriesFromFolder();
}