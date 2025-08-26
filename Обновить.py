from PyQt5.QtWidgets import QApplication, QMessageBox
import sys

code = '''
import subprocess
subprocess.call(["git", "pull"]);
'''

if __name__ == '__main__':
    app = QApplication(sys.argv)

    exec(code)

    QMessageBox.information(None, "Обновить", "Данные обновлены!")
