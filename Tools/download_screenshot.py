from PyQt5.QtWidgets import QApplication
from PyQt5.Qt import QSettings
import sys, requests, base64
from pathlib import Path


def screenshots_folder():
    folder = Path.cwd() / "screenshots"
    folder.mkdir(parents=True, exist_ok=True)
    return folder


def screenshot_list(url):
    response = requests.get(url + ".json?shallow=true")
    return list(response.json().keys())


if __name__ == '__main__':
    app = QApplication(sys.argv)

    settings = QSettings("Home", "Ardurepo")
    url = settings.value("db_url") + "/screenshots"

    folder = screenshots_folder()

    screenshot_names = screenshot_list(url)
    for name in screenshot_names:
        print(f"downloading {name}.jpg...")
        response = requests.get(url + f"/{name}.json")
        if response.status_code != 200:
            print(f"Download error: {response.status_code}")
            continue

        screenshot_file = folder / f"{name}.jpg"
        with open(screenshot_file, "wb") as f:
            decoded_data = base64.b64decode(response.json())
            f.write(decoded_data)
            f.close()
            print(f"Saved to {screenshot_file}")

