from PyQt5.QtWidgets import QApplication, QMessageBox
import sys

code = '''
import subprocess
subprocess.call(["git", "clean", "-df"]);
subprocess.call(["git", "reset", "--hard"]);
'''

if __name__ == '__main__':
    app = QApplication(sys.argv)

    exec(code)

    QMessageBox.information(None, "Сбросить", "Данные сброшены!")
