from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QLabel
from PyQt5.QtGui import QPixmap, QImage
from PyQt5.QtCore import QRect, Qt
import sys

class ScreenshotApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Скриншот PyQt")
        self.button = QPushButton("Сделать скриншот")
        self.button.clicked.connect(self.take_screenshot)
        self.image_label = QLabel()
        self.image_label.setFixedSize(300, 200) # Установите желаемый размер для отображения
        layout = QVBoxLayout()
        layout.addWidget(self.button)
        layout.addWidget(self.image_label)
        self.setLayout(layout)

    def take_screenshot(self):
        screen = QApplication.primaryScreen()
        if screen:
            screenshot = screen.grabWindow(0)  # 0 для захвата всего экрана
            self.image_label.setPixmap(screenshot.scaled(300, 200, Qt.KeepAspectRatio)) # Отображаем уменьшенную копию
        else:
            print("Не удалось получить экран.")

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = ScreenshotApp()
    window.show()
    sys.exit(app.exec_())