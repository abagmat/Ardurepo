from PyQt5.QtWidgets import QApplication, QMessageBox
import sys

code = '''
import subprocess
subprocess.call(["git", "pull"]);

subprocess.call(["pip", "install", "urllib3==1.26.6"]);
subprocess.call(["pip", "install", "pywin32==308"]);
subprocess.call(["pip", "install", "requests==2.31.0"]);
'''

if __name__ == '__main__':
    app = QApplication(sys.argv)

    exec(code)

    QMessageBox.information(None, "Обновить", "Данные обновлены!")
