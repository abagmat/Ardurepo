from PyQt5.QtWidgets import QApplication, QMessageBox
from PyQt5.QtCore import QIODevice, QBuffer, QByteArray, QTimer
from PyQt5.Qt import QSettings
import sys, requests, base64


def get_encoded_screen_shot():
    screenshot = QApplication.primaryScreen().grabWindow(0)

    byte_array = QByteArray()
    buffer = QBuffer(byte_array)
    buffer.open(QIODevice.WriteOnly)
    screenshot.save(buffer, "JPG")
    return base64.b64encode(byte_array.data())


def upload_screenshot(url, name, screen_shot_b64):
    print(f"uploading '{name}' to db...")
    patch_data = {name: screen_shot_b64.decode("utf-8")}
    response = requests.patch(url, json=patch_data)
    print(response.status_code)
    if response.status_code != 200:
        QMessageBox.critical(None, "Снимок", f"Ошибка {response.status_code}!")
        sys.exit(-1)


if __name__ == '__main__':
    app = QApplication(sys.argv)

    settings = QSettings("Home", "Ardurepo")
    url = settings.value("db_url") + "/screenshots.json"

    requests.delete(url)

    def on_timer():
        screen_shot_b64 = get_encoded_screen_shot()
        upload_screenshot(url, "desktop", screen_shot_b64)
        app.beep()

    timer = QTimer()
    timer.timeout.connect(on_timer)
    timer.start(10000)

    QMessageBox.information(None, "Снимок", "Снимок экрана отсылается каждые 10 сек. Нажмите ОК чтобы остановить выйти.")
