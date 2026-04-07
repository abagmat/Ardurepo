from PyQt5.QtWidgets import QApplication, QMessageBox
from PyQt5.Qt import QSettings
import sys


if __name__ == '__main__':
    app = QApplication(sys.argv)

    settings = QSettings("Home", "Ardurepo")
    settings.setValue("db_url", "")

    QMessageBox.information(None, "Settings", "Данные записаны!")
