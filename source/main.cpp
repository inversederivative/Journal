#include <MainWindow.hpp>
#include <QStyleFactory>
#include <QStandardPaths>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    app.setStyle(QStyleFactory::create("Fusion"));

    // Create the main window
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}